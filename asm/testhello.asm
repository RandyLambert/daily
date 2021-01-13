data segment
    string db 'hello world$'
data ends
code segment
assume ds:data,cs:code
start:
    mov ax,data
    mov ds,ax
    lea dx,hello
    mov ah,09h
    int 21h
    mov ah,4c
    int 21h
code ends
end start
