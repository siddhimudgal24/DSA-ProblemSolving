#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    // approach1->use hashmaps and store the occurence of each element of the grid
    int total = n*n;
    int repeated = -1;
    int missing = -1;
    vector<int>count(total+1,0);
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            count[grid[i][j]]++;
        }
    }
    for(int i =1;i<=total;i++){
        if(count[i]==0){
            missing = i;
        }else if(count[i]==2){
            repeated = i;
        }
    }
    return {repeated,missing};
    }
int main(){
    // A n*n grid is given 
    cout<<"Enter the value of n here:"<<endl;
    int n;
    cin>>n;
    vector<vector<int>>grid(n, vector<int>(n));
    cout<<"Enter the values in the grid"<<endl;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<int>ans = findMissingAndRepeatedValues(grid);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}