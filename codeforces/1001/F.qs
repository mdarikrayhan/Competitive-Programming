namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for(i in 0..Length(qs)-1){if(bits0[i]){X(qs[i]);}}
            for(i in 0..Length(qs)-1){if(M(qs[i])==One){return 1;}}
            return 0;
        }
    }
}