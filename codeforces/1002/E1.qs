namespace Solution{
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Math;

	operation Solve(N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[] {
		body{
			mutable res = new Int[N];

			using(qs = Qubit[N+1]){
				X(qs[N]);

				ApplyToEach(H, qs);
				Uf(qs[0..N-1], qs[N]);
				ApplyToEach(H, qs);

				for(i in 0..N-1){
					if(M(qs[i]) != Zero){
						set res w/= i <- 1;
					}
				}

				ResetAll(qs);
			}

			return res;
		}
	}
}