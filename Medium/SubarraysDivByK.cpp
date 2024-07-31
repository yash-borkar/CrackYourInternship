https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int>mp;

        int ans = 0;
        int rem = 0;
        int sum = 0;
        mp[rem]++;

        for(auto i:nums){
            sum+=i;
            rem = sum % k;
            if(rem<0) rem+=k;   // For negative remainder
            if(mp.find(rem)!=mp.end()) ans+=mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};