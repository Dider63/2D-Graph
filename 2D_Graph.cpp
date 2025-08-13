#include<iostream>
#include<vector>
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





return 0;
}
