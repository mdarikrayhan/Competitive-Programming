namespace Solution{
 open Microsoft.Quantum.Primitive;
 open Microsoft.Quantum.Canon;
 open Microsoft.Quantum.Math;
  operation Solve(q : Qubit) : Int {
  body{
   if(RandomInt(2) == 1){
    return (M(q) == One ? 1 | -1);
   }else{
    H(q);
    return (M(q) == One ? 0 | -1);
   }
  }
 }
}