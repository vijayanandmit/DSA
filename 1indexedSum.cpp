//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'findSum' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY numbers
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<long> findSum(vector<int> nums, vector<vector<int> > queries) {

    vector<long> sums;
    int l, r, x, s=0;
    int n = nums.size();
    int m = queries.size(); // q = [m x 3]
    //zero -> add 10 to sum
    
    //queries[i] = 3 for all i
    
    //cout << queries[0];
    
    //sum.push_back();
    for (int i=0 ; i<m ; ++i) {
        l = queries[i][0];
        r = queries[i][1];
        x = queries[i][2];
        while(l<=r) {
            if(nums[l-1]) //1-indexed
                s += nums[l-1]; //1-indexed
            else
                s += x;
            l = l+1;
        }
        sums.push_back(s);
    }
    
    return sums;
}
int main() {
	vector<int> n {-5, 0};
	vector< vector<int> > q {{1, 2, 10}};
	vector<long> s= findSum(n,q);
	cout << s[0];
	return 0;
}
/*
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string numbers_count_temp;
    getline(cin, numbers_count_temp);

    int numbers_count = stoi(ltrim(rtrim(numbers_count_temp)));

    vector<int> numbers(numbers_count);

    for (int i = 0; i < numbers_count; i++) {
        string numbers_item_temp;
        getline(cin, numbers_item_temp);

        int numbers_item = stoi(ltrim(rtrim(numbers_item_temp)));

        numbers[i] = numbers_item;
    }

    string queries_rows_temp;
    getline(cin, queries_rows_temp);

    int queries_rows = stoi(ltrim(rtrim(queries_rows_temp)));

    string queries_columns_temp;
    getline(cin, queries_columns_temp);

    int queries_columns = stoi(ltrim(rtrim(queries_columns_temp)));

    vector<vector<int> > queries(queries_rows);

    for (int i = 0; i < queries_rows; i++) {
        queries[i].resize(queries_columns);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < queries_columns; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<long> result = findSum(numbers, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
*/
