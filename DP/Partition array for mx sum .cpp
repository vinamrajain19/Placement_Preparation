class Solution {
public:
    
    int dp[501];
    
    int f(vector<int> &arr,int k,int idx){
        
        if(idx == arr.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ans = 0;
        int mx = 0;
        int cnt = 0;
        
        
        int x = min(idx+k,(int)arr.size());
        
        for(int j= idx;j < x;j++){
            cnt++;
            mx = max(mx,arr[j]);
            
            int temp = (mx*cnt) + f(arr,k,j+1);
            ans = max(ans,temp);
        }
        
        return dp[idx] =  ans;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return f(arr,k,0);
    }
};
