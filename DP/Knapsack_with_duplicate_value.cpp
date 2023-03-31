// User function Template for C++

class Solution{
public:

   int dp[1001][1001];

    int f(int N,int W,int val[],int wt[],int idx){
       if(W < 0) return -1e9;
       
       //if(W == 0) return 0;
       
       if(idx == N-1){
           if(W >= wt[idx]) return (val[idx] * (W/wt[idx]));
           return 0;
       }
       
       if(dp[idx][W] !=  -1) return dp[idx][W];
       
       int ans = -1e9;
       
       if(W >= wt[idx]){
           ans = max(ans,val[idx] + f(N,W-wt[idx],val,wt,idx));
       }
       
       ans = max(ans,f(N,W,val,wt,idx+1));
       
       return dp[idx][W] =  ans;
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int ans = f(N,W,val,wt,0);
        
        //if(ans <= -1e9) return 0;
        return ans;
        
    }
};
