class Solution {
    Integer[] dp;
    int n;
    public int solve(String s , int i){
        if(i >= n){
            return 0;
        }
        if(dp[i] != null){
            return dp[i];
        }
        //No toggle  
        int maxWeight = 0;
        maxWeight = Math.max(maxWeight , 1 + solve(s , i+1));

        if(i + 1 < n){
            //AB or BA 
            if(s.charAt(i) != s.charAt(i+1)){
                maxWeight = Math.max(maxWeight , 4+solve(s , i+2));
            }
            //AA or BB
            if(s.charAt(i) == s.charAt(i+1)){
                maxWeight = Math.max(maxWeight , 3+solve(s , i+2));
            }
        }
        return dp[i] = maxWeight;
    }
    public int getMaxWeight(String s) {
        // code here
        n = s.length();
        dp = new Integer[n];
        return solve(s , 0);
    }
}

