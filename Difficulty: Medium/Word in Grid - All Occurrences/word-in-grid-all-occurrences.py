class Solution:
    def searchWord(self, mat, word):
        n = len(mat)
        m = len(mat[0])

        # 8 possible directions
        directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),           (0, 1),
            (1, -1),  (1, 0),  (1, 1)
        ]

        ans = []

        for r in range(n):
            for c in range(m):

                # Starting character must match
                if mat[r][c] != word[0]:
                    continue

                # Try all 8 directions
                for dr, dc in directions:
                    k = 1
                    nr = r + dr
                    nc = c + dc

                    while k < len(word):
                        # Check boundary and character
                        if (nr < 0 or nr >= n or
                            nc < 0 or nc >= m or
                            mat[nr][nc] != word[k]):
                            break

                        nr += dr
                        nc += dc
                        k += 1

                    # Entire word found
                    if k == len(word):
                        ans.append([r, c])
                        break

        return ans