namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        for (i in Length(register!)-1..-1..1){
            Controlled X(register![0..i-1], register![i]);
        } X(register![0]);
    }
}