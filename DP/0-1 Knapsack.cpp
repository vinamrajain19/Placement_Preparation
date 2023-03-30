class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int help(int W,int wt[],int val[],int n,int idx,vector<vector<int>> &dp){
        if(W == 0) return 0;
        
        if(idx == 0){
            if(wt[0] <= W){
                return dp[idx][W] = val[0];
            }
            return 0;
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        if(wt[idx] <= W){
            return max(val[idx] + help(W-wt[idx],wt,val,n,idx-1,dp) , help(W,wt,val,n,idx-1,dp));
        }
        return dp[idx][W] = help(W,wt,val,n,idx-1,dp);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return help(W,wt,val,n,n-1,dp);
    }
};
