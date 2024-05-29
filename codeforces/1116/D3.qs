namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
		for(i in 0..n-2){
			CNOT(qs[n-1],qs[i]);
		}
		H(qs[n-1]);
		for(i in 0..n-2){
			CNOT(qs[n-1],qs[i]);
		}
    }
}