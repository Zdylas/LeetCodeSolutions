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

class Solution {
public:
    /*
     * Same solution as RemoveDuplicateFromSortedArray
     */
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] != val) {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};

int main(void)
{
    Solution MySol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout << MySol.removeElement(nums, 2) << endl;
    for (int num : nums) {
        cout << "Num:" << num << endl;
    }
    
}