class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mn = prices[0];
        for(int i = 1;i<prices.size();i++){
            mn = min(mn,prices[i]);
            int profit = prices[i] - mn;
            ans = max(ans,profit);
        }

        return ans;
    }
};
