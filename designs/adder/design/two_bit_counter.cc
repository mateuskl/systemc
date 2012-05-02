#include <two_bit_counter.hh>

#include <iostream>

void TwoBitCounter::count()
{
    cout << "TwoBitCounter::count\n";
    
    if (RST.read())
    {
        __count = 0;
        S0.write(0);
        S1.write(0);
    }
    
    else {
    
        switch(__count)
        {
            case 0:
            {
                S0.write(false);
                S1.write(false);
            }
            break;
            
            case 1:
            {
                S0.write(false);
                S1.write(true);
            }
            break;
            
            case 2:
            {
                S0.write(true);
                S1.write(false);
            }
            break;
            
            case 3:
            {
                S0.write(true);
                S1.write(true);
            }
            break;        
        }
        
        if (__count <= 3) 
        {
            __count ++;
        }
    }
}


void TwoBitCounter::reset()
{
    RST_O.write(true);
    wait(CLK.posedge_event());
    wait(CLK.posedge_event());
    wait(CLK.posedge_event());
    RST_O.write(false);
}





