

sub esp, 12 #栈顶指针-12
add esp, 8  #栈顶指针+8

mov [esp+8], eax    #将eax的值复制到主存[esp+8]
mov [esp+4], 958    #将985复制到主存[esp+4]
mov eax, [ebp+8]    #将主存[ebp+8]的值复制到eax
mov [esp],eax   #将eax的值复制到主存[esp]


