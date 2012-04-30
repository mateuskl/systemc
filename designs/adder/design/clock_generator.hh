#include <systemc.h>
 
SC_MODULE(ClockGenerator)
{
    
    sc_out<bool> CLK;
    
    
    void generate();
 
 
    SC_CTOR(ClockGenerator)
    {
        SC_THREAD(generate);
    }
    
private:
    void __swap_clock();
    
};
