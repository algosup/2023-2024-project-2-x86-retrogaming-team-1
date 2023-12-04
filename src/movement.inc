section .data

    xPos dw 0                   ; the position of the sprite 
    
    xVelocity dw 1              ; horizontal speed of pacman
    yVelocity dw 320            ; vertical speed of pacman

    keyRight db 4Dh             ; the hexa value of the right arrow key
    keyLeft db 4Bh              ; the hexa value of the left arrow key
    keyUp db 48h                ; the hexa value of the up arrow key
    keyDown db 50h              ; the hexa value of the down arrow key
    keyExit db 27               ; the ascii value of the esc key

section .text

readKeyb:
    ; Read keyboard input
    mov ah, 00h                 ; BIOS function to read keyboard input
    int 16h                     ; Call BIOS interrupt

    cmp ah, [keyRight]          ; compare the value of the key pressed to the value of keyRight
    je playerMovR               ; if equal jump to the playerMovRight procedure

    cmp ah, [keyLeft]           ; compare the value of the key pressed to the value of keyLeft
    je playerMovL               ; if equal jump to the playerMovLeft procedure

    cmp ah, [keyUp]             ; compare the value of the key pressed to the value of keyUp
    je playerMovUp              ; if equal jump to the playerMovUp procedure

    cmp ah, [keyDown]           ; compare the value of the key pressed to the value of keyDown
    je playerMovDown            ; if equal jump to playerMovDown procedure

    cmp al, [keyExit]           ; compare the value of the key pressed to the value of keyExit
    je exit                     ; if equal jump to the exit procedure

playerMovR:
    mov bx, [xPos]              ; move the position inside the bx register
    add bx, [xVelocity]         ; add the horizontal speed inside the vector bx
    mov word [xPos], bx         ; update xPos 
    mov di, [xPos]              ; update the position
    mov si, pacmanR_00          ; choose the sprite to be displayed
    call drawPacman             ; draw the sprite 
    ret                         ; return

playerMovL:
    mov bx, [xPos]              ; move the position inside the bx register
    sub bx, [xVelocity]         ; substract the horizontal speed inside the vector bx
    mov word [xPos], bx         ; update xPos
    mov di, [xPos]              ; update the position
    mov si, pacmanL_00          ; choose the sprite to be displayed
    call drawPacman             ; draw the sprite
    ret                         ; return

playerMovUp:
    mov bx, [xPos]              ; move the position inside the bx register
    sub bx, [yVelocity]         ; substract the vertical speed inside the vector bx
    mov word [xPos], bx         ; update xPos
    mov di, [xPos]              ; update the position
    mov si, pacmanUp_00         ; choose the sprite to be displayed
    call drawPacman             ; draw the sprite
    ret                         ; return

playerMovDown:
    mov bx, [xPos]              ; move the position inside the bx register
    add bx, [yVelocity]         ; add the vertical speed inside the vector bx
    mov word [xPos], bx         ; update xPos
    mov di, [xPos]              ; update the position
    mov si, pacmanDown_00       ; choose the sprite to be displayed
    call drawPacman             ; draw the sprite
    ret                         ; return