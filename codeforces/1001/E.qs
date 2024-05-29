namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs: Qubit[]) : Int {
        CNOT(qs[0], qs[1]);
        H(qs[0]);

        let p1 = M(qs[0]) == One ? 1 | 0;
        let p2 = M(qs[1]) == One ? 2 | 0;
        return p1 + p2;
    }
}
