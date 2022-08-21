# GDB Basics

## CMake compilation

Compile the program using the CMake file as usual. Notice how it is configured for debugging using the proper CMake flag:

```cmake
set(CMAKE_BUILD_TYPE Debug)
```

## Running our executable with GDB

On a terminal, go to the build folder and run gdb together with the executable name: 

```bash
$ gdb test_gdb_1
```

## Basics commands

Open the program layout:

```bash
(gdb) layout next
```

And run the program, so it is executed as usual.

```bash
(gdb) run
```

Press **Ctrl+C** in case of the program doesn't finish (because it runs successfully).

In the layout, 
the last executed line is highlighted. To continue executing the
program line by line, execute:

```bash
(gdb) next
```

or simply

```bash
(gdb) n
```

In case the layout gets confusing, simply type:

```bash
(gdb) refresh
```

To check the current value of any variable use:

```bash
(gdb) print <variable>
```

Using "next", you go line by line in the current scope. To go in 
any function (for example, getDouble), use:

```bash
(gdb) step
```
or simply
```bash
(gdb) s
```

It is possible to log a variable each time its value is changed using

```bash
(gdb) watch <variable>
```

If we want to pause our program in a specific point, simply add a breakpoint,
so the first time the line is reached, the program will be stopped there:

```bash
(gdb) break 67
```

You can now execute the program again from the beginning `(gdb) run`.

It is also possible to add a breakpoint directly using the name of the function
where we want to add the breakpoint, for example:

```bash
(gdb) break getDouble
```

To delete a breakpoint, simply use:

```bash
(gdb) clear <line_number OR function_name>
```

To check the data of an array, like `v`, we can access it using the following:

```bash
(gdb) print v       # It returns the direction of the first element
(gdb) print *v      # It returns the value of the first element
(gdb) print *v@3    # It returns the value of the first three elements
```

To exit the debugger, simply type:

```bash
(gdb) quit
```
