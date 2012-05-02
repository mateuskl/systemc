#include <systemc.h>
 
SC_MODULE(TwoBitCounter)
{
    sc_in<bool> CLK;
    sc_in<bool> RST;
    
    sc_out<bool> S0;
    sc_out<bool> S1;
 
    sc_out<bool> RST_O;
    
    void count();
    
    void reset();

    SC_CTOR(TwoBitCounter)
    {
        SC_METHOD(count);
        sensitive << CLK.pos();
        
        SC_THREAD(reset);
    }
    
private:    
    int __count;
    
};
