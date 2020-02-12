# SUSTech Programming Language(SPL) project 3

Generating Intermediate Representation(IR) code generation using Syntax tree from project1.



##### usage

```shell
sudo apt-get install flex bison # install required package
cmake . # Generate makefile
make # Generate splc executable file in ./bin
./bin/splc test/test_3_b01.spl # Generate test/test_3_b01.ir
```

The output would be the IR code of input program:

```
FUNCTION add :
PARAM t0
t1 := t0 + #0
t2 := t0 + #4
t4 := *t1
t5 := *t2
t3 := t4 + t5
RETURN t3
FUNCTION main :
DEC t6 8
t7 := &t6 + #0
*t7 := #1
t8 := &t6 + #4
*t8 := #2
ARG &t6
t10 := CALL add
t9 := t10
WRITE t9
RETURN #0
```



##### Run the IR simulator

1. Download irsim from [release](https://github.com/zh-plus/Compilers/releases/tag/v1)
2. `irsim sample/test01.ir -i 3`
   The option-i stands for input numbers, which are separated by commas (,).  For a program without user input, this option can be simply ignored. 
3. To exit the simulator press `Esc` or `Ctrl-C`