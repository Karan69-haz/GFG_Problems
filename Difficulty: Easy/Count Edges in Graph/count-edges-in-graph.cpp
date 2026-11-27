class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        int edgesCnt = 0;
        for (auto nodes : adj) {
            edgesCnt += nodes.size();
        }
        return edgesCnt >> 1;
        
    
        
    }
};