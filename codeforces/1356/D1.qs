namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;
    operation Solve() : (ControlledRotation[], (Double[], Double)) {
        return ([ControlledRotation((0, new Int[0]), PauliY, 0)], ([PI()], 0.0));
    }
}