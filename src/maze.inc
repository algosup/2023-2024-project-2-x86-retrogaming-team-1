section .data

    windowWidth equ 320
    windowHeight equ 200
    mazeHeight equ 24
    nb_tile equ 0

    wall:       db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00
                db 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00
                db 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00
                db 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00
                db 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00
                db 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
       

    path:       db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
section .text

drawMaze:
    mov si, maze                            ; select the sprite of the maze
    mov cl, 0b1000_0000                     ; set the comparator as cl 
    dec si
    mov al, [si]                            ; set al as the current byte of the si's array

    mov di, 0;windowWidth*mazeHeight          ; set the start of the maze
    xor bx, bx                              ; set bx to 0

; loop until the maze is drawn  
    loopDraw: 
        cmp byte [nb_tile], 8               
        jae resetComp

        cmp di, windowWidth*windowHeight-8
        jae _start.return

; check wether or not a byte is set (1)
        test al, cl                  
        jnz .drawTile                       ; if set (1) means its a wall             
        jmp .drawPath                       ; if not set (0) means its a path

        .drawTile:
            push si                         ; push si, cx and ax to reuse them later on
            push cx
            push ax
            mov si, wall                    ; select the sprite of the wall
            jmp createTile
        .drawPath:
            push si                         ; push si, cx and ax to reuse them later on
            push cx
            push ax
            mov si, path                    ; select the sprite of the path 
            jmp createTile

createTile:

    call draw_tile                          ; draw the sprite 

    pop ax                                  ; pop si, cx and ax /!\ the order
    pop cx
    pop si

    shr cl, 1                               ; shift to the right by 1

    sub di, windowWidth*8                   ; after drawing a tile, go back to the previous line 
    add di, 8                               ; add the width of a tile
    add bx, 8
    add byte [nb_tile], 1                   ; increase the counter by one 
    cmp bx, 224                     ; compare to the window width 
    jb loopDraw                             ; if not finished loop
    add di, windowWidth*7                   ; go to the next row 
    xor bx, bx
    jmp loopDraw

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