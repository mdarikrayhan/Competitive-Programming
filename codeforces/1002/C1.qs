namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(0.25*PI(), q);
            if(M(q) == Zero) {
                return 0;
            }
            return 1;
        }
    }
}