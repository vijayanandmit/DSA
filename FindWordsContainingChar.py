class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        res = []
        n = len(words)
        for i in range(n):
            if x in words[i]:
                res.append(i)
        return res


#You are given a 0-indexed array of strings words and a character x.

#Return an array of indices representing the words that contain the character x.

#Note that the returned array may be in any order.

#Example 1:

#Input: words = ["leet","code"], x = "e"
#Output: [0,1]
#Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.

