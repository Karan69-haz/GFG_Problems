class Solution:
    def longestSubseq(self, arr):
        from collections import defaultdict
        prv=defaultdict(int)
        mx=1
        for ve in arr:
            prv[ve]=max(prv[ve-1]+1,prv[ve+1]+1,1)
            mx=max(mx,prv[ve])
        return mx