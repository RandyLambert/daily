class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sLen = S.size()-1;
        int tLen = T.size()-1;

        int sCnt = 0;
        int sNum = 0;
        int tNum = 0;
        while(sLen >= 0){
            if(S[sLen] == '#'){
                sCnt++;
                sLen--;
            } else {
                if(sCnt != 0){
                    S[sLen] = '#';
                    sLen--;
                    sCnt--;
                } else{
                    sLen--;
                    sNum++;
                }
            }
        }

        int tCnt = 0;
        while(tLen >= 0){
            if(T[tLen] == '#'){
                tCnt++;
                tLen--;
            } else {
                if(tCnt != 0){
                    T[tLen] = '#';
                    tLen--;
                    tCnt--;
                } else {
                    tLen--;
                    tNum++;
                }
            }
        }
        if(tNum != sNum){
            return false;
        } else {
            int cnts = S.size()-1;
            int cntt = T.size()-1;
            int xxx = 0;
            while(cnts >= 0 && cntt >= 0){
                while(S[cnts] == '#' && cnts > 0){
                    cnts--;
                }
                while(T[cntt] == '#' && cntt > 0){
                    cntt--;
                }
                if(S[cnts] == T[cntt] && S[cnts]!= '#' && T[cntt]!= '#'){
                    xxx++;
                    if(cnts == 0 || cntt == 0){
                        break;
                    } else {
                        cnts--;
                        cntt--;
                    }
                } else {
                    break;
                } 
            }
            if(xxx == tNum){
                return true;
            } else {
                return false;
            }
        }
    }
};
