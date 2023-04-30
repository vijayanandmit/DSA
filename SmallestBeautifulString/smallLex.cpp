//https://leetcode.com/contest/weekly-contest-343/problems/lexicographically-smallest-beautiful-string/

string smallestBeautifulString(string s, int k) {
    int n = s.size(); 
    for (int i = n-1; i >= 0; --i) {
        // Iterate over the characters of the input string from right to left,
        // looking for the rightmost character that can be incremented to obtain a larger beautiful string.
        for (char ch = s[i]+1; ch < 'a' + k; ++ch) {
            // Try all possible characters that are greater than the current character,
            // and check if adding the new character would violate the beautiful string condition.
            if ((i == 0 || s[i-1] != ch) && (i <= 1 || s[i-2] != ch)) {
                // If the new character does not violate the beautiful string condition,
                // we can replace the current character with the new character,
                // and reset all subsequent characters of the string to the lexicographically smallest beautiful string.
                s[i] = ch; 
                for (int j = i+1; j < n; ++j) {
                    for (char cand = 'a'; cand < 'a' + k; ++cand) {
                        // Try all possible characters for the subsequent characters of the string,
                        // and check if adding the new character would violate the beautiful string condition.
                        if (cand != s[j-1] && (j == 1 || cand != s[j-2])) {
                            // If the new character does not violate the beautiful string condition,
                            // we can replace the current character with the new character.
                            s[j] = cand; 
                            break; 
                        }
                    }
                }
                // We have found the lexicographically smallest beautiful string larger than the input string,
                // so we can return the result.
                return s; 
            }
        }
    }
    // If no such string is found, we return an empty string.
    return ""; 
}
/*
The code starts by iterating over the characters of the input string from right to left, looking for the rightmost character that can be incremented to obtain a larger beautiful string. 

For each such character, the code tries all possible characters that are greater than the current character, and checks if adding the new character would violate the beautiful string condition. 

If the new character does not violate the beautiful string condition, the code replaces the current character with the new character, and resets all subsequent characters of the string to the lexicographically smallest 
beautiful string. Finally, the code returns the result.

If no such string is found, the code returns an empty string

*/
