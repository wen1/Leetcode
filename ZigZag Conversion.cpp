#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        // get the magic number from nRows
        int magic = nRows * 2 - 2 ;
        string ss = s;
////////////////////////////////////////////////////////////////////////
        // get number of char of each row
        vector<int> rowNum(nRows,0);
        for(int i = 0; i < s.size(); i++){
            int tempid = i % magic;
            tempid = (tempid<nRows? tempid : magic-tempid);
            rowNum[tempid]++;
        }
////////////////////////////////////////////////////////////////////////
        for(int i = 1; i<nRows; i++) rowNum[i] += rowNum[i-1];
////////////////////////////////////////////////////////////////////////
        for(int i = 0; i< s.size(); i++){
            int tempRowID = i % magic;
            tempRowID = (tempRowID < nRows? tempRowID : magic-tempRowID);
            int tempColID = i / magic;
            int temp = i % magic;
            tempColID = (temp < nRows? ((temp == 0 || temp == nRows-1)? tempColID : tempColID * 2) : tempColID*2 + 1);
            int newID = (tempRowID == 0? 0 : rowNum[tempRowID-1]) + tempColID;
            ss[newID] = s[i];
        }
        return ss;
    }
};
