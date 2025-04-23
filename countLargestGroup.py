import collections

class Solution:
    def countLargestGroup(self, n: int) -> int:
        """
        Counts how many groups of numbers in [1, n] share the largest size,
        where each group is formed by numbers having the same digit-sum.
        """
        # Create a counter to map each digit-sum to the count of numbers with that sum
        hashMap = collections.Counter()

        # For every number from 1 through n...
        for i in range(1, n + 1):
            #   Convert the number to string, map each character back to int, and sum them
            key = sum(int(x) for x in str(i))
            #   Increment the count for this digit-sum group
            hashMap[key] += 1

        # Determine the size of the largest digit-sum group
        maxVal = max(hashMap.values())
        # Count how many different digit-sum groups reach that maximum size
        count = sum(1 for v in hashMap.values() if v == maxVal)

        # Return the number of groups tied for largest size
        return count

