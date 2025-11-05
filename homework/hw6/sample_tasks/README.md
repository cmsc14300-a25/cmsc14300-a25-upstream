CMSC 14300
Autumn 2025
Homework #6

Test files

- no_tasks.txt: a task file with zero tasks
  * RTS_no_tasks_1_10.txt - the expected RTS output for running: `./scheduler_main -c 1 -t 10 -f no_tasks.txt`
  
- one_task.txt: a task file with one task
  * RTS_one_task_1_10.txt: the expected RTS output for running: `./scheduler_main -c 1 -t 10 -f one_task.txt`
  * RTS_one_task_2_10.txt: the expected RTS output for running: `./scheduler_main -c 2 -t 10 -f one_task.txt`
  * RTS_one_task_3_10.txt: the expected RTS output for running: `./scheduler_main -c 3 -t 10 -f one_task.txt`

- four_tasks.txt: a task file with four tasks, listed in order of urgency
  * RTS_four_tasks_1_25.txt: the expected RTS output for running: `./scheduler_main -c 1 -t 25 -f four_tasks.txt`
  * RTS_four_tasks_2_25.txt: the expected RTS output for running: `./scheduler_main -c 2 -t 25 -f four_tasks.txt`
  * RTS_four_tasks_3_25.txt: the expected RTS output for running: `./scheduler_main -c 3 -t 25 -f four_tasks.txt`

- another_four_tasks.txt: a task file with four tasks, these tasks are not listed in order of urgency
  * RTS_another_four_tasks_1_25.txt: the expected RTS output for running: `./scheduler_main -c 1 -t 25 -f another_four_tasks.txt`
  * RTS_another_four_tasks_10_25.txt: the expected RTS output for running: `./scheduler_main -c 10 -t 25 -f another_four_tasks.txt`

- ten_tasks.txt: a task file with ten tasks, these tasks are not listed in priority order.
  * RTS_ten_tasks_1_25.txt: the expected RTS output for running: `./scheduler_main -c 1 -t 25 -f ten_tasks.txt`
  * RTS_ten_tasks_2_25.txt: the expected RTS output for running: `./scheduler_main -c 2 -t 25 -f ten_tasks.txt`
  * RTS_ten_tasks_3_25.txt: the expected RTS output for running: `./scheduler_main -c 3 -t 25 -f ten_tasks.txt`
  * RTS_ten_tasks_3_50.txt: the expected RTS output for running: `./scheduler_main -c 3 -t 50 -f ten_tasks.txt`

- README.md -- the file you are reading
