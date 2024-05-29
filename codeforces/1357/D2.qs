namespace Solution {
 open Microsoft.Quantum.Math;
 open Microsoft.Quantum.MachineLearning;
     operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
  return ((1, [7.4]), [ControlledRotation((1, new Int[0]), PauliY, 0)], ([0.0], 0.49));
    }
}