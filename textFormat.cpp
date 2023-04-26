//#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'textFormatting' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY starting
 *  2. INTEGER_ARRAY ending
 *  3. CHARACTER_ARRAY style
 */

int textFormatting(vector<int> starting, vector<int> ending, vector<char> style) 
{
    int textSize = *max_element(ending.begin(), ending.end()) + 1;
    string text(textSize, ' ');
    for(int i=0 ; i < starting.size() ; ++i) {
        for (int j=starting[i] ; j <= ending[i] ; ++j) {
            text[j] = style[i];
        }
    }
    int oper = 0;
    char currStyle = ' ';
    bool isSelected = false;
    for (char c:text) {
        if(c!=currStyle) {
            currStyle = c;
            oper++;
            if (!isSelected) {
                oper++; // select the text if it's not already selected
                isSelected = true;
            }
        } else {
            isSelected = true; // mark text as selected if it's already styled
        }
    }
    return oper;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string starting_count_temp;
    getline(cin, starting_count_temp);

    int starting_count = stoi(ltrim(rtrim(starting_count_temp)));

    vector<int> starting(starting_count);

    for (int i = 0; i < starting_count; i++) {
        string starting_item_temp;
        getline(cin, starting_item_temp);

        int starting_item = stoi(ltrim(rtrim(starting_item_temp)));

        starting[i] = starting_item;
    }

    string ending_count_temp;
    getline(cin, ending_count_temp);

    int ending_count = stoi(ltrim(rtrim(ending_count_temp)));

    vector<int> ending(ending_count);

    for (int i = 0; i < ending_count; i++) {
        string ending_item_temp;
        getline(cin, ending_item_temp);

        int ending_item = stoi(ltrim(rtrim(ending_item_temp)));

        ending[i] = ending_item;
    }

    string style_count_temp;
    getline(cin, style_count_temp);

    int style_count = stoi(ltrim(rtrim(style_count_temp)));

    vector<char> style(style_count);

    for (int i = 0; i < style_count; i++) {
        string style_item_temp;
        getline(cin, style_item_temp);

        char style_item = style_item_temp[0];

        style[i] = style_item;
    }

    int result = textFormatting(starting, ending, style);

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

