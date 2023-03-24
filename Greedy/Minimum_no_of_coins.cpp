// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> v = {2000,500,200,100,50,20,10,5,2,1};
        
        vector<int> ans;
        
        int i = 0;
        
        while(N){
            if(N >= v[i]){
                ans.push_back(v[i]);
                N-= v[i];
            }
            else i++;
        }
        
        return ans;
    }
};
