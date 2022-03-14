# Home Work 3 - Search Program with additional Features

### Description

The goal of this project is to implement the previous C program by adding additional functionality to the search inplemented in Project #2, the program must support the following given command line options.

Read keywords, command-line arguments, search keywords, keyword count, c language.

### Prerequisites

Requirements for the software and other tools to build, test and push
- [Example 1]GCC compiler
- [Example 2]C language

## Running the tests

To compile the files 
    
    $ make

And to run the output file, Run the command lines as

    $./a.out -s 1024 -e "ls -l"
        To list all files with size >= 1024 bytes in the current directory and execute the command "ls -l" on each file
    $./a.out -f jpg -E "tar cvf jpg.tar"
        List all files that have the substring “jpg” in their filename or directory name in the current directory and creates a tar file named jpg.tar that contains these files
    $./a.out -s 1024 -e "wc -l"
        List all files that have the substring “jpg” in their filename or directory name with size >= 1024 in the current directory and execute the command "wc -l" on each file 

along with these we can also run the previous given commands to run the file as they are completely integrated into the program.


### Sample Tests

So when you run the program with 
 $./a.out -s 1024 -e "ls -l"
    -rwxrwxrwx 1 rkari rkari  2561 Mar 13 21:10 ./Readme.md
    -rwxrwxrwx 1 rkari rkari 30424 Mar 13 21:11 ./a.out
    -rwxrwxrwx 1 rkari rkari 10648 Mar 13 20:10 ./code_original/codee.c
    -rwxrwxrwx 1 rkari rkari  3251 Mar 13 20:42 ./main.c
    -rwxrwxrwx 1 rkari rkari 13536 Mar 13 20:42 ./main.o
    -rwxrwxrwx 1 rkari rkari  7180 Mar 13 20:38 ./readingDir.c
    -rwxrwxrwx 1 rkari rkari 17488 Mar 13 20:42 ./readingDir.o
$./a.out -f ea -E "tar cvf file.tar"
    ./header.h
    ./readingDir.c
    ./readingDir.o
    ./Readme.md
        along with this a file.tar file is created in the directory.
$./a.out -s 1024 -e "wc -l"
    50 ./a.out
    347 ./code_original/codee.c
    592 ./jpg.tar
    137 ./main.c
    205 ./main.o
    197 ./readingDir.c
    305 ./readingDir.o
    70 ./Readme.md
    1903 total


## Authors

  - **Revanth Kari** - *CS 532* -
   [GitHub](https://github.com/RevanthUAB/CS532_hw3)

## Acknowledgments

  - To read the file paths from the array and execute the command lines in the linux mode EXECVP is used
  - Referenced websites are Tutorialspoint, Quora, Geeksforgeeks, linux,
  - stackoverflow, overiq, programiz, csl.

[//]: #
  [tutorialspoint]:<https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm>
  [Quora]:<https://www.quora.com/How-do-you-dynamically-allocate-an-array-of-struct-pointers-in-C>
  [geeksforgeeks]:<https://www.geeksforgeeks.org/exec-family-of-functions-in-c/>
  [stackoverflow]:<https://stackoverflow.com/questions/27541910/how-to-use-execvp>
  [Linux]:<https://linux.die.net/man/3/execvp>
  [CSL]:<http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html#:~:text=The%20execvp%28%29system%20call%20requires%20two%20arguments%3A%20%20The,to%20the%20argvarray%20used%20in%20the%20main%20program%3A>
