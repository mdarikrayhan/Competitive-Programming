namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
 
	operation Solve(qs: Qubit[]): Int { body {
		H(qs[0]);
		CNOT(qs[0], qs[1]);
		H(qs[0]);
		mutable res = 0;
		if (M(qs[0]) == Zero) {
			set res = res + 2;
		}
		if (M(qs[1]) == Zero) {
			set res = res + 1;
		}
		return res;
	} }
}