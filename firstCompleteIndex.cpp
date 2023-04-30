/*

[1,3,4,2]
[[1,4],[2,3]]
[2,8,7,4,1,3,5,6,9]
[[3,2,5],[1,4,6],[8,7,9]]



*/
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rows(m), cols(n);
        int painted = 0;

        for (int i = 0; i < arr.size(); i++) {
            int x = (arr[i] - 1) / n, y = (arr[i] - 1) % n;
            rows[x]++;
            cols[y]++;
            if (rows[x] == m) painted++;
            if (cols[y] == n) painted++;
            if (painted > 0) return i;
        }

        return -1;
        
    }
};
