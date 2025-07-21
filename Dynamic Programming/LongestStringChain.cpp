#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
// #define endl '\n'

bool isPred ( string& child , string& parent ) {
    if ( child.length() + 1 != parent.length() ) return false ; 
    int i = 0 ; int j = 0 ; 
    while ( i < child.length() && j < parent.length() ) { 
        if ( child[i] == parent[j] ) i ++ , j ++  ;
        else j++ ;
    }
    return ( i == child.size() ) ; 
}
int longestEndingWithCurr ( vector<string>& words , string curr) {
    int count = 1; 
    for ( string& w : words) { 
        if ( isPred(w, curr) ) { 
            count = max ( count , 1 + longestEndingWithCurr(words , w)) ; 
        }
    }
    return count ; 
}
int longestStringChain(vector<string> & words ) { 
    int res = 1 ;
    for ( auto word : words ) { 
        res = max ( res , longestEndingWithCurr(words, word)) ;
    }
    return res ;
}


int main() {

    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result = longestStringChain(words);
    assert(result == 4 && "Test case failedddd"); // "a" -> "ba" -> "bda" -> "bdca"
    std::cout << "Singular test case passed!" << endl;
    

    return 0;
}