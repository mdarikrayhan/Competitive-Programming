namespace Solution {
 open Microsoft.Quantum.Intrinsic;
 open Microsoft.Quantum.Math;
 open Microsoft.Quantum.Measurement;
  operation Solve (t : Double, f : (Qubit => Unit is Adj+Ctl)) : Int {
  using (x = Qubit()) {
   for (i in 0..19) {
    mutable y = 0.0;
    repeat {
     set y = y + t;
     f(x);
    } until (y + t > PI());
    if (MResetZ(x) == One) {
     return 1;
    }
   }
  }
  return 0;
 }
}