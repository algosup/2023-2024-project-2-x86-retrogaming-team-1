section .data

colorWall dw 0x11

section .text

checkColor:

    mov ah, 0Ch
    mov al, 0Dh
    int 10h

    mov ah, 0Dh
    int 10h

    mov bx, 0

    cmp al, [colorWall]
    je .wall

    .wall:
    ret