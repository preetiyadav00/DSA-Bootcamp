// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       
        for(int i=0;i<=n;i++)
        {
           
            for(int j=0;j<=m;j++)
            {
                if(i==0)
                    dp[i][j]=j; //if str1 is empty insert j(curr) of str2 characters to str1
                else if(j==0)
                    dp[i][j]=i; //if str2 is empty remove i(curr) characters from str1
                else if (s[i-1]==t[j-1] )
                {
                    dp[i][j]=dp[i-1][j-1];  //do nothing move frwrd
                }
                else
                {
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    
                    // dp[i-1][j] -> insert 
                    // dp[i][j-1] -> remove
                    // dp[i-1][j-1]->replace
                }
            }
        }
        return dp[n][m];
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends