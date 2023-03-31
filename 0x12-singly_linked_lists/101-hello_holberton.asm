section .data
hello db &apos;Hello, Holberton&apos;, 0x0a, 0

section .text
global _start

_start:
; call printf with hello string
mov rdi, hello
xor rax, rax
call printf

; exit with status code 0
xor rdi, rdi
mov rax, 60
syscall
