 Simple shell project done by Chiemezie Agbo & Olajumoke Kolawole 
 ===================================================================================================

The Thompson shell was the first Unix shell, introduced in the first version of Unix in 1971, and was written by Ken Thompson.It was a simple command interpreter, not designed for scripting, but nonetheless introduced several innovative features to the command-line interface and led to the development of the later Unix shells.

							*Unix shell*

A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

Users typically interact with a Unix shell using a terminal emulator; however, direct operation via serial hardware connections or Secure Shell are common for server systems. All Unix shells provide filename wildcarding, piping, here documents, command substitution, variables and control structures for condition-testing and iteration.

*Early shells*

	Thompson shell
		The first Unix shell was the Thompson shell, sh, written by Ken Thompson at Bell Labs and distributed with Versions 1 through 6 of Unix, from 1971 to 1975. Though rudimentary by modern standards, it introduced many of the basic features common to all later Unix shells, including piping, simple control structures using if and goto, and filename wildcarding. Though not in current use, it is still available as part of some Ancient UNIX systems.

	Bourne shell
		The Bourne shell, sh, was a new Unix shell by Stephen Bourne at Bell Labs. Distributed as the shell for UNIX Version 7 in 1979, it introduced the rest of the basic features considered common to all the later Unix shells, including here documents, command substitution, more generic variables and more extensive builtin control structures. The language, including the use of a reversed keyword to mark the end of a block, was influenced by ALGOL 68. Traditionally, the Bourne shell program name is sh and its path in the Unix file system hierarchy is /bin/sh. But a number of compatible work-alikes are also available with various improvements and additional features. On many systems, sh may be a symbolic link or hard link to one of these alternatives:

	C shell
		The C shell, csh, was modeled on the C programming language, including the control structures and the expression grammar. It was written by Bill Joy as a graduate student at University of California, Berkeley, and was widely distributed with BSD Unix.[9]

		The C shell also introduced many features for interactive work, including the history and editing mechanisms, aliases, directory stacks, tilde notation, cdpath, job control and path hashing. On many systems, csh may be a symbolic link or hard link to TENEX C shell (tcsh), an improved version of Joy's original version. Although the interactive features of csh have been copied to most other shells, the language structure has not been widely copied. The only work-alike is Hamilton C shell, written by Nicole Hamilton, first distributed on OS/2 in 1988 and on Windows since 1992.


*PID & PPID*
	A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call getpid (man 2 getpid)

	Each process has a parent: the process that created it. It is possible to get the PID of a parent process by using the getppid system call (man 2 getppid), from within the child process.

*Arguments*
	The command line arguments are passed through the main function: int main(int ac, char **av);

	av is a NULL terminated array of strings
	ac is the number of items in av
	av[0] usually contains the name used to invoke the current program. av[1] is the first argument of the program, av[2] the second, and so on.

*Executing a program*
	The system call execve allows a process to execute another program (man 2 execve). Note that this system call does load the new program into the current process’ memory in place of the “previous” program: on success execve does not return to continue the rest of the “previous” program.
	Warning: in this example, execve is used without the current environment (last argument), don’t forget to add it in your Shell!

*Creating processes*
	The system call fork (man 2 fork) creates a new child process, almost identical to the parent (the process that calls fork). Once fork successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.

*Wait*
	The wait system call (man 2 wait) suspends execution of the calling process until one of its children terminates.

*File information*
	The stat (man 2 stat) system call gets the status of a file. On success, zero is returned. On error, -1 is returned.

*Environment*
	
	We have seen earlier that the shell uses an environment list, where environment variables are “stored”. The list is an array of strings, with the following format: var=value, where var is the name of the variable and value its value. As a reminder, you can list the environment with the command printenv
	Actually, every process comes with an environment. When a new process is created, it inherits a copy of its parent’s environment. To access the entire environment within a process, you have several options:
		via the main function
		via the global variable environ (man environ)

