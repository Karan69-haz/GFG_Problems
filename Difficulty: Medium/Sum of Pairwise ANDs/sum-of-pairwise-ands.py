class Solution:
    def pairAndSum(self, arr):
        ret=pl=0
        while 1:
            cnt=0
            notdone=False
            for ix,n in enumerate(arr):
                cnt+=n&1
                n>>=1
                arr[ix]=n
                notdone=notdone or n>0
            ret+=cnt*(cnt-1)//2*(1<<pl)
            pl+=1
            if not notdone:
                return ret