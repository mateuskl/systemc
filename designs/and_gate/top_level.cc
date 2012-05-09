#include <systemc.h>

#include "and_gate.hh"

#define TRACE 1

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> A;
    sc_signal<bool> B;
    sc_signal<bool> S;

    AndGate andgate("Adder");
    
    andgate.A(A);
    andgate.B(B);
    andgate.S(S);
    
#if TRACE    
    sc_trace_file *trcf = sc_create_vcd_trace_file("trace");
    if (trcf) 
    {
        sc_trace(trcf, A, "A");
        sc_trace(trcf, B, "B");
        sc_trace(trcf, S, "S");
        trcf->set_time_unit(-15);
    } else 
    {
        std::cout << "error in trace" << std::endl;
    }
#endif
    
    sc_start();
    

#if TRACE    
    if (trcf) 
    {
        sc_close_vcd_trace_file(trcf);
    }
#endif
    
    return 0;    
}
