section .data

    clock dw 0

    Cg dw 9121
    C#g dw 8609
    Dg dw 8126
    D#g dw 7670
    Eg dw 7239
    Fg dw 6833
    F#g dw 6449
    Gg dw 6087
    G#g dw 5746
    Ag dw 5423
    A#g dw 5119
    Bg dw 4831

    C dw 4560
    C# dw 4304
    D dw 4063
    D# dw 3834
    E dw 3619
    F dw 3416
    F# dw 3224
    G dw 3043
    G# dw 2873
    A dw 2711
    A# dw 2559
    B dw 2415

    Ca dw 2280
    C#a dw 2152
    Da dw 2031
    D#a dw 1917
    Ea dw 1809
    Fa dw 1715
    F#a dw 1612
    Ga dw 1521
    G#a dw 1436
    Aa dw 1355
    A#a dw 1292
    Ba dw 1207

section .text

delay:
    push ax ; Save the ax register
    mov ax, 40h
    mov es, ax
    mov ax, [clock]

InitTime:
    cmp ax, [clock]
    mov cx, 2
    je InitTime

    pop ax ; Restore the ax register
    ret ; Return from delay procedure

Cg_note:
    mov ax, [Cg]
    call play_note
    ret

C#g_note:
    mov ax, [C#g]
    call play_note
    ret

Dg_note:
    mov ax, [Dg]
    call play_note
    ret

D#g_note:
    mov ax, [D#g]
    call play_note
    ret

Eg_note:
    mov ax, [Eg]
    call play_note
    ret

Fg_note:
    mov ax, [Fg]
    call play_note
    ret

F#g_note:
    mov ax, [F#g]
    call play_note
    ret

Gg_note:
    mov ax, [Gg]
    call play_note
    ret

G#g_note:
    mov ax, [G#g]
    call play_note
    ret

Ag_note:
    mov ax, [Ag]
    call play_note
    ret

A#g_note:
    mov ax, [A#g]
    call play_note
    ret

Bg_note:
    mov ax, [Bg]
    call play_note
    ret

C_note:
    mov ax, [C]
    call play_note
    ret

C#_note:
    mov ax, [C#]
    call play_note
    ret

D_note:
    mov ax, [D]
    call play_note
    ret

D#_note:
    mov ax, [D#]
    call play_note
    ret

E_note:
    mov ax, [E]
    call play_note
    ret

F_note:
    mov ax, [F]
    call play_note
    ret

F#_note:
    mov ax, [F#]
    call play_note
    ret

G_note:
    mov ax, [G]
    call play_note
    ret

G#_note:
    mov ax, [G#]
    call play_note
    ret

A_note:
    mov ax, [A]
    call play_note
    ret

A#_note:
    mov ax, [A#]
    call play_note
    ret

B_note:
    mov ax, [B]
    call play_note
    ret

Ca_note:
    mov ax, [Ca]
    call play_note
    ret

C#a_note:
    mov ax, [C#a]
    call play_note
    ret

Da_note:
    mov ax, [Da]
    call play_note
    ret

D#a_note:
    mov ax, [D#a]
    call play_note
    ret

Ea_note:
    mov ax, [Ea]
    call play_note
    ret

Fa_note:
    mov ax, [Fa]
    call play_note
    ret

F#a_note:
    mov ax, [F#a]
    call play_note
    ret

Ga_note:
    mov ax, [Ga]
    call play_note
    ret

G#a_note:
    mov ax, [G#a]
    call play_note
    ret

Aa_note:
    mov ax, [Aa]
    call play_note
    ret

A#a_note:
    mov ax, [A#a]
    call play_note
    ret

Ba_note:
    mov ax, [Ba]
    call play_note
    ret

play_note:
    mov al, 182             ; Prepare the speaker for the note.
    out 43h, al             ; Send the value to port 43h.
    out 42h, al             ; Output low byte.
    mov al, ah              ; Output high byte.
    out 42h, al 
    in al, 0x61
    or al, 00000011b        ; Set bits 1 and 0.
    out 61h, al             ; Send new value.

    mov cx, 9121                ; tone for the sound
    mov bx, 100                  ; duration of the sound
    call pause
    
    ret

pause:
    .pause1:
        mov     cx, 1200
    .pause2:
        dec     cx
        jne     .pause2
        dec     bx
        jne     .pause1
        in      al, 61h         ; Turn off note (get value from
                                ;  port 61h).
        and     al, 11111100b   ; Reset bits 1 and 0.
        out     61h, al         ; Send new value.

    ret