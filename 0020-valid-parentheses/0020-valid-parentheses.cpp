class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                ans.push(c);
            } else {
                if(!ans.empty()){
                    if(ans.top() == '(' && c == ')' || ans.top() == '{' && c == '}' || ans.top() == '[' && c == ']'){
                        ans.pop();
                    }else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if(ans.empty()) return true;
        return false;
    }
};