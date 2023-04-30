//https://leetcode.com/contest/weekly-contest-343/submissions/detail/941853098/
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        long v = 100001; 
        int startX = start[0], startY = start[1], targetX = target[0], targetY = target[1]; 
        unordered_map<long, vector<pair<long, int>>> mp = {{target[0]*v + target[1], {{0, 0}}}}; 
        for (auto& x : specialRoads) {
            mp[x[0]*v + x[1]].emplace_back(x[2]*v+x[3], x[4]); 
            
        }
        unordered_map<long, int> dist; 
        dist[start[0]*v + start[1]] = 0; 
        priority_queue<pair<int, long>, vector<pair<int, long>>, greater<>> pq; 
        pq.emplace(0, start[0]*v + start[1]); 
        while (pq.size()) {
            auto [d, x] = pq.top(); pq.pop(); 
            if (x == target[0]*v + target[1]) return d; 
            for (auto& [xx, cost] : mp[x]) {
                if (!dist.count(xx) || d+cost < dist[xx]) {
                    dist[xx] = d + cost; 
                    pq.emplace(d+cost, xx); 
                }
            }
            for (auto& [xx, _] : mp) {
                int dd = d + abs(xx%v - x%v) + abs(xx/v - x/v); 
                if (!dist.count(xx) || dd < dist[xx]) {
                    dist[xx] = dd; 
                    pq.emplace(dd, xx); 
                }
            }
        }
        return -1; 
    }
};

/*
This is a solution to the problem of finding the minimum cost required to go from a given start point to a target point, taking into account the costs of traveling between points and the costs of using 
special roads that can be used multiple times. 

- The function takes as input the start point (as a vector of 2 integers), the target point (as a vector of 2 integers), and a 2D vector of special roads (each represented as a vector of 5 integers, 
specifying the start point, end point, and cost).
- The variable `v` is set to 100001, which is used later to convert the 2D coordinates into a unique 1D value for indexing in the unordered_map `mp`.
- The x and y coordinates of the start and target points are extracted from the input vectors.
- The unordered_map `mp` is initialized with the target point as the only key-value pair, where the key is the 1D coordinate value of the target point, and the value is a vector of pairs, each 
representing a special road from that key to another key, with the cost of using that road.
- The unordered_map `dist` is initialized with the start point as the only key-value pair, where the key is the 1D coordinate value of the start point, and the value is 0 (since the cost of getting to 
the start point is 0).
- A priority queue `pq` is initialized with the start point and its distance from the start point (which is 0).
- The while loop runs until the priority queue is empty.
- In each iteration of the while loop, the element with the smallest distance from the start point is removed from the priority queue.
- If the removed element is the target point, then the function returns the distance of that element from the start point (which is the minimum cost required to reach the target point).
- Otherwise, for each special road starting from the removed element, if the cost of using that road plus the distance from the start point to the removed element is less than the current distance of 
the end point of that road from the start point (or if the end point has not been visited before), then the distance of the end point from the start point is updated to the cost of using that road plus 
the distance from the start point to the removed element, and the end point is added to the priority queue with its new distance.
- For each point in `mp`, if the distance from the start point to that point via the removed element is less than the current distance of that point from the start point (or if that point has not been 
visited before), then the distance of that point from the start point is updated to the new distance, and that point is added to the priority queue with its new distance.
- If the target point is not reached by the end of the while loop, the function returns -1 (indicating that it is not possible to reach the target point).
*/
