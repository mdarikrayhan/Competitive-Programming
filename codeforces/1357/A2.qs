namespace Solution {
 open Microsoft.Quantum.Intrinsic;
  operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
  mutable result = 0;
  using (qs = Qubit[2]) {
   X(qs[1]);
   unitary(qs);
   if (Measure([PauliZ], [qs[0]]) == One) {
    set result = result + 2;
   }
   ResetAll(qs);
   X(qs[0]);
   unitary(qs);
   if (Measure([PauliZ], [qs[1]]) == One) {
    set result = result + 1;
   }
   ResetAll(qs);
  }
  return result;
 }
}