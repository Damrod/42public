#!/bin/bash
set -e
help(){
  echo "$1: Uses gcc and objconv to convert a C program to nasm"
  echo "usage: $1 <sourcefile.c>"
  exit 0
}
ARCH="x64"
OPT="-O0"
until [ -z "$1" ]
do
	if [ "${1: -2}" == ".c" ]
	then
		C_FILE=$(basename "$1" .c)
	fi
	if [[ "$1" == "-O0" || "$1" == "-O1" || "$1" == "-O2" || "$1" == "-O3" ]]
	then
		OPT=$1
	fi
	if [ $1 = "x86" ]
	then
		FLAG="elf"
	else
		FLAG="elf64"
	fi
	if [[ $1 = "-h" || $1 = "--help" ]]
	then
		help "$(basename "$0")"
	fi
	shift
done
if [ -z $C_FILE ]
then
	help "$(basename "$0")"
fi
O_FILE=${C_FILE}.o
NASM_FILE="${C_FILE}.nasm"
NASM_O_FILE="$NASM_FILE.o"
EXEC_FILE="$C_FILE.out"
gcc ${OPT} -c -s -fno-asynchronous-unwind-tables -o "$O_FILE" "${C_FILE}.c"
echo "This is opt ${OPT}, this is arch ${FLAG}"
objconv -fnasm "$O_FILE" "$NASM_FILE"
sed -i 's@st(0)@st0  @g' "$NASM_FILE"
sed -i 's@noexecute@         @g' "$NASM_FILE"
sed -i 's@execute@       @g' "$NASM_FILE"
sed -i 's@: function@@g' "$NASM_FILE"
sed -i 's@?_@L_@g' "$NASM_FILE"
sed -i -n '/SECTION .eh_frame/q;p' "$NASM_FILE"
sed -i 's@;.*@@g' "$NASM_FILE"
sed -i 's/^M//g' "$NASM_FILE"
sed -i 's@\s\+$@@g' "$NASM_FILE"
sed -i 's@align=1@@g' "$NASM_FILE"
sed -i '/[ ]\+ret$/ n; s/^[ ]\+[a-z|0-9]\+$//g' "$NASM_FILE"
sed -i '/^$/d;s/[ ]\+$//g' "$NASM_FILE"
unexpand --tabs="4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80" "$NASM_FILE" > tmp.nasm
mv tmp.nasm "$NASM_FILE"
echo 'Nasm file generated in '"$NASM_FILE"
nasm -f ${FLAG} -o "$NASM_O_FILE" "$NASM_FILE"
gcc -o "$EXEC_FILE"  "$NASM_O_FILE" main.c
echo 'Successfully compiled '"$NASM_FILE" to "$EXEC_FILE"
