https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    array<int,256>hash(string s){
        array<int,256>hash={0};
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<array<int,256>, vector<string>> mp;

        for(auto str:strs){
            mp[hash(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};

/* ------------------------------------------------------------------------------------------------------------------------ */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto i: strs){
            string word = i;
            sort(word.begin(), word.end());
            mp[word].push_back(i);
        }
        
        vector<vector<string>> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};