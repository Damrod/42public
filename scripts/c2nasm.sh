#!/bin/bash
##
## Adapted and expanded from :
## https://github.com/diogovk/c2nasm/blob/master/c2nasm.sh
## Changelog:
## split in two files: c2nasm and fobjconv
## added some flags to dissaseble for different architectures
## added the ability to accept optimizing flags
## added the ability to use clang besides gcc as a compiler.
## removed the "linking back to test" phase if a main.c is not provided.
##
###########################
set -e
help(){
  echo "$1: Uses gcc and objconv to convert a C program to nasm"
  echo "usage: $1 <sourcefile.c>"
  echo 'takes "-O0" ... "-O3" .. "-Os" flags for compiling'
  echo '"x86" flag for 32bit architecture compilation'
  exit 0
}
ARCH="x64"
OPT="-O0"
CC="gcc"

until [ -z "$1" ]
do
	if [ "$1" == "clang" ]
	then
		CC=clang
	fi
	if [ "${1: -2}" == ".c" ]
	then
		C_FILE=$(basename "$1" .c)
	fi
	if [[ "$1" == "-O0" || "$1" == "-O1" || "$1" == "-O2" || "$1" == "-O3" || "$1" == "-Os" ]]
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
${CC} ${OPT} -c -fno-asynchronous-unwind-tables -o "$O_FILE" "${C_FILE}.c"
echo "This is optimization flag ${OPT}, this is selected flag arch ${FLAG}"
fobjconv ${C_FILE}
echo 'Nasm file generated in '"$NASM_FILE"
nasm -f ${FLAG} -o "$NASM_O_FILE" "$NASM_FILE"
if [[ -f "main.c" ]]; then
	${CC} -o "$EXEC_FILE"  "$NASM_O_FILE" main.c
	echo 'Successfully compiled '"$NASM_FILE" to "$EXEC_FILE"
else
	echo 'Successfully compiled '"$NASM_FILE" to "$NASM_O_FILE"
fi
