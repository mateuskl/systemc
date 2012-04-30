#include <half_adder.hh>

// process
void HalfAdder::do_add()
{
    // S = A XOR B
    S.write(A.read() ^ B.read());
    
    // C = A AND B
    C.write(A.read() & B.read());
}
