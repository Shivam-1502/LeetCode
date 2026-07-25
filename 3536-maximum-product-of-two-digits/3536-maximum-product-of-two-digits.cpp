class Solution {
public:
    int maxProduct(int n) {
        int mx = -1, mx2 = -1;

        while(n > 0){
            int dig = n % 10;
            if(dig > mx){
                mx2 = mx;
                mx = dig;
            } else if(dig > mx2){
                mx2 = dig;
            }
            n /= 10;
        }
        return mx*mx2;
    }
};