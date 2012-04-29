#include <systemc.h>
 
SC_MODULE(HalfAdder)          // module (class) declaration
{
    
    // ports
    sc_in<bool> A;
    sc_in<bool> B;
  
    sc_out<bool> S;
    sc_out<bool> C;
 
 
    // process
    void do_add();
 
 
    SC_CTOR(HalfAdder)          // constructor
    {
        SC_METHOD(do_add);    // register do_add to kernel
        sensitive << A << B;  // sensitivity list of do_add
    }
};
