class Solution {
public:
    std::unordered_map<int, int> seen;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int index = 0; index < (int)nums.size(); ++index){
            int missing = target-nums[index];
            if(seen.count(missing)){
                return {seen[missing], index};
            }
            seen[nums[index]] = index;
        }

        return {};
    }
};
