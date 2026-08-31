class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        int first = -1, prev = -1;   
        int last = -1;              

        int idx = 1;                
        ListNode* p = head;          
        ListNode* c = head->next;    

        while (c->next) {
            ListNode* n = c->next;

            bool isCritical = (c->val > p->val && c->val > n->val) || (c->val < p->val && c->val < n->val);    

            if (isCritical) {
                if (first == -1) first = idx;
                if (prev != -1){
                    minDist = min(minDist, idx - prev);
                }
                prev = idx;
                last = idx;
            }
            p = c;
            c = n;
            idx++;
        }

        if (first == last || first == -1){
            return {-1, -1};
        }

        return {minDist, last - first};
    }
};