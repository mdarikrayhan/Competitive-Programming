namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
	    using (a = Qubit()) {
		    unitary(a);
		    let ans = M(a);
		    Reset(a);
		    return ans == Zero ? 0 | 1;
	    }
    }
}
