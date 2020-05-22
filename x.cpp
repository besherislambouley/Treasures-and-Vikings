/*
 * let reach [i][j] as the minimum time the vikings need to attack this cell 
 * we fill it using bfs from cell V to fill dis [i][j] and for each i , j see the minimum from dis [i] [ 0 -> m ] , dis [ 0->n ][m] taking care of the islands cells
 * we run a bfs from node Y noticing we only can visit a node if reach[i][j] > our current time 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=666013;
const ld pai=acos(-1);
int n , m , sx , sy , ex , ey , vx , vy ;
string s [709] ;
int done [709][709] , dis [709][709] , reach [709][709] ;
int X [] = { -1 , 0 , 1 , 0 } ;
int Y [] = { 0 , 1 , 0 , -1 } ;
void bfs ( int CX , int CY , int t ) {
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			dis [i][j] = 1e9; 
			done [i][j] = 0 ;
		}
	}
	dis [CX][CY] = 0 ;
	done[CX][CY] = 1 ;
	queue < pi > q ;
	q .push ( { CX , CY } ) ;
	while ( q .size () ) {
		int x = q .front () .fi ;
		int y = q .front () .se ;
		q .pop () ;
		for ( int i = 0 ; i < 4 ; i ++ ) {
			int nx = x + X [i] ;
			int ny = y + Y [i] ;
			if ( nx < n && nx >= 0 && ny < m && ny >= 0 && !done [nx][ny]  && s [nx][ny] != 'I' ) {
				if ( !t || ( t && reach [nx][ny] > dis [x][y] + 1 ) ) {
					q .push ( { nx , ny } ) ;
					done [nx][ny] = 1 ;
					dis [nx][ny] = dis [x][y] + 1 ; 
				}
			}
		}
	}
}
int main () {
	fast ; 
	cin >> n >> m ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> s [i] ;
		for ( int j = 0 ; j < m ; j ++ ) {
			if ( s [i][j] == 'Y' ) sx = i , sy = j ;
			if ( s [i][j] == 'T' ) ex = i , ey = j ;
			if ( s [i][j] == 'V' ) vx = i , vy = j ;
			reach [i][j] = 1e9 ;
		}
	}
	bfs ( vx , vy , 0 ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int mn = 1e9 ;
		for ( int j = 0 ; j < m ; j ++ ) {
			mn = min ( mn , dis [i][j] ) ;
			if ( s [i][j] == 'I' ) mn = 1e9 ;
			reach [i][j] = min ( reach [i][j] , mn ) ;
		}
		mn = 1e9 ;
		for ( int j = m -1 ; j >= 0 ; j -- ) {
			mn = min ( mn , dis [i][j] ) ;
                        if ( s [i][j] == 'I' ) mn = 1e9 ;
                        reach [i][j] = min ( reach [i][j] , mn ) ;
		}
	}
	for ( int j = 0 ; j < m ; j ++ ) {
		int mn = 1e9 ; 
		for ( int i = 0 ; i < n ; i ++ ) {
			mn = min ( mn , dis [i][j] ) ;
                        if ( s [i][j] == 'I' ) mn = 1e9 ;
                        reach [i][j] = min ( reach [i][j] , mn ) ;
		}
		for ( int i = n -1 ; i >= 0 ; i -- ) {
			mn = min ( mn , dis [i][j] ) ;
                        if ( s [i][j] == 'I' ) mn = 1e9 ;
                        reach [i][j] = min ( reach [i][j] , mn ) ;
		}
	}
	reach [sx][sy] = 1e9 ;
	bfs ( sx , sy , 1 ) ;
	if ( dis [ ex ] [ ey ] != 1e9 ) cout << "YES" << endl ;
	else cout << "NO" << endl ; 
}
