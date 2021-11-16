class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool arr[10];
        for(int i=0; i<9; i++){
            fill(arr, arr+10, false);
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                if(arr[board[i][j]-'0']){
                    return false;
                }
                else{
                    arr[board[i][j]-'0'] = true;
                }
            }
            fill(arr, arr+10, false);
            for(int j=0; j<9; j++){
                if(board[j][i]=='.') continue;
                if(arr[board[j][i]-'0']){
                    return false;
                }
                else{
                    arr[board[j][i]-'0'] = true;
                }
            }
        }
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                fill(arr, arr+10, false);
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(board[i+k][j+l]=='.') continue;
                        if(arr[board[i+k][j+l]-'0']){
                            return false;
                        }
                        else{
                            arr[board[i+k][j+l]-'0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};