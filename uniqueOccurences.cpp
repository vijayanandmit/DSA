class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool ans = false;
        vector<int> occ;
        unordered_set<int> unique;
        unordered_map<int,int> freq;

        for(int a : arr) {
            freq[a]++;
        }

        for(auto u: freq) {
            unique.insert(u.second);
            cout << u.first << " " << u.second <<endl;
        }

        ans = unique.size() == freq.size();
        return ans;
    }
};
