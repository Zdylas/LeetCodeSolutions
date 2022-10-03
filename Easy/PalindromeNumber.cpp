#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>
#include <iomanip>

using namespace std;

class Solution {
public:
    /*
     * Not sure why I had such a bad ending statement in original solve
     * Takes advantage of the fact that you should only have to convert half
     * of the number to see it is a palindrome.
     * Generally cleaner code.
     */
    bool isPalindromeBest(int x) {
        int reversed_num = 0;
        if (x < 0 || x % 10 == 0 && x != 0) {
            return false;
        }
        while (x > reversed_num) {
            reversed_num = reversed_num*10 + x%10;
            x /= 10;
        }
        return x == reversed_num || x == reversed_num/10;
    }
    /*
     * Any negatives are automatically not a palindrome
     * Create a new reversed number by using % 10 to get the last digit
     * Time Complexity O(n)
     * Space Complexity O(1)
     */
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int64_t temp = x;
        int64_t reversed_num = 0;
        while (temp > 0) {
            reversed_num *= 10;
            reversed_num += temp % 10;
            temp /= 10;
        }
        if (reversed_num == x) {
            return true;
        }
    return false;
    }
};

int main(void)
{
    Solution MySol;
    int x = 121;
    bool palindrome = MySol.isPalindromeBest(x);
    cout << boolalpha << palindrome << endl;
}