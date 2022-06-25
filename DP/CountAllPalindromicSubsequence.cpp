// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    // RR
    // if(i==j)return 1
    // if(s[i]==s[j])return 1+f(i+1,j)+f(i,j-1)
    // else
    // return f(i+1,j)+f(i,j-1)-f(i+1,j-1)

    long long int  countPS(string str)
    {
       //code here
       long long int mod=1e9 + 7;
       long long int n=str.size();
       long long int dp[n+1][n+1];
       memset(dp,0,sizeof(dp));
       for(long long int i=0;i<n;i++)
       dp[i][i]=1;   //base case 
       
       //cout<<n<<endl;
       //pehle smallest len ka dp cnt krlo i.e
       //diagonally for all i where l=2
       for(long int l=2;l<=n;l++)
       {
           for(long int i=0;i<=n-l;i++)
           {
               long int j=i+l-1; 
               if(str[i]==str[j])
               {
                   dp[i][j]=(dp[i][j]%mod + dp[i+1][j]%mod)%mod;
                   dp[i][j]=(dp[i][j]%mod + dp[i][j-1]%mod)%mod;
                   dp[i][j]=(dp[i][j]%mod + 1)%mod;
               }
               else
               {
                   dp[i][j]=(dp[i][j]%mod + dp[i+1][j]%mod)%mod;
                   dp[i][j]=(dp[i][j]%mod + dp[i][j-1]%mod)%mod;
                   dp[i][j]=((dp[i][j]%mod - dp[i+1][j-1]%mod)+mod)%mod;
               }
           }
       }
       
       return dp[0][n-1]%mod; //becz 1st row ka last ele hi longest len ka rahega
       //and it contans sum of all lengths <=n
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends