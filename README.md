# Von Neumann Machine

This is a sample implementation of Von Neumann Architecture

The main, and original idea, is explained @ wikipedia (https://en.wikipedia.org/wiki/Von_Neumann_architecture)

In this case there are some differences with original:
  - the 'ram' memory is used only to memorize data and istructions are memorized in an other location
    so, this architecture does not allow self modifying code.

  - there isn't a real error managing: when (for instance) the memory is full and the system call 'malloc' fails,
    the program will exit without trying to manage this event.

  - there isn't a real control of size of values in ram: in the original model, it was supposed that every cell of ram
    is composed, for instance, by 4 digits.

    In this case, to be more flexible, the only bound is that the instructions are signed with a single digit (0 to 8)
    yet, the value in stack are bounded only by real integer size (depending on architecture you're running this code)
    
  - if the program try to access to a memory cell that's not in range, the pair (4, 0) is returned: that means that for this
    execution, the program will sum accumulator with value at cell 0.

    So, pay attention, cause this sum could blow up your code.
