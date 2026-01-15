#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
int LpsHelper(string &s , int i , int j , int res) { 
    if ( i > j ) return 0 ;
    if ( i == j) return 1 ;

    if ( s[i] == s[j] ) { 
        res = LpsHelper(s , i + 1 , j-1 , res + 1) + 2; 
    }else { 
        res = max ( LpsHelper(s, i + 1 , j  ,res) , LpsHelper( s , i , j -1 , res )) ; 
    }

    return res ; 
}

int LongestPalindromicSequence(string &s) { 
    return LpsHelper(s,  0 , s.length() -1 , 0) ; 
}
int LpsMemoHelper(string& s , int i , int j , vector<vector<int>> &memo ) { 
    if ( i > j ) return 0 ;
    if ( i == j) return 1 ;
    if ( memo[i][j] != -1 ) return memo[i][j] ; 
    if ( s[i] == s[j] ) { 

        memo[i][j] = LpsMemoHelper(s , i + 1 , j-1 , memo) + 2; 
    }else { 

        memo[i][j] = max ( LpsMemoHelper(s, i + 1 , j  ,memo) , LpsMemoHelper( s , i , j -1  ,memo)) ; 
    }

    return memo[i][j] ; 
} 

int LpsMemo ( string&s) { 
    int n = s.length() ; 
    vector<vector<int>> memo ( n  , vector<int> (n , -1)) ; 
    return LpsMemoHelper(s,  0 , n - 1 , memo) ; 
}

int LpsTable ( string& s ) {  
    int n = s.length() ; 
    vector<vector<int>> table ( n , vector<int>( n , 0)) ; 
    int res = 0 ; 
    int iter = 0 ; 
    for ( int i = n ; i >= 0  ; i -- ) { 
        for ( int j =  1 ; j < n;  j++ ) { 

            if(i == j){
                table[i][j] = 1;
                continue ; 
            }
            if (s[i] == s[j]) { 
                // code for matching
                if(i + 1 == j) table[i][j] = 2;
                else table[i][j] = table[i + 1][j - 1] + 2;
            }else { 
                // code for not matching 
                table[i][j ] = max(table[i+1][j] , table[i][j-1]) ;             
            }

        }
    }
    return table[0][n-1] ; 
}
int main() {
    string s1 = "bbabcbcab";
    // The longest palindromic subsequence is "babcbab" (length 7)
    assert(LongestPalindromicSequence(s1) == 7);
    assert(LpsMemo(s1) == 7);
    assert(LpsTable(s1) == 7);
    cout<<"7 passed"<<endl ; 
    

    string s2 = "cbbd";
    // The longest palindromic subsequence is "bb" (length 2)
    assert(LongestPalindromicSequence(s2) == 2);
    assert(LpsMemo(s2) == 2);
    assert(LpsTable(s1) == 2);
    cout<<"2 passed"<<endl ; 

    string s3 = "a";
    // Single character string, LPS is 1
    assert(LongestPalindromicSequence(s3) == 1);
    assert(LpsMemo(s3) == 1);
    assert(LpsTable(s1) == 1);
    cout<<"1 passed"<<endl ; 
    string s4 = "";
    // Empty string, LPS is 0
    assert(LongestPalindromicSequence(s4) == 0);
    assert(LpsMemo(s4) == 0);
    assert(LpsTable(s1) == 0);
    cout<<"0 passed"<<endl ; 

    cout << "All test cases passed!\n";

    return 0;
}