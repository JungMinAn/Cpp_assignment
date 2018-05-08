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
        int sum;
        sum = 0;
        inStream >> a >> b;
        for (int i = a; i<=b; i++){
            sum += i;
        }
        cout << sum << endl;
    }
    inStream.close();
    return 0;
}
