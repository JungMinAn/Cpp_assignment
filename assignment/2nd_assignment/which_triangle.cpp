#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    
    for (int i = 0; i<numTestCases; i++){
        int a, b, c;
        inStream >> a >> b >> c;
        if (a + b <= c){
            cout << "0" <<endl;
        }
        else if ((a == b)&&(b == c)&&(a == c)){
            cout << "1" <<endl;
        }
        else if (a*a + b*b == c*c){
            cout << "2" <<endl;
        }
        else if (((a == b) && (a!=c)) || ((b == c) && (a!=b))){
            cout << "3" <<endl;
        }
        else
            cout << "4" <<endl;
    }
    inStream.close();
}


