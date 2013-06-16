#include <string>
#include <sstream>
#include <algorithm>
#include <math>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int sign = x / abs(x);
        string s = integerToString(abs(x));
        std::reverse(s.begin(),s.end());
        int res = stringToInt(s);
        return sign * res;
    }
    // return a string of the given int
    // ex: integerToString(10) -> "10"
    string integerToString(int a){
        stringstream res;
        res << a;
        return res.str();
    }
    // return a int of the given string
    // ex: stringToInt("01") -> 1
    int stringToInt(string s){
        stringstream temp;
        temp << s;
        int res;
        temp >> res;
        return res;
    }
};
//////////////////////////////////////////////////////////////////////
/* REMARK
Did you notice that the reversed integer might overflow? 
Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. 
How should you handle such cases?
*/
//////////////////////////////////////////////////////////////////////
// another version without using  STL
class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int sign = (x>0? 1 : -1);
        int absVal = x / sign;
        string  s = reverseStringFromInt(absVal);
        int res = stringToInt(s);
        return res * sign;
    }
    
    // return a string of the given int reversed (without using sstream)
    // ex: reverseStringFromInt(10) -> "1"
    string reverseStringFromInt(int a){
        int base = 10;
        string s;
        char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};
        while(a){
            s.push_back(digits[a%10]);
            a = a / base;
        }
        return s;
    }
    int stringToInt(string s){
        int multiplier = 1;
        int res = 0;
        for(int i = s.size()-1; i>=0; i--){
            s[i] -= '0';
            res += s[i] * multiplier;
            multiplier *= 10;
        }
        return res;
    }

};
