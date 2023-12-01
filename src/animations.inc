section .data

    currentSprite dd pacmanR_00

section .text
    ; identify the current frame
findFrame:
    cmp word [currentSprite], pacmanR_00
    je nf1
    cmp word [currentSprite], pacmanR_01
    je nf2
    cmp word [currentSprite], pacmanR_02
    je nf3
    cmp word [currentSprite], pacmanL_00
    je nf4
    cmp word [currentSprite], pacmanL_01
    je nf5
    cmp word [currentSprite], pacmanL_02
    je nf6
    cmp word [currentSprite], pacmanUp_00
    je nf7
    cmp word [currentSprite], pacmanUp_01
    je nf8
    cmp word [currentSprite], pacmanUp_02
    je nf9
    cmp word [currentSprite], pacmanDown_00
    je nf10
    cmp word [currentSprite], pacmanDown_01
    je nf11
    cmp word [currentSprite], pacmanDown_02
    je nf12
;---------------------------------
;   nf land
; move into si the new sprite to be displayed
; display that sprite
; go back into the loop
nf1:
    mov word [currentSprite], pacmanR_01
    mov si, [currentSprite]
    call drawPacman
    ret
nf2:
    mov word [currentSprite], pacmanR_02
    mov si, [currentSprite]
    call drawPacman
    ret
nf3:
    mov word [currentSprite], pacmanR_00
    mov si, [currentSprite]
    call drawPacman
    ret
nf4:
    mov word [currentSprite], pacmanL_01
    mov si, [currentSprite]
    call drawPacman
    ret
nf5:
    mov word [currentSprite], pacmanL_02
    mov si, [currentSprite]
    call drawPacman
    ret
nf6:
    mov word [currentSprite], pacmanL_00
    mov si, [currentSprite]
    call drawPacman
    ret
nf7:
    mov word [currentSprite], pacmanUp_01
    mov si, [currentSprite]
    call drawPacman
    ret
nf8:
    mov word [currentSprite], pacmanUp_02
    mov si, [currentSprite]
    call drawPacman
    ret
nf9:
    mov word [currentSprite], pacmanUp_00
    mov si, [currentSprite]
    call drawPacman
    ret
nf10:
    mov word [currentSprite], pacmanDown_01
    mov si,[currentSprite]
    call drawPacman
    ret
nf11:
    mov word [currentSprite], pacmanDown_02
    mov si,[currentSprite]
    call drawPacman
    ret
nf12:
    mov word [currentSprite], pacmanDown_00
    mov si, [currentSprite]
    call drawPacman
    ret