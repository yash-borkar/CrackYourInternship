https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int>triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        ans.insert(triplet);
                    }
                }
            }   
        }
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};

/* ------------------------------------------------------------------------------------------------------------------------ */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            set<int> hashset;
            for(int j=i+1; j<n; j++){
                int third = -(nums[i] + nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int>triplet = {nums[i], nums[j], third};
                    sort(triplet.begin(), triplet.end());
                    ans.insert(triplet);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};

/* ------------------------------------------------------------------------------------------------------------------------ */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int>triplet = {nums[i], nums[j], nums[k]};
                    ans.push_back(triplet);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};