#include <bits/stdc++.h>
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


int main() {
    string s1 = "bbabcbcab";
    // The longest palindromic subsequence is "babcbab" (length 7)
    assert(LongestPalindromicSequence(s1) == 7);

    string s2 = "cbbd";
    // The longest palindromic subsequence is "bb" (length 2)
    assert(LongestPalindromicSequence(s2) == 2);

    string s3 = "a";
    // Single character string, LPS is 1
    assert(LongestPalindromicSequence(s3) == 1);

    string s4 = "";
    // Empty string, LPS is 0
    assert(LongestPalindromicSequence(s4) == 0);

    cout << "All test cases passed!\n";

    return 0;
}