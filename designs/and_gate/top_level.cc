#include <systemc.h>

#include <iostream>

#include "and_gate.hh"

#define TRACE 1

SC_MODULE(TopLevelAndGateSimulation)
{
    int iter;    
    
    sc_clock clock;    
    
    AndGate andgate;
    
    sc_in<bool> clk_in;
    
    sc_signal<bool> A;
    sc_signal<bool> B;
    sc_signal<bool> S;

    
    void compute()
    {
        std::cout << "compute\n";
        
        A.write(false);
        B.write(true);
        
        wait(clk_in.posedge_event());
        wait(clk_in.posedge_event());
        wait(clk_in.posedge_event());
        
        A.write(true);
        B.write(true);       
    }
    
    void doand()
    {       
        std::cout << "doand: " << iter << "\n";
        
        if (iter < 10)
        {
            iter ++;
        }
        else
        {
            // sc_stop();
        }
    }
    
    
    SC_CTOR(TopLevelAndGateSimulation) :
        clock("clock"),
        andgate("Adder"),
        iter(0)        
    {
        
        andgate.A(A);
        andgate.B(B);
        andgate.S(S);
        clk_in(clock);

        SC_METHOD(doand);
        sensitive << clk_in.pos();
        
        SC_THREAD(compute);
    }
};

int sc_main(int argc, char *argv[])
{
    TopLevelAndGateSimulation top("TopLevel");
    
#if TRACE    
    sc_trace_file *trcf = sc_create_vcd_trace_file("trace");
    if (trcf) 
    {
        sc_trace(trcf, top.clk_in, "clk_in");
        sc_trace(trcf, top.A, "A");
        sc_trace(trcf, top.B, "B");
        sc_trace(trcf, top.S, "S");
        trcf->set_time_unit(-15);
    } else 
    {
        std::cout << "error in trace" << std::endl;
    }
#endif
    
    //sc_start(0);
    sc_start(10, SC_US);
    

#if TRACE    
    if (trcf) 
    {
        sc_close_vcd_trace_file(trcf);
    }
#endif
    
    return 0;    
}
