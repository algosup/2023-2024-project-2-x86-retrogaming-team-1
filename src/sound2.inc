section .data
    melody db 0, 2, 4, 5, 7, 9, 11, 12 ; Séquence de notes

    clock dw 0
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
        global movMelody

movMelody:
    add word [time], 1
    cmp word [time], 120
    jne .skipChangeNote
    mov word [time], 0
    mov bx, [tour]

    cmp bx, 0
    je Gg_note            ; Jump to Gg_note if bx is 0
    cmp bx, 1
    je C_note             ; Jump to C_note if bx is 1
    cmp bx, 2
    je D_note             ; Jump to D_note if bx is 2
    cmp bx, 3
    je E_note             ; Jump to E_note if bx is 3
    cmp bx, 4
    je Gg_note            ; Jump to Gg_note if bx is 4

.skipChangeNote:
    call play_note
    ret

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
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

C#g_note:
    mov ax, [C#g]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Dg_note:
    mov ax, [Dg]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

D#g_note:
    mov ax, [D#g]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Eg_note:
    mov ax, [Eg]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Fg_note:
    mov ax, [Fg]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

F#g_note:
    mov ax, [F#g]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Gg_note:
    mov ax, [Gg]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

G#g_note:
    mov ax, [G#g]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Ag_note:
    mov ax, [Ag]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

A#g_note:
    mov ax, [A#g]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Bg_note:
    mov ax, [Bg]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

C_note:
    mov ax, [C]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

C#_note:
    mov ax, [C#]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

D_note:
    mov ax, [D]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

D#_note:
    mov ax, [D#]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

E_note:
    mov ax, [E]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

F_note:
    mov ax, [F]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

F#_note:
    mov ax, [F#]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

G_note:
    mov ax, [G]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

G#_note:
    mov ax, [G#]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

A_note:
    mov ax, [A]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

A#_note:
    mov ax, [A#]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

B_note:
    mov ax, [B]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Ca_note:
    mov ax, [Ca]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

C#a_note:
    mov ax, [C#a]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Da_note:
    mov ax, [Da]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

D#a_note:
    mov ax, [D#a]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Ea_note:
    mov ax, [Ea]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Fa_note:
    mov ax, [Fa]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

F#a_note:
    mov ax, [F#a]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Ga_note:
    mov ax, [Ga]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

G#a_note:
    mov ax, [G#a]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Aa_note:
    mov ax, [Aa]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

A#a_note:
    mov ax, [A#a]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

Ba_note:
    mov ax, [Ba]
    mov [frequence], ax
    int 21h                   ; Appel de l'interruption 21h
    ret

play_note:
    mov al, 182             ; Prepare the speaker for the note.
    out 43h, al             ; Send the value to port 43h.
    mov ax, [frequence]
    out 42h, al             ; Output low byte.
    mov al, ah              ; Output high byte.
    out 42h, al 
    in al, 61h
    or al, 00000011b        ; Set bits 1 and 0.
    out 61h, al             ; Send new value.

    ; Stop sound by resetting bit 0 to 0.
;    in al, 61h
;    and al, 11111110b
;    out 61h, al

    ret 

section .bss
    time resw 1               ; Variable pour compter le temps
    tour resw 1               ; Variable pour stocker le tour
    message_gg db 'Playing Gg note', 0  ; Message à afficher
