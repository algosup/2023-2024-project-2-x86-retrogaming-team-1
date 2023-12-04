; TODO
; fix the mouvement of pacman
; start of a map
; fix character printing

org 100h    

section .bss

    backBufferSeg resw 1

section .text

    _start:
    
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

    mainLoop:

    mov bl, 0xFF                ; move into bl the color we want to clear with
    call clearGhost             ; clear the previous ghost

    mov di, [xPos]              ; set the original coordinate of the sprite    

    call readKeyb               ; call the keyboard reader

    ; This loop is to slow down the animation
    mov cx, 5000                ; 50000 is the time we wait before moving the sprite
    waitloop:                   ; cx is a loop register
    loop waitloop               ; once count = 0 exit the loop
    
    jmp mainLoop                ; loop

    ;dos box default video mode
    mov ax, 03h                 ; set into video mode
    int 21h                     ; call DOS interupt

    int 20h                     ; quit 

    ; procedures:

    clearGhost:
    mov di, [xPos]              ; input the position of the sprite
    push bx                     
    mov bx, 0xA000              ; set the video memory segment to 0xA000
    mov es, bx
    pop bx
    mov dx, 16                  ; set the destination index to 1§
    .eachLine:      
        mov cx, 16              ; set the count register to 16 (number of pixel to copy per line)
        rep movsb               ; repeat the move byte action (copying pixel)
        add di, 320-16          ; move the destination index to the next line (320 pixel per line)
        dec dx                  ; decrement the loop counter (dx)
        jnz .eachLine           ; jump to .eachline if not zero
    ret                         ; return to the caller


    ; si must have the sprite address
    ; di must have the target address
    drawPacman:
    mov ax, 0xA000              ; memory location of the video mode
    mov es, ax
    mov dx, 16                  ; set the destination index to 16 (starting position in video memory)
    .eachLine:                  ; loop till each line of the sprite is printed
        mov cx, 16              ; set the count register to 16 (number of pixel to copy per line)
        rep movsb               ; repeat the move byte action (copying pixel)
        add di, 320-16          ; move the destination index to the next line (320 pixel per line)
        dec dx                  ; decrement the loop counter (dx) and jump to .eachLine if not zero
        jnz .eachLine
        ret                     ; return to the main loop

    exit:                       ; If escape key is pressed, jump to label 'exit'
    mov ah, 4ch
    xor al, al
    int 21h

    %include "sprites.inc"          ; include the file with the sprites
    %include "movement.inc"         ; include the file for the movement
    %include "heapLibrarie.inc"     ; include the heap librarie