section .bss 

nextFreeSegment resw 1

section .text

heapInit:
mov ax,cs
add ax, 1000h
mov [cs:nextFreeSegment], ax
ret

;input in ax the number of paragraph to allocate
;output in bx the BaseSegmentId
heapAllocParagraph:
mov bx, [cs:nextFreeSegment]
add [cs:nextFreeSegment], ax
ret