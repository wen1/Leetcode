#include <utility>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    pair<int, int > longest;
public:
    string longestPalindrome(string s) {
        longest.first = 0;
        longest.second = 0;
        int maxLen = 1;
        for (int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if ( isPalindromic(i,j,s) && (maxLen < j - i + 1) ){
                    longest.first = i;
                    longest.second = j;
                    maxLen = longest.second -longest.first + 1;
                }            
            }
        }
        return s.substr(longest.first,maxLen);
    }
    bool isPalindromic(int start , int end, const string& s){
        for (int i = 0; i< (end-start+1)/2; i++){
            //cout << s[start+i] << " " << s[end-i] << endl;
            if(s[start+i]!= s[end-i]) return false;
        }
        return true;
    }
};
