class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int dp[10001];
    int f(int arr[],int n ,int i){
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int take = arr[i] + f(arr,n,i+2);
        int no = f(arr,n,i+1);
        
        return dp[i] =  max(no,take);
    }
    int FindMaxSum(int arr[], int n)
    {
        memset(dp,-1,sizeof(dp));
        return f(arr,n,0);
    }
};
