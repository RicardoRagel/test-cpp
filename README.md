# test-cpp
This repository contains several packages to perform C++ tests:

1. **TestCpp**: Different examples using classes and STD containers.
2. **TestThread**: 

## Dependencies

Make sure you have a C++ compiler and CMake installed:

```bash
sudo apt-get install build-essential cmake
```

If you are going to generate also the Doxygen documentation, also install:
```bash
sudo apt-get install doxygen
```

## Build

You can build the complete repository or each package individually using CMake as usual:

```bash
mkdir build && cd build
cmake ..
make
```

In case of the TestCpp example, you can also generate the documentation just modifying the cmake step to:

```bash
cmake -DBUILD_DOC=ON ..
```

# Usage

1. **TestCpp**: Execute the program selecting the Test number:

    ```bash
    ./test_cpp <TEST_NUMBER>
    ```

2. **TestThread**: 
