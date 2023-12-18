section .data

    colorWall dw 0x11
    colorGhost1 dw 0x28
    colorGhost2 dw 0x2A
    colorGhost3 dw 0x0D
    colorGhost4 dw 0x0B

section .text

checkColor:

    ; mov ah, 0Ch
    ; mov al, 0Dh
    ; int 10h

    mov ah, 0Dh
    int 10h

    mov bx, 0

    cmp al, [colorWall]
    je .return

    mov bx, 1

    cmp al, [colorGhost1]
    je .ghost
    cmp al, [colorGhost2]
    je .ghost
    cmp al, [colorGhost3]
    je .ghost
    cmp al, [colorGhost4]
    je .ghost

    jmp .return

    .ghost:
    mov bx, 5
    jmp .return


    .return:
    ret