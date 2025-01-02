namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
     operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
  mutable pos = -1;
  let n = Length(qs);
  for (i in 0..(n-1)) {
   if(bits0[i] != bits1[i]) {
    if (pos == -1) {
     H(qs[i]);
     set pos = i;
    }else{
     CNOT(qs[pos], qs[i]);
    }
   }
  }
   for (i in 0..(n-1)) {
   if(bits0[i]) {
    X(qs[i]);
   }
  }
 }
}