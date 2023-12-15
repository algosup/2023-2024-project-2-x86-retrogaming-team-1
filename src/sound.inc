section .data
    clock dw 0
    time dw 119
    tour dw 0
    frequence dw 0

;    %define Cg 9121
;    %define C#g 8609
;    %define Dg 8126
;    %define D#g 7670
;    %define Eg 7239
;    %define Fg 6833
;    %define F#g 6449
;    %define Gg 6087
;    %define G#g 5746
;    %define Ag 5423
;    %define A#g 5119
;    %define Bg 4831

;    %define C 4560
;    %define C# 4304
;    %define D 4063
;    %define D# 3834
;    %define E 3619
;    %define F 3416
;    %define F# 3224
;    %define G 3043
;    %define G# 2873
;    %define A 2711
;    %define A# 2559
;    %define B 2415

;    %define Ca 2280
;    %define C#a 2152
;    %define Da 2031
;    %define D#a 1917
;    %define Ea 1809
;    %define Fa 1715
;    %define F#a 1612
;    %define Ga 1521
;    %define G#a 1436
;    %define Aa 1355
;    %define A#a 1292
;    %define Ba 1207

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
    ret

C#g_note:
    mov ax, [C#g]
    mov [frequence], ax
    ret

Dg_note:
    mov ax, [Dg]
    mov [frequence], ax
    ret

D#g_note:
    mov ax, [D#g]
    mov [frequence], ax
    ret

Eg_note:
    mov ax, [Eg]
    mov [frequence], ax
    ret

Fg_note:
    mov ax, [Fg]
    mov [frequence], ax
    ret

F#g_note:
    mov ax, [F#g]
    mov [frequence], ax
    ret

Gg_note:
    mov ax, [Gg]
    mov [frequence], ax
    ret

G#g_note:
    mov ax, [G#g]
    mov [frequence], ax
    ret

Ag_note:
    mov ax, [Ag]
    mov [frequence], ax
    ret

A#g_note:
    mov ax, [A#g]
    mov [frequence], ax
    ret

Bg_note:
    mov ax, [Bg]
    mov [frequence], ax
    ret

C_note:
    mov ax, [C]
    mov [frequence], ax
    ret

C#_note:
    mov ax, [C#]
    mov [frequence], ax
    ret

D_note:
    mov ax, [D]
    mov [frequence], ax
    ret

D#_note:
    mov ax, [D#]
    mov [frequence], ax
    ret

E_note:
    mov ax, [E]
    mov [frequence], ax
    ret

F_note:
    mov ax, [F]
    mov [frequence], ax
    ret

F#_note:
    mov ax, [F#]
    mov [frequence], ax
    ret

G_note:
    mov ax, [G]
    mov [frequence], ax
    ret

G#_note:
    mov ax, [G#]
    mov [frequence], ax
    ret

A_note:
    mov ax, [A]
    mov [frequence], ax
    ret

A#_note:
    mov ax, [A#]
    mov [frequence], ax
    ret

B_note:
    mov ax, [B]
    mov [frequence], ax
    ret

Ca_note:
    mov ax, [Ca]
    mov [frequence], ax
    ret

C#a_note:
    mov ax, [C#a]
    mov [frequence], ax
    ret

Da_note:
    mov ax, [Da]
    mov [frequence], ax
    ret

D#a_note:
    mov ax, [D#a]
    mov [frequence], ax
    ret

Ea_note:
    mov ax, [Ea]
    mov [frequence], ax
    ret

Fa_note:
    mov ax, [Fa]
    mov [frequence], ax
    ret

F#a_note:
    mov ax, [F#a]
    mov [frequence], ax
    ret

Ga_note:
    mov ax, [Ga]
    mov [frequence], ax
    ret

G#a_note:
    mov ax, [G#a]
    mov [frequence], ax
    ret

Aa_note:
    mov ax, [Aa]
    mov [frequence], ax
    ret

A#a_note:
    mov ax, [A#a]
    mov [frequence], ax
    ret

Ba_note:
    mov ax, [Ba]
    mov [frequence], ax
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
    ret 

;musicStart:
;    add word [time], 1
;    cmp word [time], 1
;    jne .skipChangeNote
;    mov word [time], 0
;    mov bx, [tour]
;    cmp bx, 0
;    call B_note
;    cmp bx, 1
;    call Ba_note
;    cmp bx, 2
;    call F#a_note
;    cmp bx, 3
;    call D#a_note

;    cmp bx, 4
;    call Ba_note
;    cmp bx, 5
;    call Fa_note
;    cmp bx, 6
;    call Ea_note

;    cmp bx, 8
;    call B_note
;    cmp bx, 9
;    call Ba_note
;    cmp bx, 10
;    call F#a_note
;    cmp bx, 11
;    call D#a_note

;    cmp bx, 12
;    call Ba_note
;    cmp bx, 13
;    call Fa_note
;    cmp bx, 14
;    call Ea_note

;    cmp bx, 16
;    call B_note
;    cmp bx, 17
;    call Ba_note
;    cmp bx, 18
;    call F#a_note
;    cmp bx, 19
;    call D#a_note

;    cmp bx, 20
;    call Ba_note
;    cmp bx, 21
;    call Fa_note
;    cmp bx, 22
;    call Ea_note

;    cmp bx, 24
;    call Ea_note
;    cmp bx, 25
;    call Fa_note
;    cmp bx, 26
;    call Ga_note
;    cmp bx, 27
;    call Aa_note
;    cmp bx, 28
;    call Ba_note
;    .skipChangeNote:
;    call play_note
;    ret

movMelody:
    add word [time], 1
    cmp word [time], 120
    jne .skipChangeNote
    mov word [time], 0
    mov bx, [tour]
    cmp bx, 0
    call Gg_note            ; call the sound procedure
    cmp bx, 1
    call C_note
    cmp bx, 1
    call D_note
    cmp bx, 3
    call E_note
    cmp bx, 4
    call Gg_note
    .skipChangeNote:
    call play_note
    ret

;TODO
;stop musique quand pac-man s'arrête
;change la note