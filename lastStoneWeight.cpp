class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int lWeight = 0;
        while(stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int a = stones.back();
            stones.pop_back();
            int b = stones.back();
            stones.pop_back();
            if(a == b)  {
                continue;
            }
            else if(a>b)
                //difference should be inserted, and sorted
                stones.push_back(a-b);
            else
                stones.push_back(b-a);
        }

        return stones.size() ? stones[0]:0;
    }
};
