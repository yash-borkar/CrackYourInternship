https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxAns = 0;
        int points = 0;

        for(int i=0; i<k; i++){
            points += cardPoints[i];
        }
        maxAns = points;

        int rIndex = n-1;
        for(int i=k-1; i>=0; i--){
            points = points - cardPoints[i] + cardPoints[rIndex];
            maxAns = max(maxAns, points);
            rIndex--;
        }
        return maxAns;
    }
};