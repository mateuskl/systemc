#include <systemc.h>
 
SC_MODULE(AndGate)
{
    sc_in<bool> A;
    sc_in<bool> B;

    sc_out<bool> S;
 
 
    void compute();
 
 
    SC_CTOR(AndGate)
    {
        SC_METHOD(compute);
        sensitive << A << B;
    }
};
