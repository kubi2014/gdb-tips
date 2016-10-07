Run your first gdb session with the following program:

```C
File: intro.c
#include "stdio.h"

void crashme()
{
  int* tmpInt = NULL;

  /* try to force this program to crash */
  *tmpInt = 0;
}

int main(int argc, const char* argv[])
{
  printf("Hello world !\n");

  if (argc > 1)
  {
    crashme();
  }

  printf("Bye this world !\n");

  return 0;
}
```

Compile the program:
```bash
gcc -g intro.c -o intro
```

Load and run that program with gdb:
```bash
biwiki@biwiki:~/github/gdb-tips/programs$ gdb intro
GNU gdb (Ubuntu 7.11.1-0ubuntu1~16.04) 7.11.1
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from intro...done.
(gdb) run
Starting program: /home/biwiki/github/gdb-tips/programs/intro
Hello world !
Bye this world !
[Inferior 1 (process 2911) exited normally]
```

Now run it again but with an argument, this will crash the program:
```bash
(gdb) run abc
Starting program: /home/biwiki/github/gdb-tips/programs/intro abc
Hello world !

Program received signal SIGSEGV, Segmentation fault.
0x0000000000400536 in crashme () at intro.c:8
8         *tmpInt = 0;
```

Check the value of pointer tmpInt:
```bash
(gdb) print tmpInt
$1 = (int *) 0x0
```

It can be seen that the program was crash due to a write statement to a null pointer (tmpInt)
