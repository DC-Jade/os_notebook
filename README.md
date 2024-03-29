[TOC]

# os_notebook

## Introduction

- This is a operating system learning notebook

- Reference: 

  [南京大学-操作系统](https://www.bilibili.com/video/BV1N741177F5?p=3&spm_id_from=pageDriver)\

  [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)\

  [南京大学 计算机系统基础](http://jyywiki.cn/ICS/2020/)\

	[深入理解计算机系统](https://baike.baidu.com/item/深入理解计算机系统/4542223)\

  [程序员的自我修养](https://book.douban.com/subject/3652388/)\
	
	[Source Code](https://github.com/remzi-arpacidusseau/ostep-code)\

## Supported

- os
  
  Ubuntu 16.04 LTS
  
- compiler
  
  gcc version 9.4.0
-   This is os lab notebook 

## Start

```bash
git clone git@github.com:DC-Jade/c_notebook.git
```

~~## PA1~~

-   [Turing machine, TRM](https://en.wikipedia.org/wiki/Turing_machine)
    -   while (1) { get instruction; run instruction; update instruction; }
-   状态机模型
    -   $多元组(PC, R_1, ..., R_n， mermory)$
    -   [Program counter, PC](https://en.wikipedia.org/wiki/Program_counter)
    -   $R_i(i = 1, ..., n), register$
-   [ISA](https://en.wikipedia.org/wiki/Instruction_set_architecture)
    -   指令集架构， 硬件无关的机器指令集的集合
-   地址映射
    -   pmem

## Program 程序

~~### Intrinsic 本质~~

### 1. state machine

- $tuple(pc, r_1, ..., r_n， mermory)$

- [program counter, pc](https://en.wikipedia.org/wiki/Program_counter)

- $r_i(i = 1, ..., n), register$ x86

  ​	rip -> pc ; r[abcd]x ; rbp -> begin ptr of stack ; rsp -> stop ptr of stack, controlling stack

### 2. computing + syscall

- computing program

  up to 99%

- syscall

  store process status and managing process

- function

  - intrinsic

    stack and frame

  - function call

    push frame

  - function return

    pop frame

```bash
cd src/
mgcc hanoi.c  # -g is required for gdb
gdb ../bin/hanoi
	layout src
	wa $rax  # watch point, trace register rax

# min_hello.S
gcc -c min_hello.S && ld min_hello.o -o ../bin/min_hello
```

## Compile process 编译过程

.c(src) -> (preprocessing, gcc -I) -> .I -> (compiling, gcc -E) -> .S(assembly code) 

-> (assembling, gcc -c) -> linking(ld || gcc -o) -> .o(ELF, object code)

### 1. preprocessing

- Expand #include macro(marked with #)

- rm comments
- save #pragma compiling instructions, required for compiling(step2)

### 2. compiling

transfer c/c++ code to assembly code, producing assmebly file(.S)

### 3. assembling

transfer assembly code to machine instruction(binary code), producing intermediate object file(.o)

### 4. linking

linking object file, incluing shared object file(.so), producing executable file(a.out)

dereference of symbols in different modules, adjust symbols address in different modules(object file)

<img src="figure/linking_process.jpg" alt="linking_process" style="zoom:50%;" />

## operating system, OS 操作系统

- ~~硬件：C程序~~
- ~~应用程序： 系统调用API的集合~~

### Intrinsic

1. machine 

​	C program

2. application program

​	syscall APIs

## Virtualisation 虚拟化

### Abstraction

Abstraction makes it possible to write a large program by dividing it into small and under- standable pieces

- CPU
- Virtual Memory
  - abstraction of main memory

- File
  - abstraction of I/O devices

- Protection
- Isolation

## Concurrency 并发

- Definition

  running  instructs of process/thread  by turns

  Control flow of a process overlaped with others in time

- Multiple threads

- Atomic

- Plot status machine 

- 互斥

```bash
cd ../include
wget http://jyywiki.cn/pages/OS/2022/demos/thread.h
cd ../src
mgcc multi_thread.c -l pthread && ../bin/multi_thread
```



## Persistence 持久性

## Scripts(.sh)

```bash
mgcc () {
  arg1=$1;  # .c file
  arg2=${@:2:10}  # argments
  # -g - debug information
  gcc $arg1 -Wall -g $arg2 -o ../bin/${arg1%\.c}
}
```

## Basics

### Hardware Composite Model

<img src="figure/hardware_composite_model.png" alt="composite_model" style="zoom:50%;" />

<img src="figure/cache_model.png" alt="cache_model" style="zoom:50%;" />

- Main memory

  主存是一个临时存储设备，在处理器执行程序时，用来存放程序和程序处理的数据,主存是由一组动态随机存取存储器(DRAM)芯片组成的; 从逻辑上来说，存储 器是一个线性的字节数组，每个字节都有其唯一的地址(数组索引)

- CPU

  中央处理单元(CPU),简称处理器，解释(或执行)存储在主存中二进制指令。主要由ALU （算术逻辑单元）和 PC（程序计数器）

  ALU处理指令，进行状态计算，如；PC是一个大小为一个字的存储设备(或寄存器)，指向主存中的某条机器语言指令(即含有该条指令的地址；

- Memory Hierarchy

  <img src="figure/memory_hierarchy.png" alt="memory_hierarchy_model" style="zoom:50%;" />

### Process

<img src="figure/process_virtual_memory.png" alt="process_virtual_memory_model" style="zoom:50%;" />

### Bit

- Bit，二进制数字
- Byte，字节；8位bit，最小寻址的内存单位
- Word，字; 数据传输单元，和寄存器长度一致

### Exception

1. interruption
2. trap
3. falut
4. Halt

### Parallel

control flow runs in different cpus by concurrency

### Context

all status of a process

### Reentrant function（可重入函数）

ont type of thread_safe function

- don’t use gloabl or static variables in peer threads

### Symbol

global and static variables and function 

symbol name - name  of globale and static variables and function

### module

one c/cpp file, always **same as an object file**

### ELF(executable linkable format)

- used by obejct file and executable file , relocatable or executable

- three types

  1. relocatable file(.o)
  2. execuable file(a.out)
  3. shared object file(.so)

- .bss and .data

  .bss - uninitialized global and static variables, (static int i = 0, seen as unitialized, located at the .bss)

  .bss allocated by the linker, due to weak symbols size is undetermined in compiling process

  .data - initialized global and static variables 

- cmd

  ```bash
  objdmp -h -s -x .o
  readelf -h -S -s .o
  nm .o
  strip .o # remove symbol info(including debug info)
  size .o
  ```
  
  

​												<img src="figure/elf_format.jpg" alt="elf_format" style="zoom:50%;" />

### name mangling/decoration

a symbol decoration mechanism in C++, used to void symbol name confict

### Stack model

<img src="figure/stack_model.png" alt="stack_model" style="zoom:50%;" />

## Trick

### swap

```c
int a = 100, b = 1;
void swap(int *a, int *b);
swap(&a, &b);
void swap(int *a, int *b) {
  *a ^= *b ^= *a ^= *b;
}
```

