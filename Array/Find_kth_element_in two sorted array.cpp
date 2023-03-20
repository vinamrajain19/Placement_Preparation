class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       int i = 0;
       int j = 0;
       int z  = 0;
       
       while( i< n and j < m){
           if(arr1[i] <= arr2[j]){
               i++ ,z++;
               if(z == k) return arr1[i-1];
           }
           else{
               j++,z++;
               if(z== k) return arr2[j-1];
           }
       }
       
       while(i<n){
           i++;
           z++;
           if(z == k) return arr1[i-1];
       }
       
       while(j<m){
           j++;
           z++;
           if(z == k) return arr2[j-1];
       }
       
       return -1;
       
    } 
};
