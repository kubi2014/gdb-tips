Breakpoints is used to make program stop at certain points and examine data for troubleshouting.

```C
/* File: break.c */
#include "stdio.h"

int main(int argc, const char* argv[])
{
  int a=4, b=8, c=0;
  printf ("a=%d, b=%d, c=%d\n", a, b, c);

  c = a > b ? a : b;
  printf ("c = max(a,b) = %d\n", c);

  c = a + b;
  printf ("c = a + b = %d\n", c);

  return 0;
}
```

```bash
gcc -g break-addr.c -o break-addr
```

```text
biwiki@ubuntu:~/github/gdb-tips/programs$ gdb break-addr 
GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
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
Reading symbols from break-addr...done.
(gdb) list
1	/* File: break.c */
2	#include "stdio.h"
3	
4	int main(int argc, const char* argv[])
5	{
6	  int a=4, b=8, c=0;
7	  printf ("a=%d, b=%d, c=%d\n", a, b, c);
8	
9	  c = a > b ? a : b;
10	  printf ("c = max(a,b) = %d\n", c);
(gdb) break main
Breakpoint 1 at 0x40053c: file break-addr.c, line 6.
(gdb) run
Starting program: /home/biwiki/github/gdb-tips/programs/break-addr 

Breakpoint 1, main (argc=1, argv=0x7fffffffde98) at break-addr.c:6
6	  int a=4, b=8, c=0;
(gdb) info locals
a = 32767
b = 0
c = 0
(gdb) step
7	  printf ("a=%d, b=%d, c=%d\n", a, b, c);
(gdb) info locals
a = 4
b = 8
c = 0
(gdb) list
2	#include "stdio.h"
3	
4	int main(int argc, const char* argv[])
5	{
6	  int a=4, b=8, c=0;
7	  printf ("a=%d, b=%d, c=%d\n", a, b, c);
8	
9	  c = a > b ? a : b;
10	  printf ("c = max(a,b) = %d\n", c);
11	
(gdb) break break-addr.c:10
Breakpoint 2 at 0x400578: file break-addr.c, line 10.
(gdb) continue
Continuing.
a=4, b=8, c=0

Breakpoint 2, main (argc=1, argv=0x7fffffffde98) at break-addr.c:10
10	  printf ("c = max(a,b) = %d\n", c);
(gdb) info locals
a = 4
b = 8
c = 8
(gdb) info break
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x000000000040053c in main at break-addr.c:6
	breakpoint already hit 1 time
2       breakpoint     keep y   0x0000000000400578 in main at break-addr.c:10
	breakpoint already hit 1 time
(gdb) list
5	{
6	  int a=4, b=8, c=0;
7	  printf ("a=%d, b=%d, c=%d\n", a, b, c);
8	
9	  c = a > b ? a : b;
10	  printf ("c = max(a,b) = %d\n", c);
11	
12	  c = a + b;
13	  printf ("c = a + b = %d\n", c);
14	
(gdb) break 13
Breakpoint 3 at 0x400597: file break-addr.c, line 13.
(gdb) continue
Continuing.
c = max(a,b) = 8

Breakpoint 3, main (argc=1, argv=0x7fffffffde98) at break-addr.c:13
13	  printf ("c = a + b = %d\n", c);
(gdb) print c
$1 = 12
(gdb) continue
Continuing.
c = a + b = 12
[Inferior 1 (process 6425) exited normally]
(gdb) 
```

