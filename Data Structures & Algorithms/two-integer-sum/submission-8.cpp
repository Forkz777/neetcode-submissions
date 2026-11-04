class Solution {
public:
    std::unordered_map<int, int> seen;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int index = 0; index < (int)nums.size(); ++index){
            if(seen.count(target-nums[index])){
                return {seen[target - nums[index]], index};
            }
            seen[nums[index]] = index;
        }

        return {};
    }
};
