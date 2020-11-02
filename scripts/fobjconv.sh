#!/bin/bash
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
