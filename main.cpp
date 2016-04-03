#include <iostream>
#include "von_neumann.h"

using namespace std;

int main(void) {
    cout << endl << "\t*********** VON NEUMANN SIMULATOR **********" << endl << endl;
    VNMachine m = VNMachine(9999);
    m.input_source();
    m.begin_execution();

    return 0;
}
