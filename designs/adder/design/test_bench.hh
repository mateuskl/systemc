#include <systemc.h>
 
SC_MODULE(HalfAdderTestBench)   
{
    
    // stimulus
    sc_out<bool> stimulus_a;
    sc_out<bool> stimulus_b;
    
    // obtained values
    sc_in<bool> obtained_s;
    sc_in<bool> obtained_c;
 
 
    void generate_stimulus();
    void check();
 
 
    SC_CTOR(HalfAdderTestBench)
    {
        __init();
        SC_THREAD(generate_stimulus);
        
        
        SC_METHOD(check);
        sensitive << obtained_s << obtained_c;         
    }


private:
    void __init();
    
private:
    // sc_event __checked;
    // bool __ready;

    bool __expected_S[2][2];
    bool __expected_C[2][2];
    int __ia;
    int __ib;
    
};
