class Solution {
public:
    bool checkDivisibility(int n) {
        int org_n = n, digSum = 0, prod = 1;

        while(n > 0){
            int dig = n % 10;
            digSum += dig;
            prod *= dig;
            n /= 10;
        }
        int total = digSum + prod;
        return (org_n % total == 0);
    }
};