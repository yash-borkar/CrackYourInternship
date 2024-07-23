https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int idx = (abs(nums[i]) - 1) % n;
            if(nums[idx] < 0) ans.push_back(abs(nums[i]));
            else nums[idx] *= -1;
        }
        return ans;
    }
};