; TODO
; start of a map
; fix character printing
org 100h    

section .bss

    backBufferSeg resw 1

section .text

    _start:
    
    call timerStartStopWatch
    call heapInit
    mov ax, 1000h
    call heapAllocParagraph
    mov [backBufferSeg], ax

    mov ah, 00h                 ; set video mode requirement
    mov al, 013h                ; set Video Mode 4F02h (VBE mode 101h) - 640x480, 256 colors
    int 10h                     ; interupt the process

    mov di, [xPos]              ; set the original coordinate of the sprite
    mov si, pacmanR_00          ; select the sprite to be displayed
    call drawPacman             ; display the selected sprite
    call backBuffer

    mainLoop:

    ;mov al, 0FFh                ; select the color of the background
    call clearScreen            ; set the backround to the selected color
    mov di, [xPos]              ; set the original coordinate of the sprite
    mov di, [xPos]              ; set the original coordinate of the sprite
    
    mov di, [xPos]              ; set the original coordinate of the sprite    
    
    call readKeyb

    ; This loop is to slow down the animation
    mov cx, 50000               ; 50000 is the time we wait before moving the sprite
    waitloop:                   ; cx is a loop register
    loop waitloop               ; once count = 0 exit the loop
    
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
    mov bh, 00h                 ; Attribute
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

    backBuffer:
    push ds
    push es
    mov ax, [cs:backBufferSeg]
    mov ds, ax
    mov ax, 0A000h
    mov es, ax
    xor si, si
    xor di, di
    mov cx, 320*200
    rep movsb
    pop es
    pop ds
    ret

    
    exit:                       ; If escape key is pressed, jump to label 'exit'
    mov ah, 4ch                 ; DOS function to exit program
    int 21h                     ; Call DOS interrupt

    %include "sprites.inc"          ; include the file with the sprites
    %include "movement.inc"         ; include the file for the movement
    %include "heapLibrarie.inc"     ; include the heap librarie
    %include "stopwatch.inc"        ; include the stopwatch
    %include "animations.inc"