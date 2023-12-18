section .data

    keyRight db 4Dh             ; the hexa value of the right arrow key
    keyLeft db 4Bh              ; the hexa value of the left arrow key
    keyUp db 48h                ; the hexa value of the up arrow key
    keyDown db 50h              ; the hexa value of the down arrow key
    keyExit db 27               ; the ascii value of the esc key

section .text

 readKeyb:
    xor ax, ax
    mov ah, 00h
    int 16h

    cmp ah, [keyRight]          ; compare the value of the key pressed to the value of keyRight
    je playerMovR               ; if equal jump to the playerMovRight procedure

    cmp ah, [keyLeft]           ; compare the value of the key pressed to the value of keyLeft
    je playerMovL               ; if equal jump to the playerMovLeft procedure

    cmp ah, [keyUp]             ; compare the value of the key pressed to the value of keyUp
    je playerMovUp              ; if equal jump to the playerMovUp procedure

    cmp ah, [keyDown]           ; compare the value of the key pressed to the value of keyDown
    je playerMovDown            ; if equal jump to playerMovDown procedure

    cmp al, [keyExit]           ; compare the value of the key pressed to the value of keyExit
    je .exit                    ; if equal jump to the exit procedure

    ret

    ; exit the program
    .exit:                      
        mov ah, 4ch
        xor al, al
        int 21h