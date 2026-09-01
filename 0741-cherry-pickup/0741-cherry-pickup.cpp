class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n,INT_MIN)));
        dp[0][0][0]=grid[0][0];
        for(int r1=0;r1<n;r1++){
            for(int c1=0;c1<n;c1++){
                for(int r2=0;r2<n;r2++){
                    int c2=r1+c1-r2;
                    if(c2<0 || c2>=n){continue;}
                    if(grid[r1][c1]==-1 || grid[r2][c2]==-1){continue;}
                    if(r1==0 && c1==0 && r2==0){continue;}
                    
                    int curr;
                    if(r1==r2 && c1==c2){curr=grid[r1][c1];}
                    else{curr=grid[r1][c1]+grid[r2][c2];}

                    int maxi=INT_MIN;
                    if(r1>0 && r2>0){maxi=max(maxi,dp[r1-1][c1][r2-1]);}
                    if(r1>0 && c2>0){maxi=max(maxi,dp[r1-1][c1][r2]);}
                    if(c1>0 && c2>0){maxi=max(maxi,dp[r1][c1-1][r2]);}
                    if(c1>0 && r2>0){maxi=max(maxi,dp[r1][c1-1][r2-1]);}
                    dp[r1][c1][r2]=maxi+curr;
                }
            }
        }
        if(dp[n-1][n-1][n-1]<0){return 0;}
        return dp[n-1][n-1][n-1];
    }
};