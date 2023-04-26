#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'isPossible' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. INTEGER c
 *  4. INTEGER d
 */

string isPossible(int a, int b, int c, int d) {
    //while loop works for half of test cases, but for remaining
    //half testcases are exceeding Time limit, which needs more check
    
    if(a==c || b==d)
        return "Yes";
        
    int gab = gcd(a,b);
    int cd = gcd(c,d);
    
    if(gab != cd || c%gab != 0 || d%gab !=0 ) {
        return "No";
    }
    
    int k = c/gab;
    int l = d/gab;
    if((k-1)*l < b/gab || (l-1)*k < a/gab) {
        return "No";
    }
    return "Yes";
    
    /*
    while(c>=a || d>=b) {
        if(c==a && d==b) {
            return "Yes";
        }
        if(c>d) c-=d;
        else    d-=c;
    }
    return "No";
    */
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_temp;
    getline(cin, a_temp);

    int a = stoi(ltrim(rtrim(a_temp)));

    string b_temp;
    getline(cin, b_temp);

    int b = stoi(ltrim(rtrim(b_temp)));

    string c_temp;
    getline(cin, c_temp);

    int c = stoi(ltrim(rtrim(c_temp)));

    string d_temp;
    getline(cin, d_temp);

    int d = stoi(ltrim(rtrim(d_temp)));

    string result = isPossible(a, b, c, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

