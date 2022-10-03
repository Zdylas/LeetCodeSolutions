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
     * Completed Using Binary Search
     */
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = size(nums)-1;
        while (l<=h)
        {
            int m=(l+h)/2;
          
            if (arr[m]<tar)
            {
                
                l=m+1;
                  ans=m;
            }
            else
            {
              
                h=m-1;
            }
            
            
            
        }
      
      return l;
    }

    int searchInsert(vector<int>& nums, int target) {
        int location = 0;
        for (location; location < size(nums); location++) {
            if (nums[location] >= target) {
                return location;
            }
        }
        return location;
    }
};

int main(void)
{
    Solution MySol;
    vector<int> nums = {1,3,5,6};
    cout << MySol.searchInsert(nums, 5) << endl;
    
}