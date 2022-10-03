#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;


class Solution {
public:
    /*
     * This code takes advantage of the fact that a uneven length string must have invalid brackets
     * Utilizes a stack to hold the characters and returns false as soon as a bracket mismatch is found
     * 
     * IMPORTANT: stack<char> and vector<char> have the same features with the same memory and time usage
     * however stack shows the reader the exact use of the variable
     */
    bool isValid(string s) {
        size_t length = size(s);
        if (length % 2 != 0) {
            return false;
        } else if (length == 0) {
            return true;
        }

        stack<char> current;
        for (char chr : s) {
            if (current.empty()) {
                current.push(chr);
            } else if (chr == ')' && current.top() == '(') {
                current.pop();
            } else if (chr == '}' && current.top() == '{') {
                current.pop();
            } else if (chr == ']' && current.top() == '[') {
                current.pop();
            } else if (chr == ']' || chr == '}' || chr == ')') {
                return false;
            } else {
                current.push(chr);
            }
        }
        if (current.empty()) {
            return true;
        }
        
        return false;
    }


    /*
     * First attempt, pretty much hard coded using switch (chr).
     * Terrible code, too long and looks awful.
     */
    bool isValidBad(string s) {
        vector<char> current;
        for (char chr : s) {
            switch (chr) {
                case 40:
                case 41:
                    if (chr == '(') {
                        current.push_back(chr);
                    } else {
                        if (size(current) == 0) {
                            return false;
                        }

                        if (current.back() == '(') {
                            current.pop_back();
                        } else {
                            return false;
                        }
                    }
                    break;
                case 91:
                case 93:
                    if (chr == '[') {
                        current.push_back(chr);
                    } else {
                        if (size(current) == 0) {
                            return false;
                        }

                        if (current.back() == '[') {
                            current.pop_back();
                        } else {
                            return false;
                        }
                    }
                    break;
                case 123:
                case 125:
                    if (chr == '{') {
                        current.push_back(chr);
                    } else {
                        if (size(current) == 0) {
                            return false;
                        }

                        if (current.back() == '{') {
                            current.pop_back();
                        } else {
                            return false;
                        }
                    }
                    break;
                default:
                    break;  
            }
        }
        if (size(current) > 0) {
            return false;
        }
        return true;
    }
};


int main()
{
    Solution TestSolution;
    string s = "(){}}{";
    cout << TestSolution.isValid(s) << endl;
}
