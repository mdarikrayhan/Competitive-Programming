namespace Solution {
    open Microsoft.Quantum.Intrinsic;
     operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using ((q1, q2) = (Qubit(), Qubit())) {
            H(q1);
            CNOT(q1, q2);
            unitary(q1);
            CNOT(q1, q2);
            H(q1);
            CNOT(q1, q2);
            let ans = 2 * (M(q1)==One ? 1 | 0) + (M(q2)==One ? 1 | 0);
            ResetAll([q1, q2]);
            return ans;
        }
    }
}