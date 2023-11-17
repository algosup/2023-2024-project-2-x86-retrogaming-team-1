; TODO:
; fix left procedure, look into clearScreen and drawPacman for the error
; implement up and down procedure
; finish commenting clearScreen and drawPacman
; create a bin folder
; create a bash file to put the .com file into 
; create a .cmd file to launch DosBox with the good config + mount 

org 100h

section .data

    xPos dw 0                   ; the starting x coordinate of the character
    yPos dw 0                   ; the starting y coordinate of the character      

    velocity dw 1               ; the speed of the character
       
    spriteW dw 8                ; the width of the sprite

section .text

    _start

    mov ah, 00h                 ; set video mode requirement
    mov al, 13h                 ; set video mode option to 320 x 200 256 colors
    int 10h                     ; interupt the process

    mov al, 0FFh                ; select the color of the background
    call clearScreen            ; set the backround to the selected color

    ; Display the sprite:
    ;mov si, pacman             ; select the sprite to be displayed
    mov di, [xPos, yPos]        ; set the original coordinate of the character
    call drawPacman             ; call the function to display the character


    mainLoop:
    ; This loop is to slow down the animation
    mov cx, 20000               ; 20000 is the time we wait before moving the sprite
    waitloop:                   ; cx is a loop register
    loop waitloop               ; once count = 0 exit the loop

    ; Read keyboard input
    mov ah, 01h                 ; BIOS function to read keyboard input
    int 21h                     ; Call BIOS interrupt
    cmp al, 100                 ; 'd' in ascii is 100
    je right                    ; If 'd' is pressed, jump to label 'right'
    cmp al, 113                 ; 'q' in ascii is 113
    je left                     ; If 'q' is pressed, jump to label 'left'
    cmp al, 122                 ; 'z' in ascii is 122
    je up                       ; If 'z' is pressed, jump to label 'up'
    cmp al, 115                 ; 's' in ascii is 115
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
    mov ax, 0xA000              ; memory location of the video mode
    mov es, ax
    mov di, 0
    mov cx, 200*320             ; loop trougth the screen 
    rep stosb                   ; repeat till its done
    ret                         ; return to the main loop

    ; si must have the sprite address
    ; di must have the target address
    drawPacman:
    mov ax, 0xA000              ; memory location of the video mode
    mov es, ax
    mov dx, 8                   ; insert the width of the sprite
    .eachLine:                  ; loop till each line of the sprite is printed
        mov cx, 8
        rep movsb               ; repeat while whats inside al equal whats inside dx
        add di, 320-8
        dec dx
        jnz .eachLine
        ret                     ; return to the main loop

    right:
    ; Move the sprite to the right
    mov bx, [xPos]              ; the position (xPos) is inserted into the register bx
    add bx, [velocity]         ; add to the position the speed (velocity)
    mov [xPos], bx              ; update the position of the character 
    jmp mainLoop                ; return to the main loop

    left:
    ; Move the sprite to the left
    mov bx, [xPos]              ; the position is inserted to the register bx 
    neg word [velocity]        ; reverse the speed (velocity) from 1 to -1
    add bx, [velocity]         ; add it to the position
    mov [xPos], bx              ; update the position of the character
    jmp mainLoop                ; return to the main loop

    up:

    down:

    exit:                       ; If escape key is pressed, jump to label 'exit'
    mov ah, 4ch                 ; DOS function to exit program
    int 21h                     ; Call DOS interrupt