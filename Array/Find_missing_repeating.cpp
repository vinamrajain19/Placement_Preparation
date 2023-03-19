class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int i = 0;
        
        while(i < n){
            int c = arr[i] - 1;
            
            if(c < n and arr[c] != arr[i]){
                swap(arr[c],arr[i]);
            }
            else i++;
        }
        
        int miss = -1;
        int rep = -1;
        
        for(int j = 0;j<n;j++){
            if(j+1 != arr[j]){
                miss = j+1;
                rep = arr[j];
                break;
            }
        }
        
        int *ans=new int[2];
        ans[0] = rep;
        ans[1] = miss;
        return ans;
    }
};
