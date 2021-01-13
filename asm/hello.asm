;输出hello world
;data 数据段定义
data segment
    string db 'hello world','$' ;字符串结束
    string1 db 'hello world$' ;字符串结束
data ends

;代码段定义
code segment
assume ds:data,cs,code
;程序开始
start:
    mov ax,data ;将数据段段地址装入 AX 寄存器
    mov ds,ax ;将数据段段地址同归通用寄存器 AX 装入 DS
    mov dx,offset string ;将串的段内地址装入DX
    mov ah, 09h ;调用 DOS 的 09H 号功能,传入参数 DS:DX =串地址, '$' 结束字符串
    int 21h
    mov ah,4ch  ;调用 DOS 的4CH 号功能,带返回码结束,返回码存在在AL中
    int 21h
code ends ;代码段定义结束
end start ;程序结束
