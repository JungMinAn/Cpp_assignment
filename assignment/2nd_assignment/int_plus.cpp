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
        int a, b;
        inStream >> a;
        int sum;
        sum = 0;
        for (int j = 0; j<a; j++){
            inStream >> b;
            sum += b;
        }
        cout << sum <<endl; 
    }
    inStream.close();
}
