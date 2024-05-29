namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            // your code here
            mutable ret = true;
            using (qs = Qubit[N + 1])
            {
                X(qs[N]);
                for (q in qs)
                {
                    H(q);
                }
                Uf(qs[0..N-1], qs[N]);
                for (q in qs[0..N-1])
                {
                    H(q);
                }
                for (q in qs[0..N-1])
                {
                    if (M(q) == One)
                    {
                        set ret = false;
                    }
                }
                ResetAll(qs);
            }
            return ret;
        }
    }
}
