# GDB for Segmentation Faults

## CMake compilation

Compile the program using the CMake file as usual. Notice how it is configured for debugging using the proper CMake flag:

```cmake
set(CMAKE_BUILD_TYPE Debug)
```
## Running our executable to reproduce the seg fault

Simply execute it with an integer argument, the code has a bug accessing to it:

```bash
./test_gdb_2 20
```

## Running our executable with GDB

Run gdb together with the executable name: 

```bash
$ gdb test_gdb_2
```

and set the argument:

```bash
$ set args 20
```

```bash
(gdb) layout next
(gdb) run
```

It will show that the seg fault happened:

```bash
Program received signal SIGSEGV, Segmentation fault.
__GI_____strtol_l_internal (nptr=0x0, endptr=endptr@entry=0x0, base=base@entry=10, group=group@entry=0,
    loc=0x7ffff7d954a0 <_nl_global_locale>) at ../stdlib/strtol_l.c:292
../stdlib/strtol_l.c: No such file or directory.
```

and the error is inside the `atoi()` calling, that cannot be accessed by GDB and it is not possible to see the line where it failed. 

## Checking a segmentation fault

To be able to see where our program failed, it is necessary to make a `backtrace`:

```bash
(gdb) backtrace full
```

We get the following output:

```bash
#0  __GI_____strtol_l_internal (nptr=0x0, endptr=endptr@entry=0x0, base=base@entry=10, group=group@entry=0,
    loc=0x7ffff7d954a0 <_nl_global_locale>) at ../stdlib/strtol_l.c:292
#1  0x00007ffff7bf0ae6 in __strtol (nptr=<optimized out>, endptr=endptr@entry=0x0, base=base@entry=10) at ../stdlib/strtol.c:106
#2  0x00007ffff7bec5f4 in __GI_atoi (nptr=<optimized out>) at atoi.c:27
#3  0x0000555555555298 in main (argc=2, argv=0x7fffffffd9a8) at /home/ricardo/Libraries/test-cpp/TestGDB/test_2/src/test_gdb.cpp:32
```

So, the seg fault comes from the line 32 of our source file:

```cpp
second_argv = atoi(argv[2]);
```

Let's check then `argv`. First, it is necessary pausing the program before it fails:

```bash
(gdb) break 31
```

and then read the values of argv:

```bash
(gdb) print argv[0]
$1 = 0x7fffffffddbe "/home/ricardo/Libraries/test-cpp/TestGDB/test_2/build/test_gdb"
(gdb) print argv[1]
$2 = 0x7fffffffddfd "20"
(gdb) print argv[2]
$3 = 0x0
```

Obviously, our issue is that we are using argv[2], that doesn't even have a valid assigned memory direction.