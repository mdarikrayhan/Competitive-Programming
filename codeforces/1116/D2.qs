namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
     operation Solve (qs : Qubit[]) : Unit {
        for (i in 0..Length(qs)-2) {
                  H(qs[i]);
    (ControlledOnInt(0, H))(qs[i+1..Length(qs)-1], qs[i]);
  }
    }
}