data segment
array db 1,2,3,4,5,6,7,8,98,10
sum dw ?
data ends

code segment
assume ds:data,cs:code
start:
    mov ax,data
    mov ds,ax
    lex bx,array
    mov ax,0h
    mov cx,10
xun:
    mov ax,[bx]
    inc bx
    loop xun
    mov sum,ax
    xor ax,ax
    mov ah,4ch
    int 21h
code ends
end start
