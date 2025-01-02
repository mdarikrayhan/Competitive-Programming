namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
     operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (anc = Qubit[3]) {
            within {
                for (q in inputs) {
                    Controlled X([q, anc[0], anc[1]], anc[2]);
                    Controlled X([q, anc[0]], anc[1]);
                    CNOT(q, anc[0]);
                }
            }
            apply {
                (ControlledOnInt(Length(inputs) / 2, X))(anc, output);
            }
        }
    }
}