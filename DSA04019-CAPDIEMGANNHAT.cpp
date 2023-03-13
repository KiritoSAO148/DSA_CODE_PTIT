#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TC() int t; cin >> t; while (t--)
#define el cout << "\n"
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn

const int MOD = (int) 1e9+7;

void FileIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

struct Point{
	int x, y;
};

int cmpX(const void *a, const void *b){
	Point *p1 = (Point*)a, *p2 = (Point*)b;
	if (p1->x != p2->x) return p1->x - p2->x;
	return p1->y - p2->y;
}

int cmpY(const void *a, const void *b){
	Point *p1 = (Point*)a, *p2 = (Point*)b;
	if (p1->y != p2->y) return p1->y - p2->y;
	return p1->x - p2->x;
}

double distance(Point p1, Point p2){
	return sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (double)(p1.y - p2.y) * (p1.y - p2.y));
}

double min(double a, double b){
	if (a < b) return a;
	return b;
}

double bf(Point a[], int n){
	double res = DBL_MAX;
	for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j) 
			res = min(res, distance(a[i], a[j]));
    return res;
}

double stripClosest(Point strip[], int size, double d){
    double res = d;
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < res; ++j) 
			res = min(res, distance(strip[i], strip[j]));
    return res;
}

double closestUtil(Point Px[], Point Py[], int n){
    if (n <= 3) return bf(Px, n);
    int mid = n / 2;
    Point midPoint = Px[mid];
    Point Pyl[mid];
    Point Pyr[n - mid];
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i){
      	if ((Py[i].x < midPoint.x || (Py[i].x == midPoint.x && Py[i].y < midPoint.y)) && l < mid)
        	Pyl[l++] = Py[i];
      	else Pyr[r++] = Py[i];
    }
    double dl = closestUtil(Px, Pyl, mid);
    double dr = closestUtil(Px + mid, Pyr, n - mid);
    double d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; ++i)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i];
			++j;
    return stripClosest(strip, j, d);
}

double closest(Point P[], int n){
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; ++i){
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(Point), cmpX);
    qsort(Py, n, sizeof(Point), cmpY);
    return closestUtil(Px, Py, n);
}

int main(){
    //FileIO();
    FastIO;
    TC(){
    	int n; cin >> n;
    	Point a[n];
    	f0 (i,n) cin >> a[i].x >> a[i].y;
    	cout << fixed << setprecision(6) << closest(a, n); el;
	}
    return 0;
}

