#include <half_adder.hh>

#include <iostream>

// process
void HalfAdder::do_add()
{
    std::cout << "HalfAdder::do_add\n";
    
    // S = A XOR B
    S.write((A.read() ^ B.read()));
    
    std::cout << "S: " << S.read() << " A: " << A.read() << " B: " << B.read() << " A XOR B: " << (A.read() ^ B.read())  << std::endl; 
    
    // C = A AND B
    C.write(A.read() & B.read());
}
