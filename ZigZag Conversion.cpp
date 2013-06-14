class Solution {
public:
    string convert(string s, int nRows) {
        // get the magic number from nRows
        int magic = nRows+nRows-2;
        
        // get the number of char each row holds
        int rowNum[nRows];  rowNum[nRows-1] = s.size()/nRows;
        getRowNum( rowNum, nRows,s.size() );
        
        return "ss";
    }
    void getRowNum(int* rowNum,int nRows, int len){
        int quotient = len / nRows;
        int remainder = len % nRows;
        
        rowNum[0] = quotient + (remainder > 0? 1 : 0);
        rowNum[nRows-1] = quotient +
        for(int i = 1; i < nRows- ; i++){
            rowNum[i] = quotient + (i < remainder? quotient+1 : quotient) + (i);
        }
    }
};
