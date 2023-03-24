class Solution {
public:
    int jump(vector<int>& nums) {
        int can = 0;
        int  ans = 0;
        
        int last = 0;
        
        for(int i = 0;i<nums.size();i++){
            can = max(can, i+nums[i]);
            
            if(i >= nums.size()-1) break;
            
            if(i == last){
                ans++;
                last = can;
            }
        }
        
        return ans;
    }
};
