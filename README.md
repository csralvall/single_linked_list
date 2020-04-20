# Single Linked List #
*v2.0*


### What is this repository for? ###

 This is a single linked list implementation intended to practice some concepts about data structures and also learn to use new tools like Make and Doxygen.
 
 Tune the project as you want to your needs.


### How do I get set up? ###

* Summary of set up:

    - To make it work with builtin-types you only need to create the appropiate header to include in your project (e.g.: inc/int_list.h).
    - With own made types you will need to define a new display and destroy functions, and define your type with typedef to use only one word inside the macros.

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
