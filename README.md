# P9-Patrones

##### Fecha: 18/01/23
##### Author: Peral del Pino, Iker
##### Goal: The pourpouse of this exercise is to implement at least one design pattern of our choice and to arrange files and directorys as it's requested

## Introduction

This final version of the prgram has the all the methods and classes requested in the previous exercises. The prgram generates an interface for the fictional enterprise ***Julio Veganos e Hijos***. 

The interface has a *login* window in wich only employers with ID and NIF saved in the *users.dat* file can log in. Once inside, all users can see sensor information and manage security. Admin employers also can add and erase users. The file *Exceptions.h* has the needed classes to prevent Possible errors of use.

## How to Run the program

To compile and run the program it should be followed some steps:

* First of all download the files from the repository and make sure they are all where they should be.
* Then, use the command *make* in the command line to compile.
* Once the program is compiled, a *main* file should have appeared in the *build* directory. Now, to run the program, write the command *./build/main* in the command line.

```bash
~$ ./build/main

```

## Design pattern chosen

The design pattern chosen for this program is the ***singleton*** pattern due to it's easy implementation and because it could help to avoid future errors. This pattern is used to avoid the creation of several objects of a type that should only exits one of each. The objects that has this pattern implemented are the **Login** and the **Dashboard** of the *[main.cpp](https://github.com/clases-julio/p9-patrones-iperal2021/blob/main/src/main.cpp)* file.
```c
Login* login = Login::getTheLogin ();

Dashboard* dashboard = Dashboard::getTheDashboard ();

while (true) {
       
    system("clear"); // used in lots of functions to clear the screen
        
    login->login(ptrbase); // initialize the login screen
        
    dashboard->dashboard(ptrbase, login->go_to_dashboard());
}
return 0;
```

## Documentation

To view the doxygen documentation, once the repository is downloaded the next commands are needed to see the *Latex* PDF and the website:
* PDF: Go to the /doc/doxygen/latex directory and write the next command

```bash
~$ make && evince refman.pdf
```
* HTML: Go to the /doc/doxygen/html directory and write the next command

```bash
~$ firefox index.html
```
