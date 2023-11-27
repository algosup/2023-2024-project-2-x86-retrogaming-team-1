; TODO
; fix sprites
; start of a map
; fix collisions
; fix color of the clearScreen;
; fix character printing

%include "pacman.asm"          ; include the file with the sprites

org 100h    

section .data

    xPos dw 0                   ; the starting x coordinate of the sprite

    yVelocity dw 320            ; to go from one line to another
    xVelocity dw 1              ; horizontal speed


section .text

    _start:

    mov ah, 00h                 ; set video mode requirement
    mov al, 13h                 ; set video mode option to 320 x 200 256 colors
    int 10h                     ; interupt the process
    mov si, pacmanR             ; select the sprite to be displayed

    mainLoop:

    mov al, 0FFh                 ; select the color of the background
    call clearScreen            ; set the backround to the selected color
    mov di, [xPos]              ; set the original coordinate of the sprite
    call drawPacman             ; call the function to display the sprite

    ; This loop is to slow down the animation
    mov cx, 50000               ; 20000 is the time we wait before moving the sprite
    waitloop:                   ; cx is a loop register
    loop waitloop               ; once count = 0 exit the loop

    ; Read keyboard input
    mov ah, 01h                 ; BIOS function to read keyboard input
    int 21h                     ; Call BIOS interrupt
    cmp al, 77                  ; 'd' in ascii is 100
    je collisionR                    ; If 'd' is pressed, jump to label 'collisionR'
    cmp al, 75                  ; 'q' in ascii is 113
    je collisionL                     ; If 'q' is pressed, jump to label 'left'
    cmp al, 72                  ; 'z' in ascii is 122
    je collisisonUp                       ; If 'z' is pressed, jump to label 'up'
    cmp al, 80                  ; 's' in ascii is 115
    je collisionDown                     ; If 's' is pressed, jump to label 'down'
    cmp al, 27                  ; ASCII value of escape key
    je exit                     ; go to the exit function if the comparison return an equal
    
    mov bl, 0xFF                ; move into bl the color we want to clear with
    call clearGhost             ; call clearGhost

    jmp mainLoop

    ;dos box default video mode
    mov ax, 03h                 ; set into video mode
    int 21h                     ; call DOS interupt

    int 20h                     ; quit 

    ; procedures:

    clearScreen:
    ; Clear the screen
    mov ah, 06h                 ; BIOS function to clear screen
    mov al, 0                   ; Clear entire screen
    mov bh, 07h                 ; Attribute
    mov cx, 0                   ; Upper left corner
    mov dx, 184fh               ; Lower right corner  
    int 10h                     ; Call BIOS interrupt

    clearGhost:
    mov di, [xPos]              ; input the position of the sprite
    push bx                     
    mov bx, 0xA000              ; set the video memory segment to 0xA000
    mov es, bx
    pop bx
    mov dx, 16                   ; set the destination index to 1§
    .eachLine:      
        mov cx, 16              ; set the count register to 16 (number of pixel to copy per line)
        rep stosb               ; repeat the move byte action (copying pixel)
        add di, 320-16          ; move the destination index to the next line (320 pixel per line)
        dec dx                  ; decrement the loop counter (dx)
        jnz .eachLine           ; jump to .eachline if not zero
    ret                         ; return to the caller


    ; si must have the sprite address
    ; di must have the target address
    drawPacman:
    mov bx, 0xA000              ; memory location of the video mode
    mov es, bx
    mov dx, 16                   ; set the destination index to 16 (starting position in video memory)
    .eachLine:                  ; loop till each line of the sprite is printed
        mov cx, 16               ; set the count register to 16 (number of pixel to copy per line)
        rep movsb               ; repeat the move byte action (copying pixel)
        add di, 320-16           ; move the destination index to the next line (320 pixel per line)
        dec dx                  ; decrement the loop counter (dx) and jump to .eachLine if not zero
        jnz .eachLine
        ret                     ; return to the main loop

    right:
    ; Move the sprite to the right
    mov ax, 0C01h               ; reset the keyboard buffer
    int 21h
    cmp word [xVelocity], 0     ; check if velocity is positif
    jl .reverse                 ; if not go to sub procedure .reverse
    mov bx, [xPos]              ; the position is increased by the speed of the character (here 1)
    add bx, [xVelocity]
    mov [xPos], bx              ; update the new position and speed of the character
    mov si, pacmanR
    call drawPacman
    jmp mainLoop                ; return to the main loop
    .reverse:
        neg word [xVelocity]    ; reverse the value of velocity to 1
        jmp right               ; return to the procedure right


    left:
    ; Move the sprite to the left
    mov ax, 0C01h               ; reset the keyboard buffer
    int 21h
    cmp word [xVelocity], 0     ; check if velocity is negatif
    jg .reverse                 ; if not go to sub procedure .reverse
    mov bx, [xPos]              ; the position is increased by the speed of the character (here -1)
    add bx, [xVelocity]
    mov [xPos], bx              ; update the new position and speed of the character
    mov si, pacmanR
    call drawPacman
    jmp mainLoop                ; return to the main loop
    .reverse:
        neg word [xVelocity]    ; reverse the value of velocity to -1
        jmp left                ; return to the procedure left 

    up:
    ; Move the sprite upward
    mov ax, 0C01h               ;reset the keyboard buffer
    int 21h
    cmp word [yVelocity], 0     ; check the value of velocity
    jg .reverse                 ; if the value is positive go to sub procedure .reverse
    mov bx, [xPos]              ; the position is increased by the speed of the sprite to go to the next line (here 320)
    add bx, [yVelocity]
    mov [xPos], bx              ; update the position and speed of the sprite
    mov si, pacmanDown
    call drawPacman
    jmp mainLoop                ; return to the main loop
    .reverse:
        neg word [yVelocity]    ; negate the value of velocity to -320
        jmp up                  ; return to the procedure up

    down:
    ; Move the sprite down
    mov ax, 0C01h               ; reset the keyboard buffer
    int 21h
    cmp word [yVelocity], 0     ; check the value of velocity
    jl .reverse                 ; if the value is negative go to sub procedure .reverse
    mov bx, [xPos]              ; the position is increased by the speed of the sprite to go to the next line (here -320)
    add bx, [yVelocity]
    mov [xPos], bx              ; update the position and speed of the sprite
    mov si, pacmanUp
    call drawPacman
    jmp mainLoop                ; return to the main loop
    .reverse:
        neg word [yVelocity]    ; negate the value of velocity to +320
        jmp down                ; return to the procedure down

    collisionR:
    mov cl, [xPos]              ; put the position in the "checker"
    inc cl                      ; increase the position to simulate going to the right
    cmp cl, '#'                 ; check if there is a wall at this position
    je mainLoop                 ; if yes go back to the main loop
    jmp right                   ; if no go to the 'right' procedure

    collisionL:
    mov cl, [xPos]              ; put the position in the "checker"
    dec cl                      ; decrease the position to simulate going to the left
    cmp cl, '#'                 ; check if there is a wall at this position
    je mainLoop                 ; if yes go back to the main loop
    jmp left                    ; if no go to the 'left' procedure

    collisisonUp:
    mov cl, [xPos]              ; put the position in the "checker"
    sub cl, [yVelocity]         ; decresease the position to simulate going up 
    cmp cl, '#'                 ; check if there is a wall at this position
    je mainLoop                 ; if yes go back to the main loop
    jmp up                      ; if no go to the 'up' procedure

    collisionDown:
    mov cl, [xPos]              ; put the position in the "checker"
    add cl, [yVelocity]         ; increase the position to simulate going down
    cmp cl, '#'                 ; check if there is a wall at this position
    je mainLoop                 ; if yes go back to the main loop
    jmp down                    ; if no go to the 'down' procedure

    exit:                       ; If escape key is pressed, jump to label 'exit'
    mov ah, 4ch                 ; DOS function to exit program
    int 21h                     ; Call DOS interrupt