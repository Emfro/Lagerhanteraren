# Lagerhanteraren
##Axel Boström & Emil Fröjd
##Introduction
This is a Storagehandler, which is essentially a database of products, each of these having certain specific elements chosen by the user. The actions available are the following:
- Add product
- Remove product
- Edit product
- Undo the last change
- Print the database
- Quit

##Build
This is built using a makefile.

##Program
To compile and run the program one must simply write "make run". To compile and run separately, one must simply write "make lagermain", and then "./lager" to run the program.

##Tests
To make use of the tests, one must have test.input in the same folder as the program, and then write "make test", which runs the tests.

##Usage
The program is used by following the guidelines given during runtime, using the acceptable input given to the user. 

##Goals
During the development of this program, we have not been able to achieve any goals using the code written, as we achieved most of these during previous projects.

##Expansions
If we were to expand on this program, we would probably make the "Undo" function reusable, that is, if used mutiple times, multiple choices would be undone.
