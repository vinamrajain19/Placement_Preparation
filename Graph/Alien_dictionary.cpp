// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            
            int n=min(s1.size(),s2.size());
            for(int i=0;i<n;i++){
                if(s1[i]!=s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        
        vector<int>ind(K,0);
        queue<int>q;
        
        for(int i=0;i<K;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        
        for(int i=0;i<K;i++){
            if(ind[i]==0) q.push(i);
        }
        
        vector<int>tpo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            tpo.push_back(node);
            
            for(auto child:adj[node]){
                ind[child]--;
                if(ind[child]==0) q.push(child);
            }
        }
        
        string ans="";
        
        for(auto it:tpo){
            ans.push_back(char(it+'a'));
        }
        return ans;
    }
};
