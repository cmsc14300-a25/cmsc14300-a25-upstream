CMSC 14300
Autumn 2025
Homework #6

You will modify these files:

- task_pq.c: a module for representing task priority queues
- task_manager.c: a module for representing task managers
- Attestation.md: the required attestation file

You will copy these files from your solution to Homework 5:

- task.c: a module for representing tasks
- scheduler.c: a simple task scheduler

You may modify these files, if you like.  These programs do basic testing
you are welcome to add additional test code to any of them.

- check_task_extra.c: a program to verify that you added the
     extra tasks from task_extra_functions.c to your implementation
     of task.c properly
- simple_test_task_pq.c: a simple program for testing your
    task priority queue implementation.
- simple_test_task_manager.c: a simple program for testing your
    task manager.
- scheduler_main.c: a simple program that runs the scheduler

- sample_tasks/: a directory with a few task and RST files.  You
    may add task files to this directory.  

Do NOT modify these files:
  
- task.h: the header file for the task module
- task_extra_functions.c: you will copy these functions into your    
  implementation of task.c
- task_manager.h: the header file for the task manager module
- task_pq.h: the header file for the task priority queue
- scheduler.h: the header file for the scheduler
- util.c, util.h: a simple utility function for reading task files.
- growable_array.c, growable_array.h: a growable array module
  
- Makefile -- a makefile for building check_task_extra   
    simple_test_task_pq, simple_test_task_manager, scheduler_main

- README.md -- the file you are reading
