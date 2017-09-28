#Makefile

## Shell Commands 
There are two ways to invoke shell commands from make file
- Rule bodies or Recipies
- The $(shell) function:
    * It's intended purpose is to capture the output of a command into gmake variables
```Makefile
USERNAME := $(shell whoami)
```
