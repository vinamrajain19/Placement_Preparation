// User function Template for C++

class Solution {
public:

    bool f(int n,int k,vector<int> &st,int mid){
        int cows = 1;
        
        int last  = st[0];
        
        for(int i = 1;i<n;i++){
            if(st[i] - last >= mid){
                cows++;
                last = st[i];
            }
        }
        
        return cows >= k;
    }

    int solve(int n, int k, vector<int> &st) {
    
        // Write your code here\
        
        sort(begin(st),end(st));
        
        int s = 0;
        
        int e = st[n-1] - st[0];
        
        int ans = -1;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(f(n,k,st,m)){
                ans = m;
                s = m+1;
            }
            else e = m-1;
        }
        
        return ans;
    }
};
