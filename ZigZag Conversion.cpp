// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        // get the magic number from nRows
        int magic = nRows * 2 - 2 ;
        string ss = s;
        // get number of char of each row
        vector<int> rowNum(nRows,0);
        for(int i = 0; i < s.size(); i++){
            int tempid = i % magic;
            tempid = (tempid<nRows? tempid : magic-tempid);
            rowNum[tempid]++;
        }
        
        for(int i =0; i<rowNum.size(); i++) cout << rowNum[i] << " ";
        cout << endl;
////////////////////////////////////////////////////////////////////////
        for(int i = 1; i<nRows; i++) rowNum[i] += rowNum[i-1];
        for(int i =0; i<rowNum.size(); i++) cout << rowNum[i] << " ";
        cout << endl;
////////////////////////////////////////////////////////////////////////
        for(int i = 0; i< s.size(); i++){
            int tempRowID = i % magic;
            tempRowID = (tempRowID < nRows? tempRowID : magic-tempRowID);
            int tempColID = i / magic;
            int temp = i % magic;
            tempColID = (temp < nRows? ((temp == 0 || temp == nRows-1)? tempColID : tempColID * 2) : tempColID*2 + 1);
            int newID = (tempRowID == 0? 0 : rowNum[tempRowID-1]) + tempColID;
            ss[newID] = s[i];
            //
            cout << "new:\t" << newID << "\told:\t" << i << endl;
        }
        cout << ss << endl;
        return "ss";
    }
};
/*    void getRowNum(int* rowNum,int nRows, int len){
        int quotient = len / nRows;
        int remainder = len % nRows;
        
        rowNum[0] = quotient + (remainder > 0? 1 : 0);
        rowNum[nRows-1] = quotient +
        for(int i = 1; i < nRows- ; i++){
            rowNum[i] = quotient + (i < remainder? quotient+1 : quotient) + (i);
        }
    }
*/
