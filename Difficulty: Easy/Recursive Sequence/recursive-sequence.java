class Solution {
    static final long mod=1000000007;

    static long helper(int i,int n,long curr){
        if(i>n)return 0;
        long product=1;

       for(int j=0;j<i;j++){
           product=(product*curr)%mod;
           curr++;

       } 

        long next=helper(i+1,n,curr);
        return  (product+next)%mod;

    }
    static long sequence(int n) {
        // code here

        return helper(1,n,1);
    }
}
