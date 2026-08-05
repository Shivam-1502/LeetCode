class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> inDeg(n, 0);
        vector<bool> suspicious(n);

        for(const auto& inv : invocations){
            edges[inv[0]].push_back(inv[1]);
            inDeg[inv[1]]++;
        }

        queue<int> q;
        q.push(k);

        suspicious[k] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : edges[u]){
                inDeg[v]--;

                if(!suspicious[v]){
                    q.push(v);
                    suspicious[v] = true;
                }
            }
        }

        bool canRemoveAll = true;
        vector<int> remaining;

        for(int i = 0; i < n; i++){
            if(suspicious[i] && inDeg[i] > 0){
                canRemoveAll = false;
                break;
            } else if(!suspicious[i]) {
                remaining.push_back(i);
            }
        }

        if(!canRemoveAll){
            vector<int> allNodes(n);
            iota(allNodes.begin(), allNodes.end(), 0);
            return allNodes;
        }

        return remaining;
    }
};