class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();

        ranges::sort(discounts);
        ranges::sort(prices);

        double sum = 0;
        for(int i = n-1, j = m-1; i > -1; --i){
            double dis = 0;
            if(j > -1){
                dis = prices[i] * discounts[j] / 100.0f;
                --j;
            }

            sum += prices[i] - dis;
        }
        return sum;
    }
};