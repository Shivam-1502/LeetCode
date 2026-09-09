class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        int n = ast.size();

        for(int i = 0; i < n; i++){
            if(ast[i] > 0){
                s.push(ast[i]);
            } else {
                while(!s.empty() && s.top() > 0 && s.top() < abs(ast[i])) s.pop();
                if(s.empty() || s.top() < 0) s.push(ast[i]);
                else if(s.top() == abs(ast[i])) s.pop();
                
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};