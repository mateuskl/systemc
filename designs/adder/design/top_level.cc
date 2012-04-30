#include <systemc.h>

#include <clock_generator.hh>
#include <two_bit_counter.hh>
#include <half_adder.hh>
#include <test_bench.hh>

#include <iostream>

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> A;
    sc_signal<bool> B;
    sc_signal<bool> S;
    sc_signal<bool> C;
    sc_signal<bool> CLK;
    
    ClockGenerator clock("clock");
    TwoBitCounter counter("counter");
    HalfAdder adder("Adder");
    HalfAdderTestBench testBench("TestBench");
    
    clock.CLK(CLK);
    
    counter.CLK(CLK);
    counter.S0(A);
    counter.S1(B);
    
    adder.A(A);
    adder.B(B);
    adder.S(S);
    adder.C(C);
    
    testBench.A(A);
    testBench.B(B);
    testBench.obtained_s(S);
    testBench.obtained_c(C);
    
    sc_start();
    
    // while(true); here this thread sould yield or something
    
    std::cout << "bye\n";
    
    return 0;    
}
