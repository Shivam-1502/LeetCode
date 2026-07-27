class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;

        for(int num : nums){
            int ma = a;

            a = max(a, num);
            b = max(b, min(ma, num));
        }
        return (a - 1)*(b-1);
    }
};