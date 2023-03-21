//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool f(int A[],int M,int N,int m){
        int sum = 0;
        int grp = 1;
        for(int i = 0;i<N;i++){
            if(sum + A[i] <= m){
                sum += A[i];
            }
            else{
                grp++;
                if(grp > M or A[i] > m) return false;
                sum = A[i];
            }
        }
        
        return true;
    }
    
    
    int findPages(int A[], int N, int M) 
    {
        if(M > N) return -1;
        
        int sum = 0;
        for(int i = 0;i<N;i++){
            sum += A[i];
        }
        
        int s = 0;
        int e = sum;
        
        int ans = -1;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(f(A,M,N,m)){
                ans = m;
                e = m-1;
            }
            else s = m+1;
        }
        
        return ans;
    }
};
