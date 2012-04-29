#include <test_bench.hh>

#include <half_adder.hh>

#include <iostream>

using namespace std;

void HalfAdderTestBench::__init()
{
    // __ready = false;
    
    // S = A XOR B
    __expected_S[0][0] = 0;
    __expected_S[0][1] = 1;
    __expected_S[1][0] = 1;
    __expected_S[1][1] = 0;
    
    // C = A AND B
    __expected_C[0][0] = 0;
    __expected_C[0][1] = 0;
    __expected_C[1][0] = 0;
    __expected_C[1][1] = 1;
}


void HalfAdderTestBench::generate_stimulus()
{
    for (int ia = 0; ia < 2; ia++) 
    {
        for (int ib = 0; ib < 2; ib++)
        {
            stimulus_a.write(static_cast<bool>(ia));
            stimulus_b.write(static_cast<bool>(ib));
            __ia = ia;
            __ib = ib;
            
            cout << "generate_stimulus: " << ia << "," << ib << "\n";
            // __ready = true;
            // wait(__checked);
        }
    }
    
    // sc_stop();
}


void HalfAdderTestBench::check()
{
    /*
    if (!__ready)
    {
        return;
    }
    */
    
    if ((__ia == 0 || __ia == 1) && ((__ib == 0 || __ib == 1)))
    {
    
        cout << "check::begin" << __ia << "," << __ib << "\n";
        
        cout << "A: " << __ia << " B: " << __ib << " => " <<  "expS: " << __expected_S[__ia][__ib] << " obtS: " << obtained_s.read() << " expC: " << __expected_C[__ia][__ib] << " obtC: " << obtained_c.read();
        assert(__expected_S[__ia][__ib] == obtained_s.read());
        assert(__expected_C[__ia][__ib] == obtained_c.read());
        
        //__ready = false;
        //__checked.notify();  
    
        cout << "check::end\n";
    }
}
