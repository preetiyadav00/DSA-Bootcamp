long long int countDerangements(int n) {
    // Write your code here.
    //RR
        //f(n)=(n-1)*(f(n-1)+f(n-2))
        //n-1 ways for any ele 
        //eg 0 is replaced with ith ele
        //f(n-2) -> agr us ith ele ko 0 se replace kiya
        // now we have to look for only n-2 ele as 
        //ith ele is aready placed
        //f(n-1) -->otherwise us ith ele ko n-1 pos me se kahi bhi 
        //place kiya to prblm reduced to f(n-1)
    
    
    long long int dp[n+1];
    long long int mod=1e9 + 7;
    for(int i=0;i<=n;i++)
        dp[i]=0;
    dp[1]=0; //no way
    dp[2]=1; //for 2 ele
    for(int i=2;i<=n;i++)
    {
        dp[i]+=((i-1)*(dp[i-1]%mod+dp[i-2]%mod)%mod)%mod;
        dp[i]=dp[i]%mod;
    }
    return dp[n]%mod;
}