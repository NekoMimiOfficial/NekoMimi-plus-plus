# The NekoMimi++ Headers  
This is a C++ variant of my Python library but.. well.. C++-fied  
Contains many useful features not found in the standard C++ libraries such as type converters, conditional checks, wrappers and more useful tools  

# Installation  
Install the provided deb package in the releases  

# Building  
This module uses no external dependencies besides `cmake`  
After installing `cmake` run `./build.sh` to compile and build a deb package  
If you want to build for a different distribution then you can follow the steps in the **Compiling** section and adapt it to your package format  

# Compiling  
After installing `cmake` run the following commands:  
```sh
cmake -L .
make -j6
```
You should now find the library files built under the `objects/` folder  
You can use the `link_directories()` cmake keyword to add the directory of the library to any of your cmake projects and then link against the `NMPP` module  
Examples found at the `tests/` folder (for the cmake file, and well... the cpp files if you need those)  

# You Like Neko ?? :3  
Neko wuvs you chewwww !! <3  
wanna connect? *sorry no server yet lol*  
contact info found at [my github profile](https://github.com/NekoMimiOfficial/NekoMimiOfficial) 
