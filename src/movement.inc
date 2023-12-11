section .data

    xPos dw windowWidth*96+(windowWidth-16)/2                   ; the position of the sprite 
    
    xVelocity dw 1              ; horizontal speed of pacman
    yVelocity dw 320            ; vertical speed of pacman

section .text

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