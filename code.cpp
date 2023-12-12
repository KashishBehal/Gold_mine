class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
       for(int col=m-2;col>=0;col--){
           for(int row=0;row<n;row++){
               int right= M[row][col+1];
               int right_up=(row==0)?0:M[row-1][col+1];
               int right_down=(row==n-1)?0:M[row+1][col+1];
               M[row][col]=M[row][col]+max(right  , max( right_up , right_down));
           }
       }
       int ans=M[0][0];
       for(int i=0;i<n;i++){
           ans=max(ans , M[i][0]);
       }
       return ans;
    }
};
