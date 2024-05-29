namespace Solution {
    open Microsoft.Quantum.MachineLearning;
     operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((4, [0.5, 0.0]), [ControlledRotation((1, new Int[0]), PauliY, 0)], ([0.0], 0.0));
    }
}