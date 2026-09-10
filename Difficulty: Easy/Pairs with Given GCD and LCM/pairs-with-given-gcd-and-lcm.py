class Solution:
    def pairCount(self, x, y):
        if y % x != 0:
            return 0

        n = y // x
        count = 0

        for a in range(1, n + 1):
            if n % a == 0:
                b = n // a

                if self.gcd(a, b) == 1:
                    count += 1

        return count

    def gcd(self, a, b):
        while b != 0:
            a, b = b, a % b
        return a