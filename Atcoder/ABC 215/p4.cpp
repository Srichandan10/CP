//Author- CHANDAN SRIVASTAVA
//Problem link- 
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int 			long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<int>
#define vs				vector<string>
#define pii             pair<int,int>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<int>
#define pq_min          priority_queue<int,vi,greater<int> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define rep(i,a,b) 		for(int i=(a);i<=(b);i++)
#define reprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
int spf[MAXN];
 
// Hash to store prime factors count
int hash1[MAXN] = { 0 };
 
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
 
        // Marking smallest prime factor for every
        // number to be itself
        spf[i] = i;
 
    // Separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    // Checking if i is prime
    for (int i = 3; i * i < MAXN; i++) {
 
        // Marking SPF for all numbers divisible by i
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
 
                // Marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
 
// Function to store the prime factors after dividing
// by the smallest prime factor at every step
void getFactorization(int x)
{
    int temp;
    while (x != 1) {
        temp = spf[x];
        if (x % temp == 0) {
 
            // Storing the count of
            // prime factors in hash
            hash1[spf[x]]++;
            x = x / spf[x];
        }
        while (x % temp == 0)
            x = x / temp;
    }
}
 
// Function that returns true if there are
// no common prime factors between x
// and other numbers of the array
bool check(int x)
{
    int temp;
    while (x != 1) {
        temp = spf[x];
 
        // Checking whether it common
        // prime factor with other numbers
        if (x % temp == 0 && hash1[temp] > 1)
            return false;
        while (x % temp == 0)
            x = x / temp;
    }
    return true;
}


void solve(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vi a(n);
	rep(i,0,n-1){
		cin>>a[i];
	}

}



signed main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	
	int testcases;
	cin>>testcases;
	while(testcases--){
		solve();
	}



	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}