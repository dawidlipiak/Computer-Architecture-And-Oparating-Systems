%include 	'functions.asm'

section .bss
	n DB 0

section .text
global _start

_start:
	pop 	ecx	;liczba argumentow na stosie
	
	cmp	ecx,0h	;sprawdz czy nie sa jakies argumenty do wypisania 
	jz	noMoreArgs
	pop	eax	;pierwszy argument to wywolanie programu
	pop	ebx

getNumber:
	mov	n,[ebx]
	mul
	sub	ebx,48
	mov 	[n],ebx
	cmp     ecx,0h  ;sprawdz czy nie sa jakies argumenty do wypisania 
        jz      noMoreArgs

	mov	eax, 1
	int 	80h
	

	;mov 	eax,0
	;mov 	eax,[n]
	;call	sprintLF

noMoreArgs:
	;call 	quit
