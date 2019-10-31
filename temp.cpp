#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define INF LONG_MAX
#define pr(i,x,n) for(int ii=i;ii<n+i;ii++){cout<<x[ii]<<" ";}cout<<endl;
#define ip(i,x,n) for(int ii=i;ii<n+i;ii++){cin>>x[ii];};
#define db(x,y) cout<<x<<" "<<y<<endl;
#define LD long double
#define PR pair<LD,LL>

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);       
} 
 
int main() {
static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();

	int t ;
	cin >> t;
	while(t--){
        int n;
		cin >> n;
		std::vector<int> arr(n);
		
		for(int i = 0; i < n; i++){
		    cin >> arr[i];
		}
		
		sort(arr.begin(),arr.end());
		
		if(arr[n/4] > arr[n/4-1] &&
		   arr[2 * n/4] > arr[2 * n/4 - 1] && 
		   arr[3 * n/4] > arr[3 * n/4 - 1]){
		      cout << arr[n/4] << " " << arr[2 * n/4] << " " << arr[3 * n/4] << endl;
		  }else
		  cout << -1 << endl;
	}
	
	return 0;
}