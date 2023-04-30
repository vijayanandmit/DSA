class Solution {
public:
    bool is_palindrome(const string& s) {
        if(s.length() == 1)
            return false;
        int n = s.length();
        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n-i-1]) {
                return false;
            }
        }
        return true;
    }

    string find_beautiful_string(const string& s, int k) {
        int n = s.length();
        for (int i = 0; i <= n-k; i++) {
            string sub = s.substr(i, k);
            if (!is_palindrome(sub)) {
                return s;
            } else 
                smallestBeautifulString(s, k);
        }
        return "";
    }
    
    
    string smallestBeautifulString(string s, int k) {
        int n = s.length();
        string t = s; //Next string after increment is t
        for (int i = n-1; i >= 0; i--) {
            // Iterate over the characters of the input string from right to left
            if (t[i] < 'a' + k-1) {
                // If the current character is less than the maximum allowable character ('a' + k-1),
                // we can increment it and reset all subsequent characters to 'a'.
                t[i]++;
                
                
                /////// Need change/update here to check 
                //input = "ced", 6, expected output = "cef", output is "cee"
                // ee is palindrome, it should become ef
                string sub = s.substr(i, k);
                if(is_palindrome(sub))
                    t[i]++;
                ///////
                
                
                for (int j = i+1; j < n; j++) {
                    t[j] = 'a';
                }
                // We have found the lexicographically smallest beautiful string larger than the input string,
                // so we can exit the loop and return the result.
                break;
            }
        }

        return is_palindrome(t) ? "" : t;
        

    }
};
