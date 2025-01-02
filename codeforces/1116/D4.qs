namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arrays;

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        X(Tail(qs));
        ApplyToEach(Controlled X([Tail(qs)], _), Most(qs));
        X(Tail(qs));

        X(Head(qs));
        for (i in 1..N-2) {
            Controlled X(qs[0..i-1], qs[i]);
        }

        H(Tail(qs));
        ApplyToEach(Controlled X([Tail(qs)], _), Most(qs));
    }
}
