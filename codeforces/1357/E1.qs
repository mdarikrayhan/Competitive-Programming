namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
     operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        (OperationPowCA(QFTLE, p % 4))(inputRegister);
    }
}