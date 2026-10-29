class Solution {
    public int minComputation(int[] files) {
        // code here
        int n=files.length;
        PriorityQueue<Integer>pq=new PriorityQueue<>();
        for(int i=0;i<n;i++)
        {
            pq.add(files[i]);
        }
        int ans=0;
        while(pq.size()>1)
        {
            int x=pq.remove();
            int y=pq.remove();

            ans+=x+y;
            pq.add(x+y);
        }
        return ans;
    }
}

