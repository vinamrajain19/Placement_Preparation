class Solution
{
	public:
	
	     vector<string> ans;
	     unordered_set<string> st;
	     
	     
    int f(string &s1,string &s2,int i1,int i2,vector<vector<int>> &dp){
        
        if(i1 == 0 or i2 == 0) return 0;
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(s1[i1-1] == s2[i2-1]){
            return dp[i1][i2] =  1 + f(s1,s2,i1-1,i2-1,dp);
        }
        return dp[i1][i2] =  max(f(s1,s2,i1-1,i2,dp),f(s1,s2,i1,i2-1,dp));
    }
    
    
    void f2(string &s,string &t,int i,int j,int cnt,string &temp){
        if(cnt == 0){
            if(st.find(temp) == st.end()){
                st.insert(temp);
                ans.push_back(temp);
                
            }
            return;
        }
        
        
        if(i >= s.size() or j >= t.size()) return;
        
        for(int r = i;r<s.size();r++){
            for(int c = j;c<t.size();c++){
                if(s[r] == t[c]){
                    temp.push_back(s[r]);
                    f2(s,t,r+1,c+1,cnt-1,temp);
                    temp.pop_back();
                }
            }
        }
        
        
    }
    
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
		    int ans1 = f(s,t,s.size(),t.size(),dp);
		    string temp = "";
		    f2(s,t,0,0,ans1,temp);
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		}
};
