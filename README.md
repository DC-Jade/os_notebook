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

## PA1

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