class Solution {
public:
    string longestPalindrome(string s) {
        
        long long int n=s.size(),start,end,ans=0,temp,in1,in2;
        string re="";
        for(int i=0;i<s.size();i++)
        {
            start=i,end=i; //for odd size ka palindrome
            // for every i start and end ko expand krte jaenge
            //jab ta same hai dono in ke char
            //aise longest palindromic substring milegi
            while(start>=0 && end<=n-1 && s[start]==s[end])
            {
                temp=end-start+1; //len of substring
                if(temp>ans)
                {
                    ans=temp;
                    in1=start;
                    in2=end;
                }
                 start--;
                 end++;
            }
        }
        for(int i=0;i<s.size()-1;i++)
        {
            start=i,end=i+1;    //for even size ka palindrome
            while(start>=0 && end<=n-1 && s[start]==s[end])
            {
                temp=end-start+1;
                if(temp>ans)
                {
                    ans=temp;
                    in1=start;
                    in2=end;
                }
                 start--;
                 end++;
            }
        }
        //cout<<ans<<endl;
        for(int i=in1;i<=in2;i++)
            re+=s[i];
        return re;
    }
};