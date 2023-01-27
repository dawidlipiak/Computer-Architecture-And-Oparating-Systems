%include	'function1.asm'
section .data
   	multiplicand dw 10101b   ; Example multiplicand
    	multiplier dw 101b    ; Example multiplier
    	
section .text
    	global _start

_start:
        mov     eax, 0  	       ; Move multiplicand 21 into EAX
        mov     ecx, 101b	       ; Move multiplier 5 into ECX
        mov     esi, 0                 ; Set position on 0
        mov     edx, 0               ; Clear EDX for the addition
        mov     edx, 10101b

mul_loop:
        push    ecx                       ; Check if least significant bit of ECX is set
        and     ecx, 1
        cmp     ecx, 1
        pop     ecx
        jz      shift                   ; If not, skip the addition
        shl     edx, esi                ; Shift EDX left by position of multiplier bit
        add     eax, edx               ; Add EDX (multiplicand) to EAX (result)

shift:
        shr     ecx, 1                 ; Shift ECX right by 1 bit
        inc     esi
        mov     edx, [multiplicand]
        jnz     mul_loop               ; Repeat until ECX is zer
    	
        call	iprintLF
	call 	quit			; Exit the program
