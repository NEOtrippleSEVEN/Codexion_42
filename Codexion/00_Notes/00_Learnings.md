# What to learn first 

1. **POSIX Threads** : `pthread_create`, `pthread_join`, and the difference between thread-local and shared data. 

2. **Mutexes** : Protect Dongle State, stop state, counters and output so concurrent actions cannot corrupt shared data. 

3. **Condition Variables** : Let waiting coders sleep until dongle becomes eligible instead of spinning and wasting CPU. 

4. **Time Handling** : use `gettimeofday()` or `clock_gettime()` to calculate elapsed ms and detect burnout within 10ms.

5. **Deadlock * starvation** : Understand why grabbing one dogles and indefinit;y waiting for the next is dangerous.

6. **Priority Queues/Heaps** : implement request based on FIFO and EDF (Earliest Deadline First).

