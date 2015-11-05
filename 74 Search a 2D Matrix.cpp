class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        vector<int> col;
        for(int i = 0; i< matrix.size(); i++) col.push_back(matrix[i][0]);

        auto itr = lower_bound(col.begin(), col.end(), target);
        if( itr != col.end() && target == *itr) return true;
        if( itr == col.begin()) return false;
        vector<int> row;
        for(int i = 0; i< matrix[0].size(); i++) row.push_back(matrix[itr - col.begin() - 1][i]);

        auto itr_row = lower_bound(row.begin(), row.end(), target);
        if(itr_row == row.end() ) return false;
        else if( * itr_row == target) return true;
        else return false;
    }
};
