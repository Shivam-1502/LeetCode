class Solution {
    static const long long LIMIT = 1e6;

    long long combCapped(long long n, long long r){
        if(r < 0 || r > n) return 0;
        r = min(r, n - r);
        if(r == 0) return 1;

        __int128 res = 1;
        for(long long i = 1; i <= r; ++i){
            res = res * (n - r + i)/i;
            if(res > LIMIT) return LIMIT + 1;
        }
        return (long long)res;
    }

    long long countWays(vector<int>& freq){
        long long rem = 0;
        for(int x : freq) rem += x;

        long long ans = 1;
        for(int c : freq){
            if(c == 0) continue;
            long long part = combCapped(rem, c);
            ans *= part;

            if(ans > LIMIT) return LIMIT + 1;
            rem -= c;
        }
        return ans;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);

        for(int i = 0; i < n/2; ++i) ++freq[s[i] - 'a'];

        if(countWays(freq) < k) return "";

        int idx = 0;
        for(int pos = 0; pos < n/2; ++pos){
            for(int ch = 0; ch < 26; ++ch){
                if(freq[ch] == 0) continue;

                --freq[ch];
                long long ways = countWays(freq);
                if(ways >= k){
                    s[idx++] = char('a' + ch);
                    break;
                }
                k -= ways;
                ++freq[ch];
            }
        }

        for(int i = 0; i < n/2; ++i){
            s[n - i - 1] = s[i];
        }
        return s;
    }
};