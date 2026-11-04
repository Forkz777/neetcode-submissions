class Solution {
public:
    std::unordered_set<int> seen;

    bool hasDuplicate(vector<int>& nums) {
        int hasAppeared[(int)nums.size()];
        for(int num : nums){
            if(seen.count(num)){
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};