class Solution {
    public boolean checkPath(ArrayList<ArrayList<Integer>> adj, int u, int v) {
        // code here
        int n = adj.size() ;
        boolean isVisited[] = new boolean[n] ;
        for( int i = 0 ; i < n ; i++){
            if( !isVisited[i]){
                dfs(i , adj , isVisited ) ;
                if( isVisited[u]!=isVisited[v]) return false;
            }
        }
        return true ;

    }
    public void dfs( int i ,ArrayList<ArrayList<Integer>> adj ,  boolean isVisited[] ){
        isVisited[i] = true ;
        for( int neigh : adj.get(i)){
            if( !isVisited[neigh]) dfs(neigh , adj , isVisited) ;
        }
    }
}
