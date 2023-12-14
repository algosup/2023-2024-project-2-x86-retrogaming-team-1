section .data

colorWall dw 0x10

section .text

checkColor:

    mov ah, 0Dh
    int 10h

    mov bx, 0

    cmp bx, [colorWall]
    mov ax, 1

    ret