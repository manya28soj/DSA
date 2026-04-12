class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        //build grapgh
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>q;

        //push nodes with indegree 0
        for(int i =0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    
    int count =0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;

        for(int neighbour :adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return count == numCourses;
    }

};