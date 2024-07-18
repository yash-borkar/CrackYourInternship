https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    bool ispalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
            
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                // remove i
                int ans1=ispalindrome(s, i+1, j);

                //remove j;
                int ans2=ispalindrome(s, i, j-1);

                return ans1||ans2;
            }
            i++;
            j--;
        }
        return true;
    }
};