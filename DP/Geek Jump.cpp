class Solution {
  public:
  
     int dp[100001];
    int f(vector<int> &h,int n,int idx){
        if(idx >= n) return 1e9;
        
        if(idx == n-1) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int a = 1e9;
        int b = 1e9;
        
        if(idx+1 < n){
            a = abs(h[idx] - h[idx+1]) + f(h,n,idx+1);
        }
        if(idx+2 < n){
            b = abs(h[idx] - h[idx+2]) + f(h,n,idx+2);
        }
        
        return dp[idx] = min(a,b);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return f(height,n,0);
    }
};
