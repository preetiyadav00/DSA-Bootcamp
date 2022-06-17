// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        int mod= 1e9 + 7;
        if(n==1)
        return k%mod;
        vector<vector<long long int>>dp(3,vector<long long int>(n,0));
        
        for(int j=1;j<n;j++)
        {
            if(j==1)
            {
             dp[0][j]=(k*1)%mod;
             dp[1][j]=k%mod*(k-1)%mod;
             dp[2][j]=(dp[0][j]%mod + dp[1][j]%mod)%mod;
            }
            else
            {
                dp[0][j]=dp[1][j-1]%mod * 1;
                dp[1][j]=(dp[2][j-1]%mod * (k-1)%mod)%mod;
                dp[2][j]=(dp[0][j]%mod + dp[1][j]%mod)%mod;
            }
             
        }
        return dp[2][n-1]%mod;
        
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends