# Make MakeFile

This is a C program that "automatically" creates a makefile for C and C++. 
This means that you still need to start the program and insert some inputs, I will try to change it to work fully automatic but for now this will do.

## Prerequisites

```
gcc compiler
```
or
```
g++ compiler
```

## Starting

Download the file and open the terminal in the same folder as the *makemakefile.c* and type ```gcc -o a makemakefile.c``` and then execute the program with ```./a```.

## How to use it

The program should then ask you for the compiler and if you want to do a *makefile* for C Language type ```gcc``` and for C++ Language type ```g++```.

Then it asks for the number of input file, for example if you only have one file *example.cpp* you only have 1 input file, so type ```1```. For now the program only accepts 1 input file, I am working on changing that.

After that, it asks for the name of the input file, for example if you have a file *example.cpp* the name of your file is *example*, so you type ```example```.

And that is everything, you can now add the generated makefile to anywhere else!

## Known Issues

- I didn't use functions (I'm sorry, I will change it ASAP);
- It only accepts 1 input file;
- It only works for C and C++.

## Contributing

- Feel free to contribute for this repository

## Author

* **Daniel Lages** - [daniellages](https://github.com/daniellages)

## License

This project is licensed under the MIT License.