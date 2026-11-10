#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    // approach2 ->mathematical approach 
    long long total = 1LL*n*n;
    long long actual_sum = 0;
    long long actual_sq_sum = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            actual_sum+=grid[i][j];
            actual_sq_sum+=(grid[i][j]*grid[i][j]);
        }
    }
    long long expected_sum = (total * (total+1))/2;
    long long expected_sq_sum = (total* (total+1)*(2*total +1))/6;
    long long diff = expected_sum- actual_sum;//a-b
    long long sq_diff = expected_sq_sum - actual_sq_sum;//a2 - b2
    long long sum = sq_diff/diff;//a+b
    int missing = (diff+sum)/2;
    int repeated = (sum-missing);
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