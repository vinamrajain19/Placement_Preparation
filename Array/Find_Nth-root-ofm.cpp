class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	    long long s = 1;
	    long long e = 1e6;
	    
	    while(s <= e){
	        long long mid = s+(e-s)/2;
	        
	        if(pow(mid,n) == m) return mid;
	        
	        else if(pow(mid,n) < m) s= mid +1;
	        else e = mid-1;
	    }
	    
	    return -1;
	}  
};
