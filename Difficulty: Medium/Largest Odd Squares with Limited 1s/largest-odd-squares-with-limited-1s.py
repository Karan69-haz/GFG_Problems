class Solution:
    def largestSquare(self, mat, queries, k):
        n, m = len(mat), len(mat[0])
        
        # Step 1: Build prefix sum
        pref = [[0]*(m+1) for _ in range(n+1)]
        for i in range(n):
            for j in range(m):
                pref[i+1][j+1] = mat[i][j] + pref[i][j+1] + pref[i+1][j] - pref[i][j]
        
        def get_ones(r1, c1, r2, c2):
            return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]
        
        # Step 2: Answer queries
        ans = []
        for i, j in queries:
            best = -1
            side = 1
            while True:
                half = side // 2
                r1, r2 = i - half, i + half
                c1, c2 = j - half, j + half
                if r1 < 0 or c1 < 0 or r2 >= n or c2 >= m:
                    break
                ones = get_ones(r1, c1, r2, c2)
                if ones <= k:
                    best = side
                    side += 2
                else:
                    break
            ans.append(best)
        return ans

