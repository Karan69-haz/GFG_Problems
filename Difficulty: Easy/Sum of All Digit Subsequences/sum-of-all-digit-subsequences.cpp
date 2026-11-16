class Solution {
  public:
    int subsequenceSum(string &s) {
        // code here
        int mod = 1e9 + 7;
        int n = s.size();
        long long p = 1;
        long long sum = 0;
        for(int i=0;i<n;i++)sum+=(s[i]-'0');
        for(int i=0;i<n-1;i++) p = ((p*2)%mod);
        return (sum*p)%mod;
    }
};
