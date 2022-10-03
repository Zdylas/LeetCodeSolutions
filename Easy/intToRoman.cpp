#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>
#include <iomanip>
#include <string>


using namespace std;

class Solution {
public:
    /*
     * Creates map that holds the value of each char, iterates through list backwards
     * and adds if the symbol is greater than or equal to previous character, otherwise
     * subtracts.
     */ 
    int romanToInt(string s) {
        int total = 0;
        int previous = 0;
        unordered_map<char, int> symbols = {{'I',    1},
                                            {'V',    5},
                                            {'X',   10},
                                            {'L',   50},
                                            {'C',  100},
                                            {'D',  500},
                                            {'M', 1000}};
        for (auto it = s.end() - 1; it != s.begin() - 1; it--) {
            auto symbol = symbols.find(*it); 
            if (symbol->second >= previous) {
                total += symbol->second;
            } else {
                total -= symbol->second;
            }
            previous = symbol->second;

        }
        return total;
    }
    
};

int main(void)
{
    Solution MySol;
    string s = "MCMXCIV";
    int testing = MySol.romanToInt(s);
    cout << testing << endl;
}