https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long i=0;
        long long j=m-1;
        long long ans=INT_MAX;
        while(j<n){
            if(a[j]-a[i]<ans) ans=a[j]-a[i];
            i++;
            j++;    
        }
        
        return ans; 
    }   
};