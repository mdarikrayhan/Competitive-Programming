namespace Solution{
open Microsoft.Quantum.Measurement;
open Microsoft.Quantum.Intrinsic;
operation Solve(f:(Qubit=>Unit is Adj+Ctl)):Int{
    using(q=Qubit[2]){
        H(q[0]);
        CNOT(q[0], q[1]);
        Controlled f([q[0]], q[1]);
        Controlled f([q[0]], q[1]);
        CNOT(q[0], q[1]);
        H(q[0]);
                let parity=M(q[0])==One;
        ResetAll(q);
                H(q[0]);
        CNOT(q[0], q[1]);
        Controlled f([q[0]], q[1]);
        //Controlled Y([q[0]], q[1]);
                if(not parity){
            S(q[0]);
        }
        H(q[0]);
        return (MResetZ(q[0])==One ? 2|0)+(parity ? 1|0);
    }
}
}