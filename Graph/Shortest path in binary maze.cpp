class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 or grid[n-1][n-1]) return -1;
           
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1}};
        
        q.push({0,0});
        vis[0][0] = 1;
        
        int ans = 1;
        
        while(q.size()){
            
            int t = q.size();
            
            while(t--){
                int x = q.front().first;
                int y = q.front().second;
                
                if(x == n-1 and y == n-1) return ans;

                q.pop();

                for(auto it : dir){
                    int nx = x + it[0];
                    int ny = y + it[1];

                    if(nx < 0 or ny < 0 or nx >= n or ny >= n or vis[nx][ny] == 1 or grid[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }   
            
            ans++;
            
        }
        
        return -1;
    }
};
