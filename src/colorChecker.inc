section .data

    ; the colors of the differents things we want to check for
    colorWall dw 0x11
    colorGhost1 dw 0x28
    colorGhost2 dw 0x2A
    colorGhost3 dw 0x0D
    colorGhost4 dw 0x0B

section .text

checkColor:

    ; debug 
    ;----------------
    ; mov ah, 0Ch
    ; mov al, 0Dh
    ; int 10h
    ;----------------

    mov ah, 0Dh                 ; return the color of the pixel into al
    int 10h

    mov bx, 0                   ; set the page 

    cmp al, [colorWall]         ; check for a wall colision
    je .return                  

    mov bx, 1                   ; set the page 

    ; check for the different ghosts
    ; same result because the ghost do the same thing
    cmp al, [colorGhost1]
    je .ghost
    cmp al, [colorGhost2]
    je .ghost
    cmp al, [colorGhost3]
    je .ghost
    cmp al, [colorGhost4]
    je .ghost

    ; incase there is no colision
    jmp .return                 

    ; incase there is a colision with a ghost
    .ghost:                     
    mov bx, 5
    jmp .return


    .return:
    ret