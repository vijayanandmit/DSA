/*
Failing hidden Input:
[1,1]
[10,8]
[[6,4,9,7,1],[5,2,2,1,3],[3,2,5,5,2]]
Output:
11
Expected: 10
*/


class Solution {
public:
    
int minimumCost(std::vector<int>& start, std::vector<int>& target, std::vector<std::vector<int>>& specialRoads) {
    int n = specialRoads.size();
    int ans = INT_MAX;

    // Check all possible paths from start to target
    for (int i = 0; i < (1 << n); i++) {
        int cost = 0;
        int x = start[0], y = start[1];
        for (int j = 0; j < n; j++) {
            int xi = specialRoads[j][0], yi = specialRoads[j][1];
            int xj = specialRoads[j][2], yj = specialRoads[j][3];
            int c = specialRoads[j][4];
            if ((i & (1 << j)) != 0) {
                cost += abs(xi - x) + abs(yi - y) + c;
                x = xj;
                y = yj;
            }
        }
        cost += abs(target[0] - x) + abs(target[1] - y);
        ans = std::min(ans, cost);
    }

    return ans;
}

};

