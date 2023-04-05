class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool f(int node,vector<int> &vis,vector<int> adj[],int par){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it] == 0){
                if(f(it,vis,adj,node)) return true;
            }
            else if(par != it){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        for(int i = 0;i<V;i++){
            if(vis[i] == 0){
                if(f(i,vis,adj,-1)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
