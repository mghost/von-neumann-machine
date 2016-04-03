#ifndef __von_neumann_cpp__
#define __von_neumann_cpp__

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#include "memory.h"
#include "program.h"
#include "von_neumann.h"

/*************** constructor(s) ***************/

VNMachine::VNMachine(int size) {
    this->_acc = this->_pc = 0;
    this->_ram = Memory(size);
    this->_pgr = Program();
}

/*************** protected ********************/

void VNMachine::fetch() {
    _pair istr = this->_pgr.get(this->_pc);
    switch(istr.operation) {
    case INPUT:
        cout << " [in]     ";
        cin >> this->_acc;
        cout << endl;

        break;
    case OUTPUT:
        cout << " [out]    " << this->_acc << endl << endl;

        break;
    case LOAD:
        this->_acc = this->_ram.get(istr.info);

        break;
    case STORE:
        this->_ram.put(istr.info, this->_acc);

        break;
    case ADD:
        this->_acc = this->_acc + this->_ram.get(istr.info);

        break;
    case SUB:
        this->_acc = this->_ram.get(istr.info) - this->_acc;
        if(this->_acc < 0)
            this->_acc = 0;

        break;
    case JUMP:
        this->_pc = istr.info;

        break;
    case JNZERO:
        if(this->_acc != 0)
            this->_pc = istr.info;

        break;
    case EXIT:
        fflush(stdout);
        exit(EXIT_SUCCESS);

        break;
    }

    this->_pc++;
}

/*************** public ***********************/

void VNMachine::begin_execution() {
    for(;;)
        fetch();
}

void VNMachine::input_source() {
    for(;;) {
        int operation, value = 0;
        cout << " istr number :    ";
        cin >> operation;

        if(operation == EXIT) {
            this->_pgr.put(EXIT, 0);
            cout << "\n\t\t *** source code end ***" << endl << endl << endl;
            break;
        }

        if(operation!=INPUT && operation!=OUTPUT) {
            cout << " istr value  :    ";
            cin >> value;
        }

        this->_pgr.put(operation, value);
        //cout << "   [?] memorized:   (" << operation << ", " << value << ")" << endl;
        cout << endl;
    }
}

#endif
