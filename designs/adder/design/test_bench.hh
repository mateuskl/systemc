#include <systemc.h>
 
SC_MODULE(HalfAdderTestBench)   
{
    
    sc_in<bool> CLK;
    
    sc_in<bool> A;
    sc_in<bool> B;
    sc_in<bool> obtained_s;
    sc_in<bool> obtained_c;
 
    void check();
 
 
    SC_CTOR(HalfAdderTestBench)
    {
        __init();
        
        SC_METHOD(check);
        sensitive << CLK;         
    }


private:
    void __init();
    
private:
    bool __expected_S[2][2];
    bool __expected_C[2][2];
    
};
