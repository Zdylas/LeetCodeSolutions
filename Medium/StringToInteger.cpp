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
#include <cctype>
#include <climits>

using namespace std;



class Solution {
public:

    int myAtoi(string s) {
        int32_t number = 0, i = 0;
        int8_t isNegative = 1;
        long long mx = INT_MAX, mn = INT_MIN;
        while(s[i] == ' ') i++;
        if (s[i] == '+') i++;
        else if (s[i] == '-') {
            i++;
            isNegative = -1;
        }
        while (isdigit(s[i])) {
            if(number > (mx / 10) || (number == (mx / 10) && (s[i]-'0') > 7)){
                if (isNegative == -1) {
                    return mn;
                }
                return mx;
            }
            number *= 10;
            number += s[i] - '0';
            i++;
        }

        return isNegative * number;
    }


    /*
     * First attempt: Not clean, lots of checks that could probably be shortened down
     */
    int myAtoiBad(string s) {
        int number = 0;
        bool negative = false;
        bool found = false;
        for (int i = 0;; i++) {
            // cout << s[i];
            // cout << isdigit(s[i]) <<endl;
            // cout << "Number:" << number << endl;
            if (s[i] == ' ' && !found) {
                continue;
            } else if (s[i] == '+' && isdigit(s[i+1]) && !found) {
                continue;
            } else if (s[i] == '-' && isdigit(s[i+1]) && !found) {
                negative = true;
            } else if (!isdigit(s[i]) && !found) {
                return 0;
            } else if (isdigit(s[i])) {
                found = true;
                if ((INT32_MAX/10) < number) {
                    return negative ? -INT32_MAX-1 : INT32_MAX;
                }
                if ((INT32_MAX - (s[i] - '0')) < number*10) {
                    return negative ? -INT32_MAX-1 : INT32_MAX;
                }
                number *= 10;
                number += s[i] - '0';
            }

            if (!isdigit(s[i]) && found) {
                return negative ? -number : number;
            }
        }
    }
};

int main(void)
{
    Solution mySol;
    string s = "42";
    
    cout << mySol.myAtoi(s) << endl;
}