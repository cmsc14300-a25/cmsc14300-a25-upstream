CMSC 14300
Autumn 2025
Homework #3

This directory contains the files for Homework #3.

You will modify these files:

ballot.c: the C file for ballot functions
round.c: the C file for round functions

student_test_ballot.c: basic test code for ballot functions.
  You will add tests to this file
student_test_round.c: basic test code for round functions.
  You will add tests to this file

tests: a directory with sample ballot and candidates files.  
  You may add files to this directory, but do not modify
  the existing files.

Attestation.md: you must complete the three attestations
  listed in this file.  Submissions that do not include
  this information will not be graded.  

####### Do NOT modify these files:

ballot.h: the header file for ballot functions
round.h: the header file for round functions
election.c : a program that runs an election

util.c, h: utility functions used by the test code.

tests: a directory with sample ballot and candidates files.  

check_space.c: a simple program to allocate and deallocate ballots

Makefile: file to be used with make.  Run:
  make student_test_ballot - to compile your ballot code to
    generate an executable for the automated tests
    for the ballot functions

  make student_round_ballot - to compile your ballot and round code
    to generate an executable for the automated tests
    for the round functions

  make check_space - to compile your ballot code with check_space.c
    to generate an executable that can be used with valgrind to test
    your ballot free function 

  make election - to compile your code with our election 
    code to generate an executable to run an elections    

  make clean - remove generated files (a good thing
    to do before you add/commit/push your code).

README.md: the file you are reading

