#include<bits/stdc++.h>
using namespace std;

void knap(vector<int> p, vector<int> wt, int W, int n){

    vector<vector<int>> dp(n+1, vector<int> (W+1));

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){

            if(i == 0 || w == 0) dp[i][w] = 0;
            else if(wt[i-1] <= w) dp[i][w] = max(p[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else dp[i][w] = dp[i-1][w];
        }
    }

    cout<<"max profit : "<<dp[n][W];

    int i = n, w = W;

    while(i > 0 && w > 0){
        if(dp[i][w] != dp[i-1][w]){
            cout<<"item "<<i<<", wt : "<<wt[i-1]<<", profit : "<<p[i-1]<<endl;
            cout<<"weight remaining : "<<W-w<<endl;
            w = w - wt[i-1];
        }
        i--;
    }
    // return 0;
}

int main(){

    int n, W;
    cout<<"enter no. of items : ";
    cin>>n;

    vector<int> wts(n), pft(n);
    cout<<"enter weights : ";
    for(int i = 0; i < n; i++) cin>>wts[i];
    cout<<"enter profits : ";   
    for(int i = 0; i < n; i++) cin>>pft[i];
    cout<<"enter max wt : ";
    cin>>W;

    knap(pft, wts, W, n);

    return 0;
}
