class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';

        for(int i = 0; i < s.length(); ++i){
            char ch = s[i];

            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || i == s.size() - 1){
                if(op == '+') st.push(num);
                else if(op == '-') st.push(-num);
                else if(op == '*'){
                    int t = st.top(); 
                    st.pop();
                    st.push(t * num);
                }
                else if(op == '/'){
                    int t = st.top(); 
                    st.pop();
                    st.push(t / num);
                }
                op = ch;
                num = 0;
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};