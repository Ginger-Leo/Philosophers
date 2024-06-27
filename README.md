# philosophers

## Description:
This project main objective is to create threads and, consequentially, to do multithreading to demonstrate the philosophers dinner table problem. (insert later what is the problem)

## Skills learned:
- Multithreading: <PLACEHOLDER>

## Usage:
1. Make the files with "make all";
2. Run the program with ```./philo``` and entering four/five arguments:
	- Number of philosophers (max 200);
	- Time to die;
	- Time to eat;
	- Time to sleep;
	- Number of times each philosopher must eat (optional);
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
	- One philosopher: OK;
	- Five philosophers: OK;
	- Zero before actual number of philos: OK (all cases);
	- 200 philos: OK;
	- Negatives (error handling): OK;
	- Zeroes: OK;
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
2. The memset() in our struct_bzero() is working. All philosopher structs and overseer are set to 0. This solution is more scalable since memset does the work for us if we want to add variables for the philosophers later (not the case here though);


03.06.2024
1. Overseer was missing variables. Therefore, in struct_filler() the variables that are assigned after the loop to avoid unnecessary overwritting inside the loop. Assignment takes less processing power than an assignment, therefore we are just taking the variables out of the first philosopher, because there must always be at least ONE philosopher;
2. Forks now have dynamic memory allocation. This is a more efficient way of the program knowing the exact ammount of forks necessary for each philosophers;
3. Inserted eaten_flag and death_flag in overseer to know when a philosopher is dead; 
4. Each philosopher now has a pointer to the overseer to be able to know if there is a dead philosopher among them. Inside the main thread there is a while loop that will only cease when the death/eaten flag is switched to one;

04.06.2024 && 05.06.2024
1. Forks are being locked as soon as the threads are created;
2. Forks have to be accessed from the overseer. The mutex is being initialized by the overseer struct, so any attempt of initializing through the data/philosophers struct will end up causing a segmentation fault;
3. The logic of philosopize() has been altered to allow first locking, and then entering the routine of the philosophers;
4. So far we have accomplished to make a simple condition for death: when sleep is bigger than time to die;

06.06.2024
1. Segmentation fault around the forks unlocking;

07.06.2024
1. Reestructured the code in different ways, but came back to previous architecture (04.06.2024 && 05.06.2024);
2. Segfault remains in unlocking part;
3. Segfault was indeed located in the unlocking part, as soon as we entered the simulation. The underlying problem was that philo_id was one index number above from what it was supposed to be;
4. Locking of forks is now happening outside of the threading. This way we know that the beginning of the simulation will be more synchronized;
5. Leaks are still a problem;
6. Leaks have been solved: added function free_struct that is individually taking care of freeing both structs with their respective allocations;
7. Refactoring: a bunch of the code has been refactored to adapt to the norms. Mostly changing return values for some functions so it would come down to the main() and exit with zero at the end. Not quite sure how it will be done later within threads;

11.06.2024
1. Microphone() function was created: the general idea of this funcitonality is to only allow one philosopher to speak at given time and not have cross-talking between philosophers;
2. Death lock has been created: the general idea is to lock all and everything as soon as someone dies. The implementation is still in early stage;

13.06.2024
1. Fixed the segfault. The problem originated from multiple problems: 1. The mutex pointer had to have some memory allocated to it; 2. The order in which memory should've been allocated was there, we were just not following it (before memset and initialization); 3. The allocation should've been for a t_mtx pointer and now a "character";
2. Apparently there is an issue with types pthread_mutex_t that they seem to all be pointing to NULL at time of memory allocation, which renders the general logic of the code useless -> ISSUE SOLVED: apparently there was allocation of a pointer instead of t_mtx;
3. free_struct() has been remanaged. Now it takes a condition that is dictate by macros (DATA, OVERSEER, and BOTH), the usage is pretty straight forward: type DATA to free the arrays in data, type OVERSEER to free the overseer arrays, and both to free arrays from both;

14.06.2024
1. Struct_bzero() changed name to struct_init();
2. Added full routine to the philosophers: thinking, eating, and sleeping has been added;
3. Most of the routine is fairly simple, working with a check for the death flag (overseer->death_flag) and the microphone that is locked while in used;
4. Most of the routine is working, except that after a random amount of meals, the program runs into an infinite loop, which may be a race condition (locked fork trying to be accessed);
5. Added ft_usleep() that corrects the delays from usleep() by using busy waiting;

17.06.2024
1. Adding a new conditional function im_gonna_barf() to check the amount of times to eat and change the flag (overseer->eaten_flag) to quit the simulation;
2. The race condition may be originating from the eating() because the forks are locked while one of the philosophers is trying to access them. Therefore, the solution may be to come up with a function that is going to keep the philosophers waiting for their forks when not available (function name is the_line());
3. After using fsanitize=thread we were able to check which function was presenting race conditions. The eating() part of the routine has the a double lock in the microphone(), which already has a lock in itself and does not need an extraneous lock, otherwhise other philosophers will have problems trying to access it;
```
