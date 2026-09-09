class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long a = n - 999;

        if(a > 0){
            total += a;

            a = n - 999999;
            if(a > 0){
                total += a;

                a = n - 999999999;
                if(a > 0){
                    total += a;

                    a = n - 999999999999;
                    if(a > 0){
                        total += a;

                        a = n - 999999999999999;
                        if(a > 0){
                            total += a;
                        }
                    }
                }
            }
        }
        return total;
    }
};