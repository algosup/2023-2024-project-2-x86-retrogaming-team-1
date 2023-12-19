section .data
    clock dw 0
    time dw 119
    tour dw 0
    frequence dw 0

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

Cg_note:
    mov ax, [Cg]
    mov [frequence], ax
    call play_note
    ret

C#g_note:
    mov ax, [C#g]
    mov [frequence], ax
    call play_note
    ret

Dg_note:
    mov ax, [Dg]
    mov [frequence], ax
    call play_note
    ret

D#g_note:
    mov ax, [D#g]
    mov [frequence], ax
    call play_note
    ret

Eg_note:
    mov ax, [Eg]
    mov [frequence], ax
    call play_note
    ret

Fg_note:
    mov ax, [Fg]
    mov [frequence], ax
    call play_note
    ret

F#g_note:
    mov ax, [F#g]
    mov [frequence], ax
    call play_note
    ret

Gg_note:
    mov ax, [Gg]
    mov [frequence], ax
    call play_note
    ret

G#g_note:
    mov ax, [G#g]
    mov [frequence], ax
    call play_note
    ret

Ag_note:
    mov ax, [Ag]
    mov [frequence], ax
    call play_note
    ret

A#g_note:
    mov ax, [A#g]
    mov [frequence], ax
    call play_note
    ret

Bg_note:
    mov ax, [Bg]
    mov [frequence], ax
    call play_note
    ret

C_note:
    mov ax, [C]
    mov [frequence], ax
    call play_note
    ret

C#_note:
    mov ax, [C#]
    mov [frequence], ax
    call play_note
    ret

D_note:
    mov ax, [D]
    mov [frequence], ax
    call play_note
    ret

D#_note:
    mov ax, [D#]
    mov [frequence], ax
    call play_note
    ret

E_note:
    mov ax, [E]
    mov [frequence], ax
    call play_note
    ret

F_note:
    mov ax, [F]
    mov [frequence], ax
    call play_note
    ret

F#_note:
    mov ax, [F#]
    mov [frequence], ax
    call play_note
    ret

G_note:
    mov ax, [G]
    mov [frequence], ax
    call play_note
    ret

G#_note:
    mov ax, [G#]
    mov [frequence], ax
    call play_note
    ret

A_note:
    mov ax, [A]
    mov [frequence], ax
    call play_note
    ret

A#_note:
    mov ax, [A#]
    mov [frequence], ax
    call play_note
    ret

B_note:
    mov ax, [B]
    mov [frequence], ax
    call play_note
    ret

Ca_note:
    mov ax, [Ca]
    mov [frequence], ax
    call play_note
    ret

C#a_note:
    mov ax, [C#a]
    mov [frequence], ax
    call play_note
    ret

Da_note:
    mov ax, [Da]
    mov [frequence], ax
    call play_note
    ret

D#a_note:
    mov ax, [D#a]
    mov [frequence], ax
    call play_note
    ret

Ea_note:
    mov ax, [Ea]
    mov [frequence], ax
    call play_note
    ret

Fa_note:
    mov ax, [Fa]
    mov [frequence], ax
    call play_note
    ret

F#a_note:
    mov ax, [F#a]
    mov [frequence], ax
    call play_note
    ret

Ga_note:
    mov ax, [Ga]
    mov [frequence], ax
    call play_note
    ret

G#a_note:
    mov ax, [G#a]
    mov [frequence], ax
    call play_note
    ret

Aa_note:
    mov ax, [Aa]
    mov [frequence], ax
    call play_note
    ret

A#a_note:
    mov ax, [A#a]
    mov [frequence], ax
    call play_note
    ret

Ba_note:
    mov ax, [Ba]
    mov [frequence], ax
    call play_note
    ret

play_note:
    mov al, 3               ; Prepare the speaker for the note.
    out 80h, al             ; Send the value to port 80h.
    mov ax, [frequence]
    out 42h, al             ; Output low byte.
    mov al, ah              ; Output high byte.
    out 42h, al 
    in al, 61h
    or al, 00000011b        ; Set bits 1 and 0.
    out 61h, al             ; Send new value.

    call extendNote
    inc bx
    ret 

extendNote:
    push bx
    mov cx, 9121
    mov bx, 10
    .pause1:
        mov cx, 2500
    .pause2:
        dec cx
        jne .pause2
        dec bx
        jne .pause1

        in  al, 0x61
        and al, 11111100b
        out 0x61, al

    pop bx
    ret

musicStart:
    call B_note
    call B_note
    call Ba_note
    call Ba_note
    call F#a_note
    call F#a_note
    call D#a_note
    call D#a_note

    call Ba_note
    call Ba_note
    call Fa_note
    call Fa_note
    call Ea_note
    call Ea_note
    call Ea_note
    call Ea_note

    call B_note
    call B_note
    call Ba_note
    call Ba_note
    call F#a_note
    call F#a_note
    call D#a_note
    call D#a_note

    call Ba_note
    call Ba_note
    call Fa_note
    call Fa_note
    call Ea_note
    call Ea_note
    call Ea_note
    call Ea_note

    call B_note
    call B_note
    call Ba_note
    call Ba_note
    call F#a_note
    call F#a_note
    call D#a_note
    call D#a_note

    call Ba_note
    call Ba_note
    call Fa_note
    call Fa_note
    call Ea_note
    call Ea_note
    call Ea_note
    call Ea_note

    call Ea_note
    call Fa_note
    call Fa_note
    call Ga_note
    call Aa_note
    call Ba_note
    call Ba_note
    call Ba_note
    ret

movMelody:
    add word [time], 1
    cmp word [time], 120
    jne .skipChangeNote
    mov word [time], 0
    mov bx, [tour]
    cmp bx, 0
    call Gg_note                ; call the sound procedure
    cmp bx, 20
    call C_note
    cmp bx, 40
    call D_note
    cmp bx, 60
    call E_note
    cmp bx, 80
    call Gg_note
    .skipChangeNote:
    call play_note
    ret

;musicLive:
;    call Cg_note
;    call A_note
;    call Dg_note
;    call B_note
;    call Eg_note
;    call Ca_note
;    call Fg_note
;    call Da_note
;    call Ag_note
;    call Ea_note
;    call Bg_note
;    call Fa_note

musicDeath:
    call Ga_note
    call C_note
    call Fa_note
    call Bg_note
    call Ea_note
    call Ag_note
    call Da_note
    call Gg_note
    call Ca_note
    call Fg_note
    call B_note
    call Eg_note
    call extendNote

musicGO:
    call Ea_note
    call Ea_note
    call Fa_note
    call Fa_note
    call Ga_note
    call Ga_note
    call A_note
    call A_note
    call B_note
    call B_note
    call Ca_note
    call Ca_note
    call C_note
    call C_note
    call D_note
    call D_note
    call E_note
    call E_note
    call Dg_note
    call Dg_note
    call Eg_note
    call Eg_note
    call Fg_note
    call Fg_note
