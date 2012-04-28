#include <systemc.h>
 
SC_MODULE(HalfAdder)          // module (class) declaration
{
    
    // ports
    sc_in<sc_bit> A;
    sc_in<sc_bit> B;
  
    sc_out<sc_bit> S;
    sc_out<sc_bit> C;
 
 
    // process
    void do_add();
 
 
    SC_CTOR(HalfAdder)          // constructor
    {
        SC_METHOD(do_add);    // register do_add to kernel
        sensitive << A << B;  // sensitivity list of do_add
    }
};
