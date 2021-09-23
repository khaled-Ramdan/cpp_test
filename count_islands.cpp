#include<iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> grid;
vector<vector<bool>>visited;//visited 2d array
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};
bool inside(int i, int j){//check if boundaries are inside the grid
    if(i>=0 && i<grid.size()  && j>=0 && j<grid[0].size())return true;
    else return false;
}
void dfs(int i, int j){
    if(inside(i,j) && grid[i][j]=='.' && !visited[i][j] ) {
        visited[i][j]=true;//now this point is visited
        for(int k=0;k<8;k++){
            dfs(i+dx[k],j+dy[k]);
        }   
        /*
        //recursive call
        dfs(i-1,j);//up
        dfs(i+1,j);//dowen
        dfs(i,j+1);//right
        dfs(i,j-1);//left
        //if there are an allow for diagonally move
        dfs(i-1,j-1);
        dfs(i-1,j+1);
        dfs(i+1,j-1);
        dfs(i+1,j+1);*/
    }
}
void flodfill(){
    int count_islands=0;
    visited.resize(grid.size(),vector<bool>(grid[0].size()));//visited 2d array
     for(int i=0;i<grid.size();i++){
         for(int j=0;j<grid[0].size();j++){
             if(grid[i][j]=='.'&&!visited[i][j]){ 
                dfs(i,j);
               count_islands++;
            }
         }
     }
     cout<<count_islands<<endl;
}
int main(){
    int n;
    cin>>n;
    string ss;
    grid.resize(n);
    for(int i=0;i<n;i++){
        cin>>ss;
        grid[i]=ss;
    }
    flodfill();
    return 0;
}
