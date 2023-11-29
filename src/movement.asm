section .data

    xPos dw 0
    
    xVelocity dw 1
    yVelocity dw 320

section .text

readKeyb:
    ; Read keyboard input
    mov ah, 01h                 ; BIOS function to read keyboard input
    int 21h                     ; Call BIOS interrupt
    cmp al, 77                  ; 'd' in ascii is 100
    je playerMovR               ; If 'd' is pressed, jump to label 'collisionR'
    cmp al, 75                  ; 'q' in ascii is 113
    je playerMovL               ; If 'q' is pressed, jump to label 'left'
    cmp al, 72                  ; 'z' in ascii is 122
    je playerMovUp              ; If 'z' is pressed, jump to label 'up'
    cmp al, 80                  ; 's' in ascii is 115
    je playerMovDown            ; If 's' is pressed, jump to label 'down'
    cmp al, 27
    je exit

    ;mov ax, 0C01h               ; reset the keyboard buffer
    ;int 21h

    ret

playerMovR:
    mov bx, [xPos]
    add bx, [xVelocity]
    mov word [xPos], bx
    mov si, pacmanR
    call drawPacman
    jmp readKeyb

playerMovL:
    mov bx, [xPos]
    sub bx, [xVelocity]
    mov word [xPos], bx
    mov si, pacmanL
    call drawPacman
    jmp readKeyb

playerMovUp:
    mov bx, [xPos]
    sub bx, [yVelocity]
    mov word [xPos], bx
    mov si, pacmanUp
    call drawPacman
    jmp readKeyb

playerMovDown:
    mov bx, [xPos]
    add bx, [yVelocity]
    mov word [xPos], bx
    mov si, pacmanDown
    call drawPacman
    jmp readKeyb
