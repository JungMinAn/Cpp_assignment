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
        int a, endnum, subnum;
        endnum = 1;
        inStream >> a;
        for (int j = 0; j<a; j++){
            int b;
            inStream >> b;
            subnum = b%10;
            endnum = (endnum*subnum)%10;
        }
        cout << endnum << endl;
    }
    inStream.close();
}
