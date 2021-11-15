class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> temp;
        temp.push_back(1);
        v.push_back(temp);
        if(numRows==1){
            return v;
        }
        temp.push_back(1);
        v.push_back(temp);
        if(numRows==2){
            return v;
        }
        for(int i=3; i<=numRows; i++){
            temp.clear();
            temp.push_back(1);
            for(int j=1; j<i-1; j++){
                temp.push_back(v[i-2][j-1]+v[i-2][j]);
            }
            temp.push_back(1);
            v.push_back(temp);
        }
        return v;
    }
};