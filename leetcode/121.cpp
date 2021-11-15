class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_price = 0;
        int answer = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]<min_price){
                answer = max(answer, max_price-min_price);
                min_price = prices[i];
                max_price = 0;
            }
            else{
                max_price = max(max_price,prices[i]);
            }
        }
        answer = max(answer, max_price-min_price);
        return answer;
    }
};