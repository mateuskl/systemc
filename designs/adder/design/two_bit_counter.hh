#include <systemc.h>
 
SC_MODULE(TwoBitCounter)
{
    sc_in<bool> CLK;
    
    sc_out<bool> S0;
    sc_out<bool> s1;
 
    
    void count();

    SC_CTOR(TwoBitCounter)
    {
        __count = 0;
        SC_METHOD(count);
        sensitive << CLK;
    }
    
private:    
    int __count;
    
};
