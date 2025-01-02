#include <bits/stdc++.h>
using namespace std;

#define int long long

int calculateMaximumSum()
{
    // Input: Read array size
    int arraySize;
    cin >> arraySize;

    // Input: Read array elements
    vector<int> array(arraySize);
    for (int i = 0; i < arraySize; ++i)
    {
        cin >> array[i];
    }

    // Initialize variables
    int remainingSum = 0;
    vector<pair<int, int>> dynamicProgramming(arraySize + 1, make_pair(0, 1));
    dynamicProgramming[arraySize] = make_pair(0, 1);

    // Dynamic Programming loop to calculate maximum sum
    for (int i = arraySize - 1; i >= 0; --i)
    {
        int total = dynamicProgramming[i + 1].first;
        int count = dynamicProgramming[i + 1].second;
        dynamicProgramming[i] = make_pair(total + array[i], count);
        dynamicProgramming[i] = max(dynamicProgramming[i], make_pair(total + remainingSum + array[i], count + 1));
        remainingSum += array[i];
    }

    // Return the maximum sum for the current test case
    return dynamicProgramming[0].first;
}

int32_t main()
{
    // Input: Read the number of test cases
    int testCases;
    cin >> testCases;

    // Process each test case
    for (int i = 0; i < testCases; ++i)
    {
        int result = calculateMaximumSum();

        // Output: Print the result for each test case
        cout << result << endl;
    }

    return 0;
}
