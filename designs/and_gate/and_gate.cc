#include <and_gate.hh>

void AndGate::compute()
{
    S.write((A.read() && B.read()));
}
