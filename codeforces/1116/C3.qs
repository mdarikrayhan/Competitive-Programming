namespace Solution {
open Microsoft.Quantum.Intrinsic;
open Microsoft.Quantum.Canon;

operation Solve (x : Qubit[], y : Qubit) : Unit is Adj+Ctl{
	body (...){
	using (qs = Qubit[2]){
	let sum = qs[0];
	let carry = qs[1];
	X(sum);
	X(carry);
	for (q in x){
		CCNOT(q,carry,sum);
		CCNOT(q,sum,carry);
	}
	CCNOT(carry,sum,y);
	for (q in x){
	  CCNOT(q,sum,carry);
	CCNOT(q,carry,sum);	
	}
	X(sum);
	X(carry);
	}
} adjoint auto;
}
}