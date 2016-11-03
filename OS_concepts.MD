### Threads
- Thread is a fundamental unit of execution within an application. A running application consists of at least 1 thread. 
- Each thread has its own stack and runs independently from the other threads.
- Resources are shared between threads. Problems can occur when the access to resources is not controlled. (Data corruption)
- Kernel-level threads : Threads managed by OS
- The OS rapidly switches from thread to thread, giving each thread a small window of time to run. (Pre-emptive threading)


### Processes
- Both processes and threads are independent sequences of execution. The typical difference is that threads (of the same process) run in a shared memory space, while processes run in separate memory spaces.
- Each process provides the resources needed to execute a program. A process has a virtual address space, executable code, open handles to system objects, a security context, a unique process identifier, environment variables, a priority class, minimum and maximum working set sizes, and at least one thread of execution. 
- Each process is started with a single thread, often called the primary thread, but can create additional threads from any of its threads.

### Concurrency Issues



### Locks, Mutexes, Semaphores, Monitors
- Applications must use thread synchronization mechanisms to control threads’ interactions with shared resources.
- A lock or mutex (from mutual exclusion) is a synchronization mechanism for enforcing limits on access to a resource in an environment where there are many threads of execution.
- A **Mutex** is only for use within a single process, but across its many threads, whereas a **semaphore** may be used across multiple processes, and across their corresponding sets of threads.
- A **Monitor** is an object designed to be accessed from multiple threads. The member functions of a monitor object will enforce mutual exclusion, so only one thread may be performing any action on the object at a given time. If one thread is currently executing a member function of the object then any other thread that tries to call a member function of that object will have to wait until the first has finished.
- A **Semaphore** is a lower-level object. Semaphores are used to implement a monitor. A semaphore essentially is just a counter. When the counter is positive, if a thread tries to acquire the semaphore then it is allowed, and the counter is decremented. When a thread is done then it releases the semaphore, and increments the counter.
- *A monitor is like a public toilet. Only one person can enter at a time. They lock the door to prevent anyone else coming in, do their stuff, and then unlock it when they leave.*
- *A semaphore is like a bike hire place. They have a certain number of bikes. If you try and hire a bike and they have one free then you can take it, otherwise you must wait. When someone returns their bike then someone else can take it. If you have a bike then you can give it to someone else to return --- the bike hire place doesn't care who returns it, as long as they get their bike back.*

### Scheduling



### Deadlock, Livelock
- Consider the situation in which two threads block each other because each is waiting for a lock that the other holds. This is called a deadlock.
- Each thread is permanently stalled because neither can continue running to the point of releasing the lock that the other needs.
- Deadlock occurs when multiple threads need the same locks but obtain them in different order.
- In theory the best solution is to write code that cannot deadlock — for instance, whenever it’s necessary to acquire more than one lock, the locks should always be acquired in the same order and released in reverse order. In practice, it becomes difficult to enforce this across a large application with many locks, each of which may be acquired by code in many different places.

![alt tag](http://2.bp.blogspot.com/-63RZ-BTlAFs/VfGeHMnGdFI/AAAAAAAADuw/gwqtrVliMsM/s1600/Deadlock%2Bof%2BThreads.jpg)


### Context Switching
- Suspending one thread so another can start to run is referred to as a context switch.


### Resource Allocation
