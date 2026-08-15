class Solution {
    int memo[20][2][2];
    string digits;
    int d;

    int countDigitFree(int pos, bool tight, bool started) {
        if (pos == digits.size()) {
            return started ? 1 : 0;
        }

        int &ans = memo[pos][tight][started];
        if (ans != -1) return ans;

        int limit = tight ? digits[pos] - '0' : 9;
        ans = 0;

        for (int digit = 0; digit <= limit; digit++) {
            bool newTight = tight && (digit == digits[pos] - '0');

            if (!started && digit == 0) {
                ans += countDigitFree(pos + 1, newTight, false);
            }
            else if (digit != d) {
                ans += countDigitFree(pos + 1, newTight, true);
            }
        }

        return ans;
    }

public:
    int countWithout(int n, int digit) {
        if (n == 0) return 0;

        digits = to_string(n);
        d = digit;

        memset(memo, -1, sizeof(memo));

        return countDigitFree(0, true, false);
    }
};