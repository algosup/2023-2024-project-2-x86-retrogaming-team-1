; =============================================================================
;
;   8086 Timer API:
;
; =============================================================================
%ifndef SYS_TIMER
%define SYS_TIMER
%define TIMER_CALIBRATION_DURATION_SECONDS 4
; -----------------------------------------------
; Stop watch data.
struc StopWatch
    .startStamp resd 1
    .endStamp resd 1
    .elapsedSeconds resd 1  ; Fixed point 32:16
endstruc
section .bss
    timerSecondPerTick resd 1
section .data
    timerCalibratingMsg db ` * Calibrating timer...\r\n` ,0
    timerCalibratedMsg db ` * Timer calibrated.\r\n` ,0
section .text
; -----------------------------------------------
; si = pointer to StopWatch record
timerStartStopWatch:
    call timerGetSystemTimer
    mov [si + StopWatch.startStamp] ,eax
    ret
; -----------------------------------------------
; si = pointer to StopWatch record
;   .endStamp and .elapsedSeconds are updated.
;   eax = elapsedSeconds
timerElapsedStopWatch:
    call timerGetSystemTimer
    mov [si + StopWatch.endStamp] ,ax
    sub ax ,[si + StopWatch.startStamp]
    mov bx ,[timerSecondPerTick]
    mul bx
    mov [si + StopWatch.elapsedSeconds] ,ax
    ret
; -----------------------------------------------
; Returns:
;   eax = system timer value.
timerGetSystemTimer:
    xor ah ,ah  ; Read system timer
    int 1ah
    mov ax ,cx
    shl eax ,16
    mov ax ,dx
    ret
; -----------------------------------------------
timerCalibrate:
    mov si ,timerCalibratingMsg
    call printAsciiZ
    ; Wait for second change:
    mov ah ,02h
    int 1ah
    mov bl ,dh      ; Keep second.
.waitForNextSecond:
    mov ah ,02h
    int 1ah
    cmp bl ,dh      ; Compare second.
    je .waitForNextSecond
    mov bl ,dh      ; Keep base second.
    ; Get timestamp:
    call timerGetSystemTimer
    push eax
    ; Wait for calibration delay:
    mov al ,bl
    add al ,TIMER_CALIBRATION_DURATION_SECONDS
    daa             ; BCD adjust.
;.wrapSeconds:
    cmp al ,60h     ; Compare with 60 seconds (Warning: BCD !!)
    jb .loadCalibrationSeconds
    int3
    sub al ,60h     ; Wrapped around.
    das             ; BCD adjust.
.loadCalibrationSeconds:
    mov bl ,al
.waitForCalibrationSecond:
    mov ah ,02h
    int 1ah
    cmp bl ,dh      ; Compare second.
    jne .waitForCalibrationSecond
    ; Get final timestamp:
    call timerGetSystemTimer
    pop ebx
    sub eax ,ebx        ; eax = delta timer.
    mov ebx ,(TIMER_CALIBRATION_DURATION_SECONDS << 16)     ; ebx => duration in seconds encoded as fp 32:16
    xchg eax ,ebx
    xor edx ,edx
    div ebx             ; eax = number of "seconds" per tick.
    mov [timerSecondPerTick] ,eax
    mov si ,timerCalibratedMsg
    call printAsciiZ
    ret

; -----------------------------------------------
;   ds:si = Source string.
printAsciiZ:
    lodsb
    cmp al ,0
    jz .endPrint
    mov dl ,al
    mov ax ,0600h
    int 21h
    jmp printAsciiZ
.endPrint:
    ret

; -----------------------------------------------
; eax = tick count.
; Returns:
;   eax = seconds (fp 32:16)
timerToSeconds:
    mov ebx ,[timerSecondPerTick]
    mul ebx
    ret
%endif
