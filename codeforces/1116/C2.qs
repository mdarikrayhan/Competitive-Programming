namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation setup(x : Qubit[], z : Qubit[], N : Int, m : Int) : Unit {
		ApplyToEachCA(X, z);
		for (P in (N+1)/2..N-1) {
			for (i in P..N-1) { CNOT(x[i-P], x[i]); X(x[i]); }

			Controlled X(x[P..N-1], z[P-(N+1)/2]);

			for (i in P..N-1) { CNOT(x[i-P], x[i]); X(x[i]); }
		}
	}
	
	operation Solve (x : Qubit[], y : Qubit) : Unit {
		body (...) {
			let N = Length(x);
			let m = (N-1) - (N-1)/2;
			using (z = Qubit[m]) {
				setup(x, z, N, m);

				Controlled X(z, y);
				X(y);

				setup(x, z, N, m);
			}
		}
		adjoint self;
	}
}