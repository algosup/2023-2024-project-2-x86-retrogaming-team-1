section .data

    xPos dw windowWidth*96+(windowWidth-16)/2                   ; the position of the sprite

    ; these two are used for the collision
    yPos dw 0       
    oldPos dw 0
    
    xVelocity dw 1              ; horizontal speed of pacman
    yVelocity dw 320            ; vertical speed of pacman

section .text

playerMovR:
    mov bx, [xPos]              ; move the position inside the bx register
    mov [oldPos], bx
    add bx, [xVelocity]         ; add the horizontal speed inside the vector bx
    mov word [xPos], bx         ; update xPos 

    ; we set cx and dx before invocking 0Dh
    .checkCollision:
        mov ax, [xPos]
        mov cx, [windowWidth]
        xor dx, dx              ; set dx to 0
        div cx                  ; isolate the sprite
        mov [yPos], dx          ; set yPos to 0
        add word [yPos], 15     ; go to the edge of the sprite
        mov cx, [yPos]          ; cx set
        add ax, 8               ; go to the middle of the sprite
        mov dx, ax              ; dx set

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

        
    .move:
        mov di, [xPos]          ; update the position
        mov si, pacmanR_00      ; choose the sprite to be displayed
        call drawPacman         ; draw the sprite 

        ret                     ; return
    
    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanR_00      ; select the sprite
        call drawPacman         ; draw the sprite

        ret                     ; return

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

%include "colorChecker.inc"