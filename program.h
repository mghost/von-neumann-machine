#ifndef __program_h__
#define __program_h__

typedef enum codes {
    INPUT,      // gets input from the input channel
    OUTPUT,     // prints to the output channel
    LOAD,       // load a value from memory to accumulator
    STORE,      // store the accumulator value into memory
    ADD,        // mathematical sum between given memory cell and accumulator
    SUB,        // mathematical subtraction between memory cell and accumulator
    JUMP,       // goto a given memory cell
    JNZERO,     // goto a given memory cell if accumulator has value 0
    EXIT        // terminate the execution
} code;

// definition of pair to manage the two informations: (operation type, value to manage)
typedef struct Pair {
    code operation;
    int info;
} _pair;

class Program {
private:
    _pair* _source;
    int _length, _cistr;

protected:
    int check(int address);
    void* check_alloc(int size, int dim);
    void* check_realloc(int size, int dim);
    int check_instruction(int icode);

public:
    Program();

    int length();
    _pair get(int address);
    void put(int icode, int ivalue);
};

#endif
