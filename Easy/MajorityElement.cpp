https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int, int>m;

        // for (auto i : nums){
        //     m[i]++;
        // }

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        int ans=0;
        for (auto i : m){
            if(i.second >n) ans = i.first;
        }
        return ans;
    }
};