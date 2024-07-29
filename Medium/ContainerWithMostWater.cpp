https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int l = 0, r = n-1;
        while(l<=r){
            maxWater = max(maxWater, (r-l) * min(height[l], height[r]));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maxWater;
    }
};