static const unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int left = 0, right = n - 1;

        while(left < right){
            while(left < n && vowel.find(s[left]) == vowel.end()) ++left;
            while(right >= 0 && vowel.find(s[right]) == vowel.end()) --right;

            if(left >= right) break;
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        return s;
    }
};