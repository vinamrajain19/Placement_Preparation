

 // We will do a binary search in one of the arrays which have a minimum size among the two. 

 // Firstly, calculate the median position with (n+1)/2. Point two-pointer, say low and high, equal to 0 and size of the array on which we are applying binary search respectively. Find the partition of the array. Check if the left half has a total number of elements equal to the median position. If not, get the remaining elements from the second array. Now, check if partitioning is valid. This is only when l1<=r2 and l2<=r1. If valid, return max(l1,l2)(when odd number of elements present) else return (max(l1,l2)+min(r1,r2))/2.

// If partitioning is not valid, move ranges. When l1>r2, move left and perform the above operations again. When l2>r2, move right and perform the above operations.


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int s = 0;
        int e = n1;
        
        
        while(s <= e){
            int cut1 = (s+e)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            
            int l1 = cut1 == 0 ? -1e9 : nums1[cut1-1];
            int l2 = cut2 == 0 ? -1e9 : nums2[cut2-1];
            int r1 = cut1 == n1 ? 1e9 : nums1[cut1];
            int r2  = cut2 == n2 ? 1e9 : nums2[cut2];
            
            if(l1 <= r2 and l2 <= r1){
                if((n1+n2) % 2 == 0) {
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                }
                else return max(l1,l2);
            }
            else if(l1 > r2){
                e = cut1-1;
            }
            else s = cut1+1;
        }
        
        return 0.0;
        
        
    }
};
