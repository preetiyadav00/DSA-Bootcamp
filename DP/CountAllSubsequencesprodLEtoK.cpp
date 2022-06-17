// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(vector<int>&v,int n,int k)
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(j<v[i-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    //include=1+dp[i-1][j/v[i-1]]
                    //exclude=dp[i-1][j]
                    //total no of ways=include+exclude
                    dp[i][j]=1+dp[i-1][j/v[i-1]]+dp[i-1][j];
                }
            }
        }
        return dp[n][k];
    }
};


// { Driver Code Starts.
int main()
{
    int t=1,n,k,x,y;
    //cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);  
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }    
        Solution ob;
        cout << ob.lcs(v,n,k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
