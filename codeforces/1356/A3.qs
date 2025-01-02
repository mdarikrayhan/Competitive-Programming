namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
    using (q = Qubit()) {
    H(q);
    unitary(q);
    unitary(q);
    return MResetX(q) == Zero ? 0 | 1;
    }
    }
}
