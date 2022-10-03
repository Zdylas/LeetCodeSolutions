#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>

using namespace std;


class Solution {
public:

    string convertBest(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }

    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string collection[numRows];
        for (int i = 0; i < numRows; i++) {
            collection[i] = "";
        }
        int current_row = 1;
        bool downwards = true;
        for (int i = 0; i < size(s); i++) {
            int place = 0;
            collection[current_row-1] += s[i];

            if (downwards && current_row == numRows) {
                downwards = !downwards;
            } else if (!downwards && current_row-1 == 0) {
                downwards = !downwards;
            }
            if (downwards) current_row++;
            if (!downwards) current_row--;
            

        }
        string result;
        for (int i = 0; i < numRows; i++) {
            for (auto letter : collection[i]) {
                if (letter != '_') {
                    result += letter;
                }
                   
            }
        }
        return result;
    }
};

int main(void)
{
    Solution mySol;
    string s = "AB";
    int numRows = 1;
    cout << mySol.convert(s, numRows) << endl;
}