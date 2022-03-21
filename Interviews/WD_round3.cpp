#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
int main()
{
    string a="tomorrow is a good day";
    string rep="night";
    string repl="day";
    int sizerepl=repl.length();

    int pos=a.find(repl);
    a.insert(pos,rep);
    cout<<a<<endl;

    pos=a.find(rep);
    int sizerep=rep.length();
    a.erase(pos+sizerep,sizerepl);
    cout<<a<<endl;


    //check if 17th bit of a number is 1
    int thirtytwo = 4294967295;
    int mask=131072;
    int check;
    check = 1 & (thirtytwo >> 17);
    cout<<"Bit 17 is "<<check;
    return 0;
}

//overloading example
void returnint(int i);
int returnint(int b,int a);

//overriding exampls
//in class animal
virtual int walk(){
    return -1;
}

//in class dog
int walk()
{
    //unique implementation
    return 0;
}

// 0 1         r1
// 0 1 2       r2
// 0 1 2 3     r3
// 0 1 2 3 4   r4
// r4+1 * r1+1 = 1 2 3 4 5 6 7 8 9 10 

// (rand % 5 = 0-4) randR
// int array[9]={0,1,2,3,4,}
// int sum 
// 
// return randR+randR 
// return sum % 10
// 0-9 in eq %

// Apples and Oranges box
// Labels ALWAYS incorrect
// ?A  ?O   ?A/O
// [a] [o] [a/o]
//  ^
//  a
// Then not A, must be A/O
// [a] [o] [a/o]
//      ^
//      a