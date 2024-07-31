https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int i, int n, int m){
        for(int j=0; j<m; j++){
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void markCol(vector<vector<int>>& matrix, int j, int n, int m){
        for(int i=0; i<n; i++){
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

     1. Brute Force - O(n^3)

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    markRow(matrix, i, n, m);
                    markCol(matrix, j, n, m);
                }
            }
        }

        // Replace -1 with 0
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == -1) matrix[i][j] = 0;
            }
        }
    }
};  

/* ------------------------------------------------------------------------------------------------------------------------ */

class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int i, int n, int m){
        for(int j=0; j<m; j++){
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void markCol(vector<vector<int>>& matrix, int j, int n, int m){
        for(int i=0; i<n; i++){
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Better - O(n^2)
        vector<int>row(n, 0);
        vector<int>col(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }        
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }        
        }
    }
}

/* ------------------------------------------------------------------------------------------------------------------------ */

class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int i, int n, int m){
        for(int j=0; j<m; j++){
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void markCol(vector<vector<int>>& matrix, int j, int n, int m){
        for(int i=0; i<n; i++){
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Optimal - O(n^2)

        // vector<int>row(n, 0);  -->  matrix[][0]  
        // vector<int>col(m, 0);  -->  matrix[0][]

        int col0 = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }        
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 ||  matrix[0][j] == 0)
                        matrix[i][j] = 0;
                }
            }        
        }

        if(matrix[0][0] == 0)
            for(int j=0; j<m; j++) matrix[0][j] = 0;

        if(col0 == 0)
            for(int i=0; i<n; i++) matrix[i][0] = 0;
        
    }
};