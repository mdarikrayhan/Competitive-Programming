namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            mutable cnt = 0;
            for (i in 0..Length(qs)-1) {
                if (M(qs[i]) == One) {
                    set cnt = cnt + 1;
                }
            }
            if (cnt == 0) {
                return 0;
            }
            return 1;
        }
    }
}