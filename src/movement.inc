section .data                  ; the position of the sprite

    xPos dw windowWidth*96+(windowWidth-16)/2
    startPos dw windowWidth*96+(windowWidth-16)/2

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
    .checkCollisionMiddle:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 8
        add word [yPos], 15
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

        cmp bx, 5
        je .ghost

    .checkCollisionUp:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add word [yPos], 15
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

    .checkCollisionDown:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 15
        add word [yPos], 15
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

    .move:
        mov di, [xPos]          ; update the position
        mov si, pacmanR_00      ; choose the sprite to be displayed
        call drawSprite         ; draw the sprite 

        ret                     ; return
    
    .ghost:
        mov bx, [startPos]
        mov word [xPos], bx
        mov di, [xPos] 
        mov si, pacmanR_00
        call drawSprite
        call check_game_over

        ret

    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanR_00      ; select the sprite
        call drawSprite         ; draw the sprite

        ret                     ; return

playerMovL:
    
    mov bx, [xPos]              ; move the position inside the bx register
    mov [oldPos], bx
    sub bx, [xVelocity]         ; substract the horizontal speed inside the vector bx
    mov word [xPos], bx         ; update xPos

    .checkCollisionMiddle:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 8
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

        cmp bx, 5
        je .ghost
    
    .checkCollisionUp:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

    .checkCollisionDown:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 15
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

    .move:
        mov di, [xPos]          ; update the position
        mov si, pacmanL_00      ; choose the sprite to be displayed
        call drawSprite         ; draw the sprite 

        ret                     ; return

    .ghost:
        mov bx, [startPos]
        mov word [xPos], bx
        mov di, [xPos] 
        mov si, pacmanR_00
        call drawSprite

        ret

    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanL_00      ; select the sprite
        call drawSprite         ; draw the sprite

        ret                     ; return

playerMovUp:
    mov bx, [xPos]              ; move the position inside the bx register
    mov [oldPos], bx
    sub bx, [yVelocity]         ; substract the vertical speed inside the vector bx
    mov word [xPos], bx         ; update xPos
    
    .checkCollisionMiddle:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add word [yPos], 8
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

        cmp bx, 5
        je .ghost
    
    .checkCollisionLeft:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

    .checkCollisionRight:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add word [yPos], 15
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

    .move:
        mov di, [xPos]          ; update the position
        mov si, pacmanUp_00      ; choose the sprite to be displayed
        call drawSprite         ; draw the sprite 

        ret                     ; return

    .ghost:
        mov bx, [startPos]
        mov word [xPos], bx
        mov di, [xPos] 
        mov si, pacmanR_00
        call drawSprite

        ret

    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanUp_00      ; select the sprite
        call drawSprite         ; draw the sprite

        ret                     ; return


playerMovDown:
    mov bx, [xPos]              ; move the position inside the bx register
    mov [oldPos], bx
    add bx, [yVelocity]         ; add the vertical speed inside the vector bx
    mov word [xPos], bx         ; update xPos
   
   .checkCollisionMiddle:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 15
        add word [yPos], 8
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

        cmp bx, 5
        je .ghost
    
    .checkCollisionLeft:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 15
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop
    
    .checkCollisionRight:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 15
        add word [yPos], 15
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

    .move:
        mov di, [xPos]          ; update the position
        mov si, pacmanDown_00   ; choose the sprite to be displayed
        call drawSprite         ; draw the sprite 

        ret                     ; return

    .ghost:
        mov bx, [startPos]
        mov word [xPos], bx
        mov di, [xPos] 
        mov si, pacmanR_00
        call drawSprite

        ret

    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanDown_00   ; select the sprite
        call drawSprite         ; draw the sprite

        ret                     ; return
