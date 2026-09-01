/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int, vector<int>>> mp;
        unordered_map<int, int> vis; 
        queue<int> q;
        for(int i=0; i<employees.size(); i++){
            mp[employees[i]->id] = {employees[i]->importance, employees[i]->subordinates};
            vis[employees[i]->id] = 0;
        }

        q.push(id);
        vis[id] = 1;
        int imp = 0;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            vector<int> av = mp[f].second;
            imp+=mp[f].first;
            for(int i=0; i<av.size(); i++){
                if(!vis[av[i]]){
                    q.push(av[i]);
                }
            }
        }

        return imp;
        
    }
};