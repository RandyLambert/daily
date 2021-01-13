data segment
    array db 56,81,47,29,76,25,36,32,64,18
    sum db ?
data ends


code segment
assume ds:data,cs,code
start:
    mov ax,data
    mov ds,ax
    lex bx,array
    mov ax,0
    mov cx,9
sumNum:
    add ax,[bx]
    inc bx
    loop sumNum
    mov sum,ax
    mov ah,4ch
    int 21h
code ends
end start

