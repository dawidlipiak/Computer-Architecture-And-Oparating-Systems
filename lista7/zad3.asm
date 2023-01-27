%INCLUDE	'zad3Print.asm'
section .data
	num DW 9999 ; 0001 0010 0011 w bcd
section .text
global _start

_start:
	MOV	ax, [num]
	CALL 	iprint
	CALL 	quit
