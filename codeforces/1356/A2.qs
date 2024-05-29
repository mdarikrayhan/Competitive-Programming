namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
	    using (a = Qubit()) {
		    H(a);
		    unitary(a);
		    H(a);
		    let ans = M(a) == Zero ? 0 | 1;
		    Reset(a);
		    return ans;
	    }
    }
}
