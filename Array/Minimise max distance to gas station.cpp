class Solution {
  public:
  
    bool f(vector<int> &st,int K,double mid){
        int cnt= 0;
        double dis = 0.0;
        for(int i =1;i<st.size();i++){
            
            int temp = st[i] - st[i-1];

            dis = (double)temp/mid;

            cnt += (int(dis));
        }
        
        if(cnt <= K) return true;
        return false;
    }
    
    double findSmallestMaxDist(vector<int> &st, int K){
      // Code here
      int n = st.size();
      double s = 0;
      double e = st[n-1] - st[0];
      
      double ans = 0.0;
      
      while(e - s > 1e-6){
          double m = (s+e)/2.0;
          
          if(f(st,K,m)){
              ans = m;
              e = m;
          }
          else s  = m;
      }
      
      return ans;
    }
};
