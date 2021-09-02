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

class edge{
public:
	int u,v,w;
	edge(){
		u=0;
		v=0;
		w=0;
	}
	edge(int u,int v,int w){
		this->u=u;
		this->v=v;
		this->w=w;
	}
	bool operator<(const edge &other) const{
		return w<other.w;
	}

};
class union_find{
	int *par;
	int *sz;

public:
	union_find(int n){
		par = new int[n + 1];
		sz = new int[n + 1];

		for(int i=1;i<=n;i++){
			par[i]=i;
			sz[i]=1;
		}
	}

	int root(int x){
		if(x==par[x])
			return x;

		return par[x]=root(par[x]);  // path compression

	}

	bool find(int a, int b){
		return root(a)==root(b);
	}

	void union_sets(int a, int b){
		int ra=root(a);
		int rb=root(b);

		if(ra==rb)
			return ;
		if(sz[ra]>sz[rb]){
			swap(ra,rb);
		}
		par[ra]=rb;
		sz[rb]+=sz[ra];
	}
	int size(int a){
		return sz[root(a)];
	}

};



signed main() {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	
	int n;
	cin>>n;
	vector<edge> edges(n);
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges[i].u=u;
		edges[i].v=v;
		edges[i].w=w; 
	}
	sort(edges.begin(),edges.end());
	/*for(int i=1;i<=n-1;i++){
	
		cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
	}*/
	union_find dsu(n);
	int ans=0;
	for(int i=1;i<=n-1;i++){
		int u=edges[i].u;
		int v=edges[i].v;
		int w=edges[i].w;
		ans+=w*dsu.size(u)*dsu.size(v);
		//cout<<ans<<endl;
		dsu.union_sets(u,v);
	}
		cout<<ans<<endl;

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}