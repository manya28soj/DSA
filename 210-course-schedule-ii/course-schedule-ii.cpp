class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        //build graph
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>q;

        //push nodes with 0 indegree
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>order;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            

            for(int neighbor:adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
                   }

                   //valid order
                   if(order.size() == numCourses)
                    return order;
                    //cycle exists
                    return {};
    }
};