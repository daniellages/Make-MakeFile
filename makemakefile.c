#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int input = 0;
    char compiler[15];
    char def = 0;
    char name[50];

    //Read Compiler
    printf("What is the compiler? ");
    fgets(compiler, sizeof(compiler), stdin);
    printf("\n");

    //Setting the definition (.cpp or .c)
    if(strcmp(compiler, "gcc") == 10){
        def = 0; //C
    }else if(strcmp(compiler, "g++") == 10){
        def = 1; //C++
    }else{
        printf("Only C or C++ are supported!\nSorry :(\n");
        return 0;
    }

    //Read how many input files
    printf("How many input files?(max 1) ");
    scanf("%d", &input);
    printf("\n");


    //Open File
    FILE *make;
    make = fopen("makefile", "w");

    //Input = 1 file
    if(input == 1 && def == 0){
        //Name of the file
        printf("What is the name of the file? ");
        scanf("%s", name);      //For some reason fgets doesn't work here
        //Header
        fputs("CC = ", make);
        fputs(compiler, make);
        fputs("\n\nSRCS := $(wildcard *.c", make);
        fputs(")\n", make);
        fputs("BINS := $(SRCS:%.c", make);
        fputs("=%)\n\nall: ${BINS}\n\n", make);
        //Body
        fputs(name, make);
        fputs(": ", make);
        fputs(name, make);
        fputs(".o\n\t$(CC) -o $@ $^\n\t./$@\n\n", make);
        fputs(name, make);
        fputs(".o: ", make);
        fputs(name, make);
        fputs(".c", make);
        fputs("\n\t$(CC) -c $^\n\n%.o: %.c", make);
        fputs("\n\t$(CC) -c $^\n\n", make);
        //Clean
        fputs("clean:\n\trm -rvf *.o ${BINS}", make);
    }else if(input == 1 && def == 1){
        //Name of the file
        printf("What is the name of the file? ");
        scanf("%s", name);      //For some reason fgets doesn't work here
        //Header
        fputs("CC = ", make);
        fputs(compiler, make);
        fputs("\n\nSRCS := $(wildcard *.cpp", make);
        fputs(")\n", make);
        fputs("BINS := $(SRCS:%.cpp", make);
        fputs("=%)\n\nall: ${BINS}\n\n", make);
        //Body
        fputs(name, make);
        fputs(": ", make);
        fputs(name, make);
        fputs(".o\n\t$(CC) -o $@ $^\n\t./$@\n\n", make);
        fputs(name, make);
        fputs(".o: ", make);
        fputs(name, make);
        fputs(".cpp", make);
        fputs("\n\t$(CC) -c $^\n\n%.o: %.cpp", make);
        fputs("\n\t$(CC) -c $^\n\n", make);
        //Clean
        fputs("clean:\n\trm -rvf *.o ${BINS}", make);
        //Comment
        fputs("\n\n#Program made by Daniel Lages!\n#Commands\n\t#make\n\t\t#use to compile and execute once, if you want to execute it again type: ./", make);
        fputs(name,make);
        fputs("\n\t#make clean\n\t\t#deletes the not important files\n#Github: https://github.com/daniellages", make);
    }

    //Creddits and Commands
    printf("\nThis program was made by: daniellages\nUse: make => to compile and execute once\n     ./%s => to execute the program\n     make clean => delete not important files\n", name);

    //Close File
    fclose(make);

    return 0;
}