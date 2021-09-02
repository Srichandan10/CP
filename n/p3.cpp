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

void solve(){
	int k,n,m;
	cin>>k>>n>>m;

	vi a(n);
	vi b(m);
	rep(i,0,n-1){
		cin>>a[i];
	}
	rep(i,0,m-1){
		cin>>b[i];
	}
	int i=0;
	int j=0;
	int l=k;
	vi res;
	int flag=0;
	while(i<n && j<m){
		/*if(a[i]==0){
			i++;
			l++;
			res.pb(0);
		}
			
		if(b[j]==0){
			j++;
			l++;
			res.pb(0);
			
		}*/
		if((i>=n) || (j>=m))
			break;

		if(a[i]<b[j]){
			if(a[i]==0){
				l++;
				res.pb(0);
			}
			else if(a[i]<=l){
				res.pb(a[i]);
			}
			else
				flag=1;
			i++;

		}
		
		else if(a[i]>=b[j]){
			if(b[j]==0){
				l++;
				res.pb(0);
			}
			else if(b[j]<=l){
			res.pb(b[j]);
			}
			else
				flag=1;
			j++;
			
		}
		if(flag==1)
			break;
		

	}
	while(i<n){
		if(a[i]==0){
				l++;
				res.pb(0);
			}
			else if(a[i]<=l){
				res.pb(a[i]);
			}
			else
				flag=1;
			i++;
	}
	while(j<m){
			if(b[j]==0){
				l++;
				res.pb(0);
			}
			else if(b[j]<=l){
			res.pb(b[j]);
			}
			else
				flag=1;
			j++;
			
	}
	if(flag==1){
		cout<<-1<<endl;
	}
	else{

	logarr(res,0,res.size()-1);
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