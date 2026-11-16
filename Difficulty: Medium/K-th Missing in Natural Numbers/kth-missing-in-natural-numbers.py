class Solution:
    def findKthSmall(self, arr, k):
        # code here
        st=set()
        n=len(arr)
        for i in range(0,n):
            st.add(arr[i])

        c=0
        ans=1
        while True :
            if ans in st :
               ans+=1
            else :
                if c == k-1 :
                   return ans
                else :
                    ans+=1
                    c+=1

        return 0


