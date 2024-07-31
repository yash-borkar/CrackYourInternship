https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        bool flag = 1;
        string curr="";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(flag==1){
                    v.push_back(curr);
                    v.push_back(" ");
                    curr="";
                    flag=0;
                }
                else continue;
            }
            else{
                flag = 1;
                curr+=s[i];
            }
        }
        v.push_back(curr);
        reverse(v.begin(), v.end());

        string ans="";
        for(int i=0; i<v.size(); i++){
            string curr = v[i];
            ans+=curr;
        }

        //Ignore leading and trailing spaces

        int start;
        for(start=0; start<ans.size(); start++){
            if(ans[start]!=' ') break;
        }

        int end;
        for(end=ans.size()-1; end>=0; end--){
            if(ans[end]!=' ') break;
        }

        string finalAns = ans.substr(start, (end-start)+1);
        return finalAns;
    }
};