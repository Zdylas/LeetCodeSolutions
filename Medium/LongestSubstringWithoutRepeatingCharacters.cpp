#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>
#include <iomanip>
#include <string>
#include <list>

using namespace std;

template<typename K, typename V>
void print_map(unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

class Solution {
public:
    /*
     * Best solution, Space: O(1) Time: O(n) 
     * You can create your own HashMap on the stack because of the idea that 
     * the string s consists only of English letters, digits, symbols and spaces.
     * Sliding window method
     */
    int lengthOfLongestSubstring(string s) {
        int mySet[128] = {-1};
        for (auto& i : mySet) {
            i = -1;
        }
        int longest = 0;
        int left = 0;

        for (int right = 0; right < size(s); right++) {
            int index = mySet[s[right]];
            if (index != -1) {
                left = index + 1;
            }
            longest = max(longest, right - left + 1);
            if (size(s)-longest < left) {
                return longest;
            }
            mySet[s[right]] = right;
        }
        return longest;
    }



    int lengthOfLongestSubstringBetter(string s) {
        int li[128];
        int longest = 0;
        int current = 0;
        
        for (auto& i : li) {
            i = -1;
        }
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (-1 == li[ch]) {
                li[ch] = i;
                current++;
            }
            else {
                if (i - li[ch] > current) {
                    li[ch] = i;
                    current++;
                }
                else {
                    current = i - li[ch];
                    li[ch] = i;
                }
            }
            if (current > longest)
                longest = current;
        }
        
        return longest;
    }

    /*
     * Terrible
     */
    int lengthOfLongestSubstringBad(string s) {
        unordered_map<char, int> HashMap;
        int longest = 0;
        for (int i = 0; i < size(s); i++) {
            bool duplicate = false;
            int current_longest = 0;
            for (int j = 0+i; j < size(s) && !duplicate ; j++) {
                auto it = HashMap.find(s[j]);
                if (it != HashMap.end()) {
                    duplicate = true;
                    
                } else {
                    HashMap[s[j]] = 1;
                    current_longest++;
                }

                if (current_longest > longest) {
                    longest = current_longest;
                }
            }
            
            if (size(s) - longest < i) {
                return longest;
            }
            
            HashMap.erase(HashMap.begin(), HashMap.end());
        }
        return longest;
    }
};

int main(void)
{
    Solution mySol;
    string s = "au";
    cout << mySol.lengthOfLongestSubstring(s) << endl;
}