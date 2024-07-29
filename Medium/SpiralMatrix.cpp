https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int total_elements=m*n;
        int sr=0;
        int ec=n-1;
        int er=m-1;
        int sc=0;
        int count=0;

        while(count<total_elements){
            // Starting Row
            for(int i=sc;i<=ec && count<total_elements;i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;

            // Ending Column
            for(int i=sr;i<=er && count<total_elements;i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;

            // Ending Row
            for(int i=ec;i>=sc && count<total_elements;i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;

            // Starting Column
            for(int i=er;i>=sr && count<total_elements;i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        return ans;     
    }
};