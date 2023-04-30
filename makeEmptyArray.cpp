
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        
    // find the smallest element


        // count the number of operations
        while (!nums.empty()) {
        
            int minIndex = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            
            if (nums[0] == nums[minIndex]) {
                nums.erase(nums.begin());
                n--;
                minIndex = minIndex == 0 ? n - 1 : minIndex - 1;

            } else {
                int temp = nums[0];
                nums.erase(nums.begin());
                nums.push_back(temp);
                minIndex = minIndex == 0 ? n - 1 : minIndex - 1;

            }
            count++;
        }        
        
        return count;
    }
};
