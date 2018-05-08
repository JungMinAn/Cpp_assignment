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
        int a;
        inStream >> a;
        for (int j = 1; j<=a; j++){
            int b;
            b = 0;
            for (int k = 1; k<=j; k++){
                cout << j + b << " ";
                b += a-k;
            }
            cout <<endl;
        }
    }
    inStream.close();
}
