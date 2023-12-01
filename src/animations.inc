animationLoop:
    call timerElapsedStopWatch  ; this will tell the time elapsed ince the start of the program
    cmp eax, ecx                ; compare the old time to the new one
    jg .nextFrame
    mov ecx, eax                ; save the old time 

    ; identify the current frame
    .nextFrame:
        cmp si, pacmanR_00
        je fn1
        cmp si, pacmanR_01
        je fn2
        cmp si, pacmanR_02
        je fn3
        cmp si, pacmanL_00
        je fn4
        cmp si, pacmanL_01
        je fn5
        cmp si, pacmanL_02
        je fn6
        cmp si, pacmanUp_00
        je fn7
        cmp si, pacmanUp_01
        je fn8
        cmp si, pacmanUp_02
        je fn9
        cmp si, pacmanDown_00
        je fn10
        cmp si, pacmanDown_01
        je fn11
        cmp si, pacmanDown_02
        je fn12
    
    ret

;---------------------------------
;   fn land
; move into si the new sprite to be displayed
; display that sprite
; go back into the loop
fn1:
    mov si, pacmanR_01
    call drawPacman
    jmp animationLoop
fn2:
    mov si, pacmanR_02
    call drawPacman
    jmp animationLoop
fn3:
    mov si, pacmanR_00
    call drawPacman
    jmp animationLoop
fn4:
    mov si, pacmanL_01
    call drawPacman
    jmp animationLoop
fn5:
    mov si, pacmanL_02
    call drawPacman
    jmp animationLoop
fn6:
    mov si, pacmanL_00
    call drawPacman
    jmp animationLoop
fn7:
    mov si, pacmanUp_01
    call drawPacman
    jmp animationLoop
fn8:
    mov si, pacmanUp_02
    call drawPacman
    jmp animationLoop
fn9:
    mov si, pacmanUp_00
    call drawPacman
    jmp animationLoop
fn10:
    mov si, pacmanDown_01
    call drawPacman
    jmp animationLoop
fn11:
    mov si, pacmanDown_02
    call drawPacman
    jmp animationLoop
fn12:
    mov si, pacmanDown_00
    call drawPacman
    jmp animationLoop