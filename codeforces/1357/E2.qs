namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve(p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        using (c = Qubit[2]) {
            within {
                H(c[0]);
                H(c[1]);
                Controlled QFTLE([c[0]], inputRegister);
                Controlled QFTLE([c[1]], inputRegister);
                Controlled QFTLE([c[1]], inputRegister);
                Adjoint QFTLE(LittleEndian(c));
            } apply {
                R1(PI() / IntAsDouble(2 * p), c[0]);
                R1(PI() / IntAsDouble(p), c[1]);
            }
        }
    }
}