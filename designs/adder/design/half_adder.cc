#include <half_adder.hh>

// process
void HalfAdder::do_add()
{
    S.write(A.read() ^ B.read());
    S.write(A.read() & B.read());
}
