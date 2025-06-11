class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {      
        int track[9]={0};

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int cur = (board[i][j]-'1');
                track[cur]+=1;
                if(track[cur]>1 ) return false;
            }

            fill(begin(track),end(track),0);
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i] =='.') continue;
                int cur = (board[j][i]-'1');
                track[cur]++;
                if(track[cur]>1 ) return false;
            }

            fill(begin(track),end(track),0);
        }

        for(int boxrow=0 ; boxrow<3 ;boxrow++){
            for(int boxcol=0 ; boxcol<3 ; boxcol++){
                
                fill(begin(track),end(track),0);

                for(int i=0; i<3; i++){
                    for(int j=0;j<3; j++){
                        int row = boxrow*3 + i;
                        int col = boxcol*3 + j;
                        
                        if(board[row][col]=='.') continue;
                        int cur = board[row][col] - '1';
                        track[cur]++;
                        if(track[cur]>1 ) return false;
                    }
                }
            }
        }



        return true;
    }
};