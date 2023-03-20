//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int s = 0;
	    int e = n-1;
	    
	    if(arr[s] <= arr[e]) return 0;
	    
	    while(s < e){
	        int m = (s+e)/2;
	        
	        if(arr[m] >= arr[0]) s = m+1;
	        else e = m;
	    }
	    return s;
	}

};
