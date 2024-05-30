# philosophers

## Description:
This project main objective is to create threads and, consequentially, to do multithreading to demonstrate the philosophers dinner table problem. (insert later what is the problem)

## Skills learned:
- Multithreading: <PLACEHOLDER>

## Usage:
1. Make the files with "make all";
2. Run the program with ```./philo``` and entering four/five arguments:
	2.1. Number of philosophers (max 200);
	2.2. Time to die;
	2.3. Time to eat;
	2.4. Time to sleep;
	2.5. Number of times each philosopher must eat (optional);
3. Observe time stamps;

## Result:
- Status: <span style="color:red">Incomplete</span>
- Result: <span style="color:red">0%</span>

## Contact: 
- 42-email: <PLACEHOLDER>@student.hive.fi
- 42-profile: [https://profile.intra.42.fr/users/<INSERTUSERNAME>](https://profile.intra.42.fr/users/<INSERTUSERNAME>)

## Log:
```
28.05.2024
1. In parsing() the loop was not outputting the proper message for negative numbers being inputted. Took out the if statement that was blocking the message;
2. Git branches were outdated, got all branches up to date;
3. Tested for different positive integer cases of philosophers:
	3.1. One philosopher: OK;
	3.2. Five philosophers: OK;
	3.3. Zero before actual number of philos: OK (all cases);
	3.4. 200 philos: OK;
	3.5. Negatives (error handling): OK;
	3.6. Zeroes: OK;
4. Added zero checks with ft_atoi() in parsing();
5. Reduced redundancies in the code. Works the same, but now its more readable;
6. Reestructured files for organization;
7. Initialized the mutex lock within philosophize(), but there is no output coming from the threads;

29.05.2024
1. Most of the day went into fixing problem with general syntax to fit our approach of arrays of structs (i.e. each philosopher as a struct within itself);
2. Fixed segfault that occurred from improper dynamic allocation of memory. Memory allocaiton for the philosophers is now in struct_bzero();
3. Created separate struct for the thread that will oversee the philosophers called overseer. It has the same info that the philosophers have, but it will not be interacting with the dinner table (aka all the other threads);

30.05.2024
1. Instead of settings all values of the struct to zero manually, we will be using memset (as allowed by the subject) to have a more scalable solution to initializing our structs;
```