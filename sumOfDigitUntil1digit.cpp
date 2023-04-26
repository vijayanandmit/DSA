/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Mathematical digital root solution

return num == 0 ? 0 : 1 + (num - 1) % 9;

*/

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(1) { //make sure, break condition is met, to avoid infinite loop.
            int digit = num%10;
            sum += digit;
            if(num/10) // when there are digits left for sum, remove the last digit and continue
                num /= 10;
            else if(sum/10 == 0) { // exit condition when sum is single digit
                break;
            }
            else { //no more digits left, and sum is more than 1 digit, restart the addition with sum as num.
                num = sum;
                sum = 0;
            }
        }
        return sum;
    }
};
