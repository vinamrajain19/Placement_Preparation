//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int dp[1000001];
	int f(int *arr,int n ,int idx){
	    if(idx >= n) return 0;
	    
	    if(dp[idx] !=-1) return dp[idx];
	    
	    int a= f(arr,n,idx+1);
	    int b = arr[idx] + f(arr,n,idx+2);
	    
	    return dp[idx] = max(a,b);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    memset(dp,-1,sizeof(dp));
	    return f(arr,n,0);
	}
};
