class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int> fMap;int n = arr.size();
        for(int n:arr)
            fMap[n]++;
        for(auto& kv : fMap) {
            if(kv.second > n/4)
                return kv.first;
        }
        return -1;

    }
};
