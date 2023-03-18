/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> m;
        
        int sum = 0;
        int ans = 0;
        
        for(int i= 0;i<n;i++){
            sum += A[i];
            if(sum == 0){
                ans = max(ans,i+1);
            }
            
            
            if(m.find(sum) != m.end()){
                ans = max(ans,i - m[sum]);
            }
            else  m[sum] = i;
        }
        
        return ans;
    }
};
