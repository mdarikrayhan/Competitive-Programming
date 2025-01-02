namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[] {
		body {
			mutable b = new Int[N];
			for (i in 0..N-1) {
				set b w/= i <- 1;
			}
			using (qs = Qubit[N+1]) {
				Uf(qs[0..N-1], qs[N]);

				let res = M(qs[N]);
				if (res == One) {
					set b w/= 0 <- 0;
				}
				ResetAll(qs);
			}
			return b;
		}
	}
}