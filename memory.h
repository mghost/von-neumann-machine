#ifndef __memory_h__
#define __memory_h__

class Memory {
private:
    int* _pointer;
    int _size;

protected:
    void* check_alloc(int size, int dim);

public:
    Memory();
    Memory(int size);

    int check(int address);
    int put(int address, int value);
    int get(int address);
};

#endif
