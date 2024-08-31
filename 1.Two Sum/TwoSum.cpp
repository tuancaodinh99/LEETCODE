#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); ++i){
            int offset = target - nums[i];
            if(hashTable.find(offset) != hashTable.end()){
                return {hashTable[offset],i};
            }
            hashTable[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1,-2, -3, -4, -5};
    int target = -8;
    vector<int> result = solution.twoSum(nums, target);

    // Output: [0, 1]
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}