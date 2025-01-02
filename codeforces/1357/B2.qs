namespace Solution {
  open Microsoft.Quantum.Arithmetic;
  open Microsoft.Quantum.Convert;
  open Microsoft.Quantum.Measurement;
  open Microsoft.Quantum.Math;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Intrinsic;
   operation Solve (x : Qubit[], y : Qubit) : Unit is Adj+Ctl {
    for (num in 0..PowI(2, Length(x)) - 1) {
      if (ModI(num, 3) == 0) {
        let bits = IntAsBoolArray(num, Length(x));
        (ControlledOnBitString(bits, X))(x, y);
      }
    }
  }
}