namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Arithmetic;
	
	operation Solve (qs : Qubit[]) : Unit {
		using (q = Qubit[1]) {
			repeat {
				Reset(qs[0]);
				Reset(qs[1]);
				Reset(q[0]);
				H(qs[0]);
				H(qs[1]);
				CCNOT(qs[0], qs[1], q[0]);
				X(qs[0]);
				X(qs[1]);
			} until (M(q[0]) == Zero);
		}
	}
}
