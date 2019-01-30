#gcc abstract
>GNU CC（简称为Gcc）是GNU项目中符合ANSI C标准的编译系统，能够编译用C、C++和Object C等语言编写的程序。Gcc不仅功能强大，而且可以编译如C、C++、Object C、Java、Fortran、Pascal、Modula-3和Ada等多种语言，而且Gcc又是一个交叉平台编译器，它能够在当前CPU平台上为多种不同体系结构的硬件平台开发软件，因此尤其适合在嵌入式领域的开发编译。本章中的示例，除非特别注明，否则均采用Gcc版本为4.0.0。

##GCC入门基础

>表3.6 Gcc所支持后缀名解释

后 缀 名     | 所对应的语言              | 后 缀 名   | 所对应的语言
--          |:--:                     |:--:       |:--
.c          |C原始程序                  |     .s/.S |       汇编语言原始程序
.C/.cc/.cxx |C++原始程序                |    .h     |       预处理文件（头文件）
.m          |Objective-C原始程序        |    .o     |  目标文件
.i          |已经过预处理的C原始程序      |   .a/.so  |  编译后的库文件
.ii         |已经过预处理的C++原始程序    |

 	 
###如本章开头提到的，Gcc的编译流程分为了四个步骤，分别为：

####· 预处理（Pre-Processing）

####· 编译（Compiling）

####· 汇编（Assembling）

####· 链接（Linking）

###下面就具体来查看一下Gcc是如何完成四个步骤的。

####首先，有以下hello.c源代码
`
#include<stdio.h>

int main()

{

printf("Hello! This is our embedded world!n");

return 0;

}
`
####（1）预处理阶段

>在该阶段，编译器将上述代码中的stdio.h编译进来，并且用户可以使用Gcc的选项”-E”进行查看，该选项的作用是让Gcc在预处理结束后停止编译过程。

 	
>注意

>Gcc指令的一般格式为：Gcc [选项] 要编译的文件 [选项] [目标文件]

>其中，目标文件可缺省，Gcc默认生成可执行的文件，命为：编译文件.out

 

`[root@localhost Gcc]# Gcc –E hello.c –o hello.i`

 

>在此处，选项”-o”是指目标文件，由表3.6可知，”.i”文件为已经过预处理的C原始程序。以下列出了hello.i文件的部分内容：

 
`
typedef int (*__gconv_trans_fct) (struct __gconv_step *,

struct __gconv_step_data *, void *,

__const unsigned char *,

__const unsigned char **,

__const unsigned char *, unsigned char **,

size_t *);

…

# 2 "hello.c" 2

int main()

{

printf("Hello! This is our embedded world!n");

return 0;

}
`
 

>由此可见，Gcc确实进行了预处理，它把”stdio.h”的内容插入到hello.i文件中。

####（2）编译阶段

>接下来进行的是编译阶段，在这个阶段中，Gcc首先要检查代码的规范性、是否有语法错误等，以确定代码的实际要做的工作，在检查无误后，Gcc把代码翻译成汇编语言。用户可以使用”-S”选项来进行查看，该选项只进行编译而不进行汇编，生成汇编代码。

 

`[root@localhost Gcc]# Gcc –S hello.i –o hello.s`

 

>以下列出了hello.s的内容，可见Gcc已经将其转化为汇编了，感兴趣的读者可以分析一下这一行简单的C语言小程序是如何用汇编代码实现的。

 
`
.file "hello.c"

.section .rodata

.align 4

.LC0:

.string"Hello! This is our embedded world!"

.text

.globl main

.type main, @function

main:

pushl �p

movl %esp, �p

subl $8, %esp

andl $-16, %esp

movl $0, �x

addl $15, �x

addl $15, �x

shrl $4, �x

sall $4, �x

subl �x, %esp

subl $12, %esp

pushl $.LC0

call puts

addl $16, %esp

movl $0, �x

leave

ret

.size main, .-main

.ident "GCC: (GNU) 4.0.0 20050519 (Red Hat 4.0.0-8)"

.section .note.GNU-stack,"",@progbits
`
 

####（3）汇编阶段

>汇编阶段是把编译阶段生成的”.s”文件转成目标文件，读者在此可使用选项”-c”就可看到汇编代码已转化为”.o”的二进制目标代码了。如下所示：

 

`[root@localhost Gcc]# Gcc –c hello.s –o hello.o`

 

####（4）链接阶段

>在成功编译之后，就进入了链接阶段。在这里涉及到一个重要的概念：函数库。

>读者可以重新查看这个小程序，在这个程序中并没有定义”printf”的函数实现，且在预编译中包含进的”stdio.h”中也只有该函数的声明，而没有定义函数的实现，那么，是在哪里实现”printf”函数的呢？最后的答案是：系统把这些函数实现都被做到名为libc.so.6的库文件中去了，在没有特别指定时，Gcc会到系统默认的搜索路径”/usr/lib”下进行查找，也就是链接到libc.so.6库函数中去，这样就能实现函数”printf”了，而这也就是链接的作用。

>函数库一般分为静态库和动态库两种。静态库是指编译链接时，把库文件的代码全部加入到可执行文件中，因此生成的文件比较大，但在运行时也就不再需要库文件了。其后缀名一般为”.a”。动态库与之相反，在编译链接时并没有把库文件的代码加入到可执行文件中，而是在程序执行时由运行时链接文件加载库，这样可以节省系统的开销。动态库一般后缀名为”.so”，如前面所述的libc.so.6就是动态库。Gcc在编译时默认使用动态库。

>完成了链接之后，Gcc就可以生成可执行文件，如下所示。

 

`[root@localhost Gcc]# Gcc hello.o –o hello`

 

>运行该可执行文件，出现正确的结果如下。

 

`[root@localhost Gcc]# ./hello

Hello! This is our embedded world!`