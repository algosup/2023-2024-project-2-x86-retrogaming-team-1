section .data 

    ; the position that will be used during the game
    ; and the position you are sent to after you loose a life
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
    mov [oldPos], bx            ; set the old position in case
    add bx, [xVelocity]         ; add the horizontal speed inside the vector bx
    mov word [xPos], bx         ; update xPos 
    call movMelody              ; play the movMelody

    ; we set cx and dx before invocking 0Dh
    .checkCollisionMiddle:
        
        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 8               ; that line set the row of the sprite
        add word [yPos], 15     ; and this one the column of the sprite
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

        cmp bx, 5               ; check for a ghost
        je .ghost               ; if yes go to ghost

    ; we set cx and dx before invocking 0Dh
    .checkCollisionUp:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add word [yPos], 15     ; this line set the column of the sprite
        mov cx, [yPos]          ; the default row is the top one so we dont need to touch it
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop
    
    ; we set cx and dx before invocking 0Dh
    .checkCollisionDown:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 15              ; this line set the row of the sprite
        add word [yPos], 15     ; this one the column of the sprite
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
        mov bx, [startPos]      ; prepare the starting position
        mov word [xPos], bx     ; update the xPos to the starting one
        mov di, [xPos]          ; update the actual position
        mov si, pacmanR_00      ; select the sprite to be displayed
        call drawSprite         ; display the sprite

        ret                     ; return

    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanR_00      ; select the sprite
        call drawSprite         ; draw the sprite

        ret                     ; return

playerMovL:
    
    mov bx, [xPos]              ; move the position inside the bx register
    mov [oldPos], bx            ; set the old position in case of colision
    sub bx, [xVelocity]         ; substract the horizontal speed inside the vector bx
    mov word [xPos], bx         ; update xPos
    call movMelody              ; play the movMelody

    ; we set cx and dx before invocking 0Dh
    .checkCollisionMiddle:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 8               ; this line set the column of the sprite
        mov cx, [yPos]          ; we dont modify the row since it's already on the left side
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

        cmp bx, 5               ; check if there is a ghost
        je .ghost               ; go to ghost
    
    ; we set cx and dx before invocking 0Dh
    ; no need to modify the row/column since its the starting pixel
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

    ; we set cx and dx before invocking 0Dh
    .checkCollisionDown:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add ax, 15              ; only need to modify the column in the sprite
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
        mov bx, [startPos]      ; prepare the starting position
        mov word [xPos], bx     ; update xPos
        mov di, [xPos]          ; update the position to the starting position
        mov si, pacmanR_00      ; select the sprite to be displayed
        call drawSprite         ; draw the sprite

        ret                     ; return

    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanL_00      ; select the sprite
        call drawSprite         ; draw the sprite

        ret                     ; return

playerMovUp:
    mov bx, [xPos]              ; move the position inside the bx register
    mov [oldPos], bx            ; set the old position in case of colision
    sub bx, [yVelocity]         ; substract the vertical speed inside the vector bx
    mov word [xPos], bx         ; update xPos
    call movMelody              ; play the movMelody
    
    ; we set cx and dx before invocking 0Dh
    .checkCollisionMiddle:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add word [yPos], 8      ; change the column of the sprite 
        mov cx, [yPos]
        mov dx, ax

        call checkColor         ; file colorChecker

        cmp bx, 0               ; check if there is a wall 
        je .stop                ; if yes go to stop

        cmp bx, 5               ; check if there is a ghost
        je .ghost               ; if yes go to ghost
    
    ; we set cx and dx before invocking 0Dh
    ; no need to modify the row/column since its the starting pixel
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

    ; we set cx and dx before invocking 0Dh
    .checkCollisionRight:

        mov ax, [xPos]
        mov cx, windowWidth
        xor dx, dx
        div cx
        mov [yPos], dx
        add word [yPos], 15     ; change the column of the sprite
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
        mov bx, [startPos]      ; prepare the starting position
        mov word [xPos], bx     ; update xPos 
        mov di, [xPos]          ; update the position to the starting one 
        mov si, pacmanR_00      ; select the sprite 
        call drawSprite         ; draw the sprite

        ret                     ; return

    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanUp_00      ; select the sprite
        call drawSprite         ; draw the sprite

        ret                     ; return


playerMovDown:
    mov bx, [xPos]              ; move the position inside the bx register
    mov [oldPos], bx            ; set the old position in case of colision
    add bx, [yVelocity]         ; add the vertical speed inside the vector bx
    mov word [xPos], bx         ; update xPos
    call movMelody              ; play the movMelody
   
   ; we set cx and dx before invocking 0Dh
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

        cmp bx, 5               ; check if there is a ghost
        je .ghost               ; if yes go to ghost
    
    ; we set cx and dx before invocking 0Dh
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
    
    ; we set cx and dx before invocking 0Dh
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
        mov bx, [startPos]      ; prepare the starting position
        mov word [xPos], bx     ; update xPos
        mov di, [xPos]          ; update the position to the strating position
        mov si, pacmanR_00      ; select the sprite 
        call drawSprite         ; draw the sprite

        ret                     ; return

    .stop:
        mov bx, [oldPos]        ; revive the old position
        mov [xPos], bx          ; update the xPos
        mov dx, [xPos]          ; update the position
        mov si, pacmanDown_00   ; select the sprite
        call drawSprite         ; draw the sprite

        ret                     ; return