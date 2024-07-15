https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum=0;
                sum=nums[i]+nums[j];
                if(sum==target) {
                    ans.push_back(i);
                    ans.push_back(j);

                }
            }
        }
        return ans;
    }
};