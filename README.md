# Single Linked List #
*v2.2*


### What is this repository for? ###

 This is a single linked list implementation intended to practice some concepts about data structures and also learn to use new tools like Make and Doxygen.
 
 Tune the project as you want to your needs.


### How do I get set up? ###

* Summary of set up:

    - To make it work with ints you only need to create the appropiate header to include in your project (e.g.: inc/int_list.h).
    - With built-in types different from int you will need to implement a function to print the elements following specifications of display function (inc/single_list.h).
    - With own made types you will need to:
        1. Define a function to print your struct, you will pass its address to the defined display function as argument.
        2. Define a function to free your struct, you will pass its address to the defined destroy function as argument, and to every "remove_something" function.
        3. Define a function to copy your struct, you will pass its address to the defined copy function as argument.
        4. Define your struct with typedef to use only one word inside the macros.
        5. Wrap your macro replacements in a new header, with the new defined struct included or defined inside.

```bash
make all
```
* Dependencies:

The repositorie comes with two files and two folders. inc/ contains headers and src/ contains the code of the project with a main.c file to make a "proof of concept" of the functions implemented.

* How to run tests:

To run simple "tests":
```bash
make all && bin/test
```
To run "tests" with valgrind
```bash
make memcheck
```


### Contribution guidelines ###

* Writing tests:

There are a lot of frameworks to write good *unit test*, however i didn't have enough time to learn them, so, if you are interested you can build your own unitest and make a pull request to this repository. I would appreciate your help.
* Code review

Also, if you find any errors, in my code, my comments or something related to my style of code, also make a pull request. 
