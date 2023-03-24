class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int ans = 1;
        int last = v[0][1];
        
        for(int i = 1;i<n;i++){
            if(v[i][0] > last){
                ans++;
                last = v[i][1];
            }
        }
        
        return ans;
    }
};
