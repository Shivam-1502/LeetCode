class Solution {
public:
    int maxVowels(string s, int k) {
        bool isVowel[128] = {false};
        isVowel['a'] = isVowel['e'] = isVowel['i'] = isVowel['o'] = isVowel['u'] = true;

        int currentVowels = 0;
        int n = s.length();
        for (int i = 0; i < k; ++i) {
            if (isVowel[s[i]]) {
                currentVowels++;
            }
        }

        int maxVowels = currentVowels;
        if (maxVowels == k) return k;

        for (int i = k; i < n; ++i) {
            if (isVowel[s[i - k]]) {
                currentVowels--;
            }
            if (isVowel[s[i]]) {
                currentVowels++;
            }

            if (currentVowels > maxVowels) {
                maxVowels = currentVowels;
                if (maxVowels == k) return k;
            }
        }

        return maxVowels;
    }
};