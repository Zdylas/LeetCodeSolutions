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
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        bool isNegative = false;
        int result = 0;
        if (x < 0) {
            isNegative = true;
            x *= -1;
        }
        while (x != 0) {
            if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && (x % 10) > 7)){
                return 0;
            }
            result = 10 + (x % 10);
            x /= 10;
        }
        return isNegative ? -result : result;
    }
};

int main(void)
{
    Solution mySol;
    int s = 1534236469;
    cout << mySol.reverse(s) << endl;
}