def process_queries(n, q, original_values, queries):
    # Initialize an array to store current values
    current_values = [0] * (n + 1)

    # Copy original values to current values array
    for i in range(1, 1 + n):
        current_values[i] = original_values[i - 1]

    results = []  # List to store results of queries

    for remaining_operations in queries:
        result = 0
        current_state = current_values.copy()

        # Iterate through bits from most significant to least significant
        for j in range(60, -1, -1):
            operations_used = 0
            temp_state = current_state.copy()

            # Iterate through elements in the array
            for i in range(1, n + 1):
                # Check if the jth bit is not set in the current element
                if not ((current_state[i] >> j) & 1):
                    previous_value = current_state[i]
                    current_state[i] += (1 << j)
                    current_state[i] //= (1 << j)
                    current_state[i] *= (1 << j)
                    operations_used += (current_state[i] - previous_value)

                    # Break if the number of operations exceeds the remaining limit
                    if operations_used > remaining_operations:
                        break

            # If operations are within the limit, update result and remaining operations
            if operations_used <= remaining_operations:
                remaining_operations -= operations_used
                result += (1 << j)
            else:
                current_state = temp_state.copy()

        results.append(result)

    return results


def main():
    # Input number of elements and queries
    n, q = map(int, input().split())

    # Input the original values array
    original_values = list(map(int, input().split()))

    # Input queries and store them in a list
    queries = [int(input()) for _ in range(q)]

    # Process queries and get the results
    results = process_queries(n, q, original_values, queries)

    # Output the results
    for result in results:
        print(result)


if __name__ == "__main__":
    main()
