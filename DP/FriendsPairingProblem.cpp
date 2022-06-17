// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        // f(n)=f(n-1)+(n-1)*f(n-2);
        // f(n-1)-> current is single -> prblm reduces to f(n-1)
        // f(n-2)-> curr is paired (can be paired in n-1 ways) prblm reduced to f(n-2)
        int mod=1e9+7;
        if(n<=2)
        return n;
        vector<long long int>dp(n+1,0);
        dp[0]=0,dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=((dp[i-1])%mod + ((i-1)%mod*(dp[i-2])%mod)%mod)%mod;
        }
        
        return dp[n]%mod;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends