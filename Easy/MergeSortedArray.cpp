https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>v(m+n);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                v[k]=nums1[i];
                i++;
                k++;
            }
            else{
                v[k]=nums2[j];
                j++;
                k++;
            }
        }

        while(i<m){
            v[k]=nums1[i];
            k++;
            i++;
        }

        while(j<n){
            v[k]=nums2[j];
            j++;
            k++;
        }

        for(int i=0;i<m+n;i++){
            nums1[i]=v[i];
        }
    }
};