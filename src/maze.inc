section .data

    windowWidth equ 320
    windowHeight equ 200
    mazeHeight equ 24
    nb_tile equ 0

    wall:       db 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11
                db 0x11, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x11
                db 0x11, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x11
                db 0x11, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x11
                db 0x11, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x11
                db 0x11, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x11
                db 0x11, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x11
                db 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11
       

    path:       db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
section .text

draw_maze:

    call musicStart                         ; start a little musical theme

    mov si, maze                            ; set the sprite of the maze
    mov cl, 0b1000_0000                     ; set the counter
    dec si                                  ; decrease the sprite (idk why but it works)
    mov al, [si]                            ; set al as an comparison tool

    mov di, 0                               ; set the position
    xor bx, bx                              ; make sure bx is reset

    ; loop until the maze is drawn  
    loopDraw: 
        cmp byte [nb_tile], 8               
        jae resetComp

        cmp di, windowWidth*windowHeight-8  ; when finished draw the ghosts
        jae drawGhosts                      ; in ghosts.inc

; check wether or not a byte is set (1)
        test al, cl                  
        jnz .drawTile                       ; if set (1) means its a wall             
        jmp .drawPath                       ; if not set (0) means its a path

        .drawTile:
            push si                         ; push si, cx and ax to reuse them later on
            push ax
            push cx
            mov si, wall                    ; select the sprite of the wall
            jmp createTile
        .drawPath:
            push si                         ; push si, cx and ax to reuse them later on
            push ax
            push cx
            mov si, path                    ; select the sprite of the path 
            jmp createTile

createTile:

    call draw_tile                          ; draw the sprite 

    pop cx                                  ; pop si, cx and ax /!\ the order
    pop ax
    pop si

    shr cl, 1                               ; shift to the right by 1

    sub di, windowWidth*8                   ; after drawing a tile, go back to the previous line 
    add di, 8                               ; add the width of a tile
    add bx, 8
    add byte [nb_tile], 1                   ; increase the counter by one 
    cmp bx, windowWidth                             ; compare to the window width 
    jb loopDraw                             ; if not finished loop
    add di, windowWidth*7                   ; go to the next row 
    xor bx, bx

    cmp cl, 0                               ; if cl is equal to 0 reset si
    je resetComp

;reseting cl means the current byte is finished 
resetComp:
    mov byte [nb_tile], 0                   ; reset the counter        
    mov cl, 0b1000_0000                     ; reset cl 
    inc si                                  ; increase si to get to the next byte in maze
    mov al, [si]                            ; move the current byte to al

    jmp loopDraw

;draw in 8x8
draw_tile:
    mov ax, 0xA000
    mov es, ax
    mov dx, 8
        .eachLine:
            mov cx, 8
            rep movsb
            add di, windowWidth-8
            dec dx
            jnz .eachLine
    ret
