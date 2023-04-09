class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 

     
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indeg(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
             
        }
        if(count != V){
            return {};
        }
        return ans;
	}
};
