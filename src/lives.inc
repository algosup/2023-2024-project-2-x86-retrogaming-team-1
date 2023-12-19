section .data
    message dw "Game Over$", 0

    livesCounter db 3  ; Keep a byte for the counter

section .text

check_game_over:
    ; If touched, this code occurs
    dec byte [livesCounter]  ; Decrease the life amount by 1
    ; TODO : Add a sound effect

    ; If there is no more life, this code occurs
    cmp byte [livesCounter], 0
    je .game_over

    ; Return to the main code if there is at least one life left
    ret

    .game_over:
        ; Print the Game Over message
        mov ah, 9  ; Code of the function to display a string
        mov dx, message  ; The message to display
        int 21h  ; Interrupt DOS call to display the message

        ; If there is a game over music, play it here
        ; TODO : Add music

        ; Leave the program
        mov ah, 4Ch  ; Code of the function to exit the program
        int 21h  ; Interrupt DOS call to exit the program