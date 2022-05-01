# os_notebook
## Introduction
- This is a operating system learning notebook

- Ref: \

  [南京大学-操作系统](https://www.bilibili.com/video/BV1N741177F5?p=3&spm_id_from=pageDriver)\

  [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)\

  [南京大学 计算机系统基础](https://nju-projectn.github.io/ics-pa-gitbook/ics2021/index.html)\

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

## Program

- 状态机
- 状态机模型
  -   $多元组(PC, R_1, ..., R_n， mermory)$
  -   [Program counter, PC](https://en.wikipedia.org/wiki/Program_counter)
  -   $R_i(i = 1, ..., n), register$

```bash
cd src/
mgcc hanoi.c  # -g is required for gdb
gdb ../bin/hanoi
	layout src
```

## OS

- 硬件：C程序
- 应用程序： 系统调用API的集合

## Virtualisation虚拟化

### Abstraction

Abstraction makes it possible to write a large program by dividing it into small and under- standable pieces

- CPU
- Memory
- Protection
- Isolation

## Concurrency并发

## Persistence持久性



## Scripts(.sh)

```bash
mgcc () {
  arg1=$1;  # .c file
  arg2=${@:2:10}  # argments
  # -g - debug information
  gcc $arg1 -Wall -g $arg2 -o ../bin/${arg1%\.c}
}
```

