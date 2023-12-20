org 100h    

section .bss

    backBufferSeg resw 1

section .text

global _start

    _start:
    
    call heapInit
    mov ax, 1000h
    call heapAllocParagraph
    mov [backBufferSeg], ax

    mov ah, 00h                 ; set video mode requirement
    mov al, 013h                ; set Video Mode 4F02h (VBE mode 101h) - 640x480, 256 colors
    int 10h

    mov di, 0                   ; set the starting position

    mov ax, 0xA000              
    mov es, ax
    call draw_maze              ; in maze.inc
    
    mov si, pacmanR_02
    mov di, [startPos]          ; set the original coordinate of the sprite
    call drawSprite             ; main.asm

    mainLoop:

    mov di, [xPos]              ; set the original coordinate of the sprite    

    call readKeyb               ; in keyboard_handler

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

    clearPacman:
    mov di, [xPos]              ; input the position of the sprite
    push ax
    mov ax, 0xA000              ; set the video memory segment to 0xA000
    mov es, ax
    pop ax
    mov dx, 16                  ; set the destination index to 16
    .eachLine:
        mov cx, 16              ; set the count register to 16 (number of pixel to copy per line)
        rep stosb               ; repeat the move byte action (copying pixel)
        add di, 320-16          ; move the destination index to the next line (320 pixel per line)
        dec dx                  ; decrement the loop counter (dx)
        jnz .eachLine           ; jump to .eachline if not zero
    ret                         ; return to the caller

    ; si must have the sprite address
    ; di must have the target address
    drawSprite:
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

    presentBackBuffer:
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

    %include "sprites.inc"          ; include the file with the sprites
    %include "movement.inc"         ; include the file for the movement
    %include "heapLibrarie.inc"     ; include the heap librarie
    %include "maze.inc"             ; include the map drawing
    %include "maze_sprite.inc"      ; include the sprite of the maze
    %include "keyboard_handler.inc" ; include the generation of the maze
    %include "ghost.inc"            ; include the ghost
    %include "sound.inc"            ; include the souns library
    %include "colorChecker.inc"     ; include the color checker for the collisions
    %include "lives.inc"            ; include the lives system and the game over screen
