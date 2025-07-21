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
int longestEndingWithCurr ( vector<string>& words , string curr , unordered_map<string ,int>& memo) {
    int count = 1; 
    if ( memo.find(curr) != memo.end() ) return memo[curr] ; 
    for ( string& w : words) { 
        if ( isPred(w, curr) ) { 
            count = max ( count , 1 + longestEndingWithCurr(words , w , memo)) ; 
        }
    }
    memo[curr] = count ; 
    return count ; 
}
int longestStringChain(vector<string> & words ) { 
    int res = 1 ;
    int n = words.size() ; 
    unordered_map<string,int> memo  ; 
    for ( auto word : words ) { 
        res = max ( res , longestEndingWithCurr(words, word, memo) ) ;
    }
    return res ;
}


int longestStringChainTable ( vector<string>& words ) {
    sort ( words.begin() , words.end() ,[](const auto& a , const auto&b) { 
        return a.length() > b.length() ; 
    } )  ;

    int n = words.size() ;
    vector<int> dp( n ,1 ) ; 
    int res = 1; 

    for ( int i = 0 ; i < n ; i ++ ) { 
        for ( int j = 0 ; j < i ; j++ ) { 
            if ( isPred(words[i] , words[j])) { 
                dp[i] = max ( dp[i] , dp[j] + 1 ) ; 
            }
        }
        res = max(res , dp[i]) ; 
    }
    return res;

}


int longestStringChainHash ( vector<string>& words ) {
    sort ( words.begin() , words.end() ,[](const auto& a , const auto&b) { 
        return a.length() < b.length() ; 
    } )  ;

    int n = words.size() ;
    unordered_map<string,int> dp ; 
    int res = 1; 

    for ( int i = 0 ; i < n ; i ++ ) { 
        dp[words[i]] = 1 ;
        for ( int j = 0 ; j < words[i].size() ; j++ ) { 
            string pred = words[i].substr(0 , j) + words[i].substr(j + 1) ; 
            if ( dp.find(pred) != dp.end() ) { 
                dp[words[i]] = max ( dp[words[i]] , dp[pred] + 1) ; 
            }        
        }
        res = max(res , dp[words[i]]) ; 
    }
    return res;
}


int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result = longestStringChainHash(words);
    cout<< "result : "<<result << endl; 

    assert(result == 4 && "Test case failedddd"); // "a" -> "ba" -> "bda" -> "bdca"
    std::cout << "Singular test case passed!" << endl;
    

    return 0;
}