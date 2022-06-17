#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define ii insert

int P(int n, int k) {
	// Write your code here.

    //nPr= r!* nCr  
    //r!*(n!)/(r!*(n-r)!)->> n!/(n-r)! 
    ll mod=1e9 + 7;
    vector<vector<ll>>dp(n+1,vector<ll>(k+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        ll include=0,exclude=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                include=((dp[i-1][j-1])%mod*(j%mod))%mod;  //n-1Pr-1  //j ways to include ith number
                exclude=(dp[i-1][j])%mod;    //n-1Pr 
                dp[i][j]=(include+exclude)%mod;
                
            
            }
        }
        return dp[n][k];
  
}
int main()
{
    fast
    ll t=1;
    cin>>t;
    ll n,k;
    cin>>n>>k;
    while(t--)
    {
        ll ans=P(n,k);
        cout<<ans<<endl;
        //solve();
    }
    return 0;
}

