https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
int findDuplicate(vector<int>& nums) {

    // 1.Sorting Method
    sort(nums.begin() , nums.end());
    int n = nums.size();
    int i ;
    for(int i=0;i<=n;i++){
        if(nums[i]==nums[i+1]) return nums[i+1];
    }
    return -1;


    // 2.Visited Marking Method

    int n = nums.size();
    int ans=-1;
    for(int i=0;i<n;i++){
        int index=abs(nums[i]);

        // if already visited
        if(nums[index]<0){
            ans=index;
            break;
        }
        // mark as visited
        nums[index]*=-1;
    }
    return ans;


    // 3.Positioning Method

    while(nums[0] != nums[nums[0]]){
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}
};