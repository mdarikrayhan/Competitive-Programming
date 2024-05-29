namespace Solution {
 open Microsoft.Quantum.Primitive;
 open Microsoft.Quantum.Canon;
 open Microsoft.Quantum.Math;
 open Microsoft.Quantum.Convert;
  operation Solve (qs : Qubit[]) : ()
    {
        let n = Length(qs);
    for (i in 0..n-1) {
   (ControlledOnInt(0, Ry(2.0 * ArcSin(1.0 / Sqrt(IntAsDouble(n-i))), _)))(qs[0..i-1], qs[i]);
  }
    }
}