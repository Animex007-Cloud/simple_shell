# 0x16.C - SIMPLE SHELL
----------------------------------
## RESOURCES
* ![Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)
* ![Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* ![Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
----------------------------------

### General
* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?

#### REQUIREMENTS
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. 
* All your header files should be include guarded
* Your shell should not have any memory leaks.

# OUTPUT
* Unless specified otherwise, your program must have the exact same output as `sh (/bin/sh)` as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

Example of error with `sh`:

```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

same example with your program `hsh`:

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## Compilation

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Shell should work like this in an interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
# Content...


# Authors:
* Adewale Okunade Christopher
* Ede-Esiri Ejakpovi
