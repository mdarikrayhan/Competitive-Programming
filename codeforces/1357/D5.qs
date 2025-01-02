namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;
     operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [1.3, -1.9]),
                [ControlledRotation((1, new Int[0]), PauliY, 0)],
                ([0.5 * PI()], 0.25));
    }
}