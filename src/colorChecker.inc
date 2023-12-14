section .data

colorWall dw 0x11

section .text

checkColor:

    mov ah, 0Dh
    int 10h

    mov bx, 0

    cmp al, [colorWall]
    jmp .wall

    .wall:
        mov ax, 1

    ret