class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (char c : s) {
            if (c != ')') {
                st.push(c);
            } else {
                string tmp;
                while (st.top() != '('){
                    tmp += st.top(), st.pop();
                }
                st.pop(); 
                for (char ch : tmp)
                    st.push(ch);
            }
        }

        string ans;
        while (!st.empty()){
            ans += st.top(), st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};