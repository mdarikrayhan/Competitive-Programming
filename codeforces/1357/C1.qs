namespace Solution {
open Microsoft.Quantum.Intrinsic;
 operation Solve (qs : Qubit[]) : Unit {
 let n = Length(qs);
 using (q = Qubit()){
 repeat {
  for (i in 0 .. n-1){
  H(qs[i]);
  }
  Controlled X(qs,q);
 }
until (M(q) == Zero)
fixup {
ResetAll(qs + [q]);
}
}
}
}