#include <test_bench.hh>

#include <half_adder.hh>

#include <iostream>

using namespace std;

void HalfAdderTestBench::__init()
{
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


void HalfAdderTestBench::check()
{

    // cout << "check::begin\n";
    
    cout << "A: " << A.read() << " B: " << B.read() << " => " <<  "expS: " << __expected_S[A.read()][B.read()] << " obtS: " << obtained_s.read() << " expC: " << __expected_C[A.read()][B.read()] << " obtC: " << obtained_c.read() << endl;
    
    sc_assert(__expected_S[A.read()][B.read()] == obtained_s.read());
    sc_assert(__expected_C[A.read()][B.read()] == obtained_c.read());

    // cout << "check::end\n";
    
    if (A.read() && B.read())
    {
        cout << "tests OK\n";       
        sc_stop();
    }
}
