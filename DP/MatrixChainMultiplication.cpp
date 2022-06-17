// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,0));
        for(int l=1;l<N;l++)
        {
            for(int i=0;i<N;i++)
            {
                int j=(l+i);
                 if(j==N || i==N-1)
                 break;
                int num=INT_MAX;
                dp[i][j]=num;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]));
                }
            }
        }
        // for(int i=0;i<N;i++)
        // {
        //     for(int j=0;j<N;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[1][N-1];
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends