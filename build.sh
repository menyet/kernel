echo "ASM"
nasm -f elf32 kernel.asm -o kasm.o
echo "GCC"
gcc -ffreestanding -m32 -c kernel.c -o kc.o
echo "LINK"
ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o -nostdlib
