#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int dp [ 2000 ] ; 
int FibonnaciSequenceReq ( int n , vector<int> & dp ) { 
    if ( n == 0 ) return 1;  
    if ( n == 1 ) return 1;  
    if ( dp [n] != -1 ) return dp[n] ; 
    return dp[n] = FibonnaciSequenceReq(n-1 ,dp ) + FibonnaciSequenceReq(n-2 ,dp ) ; 
}

int FibonnaciSequence ( int n ) {
    vector<int> dp ( n + 1 , -1 ) ;
    return FibonnaciSequenceReq(n,dp) ;
} 

int main() {
    int n ; 
    cin >> n ; 
    for ( int i = 0  ; i < n ; i ++ ) { 
        cout << FibonnaciSequence(i) << " "; 
    } 
}