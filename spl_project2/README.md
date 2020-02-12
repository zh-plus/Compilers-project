# SUSTech Programming Language(SPL) project 2

Performing semantic analysis on the generated syntax tree from project 1.



##### usage

```shell
sudo apt-get install flex bison # install required package
make # Generate splc executable file in ./bin
./bin/splc test/test_2_r01.spl # Generate test/test_2_r01.out
```

If the input program contains semantic error, the output would be correspond error message.

```
Error type 1 at Line 5: Variable x3 is used without definition
```

Otherwise, empty file would be created.



##### Error type

1. variable is used without definition
2. function is invoked without definition
3. variable is redefined in the same scope 
4. function is redefined (in the global scope, since we don’t have nested function) 
5. un-matching types on both sides of assignment operator (=) 
6. rvalue on the left side of assignment operator 
7. un-matching operands, such as adding an integer to a structure variable 
8. the function’s return value type mismatches the declared type 
9. the  function’s  arguments  mismatch  the  declared  parameters  (either  types or numbers, or both) 
10. applying indexing operator ([...])  on non-array type variables 
11. applying function invocation operator (foo(...))  on non-function names 
12. array indexing with non-integer type expression 
13. accessing member of non-structure variable (i.e., misuse the dot operator) 
14. accessing an undefined structure member 15redefine the same structure type

