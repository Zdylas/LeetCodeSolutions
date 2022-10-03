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
     * As expected removing the erase from my function significantly increases the speed. 
     * Used the idea that you can swap items in places that you have already looked at, by
     * the end of the list all duplicate items will be at the end.
     */
    int removeDuplicates(vector<int>& nums) {
        int unique_index = 1;
        for (int i = 1; i < size(nums); i++) {
            if (nums[i] != nums[unique_index-1]) {
                nums[unique_index] = nums[i];
                unique_index += 1;
            }
        }
        return unique_index;
    }
    /*
     * First attempt, extremely slowly, most likely due to nums.erase having to
     * change the position of elements constanstly
     */
    int removeDuplicatesErase(vector<int>& nums) {
        for (int i = 1; i < size(nums); i++) {
            if (nums[i] == nums[i-1]) {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return size(nums);
    }
};

int main(void)
{
    Solution MySol;
    vector<int> nums = {1,1,2,3,4};
    cout << MySol.removeDuplicates(nums) << endl;
    
}