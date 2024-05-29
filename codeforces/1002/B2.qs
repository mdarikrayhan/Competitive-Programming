namespace Solution {
 open Microsoft.Quantum.Primitive;
 open Microsoft.Quantum.Canon;
  operation Solve(qs: Qubit[]): Int
 {
  let initial = M(qs[0]);
  for(i in 1..Length(qs)-1)
  {
   if(M(qs[i]) != initial) { return 1; }
  }
  return 0;
 }
}