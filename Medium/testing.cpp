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
    int myAtoi(string &s) {
        int i = 0;
        int sign = 1;
        long long res = 0, mx = INT_MAX, mn = INT_MIN;
        while(s[i] == ' ') i ++;
        if(s[i] == '-'){
            sign = -1;
            i ++;
        }
        else if(s[i] == '+'){
            i ++;
        }
        while(isdigit(s[i])){
            res = res * 10 + s[i] - 48;
            if(sign * res > mx) return mx;
            if(sign * res < mn) return mn;
            i ++;
        }
        res = res * sign;
        return int(res);
    }
};

int main(void)
{
    Solution mySol;
    string s = "2147483648";
    cout << mySol.myAtoi(s) << endl;
}