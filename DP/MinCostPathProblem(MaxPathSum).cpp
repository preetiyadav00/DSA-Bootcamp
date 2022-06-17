// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        //RR
        //f[i][j]=mat[i][j]+max(f[i-1][j],f[i-1][j-1],f[i-1][j+1]);
        
        vector<vector<int>>dp(N+1,vector<int>(N+2,0));
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
                dp[i][j]+=Matrix[i-1][j-1];
                
               
            }
        }
        // for(int i=0;i<=N;i++)
        // {
        //     for(int j=0;j<=N;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        for(int j=0;j<=N;j++)
        ans=max(ans,dp[N][j]);
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends