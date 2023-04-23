class Solution {
public:
    /* 
    The key is to find at least one 1 in th the nums, once 
found then other can be made 1 with n -1 operations.
Need to find the smallest subarray whose gcd is 1.
For this, with greedy approach we will check each sub array 
and evaluate gcd.

Corner case : if there is already x no. of 1s in the array, 
then simply needed n-x no of operation. */

    int minOperations(vector<int>& nums) {
        int t = INT_MAX, c = 0, n = nums.size();

        c = count(nums.begin(), nums.end(), 1);
        
        if(c > 0) { return nums.size() - c; }

        for(int i = 0; i<nums.size(); ++i ){
            int last = nums[i];
            for(int j = i+1; j < nums.size(); ++j ){
                last = __gcd(last, nums[j]);
                if(last == 1) { t = min(t, j-i); break; }
            }
        }
        
        if(t != INT_MAX) 
            return t + nums.size()-1;
        return -1;
    }
};
