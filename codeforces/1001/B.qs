namespace Solution {
open Microsoft.Quantum.Primitive;
open Microsoft.Quantum.Canon;
operation Solve (qs : Qubit[], index : Int) : ()
{
body
{
H(qs[0]);
CNOT(qs[0], qs[1]);
// now we have (|00> + |11>) / sqrt(2) - modify it based on index arg
if (index % 2 == 1) {
// flip the phase of |11> component
Z(qs[1]);
}
if (index / 2 == 1) {
// flip the state of the second qubit
X(qs[1]);
}
}
}
}
