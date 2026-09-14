class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        
        for (const string& op : operations) {
            if (op == "C") {
                record.pop();
            } else if (op == "D") {
                int prev = record.top();
                record.push(prev * 2);
            } else if (op == "+") {
                int top1 = record.top();
                record.pop();
                int top2 = record.top();
                record.push(top1);
                record.push(top1 + top2);
            } else {
                record.push(stoi(op));
            }
        }
        
        int sum = 0;
        while (!record.empty()) {
            sum += record.top();
            record.pop();
        }
        
        return sum;
    }
};