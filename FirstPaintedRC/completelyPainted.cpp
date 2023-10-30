//https://leetcode.com/contest/weekly-contest-343/submissions/detail/941843655/
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(); 

        // Construct a vector of pairs representing the (i, j) coordinates
        // of each element in mat.
        vector<pair<int, int>> loc(m * n); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                loc[mat[i][j]-1] = make_pair(i, j); 
            }
        }

        // Initialize vectors r and c to keep track of how many elements
        // have been painted in each row and column, respectively.
        vector<int> r(m), c(n); 

        // Iterate through the elements in arr, and for each element, increment
        // the corresponding row and column counts in r and c, respectively.
        // If either the row or column count reaches the size of the matrix, return
        // the current index.
        for (int x = 0; x < arr.size(); ++x) {
            auto [i, j] = loc[arr[x]-1]; 
            if (++r[i] == n) return x; 
            if (++c[j] == m) return x; 
        }

        // If no row or column is completely painted, return -1.
        return -1;
    }
};

