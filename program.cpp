#ifndef __program_cpp__
#define __program_cpp__

#include <cstdlib>
#include "program.h"

/*************** constructor(s) ***************/

Program::Program() {
    this->_cistr = 0;
    this->_length = 1;
    this->_source = (_pair*) check_alloc(1, sizeof(_pair));
}

/*************** protected ********************/

int Program::check(int address) {
    return 0<=address && address<this->_length;
}

void* Program::check_alloc(int size, int dim) {
    void* ptr = malloc(size * dim);
    // not enough memory for allocation of an array
    if(ptr == 0)
        exit(EXIT_FAILURE);

    return ptr;
}

void* Program::check_realloc(int size, int dim) {
    void* ptr = realloc(this->_source, size*dim);
    // not enough memory for allocation of an array
    if(ptr == 0)
        exit(EXIT_FAILURE);

    return ptr;
}

int Program::check_instruction(int icode) {
    return INPUT<=icode && icode<=EXIT;
}

/*************** public ***********************/

int Program::length() {
    return this->_length;
}

_pair Program::get(int address) {
    if(this->check(address))
        return this->_source[address];

    // if given a bad address, executes a dummy sum (something + 0)
    _pair dummy;
    dummy.operation = ADD;
    dummy.info = 0;
    return dummy;
}

void Program::put(int icode, int ivalue) {
    if(this->_cistr == this->_length) {
        this->_length *= 2;
        this->_source = (_pair*) this->check_realloc(this->_length, sizeof(_pair));
    }

    if(this->check_instruction(icode)) {
        _pair istr;
        istr.operation = (code) icode;
        istr.info = ivalue;
        this->_source[this->_cistr++] = istr;
    }
}

#endif
