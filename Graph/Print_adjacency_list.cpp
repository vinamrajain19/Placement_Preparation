class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> ans;
        
        for(int i = 0;i<V;i++){
            vector<int> t;
            t.push_back(i);
            for(auto it : adj[i]){
                t.push_back(it);
            }
            ans.push_back(t);
        }
        
        return ans;
    }
};
