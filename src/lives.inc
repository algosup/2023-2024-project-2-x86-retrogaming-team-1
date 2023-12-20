section .data
    message dw "Game Over. Try again!$", 0

    livesCounter db 3  ; Initialize the lives counter to 3

section .text

check_game_over:
    ; If touched, this code occurs
    dec byte [livesCounter]  ; Decrease the life amount by 1

    ; If there is no more life, this code occurs
    cmp byte [livesCounter], 0
    je .game_over

    call musicDeath  ; Play the death music

    ; Return to the main code if there is at least one life left
    ret

    .game_over:

        ; If there is a game over music, play it here
        call musicGO

        ; Clear the screen
        mov ah, 0   ; Function 00h - Set video mode
        mov al, 3   ; Video mode 3h - Text mode 80x25, 16 colors
        int 10h     ; Interrupt BIOS call to set video mode

        ; Print the Game Over message
        mov ah, 9  ; Code of the function to display a string
        mov dx, message  ; The message to display
        int 21h  ; Interrupt DOS call to display the message

        ; Leave the program
        mov ah, 4Ch  ; Code of the function to exit the program
        int 21h  ; Interrupt DOS call to exit the program