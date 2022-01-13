#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> substringfinder(string s)
{
    int size= s.length();

    vector<string> substrings;
    for (int i=0;i<size;i++)
    {
        for(int j=1;j<size-1;j++)
        {
            substrings.push_back(s.substr(i,j));          
        }
    }
    return substrings;
}

bool isPalindrome(string s)
{
    int size= s.length();
    int lastIndex=size-1;
    bool ispalindrome=true;
    for(int i =0; i<(size)/2;i++)
    {
        if(s[i]==s[lastIndex--]) //if first++ and last-- index keep matching, then it is a palindrome. if they dont match, it is not.
            ispalindrome=true;
        else ispalindrome=false;
    }
    return ispalindrome;

}
vector<vector<string>> scanner(string s)
{
    int size= s.length();
    vector<vector<string>> ret;

    vector<string> temp=substringfinder(s);
    for(int i =0;i<temp.size();i++)
    {
        if(isPalindrome(temp[i]))
            
           ret[i].push_back(temp[i]);
    }
    return ret;
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
    string test= "ababa";
    int size= s.length();
    vector<vector<string>> ret;

    vector<string> temp=substringfinder(s);
    for(int i =0;i<temp.size();i++)
    {
        if(isPalindrome(temp[i])){
            vector<string> temp2;
            temp2.push_back(temp[i]);
            ret.push_back(temp2);
        }
    }
    return ret;
    }
};