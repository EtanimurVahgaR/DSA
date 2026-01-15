#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

// memoization 

int lcsLastIndex ( string& s1 , string& s2 , int i , int j , int res , vector<vector<int>>& memo) { 
    if ( i < 0  ||  j < 0 ) return 0 ; 
    
    if ( memo[i][j] != -1 ) return memo[i][j] ; 
    if ( s1[i] == s2[j] ) { 
        res = max ( res , lcsLastIndex( s1 , s2 , i -1  , j -1 , res,memo) +1 )  ;
    }else { 
        res = max ( lcsLastIndex( s1 , s2 , i-1 , j , res , memo), lcsLastIndex( s1 , s2 , i , j-1 , res,memo) ) ; 
    }
    memo[i][j] = res ; 
    
    return res ;
    
}
int lcsMemo(string &s1, string &s2) {
    int res = 0 ; 
    int n = s1.length() ; int m = s2.length() ; 
    vector<vector<int>> memo ( n , vector<int> ( m , - 1)) ;
    int i = n - 1 ; int j = m - 1 ; 
    res =  lcsLastIndex ( s1 , s2 , i , j , res, memo)  ; 
    return res ; 
}

// tabulation : 

int lcsTable(string &s1, string &s2) {
    int res = 0 ; 
    int n = s1.length() ; int m = s2.length() ; 
    vector<vector<int>> table ( n+1 , vector<int> (m+1 , 0)) ; 
    
    for ( int i = 1 ; i <= n ; i++ ) { 
        for ( int j = 1 ; j <= m ; j ++ ) { 
            if ( s1[i-1] == s2[j-1] ) {  
                table[i][j] = table[i-1][j-1] +  1 ; 
            }else {
                table[i][j] = max ( table[i-1][j] , table[i][j-1] ) ; 
            }
        }
    }
            
    return table[n][m] ; 
}

// space optimized tabulation 

int lcsBestTable(string &s1, string &s2) {
    int res = 0 ; 
    int n = s1.length() ; int m = s2.length() ; 
    vector<vector<int>> table ( 2  , vector<int> (m+1 , 0)) ; 
    
    for ( int i = 1 ; i <= n ; i++ ) { 
        for ( int j = 1 ; j <= m ; j ++ ) { 
            if ( s1[i-1] == s2[j-1] ) {  
                table[i%2][j] = table[(i-1)%2][j-1] +  1 ; 
            }else {
                table[i%2][j] = max ( table[(i-1)%2][j] , table[i%2][j-1] ) ; 
            }
        }
    }
            
    return table[n%2][m] ; 
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    // cout << "LCS: " << lcs(X, Y) << endl;
    cout << "LCS Memo: " << lcsMemo(X, Y) << endl;
    cout << "LCS Table: " << lcsTable(X, Y) << endl;
    cout << "LCS Memo Table: " << lcsBestTable(X, Y) << endl;
    cout << "expexted solution : " << 4 ;
    return 0;
}