#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
// #define endl '\n'

// You are given an array of words where each word consists of lowercase English letters.
// 
// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
// 
// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
// 
// Return the length of the longest possible word chain with words chosen from the given list of words.
// 
//  
// 
// Example 1:
// 
// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:
// 
// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].


bool isPred ( string& child ,  string& parent ) { 
    if (child.length() + 1 != parent.length() ) return false ;
    int i = 0 , j = 0 ; 
    while ( i < child.length() && j < parent.length() ) { 
        if ( child[i] == parent[j]) { 
            i ++ ; j ++ ; 
        }else { 
            j++ ; 
        }
 
    }
    return ( i == child.length() );
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
        return a.length() < b.length() ; 
    } )  ;


    int n = words.size() ;
    vector<int> dp( n ,1 ) ; 
    int res = 1; 

    for ( int i = 0 ; i < n ; i ++ ) { 
        for ( int j = 0 ; j < i ; j++ ) { 
            if ( isPred(words[j] , words[i])) { 
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
    int result_hash = longestStringChainHash(words);
    cout << "Hash map DP result : " << result_hash << endl;
    assert(result_hash == 4 && "Hash map DP failed");

    int result_tab = longestStringChainTable(words);
    cout << "Tabulation DP result : " << result_tab << endl;
    assert(result_tab == 4 && "Tabulation DP failed");

    int result_rec = longestStringChain(words);
    cout << "Recursive+Memo result : " << result_rec << endl;
    assert(result_rec == 4 && "Recursive+Memo failed");

    std::cout << "All test cases passed!" << endl;
    return 0;
}