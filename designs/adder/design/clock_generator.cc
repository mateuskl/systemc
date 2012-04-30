#include <clock_generator.hh>


void ClockGenerator::generate()
{
    while (true)
    {
        CLK.write(__clk);
        __swap_clock();
        wait();
    }
        
}


void ClockGenerator::__swap_clock()
{
    __clk = (__clk) ? 0 : 1;
}
