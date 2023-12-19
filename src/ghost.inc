section .data
; the starting position of the ghosts 
redStartingPos dw windowWidth*145+(windowWidth-12)/2

orangeStartingPos dw windowWidth*120+(windowWidth-46)/2
pinkStartingPos dw windowWidth*120+(windowWidth-14)/2
cyanStartingPos dw windowWidth*120+(windowWidth+18)/2

section .text

; select each ghost then draw it to their starting position
drawGhosts:
    mov di, [redStartingPos]
    mov si, blinkyL
    call drawSprite

    mov di, [orangeStartingPos]
    mov si, clydeR
    call drawSprite

    mov di, [pinkStartingPos]
    mov si, pinkyDown
    call drawSprite

    mov di, [cyanStartingPos]
    mov si, inkyUp
    call drawSprite

    ; jump to the main loop when finished
    jmp mainLoop