#include <bits/stdc++.h>
using namespace std;

//****************************************DEFINES**********************************************************
#define ll long long
#define mod 1000000007
#define mod1 998244353
#define endl "\n"
#define ld long double
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define N 1e5 +6;
#define l 1e18+1;
//****************************************DEFINES***********************************************************

//****************************************FUNCTIONS*********************************************************
//bool comp(const pair<ll,ll> &temp1,
//          const pair<ll,ll> &temp2)
//{
//    return temp1.second<temp2.second;
//}
bool comp(pair<ll,pair<ll,ll>> &p1,pair<ll,pair<ll,ll>> &p2){
    if(p1.first!=p2.first){
        return p1.first>p2.first;
    }
    if(p1.second.first!=p2.second.first){
        return p1.second.first<p2.second.first;
    }
    return p1.second.second<p2.second.second;
}
ll __lcm(ll a, ll b)
{
    return ((a*b)/ __gcd(a, b));
}
ll smallestprimeDivisor(ll n)
{

    if (n % 2 == 0)
        return 2;


    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }

    return n;
}
ll hashfunction(string s){
    ll p =31;
    ll hashVal=0;
    ll pow=1;
    for (char c : s) {
        hashVal = (hashVal + (c - 'a' + 1) * pow) % mod;
        pow = (pow * p) % mod;
    }
    return hashVal;
}
ll binexpo(ll x, ll y, ll m) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)res = (res * x) % m;
        x = (x * x) % m;
        y = y >> 1;
    }

    return res;
}

/*sieve code
 vector<bool>is_prime(n+1,true);
     is_prime[0]=is_prime[1]=false;
     for(ll i=2;i<=n;i++){
       if(is_prime[i] && ll i*i<=n){
          for(ll j=i*i;j<=n;j+=i){
                is_prime[j]=false;
                  }
              }
           }
*/
/*Prime Factors Code
vector<ll> prime_factors(vector<ll> &v, ll n){

while(n%2==0){
   v.push_back(2);
   n=n/2;
}
for(ll i=3;i<=sqrt(n);i=i+2){
    while(n%i==0){
       v.push_back(i);
       n=n/i;
     }
}
if(n>2){
   v.push_back(n);
}
}*/
/*
  const int N= 1e5+5;
    vector<ll>fact(N);
    fact[0]=1;

 for(ll i=1;i<N;i++){
fact[i]=fact[i-1]*i;
fact[i]=fact[i]%mod;
}

*/
// ****************************************FUNCTIONS**********************************************************
struct Node{
    int val;
    Node * links[2];
};
Node * newNode(){
    Node * root = new Node;
    root->val=0;
    root->links[0] = NULL;
    root->links[1] = NULL;
    return root;
}
void insert(Node *root2, int xor_val){
    Node *temp= root2;
    for(int i=31;i>=0;i--){
        bool bitval= xor_val&(1<<i);
        if(temp->links[bitval]==NULL){
            temp->links[bitval] = newNode();
        }
        temp=temp->links[bitval];
    }
    temp->val=xor_val;
}
int q(Node *root2, int xor_val){
    Node *temp= root2;
    for(int i=31;i>=0;i--){
        bool bitval= xor_val&(1<<i);
        if(temp->links[1-bitval]!=NULL){
            temp=temp->links[1-bitval];
        }
        else if(temp->links[bitval]!=NULL){
            temp=temp->links[bitval];
        }

    }
    int ans = xor_val^(temp->val);
    return ans;
}
int solve(vector<int> &v, int n){
    Node *root = newNode();
    insert(root,0);
    int maxm=INT_MIN;
    int xor_val=0;
    for(auto it: v){
        xor_val=xor_val^it;
        insert(root,xor_val);
        maxm=max(maxm,q(root,xor_val));
    }
    return maxm;
}

ll fact(ll n)
{
    if(n==0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
string decimalToBaseK(int decimal, int k) {
    if (decimal == 0) {
        return "0";
    }

    string result = "";

    while (decimal > 0) {
        int remainder = decimal % k;
        result = to_string(remainder) + result;
        decimal /= k;
    }

    return result;
}

bool check(ll n){
    if(n<=1) return false;
    for(ll i=2;i*i<=n;i++){
         if(n%i==0) return false;
    }
    return true;
}
bool compi(const pair<ll,ll> &a, const pair<ll,ll> &b){
    if(a.first>b.first){
        return true;
    }
    else if(a.first<b.first){
        return false;
    }
    else if(a.second<b.second){
        return true;
    }
    return false;
}
ll f(ll i, ll j,vector<vector<ll>> &dp,vector<ll> &vis,vector<vector<ll>> &grid){

    if(dp[i][j]!=-1) return dp[i][j];
    
}

void solution(){

    string s;
    cin>>s;
    int n=s.size();
    int cnt=0;
//    for(int i=1;i<n-1;i++){
//        if(s[i]!=s[i+1] && s[i]!='?' && s[i+1]!='?'){
//            cnt++;
//        }
//    }
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='?' && s[i-1]!=s[i+1] && s[i-1]!='?' && s[i+1]!='?'){
            s[i]=s[i-1];
        }
        else if(s[i]=='?' && s[i-1]!=s[i+1] && s[i-1]=='?' && s[i+1]!='?'){
            s[i]=s[i+1];
        }
        else if(s[i]=='?' && s[i-1]!=s[i+1] && s[i-1]!='?' && s[i+1]=='?'){
            s[i]=s[i-1];
        }
    }
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1] && s[i]!='?' && s[i+1]!='?')cnt++;
    }
    cout<<cnt<<endl;

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--) {
        solution();
    }
    return 0;

}
