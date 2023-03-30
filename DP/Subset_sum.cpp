//User function template for C++

class Solution{   
public:

    bool subsequence(int ind, int target, vector<int> arr ,  vector<vector<int>> &dp)
{
    int n = arr.size();
    if(target == 0)
        return true;
        
    if(ind == n)
    {
        if(target == 0)
            return true;
        else
            return false;
    }

    if(dp[ind][target] != -1)
        return dp[ind][target];
    
    bool take = false;
    if(arr[ind] <= target)
    {
        take = subsequence(ind+1, target - arr[ind], arr ,dp);
    }

    bool not_take = subsequence(ind+1, target , arr ,dp);
    
    return dp[ind][target] = take || not_take;
}


   bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
        return subsequence(0,sum,arr, dp);

    }

};
