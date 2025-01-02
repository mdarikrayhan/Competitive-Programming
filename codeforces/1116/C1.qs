namespace Solution {
 open Microsoft.Quantum.Primitive;
 open Microsoft.Quantum.Canon;
  operation Solve (x : Qubit[], y : Qubit) : Unit
 {
  body (...) {
   for (i in 0..Length(x)-2) {
    CNOT(x[i+1], x[i]);
   }
   (Controlled X)(x[0..Length(x)-2], y);
   for (i in Length(x)-2..-1..0) {
    CNOT(x[i+1], x[i]);
   }
  }
  adjoint auto;
 }
}