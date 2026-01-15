#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
int EdHelper(string& s1 , string& s2 , int m , int n) { 
    if ( m == 0 ) return n ; 
    if ( n == 0 ) return m ; 

    if (s1[m-1] == s2[n-1])  { 
        return EdHelper(s1 , s2 , m -1 , n-1 ) ;
    }
    return 1 + min ( { 
            EdHelper(s1 , s2 , m-1 , n) ,
            EdHelper(s1 , s2 , m-1 , n-1) ,
            EdHelper(s1 , s2 , m , n-1) ,
        });
}
int EditDistance(string& s1 , string& s2 ) { 
    return EdHelper(s1 , s2 , s1.length() , s2.length()) ; 
}
int EdMemoHelper(string& s1 , string& s2 , int m , int n , vector<vector<int>>& memo) { 
    if ( n == 0 ) return m ; 
    if ( m == 0 ) return n ; 
    if ( memo[m][n] != -1) return memo[m][n] ; 
        
    if ( s1[m-1] == s2[n-1]) { 
        
        return memo[m][n] = EdMemoHelper(s1,s2,m-1,n-1,memo) ; 
    }

    int remove  = EdMemoHelper(s1, s2, m - 1, n, memo);
    int replace = EdMemoHelper(s1, s2, m - 1, n - 1, memo);
    int insert  = EdMemoHelper(s1, s2, m, n - 1, memo);
    memo[m][n] = 1 +  min({insert , replace, remove}) ; 
    return memo[m][n];
}
int EditDistanceMemo(string & s1 , string& s2 ) { 
    int m = s1.length() ; 
    int n = s2.length() ; 
    vector<vector<int>> memo ( m+1 , vector<int> ( n+1 , -1 )) ;  
    return EdMemoHelper(s1 , s2, m , n , memo) ; 
}

int EditDistanceTable( string& s1 , string& s2 ) {
    int m = s1.length() ; int n = s2.length() ; 
    vector<vector<int>> table ( m+1 , vector<int> ( n+1 , 0 )) ; 
    for ( int i = 0 ; i <= m ; i++ ) { 
        table[i][0] = i ; 
    }
    for ( int j = 0 ; j <= n ; j++ ) { 
        table[0][j] = j ; 
    }

    for ( int i = 1 ; i <= m ; i++ ) { 
        for ( int j = 1 ; j <= n ; j++ ) { 
            if ( s1[i-1] == s2[j-1] ) { 
               table[i][j] = table[i-1][j-1] ;  
            }else { 
                table[i][j] = 1 + min({ table[i-1][j] , table[i-1][j-1] , table[i][j-1] }) ; 
            }
        } 
    }
    return table[m][n];
    
}
int EditDistanceTableSpaceOptimized( string& s1 , string& s2 ) {
    int m = s1.length() ; int n = s2.length() ; 
    vector<vector<int>> table ( 2 , vector<int> ( n+1 , 0 )) ; 

    for ( int j = 0 ; j <= n ; j++ ) { 
        table[0][j] = j ; 
    }

    for ( int i = 1 ; i <= m ; i++ ) { 
        table[i%2][0] = i ;
        for ( int j = 1 ; j <= n ; j++ ) { 
            if ( s1[i-1] == s2[j-1] ) { 
                table[(i)%2][j] = table[(i-1)%2][j-1] ;  
            }else { 
                table[(i)%2][j] = 1 + min({ table[(i-1)%2][j] , table[(i-1)%2][j-1] , table[(i)%2][j-1] }) ; 
            }
        } 
    }
    return table[m%2][n];
    
}
int main() {
    {
        string s1 = "kitten";
        string s2 = "sitting";
        assert(EditDistance(s1, s2) == 3);
        assert(EditDistanceMemo(s1 , s2) == 3) ; 
        assert(EditDistanceTable(s1 , s2) == 3) ; 
        assert(EditDistanceTableSpaceOptimized(s1 , s2) == 3) ; 
    }
    {
        string s1 = "flaw";
        string s2 = "lawn";
        assert(EditDistance(s1, s2) == 2);
        assert(EditDistanceMemo(s1 , s2) == 2) ; 
        assert(EditDistanceTable(s1 , s2) == 2) ; 
        assert(EditDistanceTableSpaceOptimized(s1 , s2) == 2) ; 
        
    }
    {
        string s1 = "intention";
        string s2 = "execution";
        assert(EditDistance(s1, s2) == 5);
        assert(EditDistanceMemo(s1 , s2) == 5) ; 
        assert(EditDistanceTable(s1 , s2) == 5) ; 
        assert(EditDistanceTableSpaceOptimized(s1 , s2) == 5) ; 
    }
    {
        string s1 = "";
        string s2 = "abc";
        assert(EditDistance(s1, s2) == 3);
        assert(EditDistanceMemo(s1 , s2) == 3) ; 
        assert(EditDistanceTable(s1 , s2) == 3) ; 
        assert(EditDistanceTableSpaceOptimized(s1 , s2) == 3) ; 
    }
    {
        string s1 = "abc";
        string s2 = "";
        assert(EditDistance(s1, s2) == 3);
        assert(EditDistanceMemo(s1 , s2) == 3) ; 
        assert(EditDistanceTable(s1 , s2) == 3) ; 
        assert(EditDistanceTableSpaceOptimized(s1 , s2) == 3) ; 
    }
    {
        string s1 = "abc";
        string s2 = "abc";
        assert(EditDistance(s1, s2) == 0);
        assert(EditDistanceMemo(s1, s2) == 0);
        assert(EditDistanceTable(s1, s2) == 0);
        assert(EditDistanceTableSpaceOptimized(s1, s2) == 0);
    }
    cout << "All test cases passed!" << endl;

    return 0;
}