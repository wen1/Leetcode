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
            tempid = i % magic;
            x = (tempid<nRows? tempid : magic-tempid);
            rowNum[x]++;
        }
        
        for(int i =0; i<rowNum.size(); i++) cout << rowNum[i] << " ";
        //
        
        
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
