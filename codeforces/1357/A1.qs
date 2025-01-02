namespace Solution{
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	operation Solve(unitary:(Qubit[]=>Unit is Adj+Ctl)):Int{
		using(qs=Qubit[2]){
			X(qs[1]);
			unitary(qs);
			Reset(qs[1]);
			return MResetZ(qs[0])==Zero?0|1;
		}
	}
}