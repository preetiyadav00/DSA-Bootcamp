
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        
        long long int dp[m+1][n+1];
        for(int i=0;i<=m;i++)   //coins
        {
            for(int j=0;j<=n;j++)   //n i.e sum
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
                else if(j==0)
                {
                    dp[i][j]=1; //sum is 0 i.e 1 way -> dont select any coin
                }
            }
        }
        long long int exclude=0,include=0;
        for(int i=1;i<=m;i++)    //coins //row
        {
            for(int j=1;j<=n;j++)    //number (0..n) //col
            {
                
                exclude=dp[i-1][j]; //no of ways if exclude ith coin 
                if((j-S[i-1])>=0)
                {include=dp[i][j-S[i-1]];}//no of ways if include ith coin
                else
                {include=0;}
                dp[i][j]=include+exclude; //total ways for ith coin
                
            }
        }
        // for(int i=0;i<=m;i++)    //coins //row
        // {
        //     for(int j=0;j<=n;j++)    //number (0..n) //col
        //     {
        //         cout<<dp[i][j]<<" ";
                
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
