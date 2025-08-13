#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void insertGraph(vector<vector<int>> &V,int source,int destination){
V[source].push_back(destination);
}
printGraph(vector<vector<int>> &V){
    int n=V.size();
for(int i=0;i<n;i++){
        cout<<i<<"-> ";
    for(int j : V[i]){
        cout<<j<<" ";
    }
    cout<<endl;
}


}

vector<int> bfs(vector<vector<int>>& adj)  {
    int V = adj.size();
    int s = 0;
    vector<int> Queue;
    queue<int> q;
    vector<bool> visited(V,false);

    visited[s]=true;

    q.push(s);
    while (!q.empty()){
        int curr=q.front();
        q.pop();
        Queue.push_back(curr);
        for (int x:adj[curr]) {
            if (!visited[x]) {
                visited[x]=true;
                q.push(x);
            }
        }
    }

    return Queue;
}


int main(){

vector<vector <int>> V(7);
insertGraph(V,0,1);
insertGraph(V,0,4);
insertGraph(V,1,2);
insertGraph(V,1,6);
insertGraph(V,2,3);
insertGraph(V,4,5);
insertGraph(V,4,6);
insertGraph(V,5,3);
insertGraph(V,5,6);
insertGraph(V,6,3);

printGraph(V);

 vector<int> ans = bfs(V);
    for(auto i:ans) {
        cout<<i<<" ";
    }



return 0;
}
