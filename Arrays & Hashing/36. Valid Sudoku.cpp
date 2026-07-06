class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9]={0};
        int used2[9][9]={0};
        int used3[9][9]={0};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.')continue;
                int num= board[i][j]-'0';
                int k=(i/3)*3+(j/3);
                if(used1[i][num-1] || used2[j][num-1] || used3[k][num-1]){
                    return false;
                }
                used1[i][num-1]=used2[j][num-1]=used3[k][num-1]=1;
            }
        }
        return true;
    }
};
