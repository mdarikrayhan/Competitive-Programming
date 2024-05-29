namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    operation Solve() : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [0.0, 0.8]), [ControlledRotation((0, new Int[0]), PauliY, 0)], ([0.0], 0.0));
    }
}