#include <systemc.h>

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
    sc_signal<bool> RST;
    
    sc_time clk_period(30, SC_NS);
    sc_clock CLK("clk", clk_period);
    
    TwoBitCounter counter("counter");
    HalfAdder adder("Adder");
    HalfAdderTestBench testBench("TestBench");
    
    counter.RST(RST);    
    counter.RST_O(RST);
    counter.CLK(CLK);
    counter.S0(A);
    counter.S1(B);
    
    adder.A(A);
    adder.B(B);
    adder.S(S);
    adder.C(C);
    
    testBench.CLK(CLK);
    testBench.A(A);
    testBench.B(B);
    testBench.obtained_s(S);
    testBench.obtained_c(C);
    
    sc_trace_file *trcf = sc_create_vcd_trace_file("trace");
    if (trcf) 
    {
        sc_trace(trcf, A, "A");
        sc_trace(trcf, B, "B");
        sc_trace(trcf, S, "S");
        sc_trace(trcf, C, "C");
        sc_trace(trcf, CLK, "CLK");
        trcf->set_time_unit(-15);
    } else 
    {
        std::cout << "error in trace" << std::endl;
    }
    
    sc_start();
    
    std::cout << "bye\n";
    
    if (trcf) 
    {
        sc_close_vcd_trace_file(trcf);
    }
    
    return 0;    
}

