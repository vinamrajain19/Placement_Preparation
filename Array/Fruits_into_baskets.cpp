int totalFruits(int N, vector<int> &f) {
        int i = 0;
        int j = 0;
        
        unordered_map<int,int> m;
        int ans = 0;
        
        while(j < N){
            m[f[j]]++;
            
                while(m.size() > 2 and i < N){
                     m[f[i]]--;
                     if(m[f[i]] == 0) m.erase(f[i]);
                     i++;
                }
                
                ans = max(ans,j-i+1);
        
            j++;
        }
        
        return ans;
    }
