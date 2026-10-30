class Solution {
public:
    string reverseStr(string s, int k) {
        char* charArray = new char[s.size() + 1];
    
        s.copy(charArray, s.size());
        charArray[s.size()] = '\0';

        for(int i = 0; i < s.size(); i += 2*k){
            int left = i;
            int right = min(i + k - 1, (int)s.size() - 1);
            while(left < right) {
                char temp = charArray[left];
                charArray[left++] = charArray[right];
                charArray[right--] = temp;
            }
        }

        return string(charArray);
    }
};