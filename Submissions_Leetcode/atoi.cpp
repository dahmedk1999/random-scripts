#include <string>
using std::string;

class Solution {
public:
    int myAtoi(string s) {
        string temp;
        short stage=0;
        bool neg=false;
        for(int i=0;i<s.length();i++)
        {
            switch(s[i])
            {
                    //Stage 0: Leading whitespaces, continue and eat them until sign or digit. If whitespace after sign/digit, break.
                    //Stage 1: Signs, break if another sign or digit
                    //Stage 2: Invalid char read before digit or after digit, break.
                    //Stage 9: Invalid stage, negate everything to 0
                case 32:
                    if(stage)break; //If not stage 0, not on leading white space
                    stage=0;
                    //skip over space
                    break;
                case 43: if(stage==1){return 0;}neg=false;stage=1;break; //read first sign, if any. Set stage to 1 afterwards. If another sign is read, invalid input. Set stage to 9
                case 45: if(stage==1){return 0;}neg=true;stage=1; break; // "" ""
                case 46: stage=4;break;
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                case 56:
                case 57:
                    if(stage==2) //If non digits were read after or before signs/whitespaces.
                        return 0;
                    else if(stage==4)break;
                    temp+=s[i];
                    stage=3;
                        break;
                default:if (stage==4)break;
                    stage=2;
                        break;

            }
        }
        int ret=0;
        int size=temp.length();
        for(int i =0;i<size;i++)
        {
            if(ret < INT_MAX/10)
            {
                ret+=((temp[i]-'0')*(pow(10,size-i-1)));
            }
            else if(ret > INT_MAX/10)
            {
                if(!neg)
                {
                    ret= INT_MAX;
                    return ret;
                }
                if(neg)
                {
                    ret= INT_MIN;
                    return ret;    
                }                
            }
            else if(ret == INT_MAX/10)
            {
                if(temp[i]-'0'<8 && !neg)
                {
                    ret+=((temp[i]-'0')*(pow(10,size-i-1)));
                    return ret;
                }
                if(temp[i]-'0'<=8 && neg)
                {
                    ret+=((temp[i]-'0')*(pow(10,size-i-1)));
                    return ret;
                }
            }
        }
        if(neg)
            ret*=-1;
       
        return ret;
    }
};