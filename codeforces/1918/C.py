# Created Date: Thursday, June 10th 2021, 10:56:57 pm
import sys
import math
from collections import Counter, defaultdict, deque
from itertools import combinations, permutations

input = sys.stdin.readline

class XORCalculator:
    def __init__(self, n1, n2, r):
        self.n1 = n1
        self.n2 = n2
        self.r = r

    def swap_values(self):
        if self.n1 > self.n2:
            self.n1 ^= self.n2
            self.n2 ^= self.n1
            self.n1 ^= self.n2

    def calculate_xor_result(self):
        return self.n2 - self.n1

    def calculate_x(self):
        x = 0
        ans = self.calculate_xor_result()

        for i in range(120, -1, -1):
            if (self.n1 ^ self.n2) >> i & 1:
                if x + (1 << i) <= self.r:
                    if (self.n1 >> i) & 1 == 0:
                        if 1 << (i + 1) <= ans:
                            x += (1 << i)
                            ans -= (1 << (i + 1))

        return ans

    def calculate_and_print_result(self):
        self.swap_values()
        result = self.calculate_x()
        print(result)

def main():
    t = int(input())

    for _ in range(t):
        n1, n2, r = map(int, input().split())
        xor_calculator = XORCalculator(n1, n2, r)
        xor_calculator.calculate_and_print_result()

if __name__ == "__main__":
    main()
