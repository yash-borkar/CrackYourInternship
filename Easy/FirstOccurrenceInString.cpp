https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        int index=0;
        int start=0;
        bool flag=1;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            index=i;
            start=i;
            for(int j=0;j<needle.size();j++){
                if(haystack[index]!=needle[j]){
                    flag=0;
                    break;
                }
                index++;
            }
            if(index-i==needle.size()) return start;
        }
        return -1;
    }
};

/* ------------------------------------------------------------------------------------------------------------------------ */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        int n = haystack.size();
        int m = needle.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(needle[j]!=haystack[j+i]) break;

                if(j==m-1) return i;
            }
        }
        return -1;
    }
};