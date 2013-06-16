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
