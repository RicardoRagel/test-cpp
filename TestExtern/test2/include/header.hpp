/*
A header file were define the extern variables, so the source files can include it and get access
to these extern (int this case, ~ shared) variables.

This header file can be also used to declare shared (linked) functions, so, for example, the main.cpp
can use these dunctions although they are defined in module.cpp (also linked in the cmake file).

Note: Why the function doesn't have the extern modifier? In C++, by default, the functions prototypes 
(declarations) are extern.
*/

extern int global_int;

// We also add here the declaration of the functions of module.cpp, so we can use them from main.cpp
int get_global_var();
