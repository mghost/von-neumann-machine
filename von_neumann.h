#ifndef __von_neumann_h__
#define __von_neumann_h__

#include "memory.h"
#include "program.h"

class VNMachine {
private:
    int _acc, _pc;
    Memory _ram;
    Program _pgr;

protected:
    void fetch();

public:
    VNMachine(int size);

    void begin_execution();
    void input_source();
};


#endif
