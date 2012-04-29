#include <systemc.h>

#include <half_adder.hh>

#include <test_bench.hh>

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> A;
    sc_signal<bool> B;
    sc_signal<bool> S;
    sc_signal<bool> C;
    
    HalfAdder ha("Adder");
    HalfAdderTestBench tb("TestBench");
    
    ha.A(A);
    ha.B(B);    
    ha.S(S);
    ha.C(C);
    
    tb.stimulus_a(A);
    tb.stimulus_b(B);
    tb.obtained_s(S);
    tb.obtained_c(C);
    
    sc_start();
    
    return 0;    
}
