#include <clock_generator.hh>


#include <iostream>

void ClockGenerator::generate()
{
    while (true)
    {
        cout << "ClockGenerator::generate inside while\n";
        
        CLK.write(__clk);
        __swap_clock();
        wait();
    }
        
}


void ClockGenerator::__swap_clock()
{
    __clk = (__clk) ? false : true;
}
