https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int minn=INT_MAX;
        int finalAns=0;
       
        for(int i=0;i<n;i++){
            if(prices[i]>minn){
                if(prices[i]-minn > finalAns) finalAns=prices[i]-minn;
            }
            else minn=prices[i]; 
        }
        return finalAns;
        
    }

};