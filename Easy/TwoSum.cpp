#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;

class  Solution {
public:
    /*
     * Clean code Online
     */
    vector<int> twoSumBest(vector<int>& nums, int target) {
        unordered_map<int, int> currentNums;
        currentNums[nums[0]] = 0;
        for (int i = 1;; i++) {
            auto it = currentNums.find(target - nums[i]);

            if (it != currentNums.end()) 
                return vector<int> {i, it->second};
                
            currentNums[nums[i]] = i;
        }
    }
    /*  
     * Two Sum completed using a map from a value to its position in the vector
     * Time Complexity O(n)
     * Space Complexity O(n)
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> Pair;
        unordered_map<int, int> currentNums;
        for (int i = 0; i < nums.size(); i++) {
            if (currentNums.count(target - nums[i]) == 1) {
                return vector<int> {currentNums.at(target - nums[i]), i};
            }
            currentNums.insert({nums[i], i});
        }
        return vector<int> {-1, 01};
    }

    /*
     * Two Sum completed using a brute force approach looping through array twice
     * Time Complexity O(n^2)
     * Space Complexity O(1)
     */
    vector<int> twoSumForced(vector<int>& nums, int target) {
        size_t arrSize = nums.size();
        vector<int> answerPair;
        for (int i = 0; i < arrSize; i++) {
            for (int j = 0; j < arrSize; j++) {     
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        answerPair.push_back(i);
                        answerPair.push_back(j);
                        return answerPair;
                    }
                }
            }
        }
        return answerPair;
    }
};

int main()
{
    Solution TestSolution;
    vector<int> nums = {1, 2, 3, 4};
    int total = 6;
    vector<int> answerPair = TestSolution.twoSum(nums, total); 
    for (int num: answerPair) {
        cout << num << " ";
    }
    cout << endl;
}
