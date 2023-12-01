section .data

    xPos dw 0
    
    xVelocity dw 1
    yVelocity dw 320

section .text

readKeyb:
    ; Read keyboard input
    mov ah, 01h                 ; BIOS function to read keyboard input
    int 21h                     ; Call BIOS interrupt
    cmp al, 77                  ; 'right arrow' in ascii is 77
    je playerMovR               ; If right arrow is pressed, jump to label 'playerMovR'
    cmp al, 75                  ; 'left arrow' in ascii is 75
    je playerMovL               ; If 'left arrow' is pressed, jump to label 'playerMov'
    cmp al, 72                  ; 'up arrow' in ascii is 72
    je playerMovUp              ; If 'up arrow' is pressed, jump to label 'playerMov'
    cmp al, 80                  ; 'down arrow' in ascii is 80
    je playerMovDown            ; If 'down arrow' is pressed, jump to label 'playerMovDown'
    cmp al, 27                  ; 'escape' in ascii is 27
    je exit                     ; If 'escape' is pressed jump to label 'exit'

    ret                         ; return to the main loop

playerMovR:
    mov bx, [xPos]              ; move the position inside the bx register
    add bx, [xVelocity]         ; add the horizontal speed inside the vector bx
    mov word [xPos], bx         ; update the position 
    mov si, pacmanR_00          ; move the sprite to be displayed inside the si register
    call drawPacman             ; draw the sprite that was selected
    jmp readKeyb                ; jump back to the keyboard reader

playerMovL:
    mov bx, [xPos]              ; move the position inside the bx register
    sub bx, [xVelocity]         ; substract the horizontal speed inside the vector bx
    mov word [xPos], bx         ; update the position 
    mov si, pacmanL_00          ; move the sprite to be displayed inside the si register
    call drawPacman             ; draw the sprite that was selected
    jmp readKeyb                ; jump back to the keyboard reader

playerMovUp:
    mov bx, [xPos]              ; move the position inside the bx register
    sub bx, [yVelocity]         ; substract the vertical speed inside the vector bx
    mov word [xPos], bx         ; update the position 
    mov si, pacmanUp_00         ; move the sprite to be displayed inside the si register
    call drawPacman             ; draw the sprite that was selected
    jmp readKeyb                ; jump back to the keyboard reader

playerMovDown:
    mov bx, [xPos]              ; move the position inside the bx register
    add bx, [yVelocity]         ; add the vertical speed inside the vector bx
    mov word [xPos], bx         ; update the position 
    mov si, pacmanDown_00       ; move the sprite to be displayed inside the si register
    call drawPacman             ; draw the sprite that was selected
    jmp readKeyb                ; jump back to the keyboard reader
