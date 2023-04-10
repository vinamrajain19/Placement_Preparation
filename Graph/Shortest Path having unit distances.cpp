// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> ans(N,1e9);
        
        vector<int> adj[N];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        ans[src] = 0;
        pq.push({0,src});
        
        while(pq.size()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                if(1 + ans[node] < ans[it]){
                    ans[it] = 1 + ans[node];
                    pq.push({ans[it],it});
                }
            }
        }
        
        for(int i = 0;i<N;i++){
            if(ans[i] == 1e9) ans[i] = -1;
        }
        
        return ans;
    }
};
