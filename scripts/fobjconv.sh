#!/bin/bash
##
## Adapted and expanded from :
## https://github.com/diogovk/c2nasm/blob/master/c2nasm.sh
##
###########################
set -e
help(){
	echo "$1: Formats and cleans up the output of objconv to nasm"
	echo "usage: $1 <sourcefile> without the extension, it will look"
	echo 'for <sourcefile.out> in the first place or <sourcefile.o>'
	echo "if it couldn't find <sourcefile.out> secondly."
	echo "it is meant both as a tool for the script c2nasm, and"
	echo "by itself to cleanup the dissasembly output for an executable"
	echo "not just the object file."
	exit 0
}

NASM_FILE="${1}.nasm"
if [[ -f "${1}.out" ]]; then
	EXEC="${1}.out"
else
	EXEC="${1}.o"
fi

objconv -fnasm "$EXEC" "$NASM_FILE"
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
sed -i 's@\(^SECTION \.text\).*@\1@g' "$NASM_FILE"
sed -i '/[ ]\+ret$/ n; s/^[ ]\+[a-z|0-9]\+$//g' "$NASM_FILE"
sed -i '/^$/d;s/[ ]\+$//g' "$NASM_FILE"
unexpand --tabs="4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80" "$NASM_FILE" > tmp.nasm
mv tmp.nasm "$NASM_FILE"
