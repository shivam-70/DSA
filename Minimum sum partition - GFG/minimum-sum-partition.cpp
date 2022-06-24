// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(i==0 and j==0)
	            {
	                dp[i][j]=true;
	                continue;
	            }
	            if(i==0)
	            {
	                dp[i][j]=false;
	                continue;
	            }
	            if(j==0)
	            {
	                dp[i][j]=true;
	                continue;
	            }
	            if(arr[i-1]>j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
	            }
	            
	        }
	    }
	    int ans=INT_MAX;
	    for(int i=sum/2;i>=0;i--)
	    {
	        if(dp[n][i]==true)
	        {
	            ans=sum-2*i;
	            break;
	        }
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends