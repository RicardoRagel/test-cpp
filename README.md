# test-cpp
This repository contains several packages, named as `Test*`, to perform different C++ tests. The special pacakge `CleanTest` can be used as a starting point for creating a new test suite.

The programs has been tested on Linux, but it should not be any issue to compile them on Windows using, for example VSCode together the extension 'CMake Tools'.

## Dependencies

Make sure you have a C++ compiler and CMake installed. On Linux:

```bash
sudo apt-get install build-essential cmake
```

## Build

You can build the complete repository or each package individually using CMake as usual. So, execute the following commands in the root folder or within any of the packages:

```bash
mkdir build && cd build
cmake ..
make
```

In case of the `TestCpp` package, you can also generate the documentation just modifying the cmake step to:

```bash
cmake -DBUILD_DOC=ON ..
```

Make sure you have installed Doxygen:

```bash
sudo apt-get install doxygen
```

# Usage

After build all or any of the packages, a serie of executables have been generate to execute the tests. Use the command `./<executable_name>` as usual.

In case of the package **TestCpp**, the program should be executed selecting a test number:

```bash
./test_cpp <TEST_NUMBER>
```
