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
 
class node{
    public:
    int max;
    int ways;
    node(){
        max = 0;
        ways = 0;
    }
};

int n;

bool valid(int i, int j){

}

node ans;

node helper(vector<vector<char>> arr, int curri, int currj){
        //base case - reach 0,0
        if(curri == 0 && currj == 0){

           int temp = max(points[curri+1][currj+1],max(points[curri][currj+1],[curri+1][currj]);

            if(temp == points[curri+1][currj+1]){
                if(points[curri+1][currj+1] == points[curri+1][currj] && points[curri+1][currj+1] == points[curri][currj+1])
                    ans.ways += 3;
                else
                 if(points[curri+1][currj+1] == points[curri+1][currj] || points[curri+1][currj+1] == points[curri][currj+1] || points[curri][currj+1] == points[curri+1][currj])
                    ans.ways += 2;
                else
                    ans.ways += 1;
                
            }
            else
            if(){

            }
            else
            {
                
            }
            
            //          ans.ways += 3;
            // else
            // if(points[i+1][j+1] == points[i+1][j] || points[i+1][j+1] == points[i][j+1] || points[i+1][j+1] == points[i][j+1)
            return ans; 
        }

        node op1,op2,op3;
        //explore into all 3 directions if possible
        if(valid(curri-1,currj) && arr[curri-1][currj] != 'x')
         {
             op1 = helper(arr,curri-1,currj);
             op1.max += arr[curri-1][currj]-'0';
            //  op1.ways++;
         }

           if(valid(curri,currj-1) && arr[curri][currj-1] != 'x')
         {
             op2 = helper(arr,curri,currj-1);
             op2.max += arr[curri][currj-1]-'0';
            //  op2.ways++;
         }

           if(valid(curri-1,currj-1) && arr[curri-1][currj-1] != 'x')
         {
             op3 = helper(arr,curri-1,currj-1);
             op3.max += arr[curri-1][currj-1];
            //  op3.ways++;
         }

        //pick the best of 3 directions
        node bestop;
        bestop.max = max(op1.max,max(op2.max,op3.max));

         ans.max = bestop.max; 
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
        vector<vector<char>> arr(n,vector<char>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        }

        node ans;
        helper(arr,n-1,n-1);
        cout << ans.max << " " << ans.ways << endl;

	}
	return 0;
}