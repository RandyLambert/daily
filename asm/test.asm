data segment
    string db 'adsadsad$'
data ends

code segment
assume cs:code,ds:data
start:

    mov ax,data
    mov ds,ax
    lex dx,string

    mov ah,9h
    int 21h
    mov ah,21h
    int 21h

code ends
end start
