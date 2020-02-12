# SUSTech Programming Language(SPL) project 4

Generating MIPS32 target code using IR code from project3.



##### usage

```shell
sudo apt-get install flex bison # install required package
cmake . # Generate makefile
make # Generate splc executable file in ./bin
./bin/splc test/test_4_r01.ir # Generate test/test_4_r01.s
```

The output would be the MIPS32 target code of input IR code:



##### Run the MIPS simulator

1. Download spim: `sudo apt-get install spim`
2. `spim -file sample/test_4_fact.s `
3. The result would be printed into stdout.