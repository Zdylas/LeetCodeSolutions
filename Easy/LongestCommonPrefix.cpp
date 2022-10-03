#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace std;

class  Solution {
public:
    /*
     * Squeezing Theorem Idea implement into code, order the strings.
     * If first_word[0] == last_word[0] all words must have the same first char
     */

    string longestCommonPrefixSorting(vector<string>& strs) {
        
        if (size(strs) == 0) {
            return "";
        }

        if (size(strs) == 1) {
            return strs[0];
        }

        sort(strs.begin(), strs.end());
        if (strs.front() == strs.back()) {
            return strs.front();
        }
        
        int max_index = 0;
        for (int i = 0;; i++) {
            if (strs.front()[i] == '\0' || strs.back()[i] == '\0') {
                return strs.front().substr(0, max_index);
            }
            if (strs.front()[i] != strs.back()[i]) {
                return strs.front().substr(0, max_index);
            }
            
            max_index += 1;
        }
    }

    /*
     * Starts by getting the longest length and the total amount of words
     * iterates through each string comparing to see if they are the same char
     * this is done until it has iterated over the entirety of the smallest string or there is a mismatch.
     */
    string longestCommonPrefix(vector<string>& strs) {
        size_t words = size(strs);
        size_t shortest_length = strs[0].length();
        for (int i = 1; i < words; i++) {
            if (strs[i].length() < shortest_length) {
                shortest_length = strs[i].length();
            }
        }

        if (shortest_length == 0) {
            return "";
        }

        if (words == 1) {
            return strs[0];
        }

        int total = 0;
        for (int i = 0;;i++) {
            char current_char = strs[0][i];
            for (int j = 1; j < words; j++) {
                if (strs[j][i] != current_char || i == shortest_length) {
                    return strs[0].substr(0, total);
                }
            }
            total += 1;
        }
    }
};

int main()
{
    Solution TestSolution;
    vector<string> strs = {"",""};
    string answer = TestSolution.longestCommonPrefixSorting(strs); 
    cout << answer << endl;
}
