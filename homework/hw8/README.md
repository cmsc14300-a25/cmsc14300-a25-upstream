CMSC 14300
Autumn 2025
Homework #8

This directory contains the files for Homework #8.

You will modify these files:

- candidates.c - the C file for the candidates API

- election.c - the C file for the election API

- voter_file.c - the C file for a slimmed down version of voter file
  API. You will add your solution for the ``read_voter_file`` function
  from HW #7 to this file.

You will copy these files from your Homework 7 directory:

- ballot.c - the C file for the precinct API.  You will add one
  function to this file.

- precinct.c - the C file for the precinct API.  You will add one
  function to this file.

- precinct_map.c - the C file for the precinct map API.  You will use
  this file without changes (other than those needed to fix bugs).

We have provided the following test files and sample data.  You are
welcome to modify any of them in service of testing your code:

- simple_test_candidates.c: a simple program for testing your candidates
  implementation

- simple_test_ballot.c: a simple test program for ballots.

- simple_test_precinct.c: a simple test program for precincts

- test_hw8.c: some of the tests from the initial autograder

- sample_files/: a directory with sample voter files.

We have provided the following C files:

- election_main.c: the main function for the election program
- growable_array.c: the C file for the growable array interface
- record_election_results.c: the C file for the API for recording election
  results.
- util.c: one utility function

We have provided tyhe following header files:

- ballot.h: the ballot API
- candidates.h: the candidates API
- election.h: the electinons API
- growable_array.h: the growable array API
- precinct.h: the precinct API
- precinct_map.h: the precincy map API
- record_election_results.h: the API for recording election results
- util.h: the utility function header file
- voter_file.h: a slimmed down version of the voter file API

Makefile: a makefile for constructing the following executabkes:
  test_hw8, simple_test_candidates election_main simple_test_ballot
  and simple_test_precinct.

README.md -- this file.