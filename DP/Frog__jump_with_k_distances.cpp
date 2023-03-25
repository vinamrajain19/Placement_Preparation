class Solution {
  public:
    
    int dp[100001];
    int f(vector<int> &h,int n,int k,int idx){
        if(idx == n-1) return 0;
        //if(idx >= n) return 1e9;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ans = INT_MAX;
        for(int i = 1;i<=k;i++){
            
            if(idx+i<n){
                 int temp = abs(h[idx] - h[idx+i]) + f(h,n,k,idx+i);
                ans = min(ans,temp);
            }
        }
        
        return dp[idx]= ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return f(height,n,k,0);
    }
};
