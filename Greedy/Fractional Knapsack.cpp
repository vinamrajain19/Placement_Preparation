//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({(double)arr[i].value/arr[i].weight,arr[i].weight});
            
        }
        sort(v.begin(),v.end());
        double profit = 0.0;
        
        int i = n-1;
        while(W){
            if(W >= v[i].second){
                profit += v[i].first * v[i].second;
                W -= v[i].second;
            }
            else{
                profit += v[i].first * W;
                break;
            }
            i--;
        }
        return profit;
    
    }
        
};
