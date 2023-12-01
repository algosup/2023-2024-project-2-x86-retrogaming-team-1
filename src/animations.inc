    ; identify the current frame
findFrame:
    cmp si, pacmanR_00
    je nf1
    cmp si, pacmanR_01
    je nf2
    cmp si, pacmanR_02
    je nf3
    cmp si, pacmanL_00
    je nf4
    cmp si, pacmanL_01
    je nf5
    cmp si, pacmanL_02
    je nf6
    cmp si, pacmanUp_00
    je nf7
    cmp si, pacmanUp_01
    je nf8
    cmp si, pacmanUp_02
    je nf9
    cmp si, pacmanDown_00
    je nf10
    cmp si, pacmanDown_01
    je nf11
    cmp si, pacmanDown_02
    je nf12
;---------------------------------
;   nf land
; move into si the new sprite to be displayed
; display that sprite
; go back into the loop
nf1:
    mov si, pacmanR_01
    call drawPacman
    ret
nf2:
    mov si, pacmanR_02
    call drawPacman
    ret
nf3:
    mov si, pacmanR_00
    call drawPacman
    ret
nf4:
    mov si, pacmanL_01
    call drawPacman
    ret
nf5:
    mov si, pacmanL_02
    call drawPacman
    ret
nf6:
    mov si, pacmanL_00
    call drawPacman
    ret
nf7:
    mov si, pacmanUp_00
    call drawPacman
    ret
nf8:
    mov si, pacmanUp_01
    call drawPacman
    ret
nf9:
    mov si, pacmanUp_02
    call drawPacman
    ret
nf10:
    mov si, pacmanDown_00
    call drawPacman
    ret
nf11:
    mov si, pacmanDown_01
    call drawPacman
    ret
nf12:
    mov si, pacmanDown_02
    call drawPacman
    ret