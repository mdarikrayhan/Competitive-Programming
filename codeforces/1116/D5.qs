namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        (ControlledOnInt(0, H))(qs[1..2], qs[0]);
        Controlled H(qs[1..2], qs[0]);
        (ControlledOnInt(0, X))([qs[0]], qs[1]);
        (ControlledOnInt(0, X))([qs[0]], qs[2]);
        H(qs[0]);
    }
}