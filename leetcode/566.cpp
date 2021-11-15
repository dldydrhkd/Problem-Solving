class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int cnt = 0;
        vector<int> v;
        vector<vector<int>> answer;
        if(mat.size()*mat[0].size()!=r*c){
            return mat;
        }
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                v.push_back(mat[i][j]);
                cnt++;
                if(cnt==c){
                    answer.push_back(v);
                    v.clear();
                    cnt = 0;
                }
            }
        }
        return answer;
    }
};