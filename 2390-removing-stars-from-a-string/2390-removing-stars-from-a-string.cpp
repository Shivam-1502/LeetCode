class Solution {
public:
    string removeStars(string s) {
        stack<char> ans;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                ans.pop();
            } else{
                ans.push(s[i]);
            }
        }
        string result = "";
        while (!ans.empty()) {
            result += ans.top();
            ans.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};