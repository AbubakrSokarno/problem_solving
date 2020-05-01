// Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3302/

class Solution {
public:
    int W , H ;
    int result = 0 ;
    bool valid(int i , int j) {
        return i >= 0 && j >= 0 && j < W && i < H ;
    }

    int dx[8] = {0,0,1,-1} ;
    int dy[8] = {1,-1,0,0} ;

    void dfs(int i , int j, vector<vector<bool>>& seen, vector<vector<char>>& grid) {
        if(seen[i][j])
            return ;

        seen[i][j] = 1 ;

        for( int x = 0 ; x < 4 ; x++) {
            int xx = dx[x] + i ;
            int yy = dy[x] + j ;
            if( valid(xx,yy) && ! seen[xx][yy] && grid[xx][yy] == '1' )
                dfs(xx,yy,seen,grid) ;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0 ;
        W = grid[0].size();
        H = grid.size() ;
        vector<vector<bool>> vis(H, vector<bool>(W)) ;
        for( int i = 0 ; i < H ; i++ ) {
            for( int j = 0 ; j < W ; j++ ) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i,j,vis,grid);
                    result++ ;
                }
            }
        }
        return result ;
    }
};
