class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    
    void f(int node,vector<int> adj[],vector<int> &vis){
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(vis[it]  == 0){
                vis[it] = 1;
                f(it,adj,vis);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vis[0]  =1;
        f(0,adj,vis);
        return ans;
    }
};
