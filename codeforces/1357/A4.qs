namespace Solution {
    open Microsoft.Quantum.Intrinsic;
     operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
  mutable ret = 0;
  using (q = Qubit[2]) {
   H(q[0]);
   Controlled unitary([q[0]],(6.28318530718, q[1]));
   H(q[0]);
   if(M(q[0])== Zero) {
    set ret=1;
   }
   ResetAll(q);
  }
  return ret;
    }
}