#ifndef __memory_cpp__
#define __memory_cpp__

#include <cstdlib>
#include "memory.h"

#define DEF_MEM 10

/*************** constructor(s) ***************/

Memory::Memory() {
    Memory(DEF_MEM);
}

Memory::Memory(int size) {
    // if input is bad, tries to go straight on
    if(size < 0)
		    size = DEF_MEM;
		size += 2;

    this->_size = size;
    this->_pointer = (int*) check_alloc(size, sizeof(int));
		
		// overwritable registers in which are stored useful
		// default values to initialize other memory cells
		this->_pointer[0] = 0;
		this->_pointer[1] = 1;
}

/*************** protected ********************/

void* Memory::check_alloc(int size, int dim) {
    void* ptr = malloc(size * dim);
    // not enough memory for allocation of an array
    if(ptr == 0)
        exit(EXIT_FAILURE);

    return ptr;
}

/*************** public ***********************/

int Memory::check(int address) {
    // checks if address is between bounds
    return address>=0 && address<this->_size;
}

int Memory::put(int address, int value) {
    // before writing in memory, you've to check the bounds
    if(this->check(address)) {
        this->_pointer[address] = value;
        return 1;
    }

    return 0;
}

int Memory::get(int address) {
    // this may be a collision, but to say
    // 'this value is ok!' you have to check if address is ok
    if(this->check(address))
        return this->_pointer[address];

    return -1;
}

#endif
