def calculate_maximum_sum():
    # Input: Read array size
    array_size = int(input())
    
    # Input: Read array elements
    array = list(map(int, input().split()))

    # Initialize variables
    remaining_sum = 0
    dynamic_programming = [(0, 1) for _ in range(array_size + 1)]
    dynamic_programming[array_size] = (0, 1)

    # Dynamic Programming loop to calculate maximum sum
    for i in range(array_size - 1, -1, -1):
        total, count = dynamic_programming[i + 1]
        dynamic_programming[i] = (total + array[i], count)
        dynamic_programming[i] = max(dynamic_programming[i], (total + remaining_sum + array[i], count + 1))
        remaining_sum += array[i]

    # Return the maximum sum for the current test case
    return dynamic_programming[0][0]


def main():
    # Input: Read the number of test cases
    test_cases = int(input())

    # Process each test case
    for _ in range(test_cases):
        result = calculate_maximum_sum()

        # Output: Print the result for each test case
        print(result)


if __name__ == "__main__":
    main()
