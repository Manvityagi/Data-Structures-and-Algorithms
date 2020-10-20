 //Question Link :https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t[9][9]; // for memorization

int rodcut(int price[], int length[],int Max_len, int n)
{
    if (n == 0 || Max_len == 0)
    {
        return 0;
    }
    if (length[n - 1] <= Max_len)
    {
        t[n][Max_len]  = max(price[n - 1]+ rodcut(price, length, Max_len - length[n - 1], n),rodcut(price, length, Max_len, n - 1));
    }

    else
    {
        t[n][Max_len]= rodcut(price, length, Max_len, n - 1);
    }

    return t[n][Max_len];
}



int main()
 {
	    int n;
	    cin>>n;
	    int price[n];
	    int length[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>price[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>length[i];
	    }
      int maximum=n;
     cout<<"Maximum obtained value is :"<<rodcut(price,length,n,maximum)

	   return 0;
}
