; TODO:
; loop left until we detect a keypress then act i.e. go left for 'q' up for 'z' or the main menu for 'esc'
; do the same for the other direction

org 100h    

section .data

    xPos dw 0                   ; the starting x coordinate of the sprite

    yVelocity dw 320            ; to go from one line to another
    xVelocity dw 1              ; horizontal speed

    ;sprite db '@'               ; place holder for the sprite

section .text

    _start:

    mov ah, 00h                 ; set video mode requirement
    mov al, 13h                 ; set video mode option to 320 x 200 256 colors
    int 10h                     ; interupt the process


    mainLoop:

    mov al, 0FFh                ; select the color of the background
    call clearScreen            ; set the backround to the selected color

    ; Display the sprite:
    ;mov si, sprite              ; select the sprite to be displayed
    mov di, [xPos]              ; set the original coordinate of the sprite
    call drawPacman             ; call the function to display the sprite

    ; This loop is to slow down the animation
    mov cx, 50000               ; 20000 is the time we wait before moving the sprite
    waitloop:                   ; cx is a loop register
    loop waitloop               ; once count = 0 exit the loop

    ; Read keyboard input
    mov ah, 01h                 ; BIOS function to read keyboard input
    int 21h                     ; Call BIOS interrupt
    cmp al, 77                ; 'd' in ascii is 100
    je right                    ; If 'd' is pressed, jump to label 'right'
    cmp al, 75                 ; 'q' in ascii is 113
    je left                     ; If 'q' is pressed, jump to label 'left'
    cmp al, 72                ; 'z' in ascii is 122
    je up                       ; If 'z' is pressed, jump to label 'up'
    cmp al, 80                 ; 's' in ascii is 115
    je down                     ; If 's' is pressed, jump to label 'down'

    ; Exit the program if the escape key is pressed
    cmp al, 27                  ; ASCII value of escape key
    je exit                     ; go to the exit function if the comparison return an equal
    jmp mainLoop                ; else return to the main loop

    jmp mainLoop

    ;dos box default video mode
    mov ax, 03h                 ; set into video mode
    int 21h                     ; call DOS interupt

    int 20h                     ; quit 

    ; procedures:

    ; need to set the color of filling in al
    clearScreen:
    mov ax, 0xA000              ; set the video memory segment to 0xA000
    mov es, ax                  
    mov di, 0                   ; set the destination index to 0 (starting position in video memory)
    mov cx, 200*320             ; set the count register to the total number of pixel on the screen
    rep stosb                   ; repeat the store byte operation (set byte to a specific color)
    ret                         ; return to the main function

    ; si must have the sprite address
    ; di must have the target address
    drawPacman:
    mov ax, 0xA000              ; memory location of the video mode
    mov es, ax
    mov dx, 8                   ; set the destination index to 8 (starting position in video memory)
    .eachLine:                  ; loop till each line of the sprite is printed
        mov cx, 8               ; setthe count register to 8 (number of pixel to copy per line)
        rep movsb               ; repeat the move byte action (copying pixel)
        add di, 320-8           ; move the destination index to the next line (320 pixel per line)
        dec dx                  ; decrement the loop counter (dx) and jump to .eachLine if not zero
        jnz .eachLine
        ret                     ; return to the main loop

right:
    ; Move the sprite to the right
    cmp word [xVelocity], 0     ; check if velocity is positif
    jl .reverse                 ; if not go to sub procedure .reverse
    mov bx, [xPos]              ; the position is increased by the speed of the character (here 1)
    add bx, [xVelocity]
    mov [xPos], bx              ; update the new position and speed of the character
    jmp mainLoop                ; return to the main loop
    .reverse:
        neg word [xVelocity]    ; reverse the value of velocity to 1
        jmp right               ; return to the procedure right


    left:
    ; Move the sprite to the left
    cmp word [xVelocity], 0     ; check if velocity is negatif
    jg .reverse                 ; if not go to sub procedure .reverse
    mov bx, [xPos]              ; the position is increased by the speed of the character (here -1)
    add bx, [xVelocity]
    mov [xPos], bx              ; update the new position and speed of the character
    jmp mainLoop                ; return to the main loop
    .reverse:
        neg word [xVelocity]    ; reverse the value of velocity to -1
        jmp left                ; return to the procedure left 

    up:
    ; Move the sprite upward
    cmp word [yVelocity], 0     ; check the value of velocity
    jg .reverse                 ; if the value is positive go to sub procedure .reverse
    mov bx, [xPos]              ; the position is increased by the speed of the sprite to go to the next line (here 320)
    add bx, [yVelocity]
    mov [xPos], bx              ; update the position and speed of the sprite
    jmp mainLoop                ; return to the main loop
    .reverse:
        neg word [yVelocity]    ; negate the value of velocity to -320
        jmp up                  ; return to the procedure up

    down:
    ; Move the sprite down
    cmp word [yVelocity], 0     ; check the value of velocity
    jl .reverse                 ; if the value is negative go to sub procedure .reverse
    mov bx, [xPos]              ; the position is increased by the speed of the sprite to go to the next line (here -320)
    add bx, [yVelocity]
    mov [xPos], bx              ; update the position and speed of the sprite 
    jmp mainLoop                ; return to the main loop
    .reverse:
        neg word [yVelocity]    ; negate the value of velocity to +320
        jmp down                ; return to the procedure down

    exit:                       ; If escape key is pressed, jump to label 'exit'
    mov ah, 4ch                 ; DOS function to exit program
    int 21h                     ; Call DOS interrupt