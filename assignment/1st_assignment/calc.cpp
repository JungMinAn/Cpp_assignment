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
        int sum, diff, abs_diff, mul, div, mod, max, eqly;
        inStream >> a >> b;
        sum = a + b;
        diff = a - b;
        abs_diff = abs(diff);
        mul = a * b;
        div = a / b;
        mod = a % b;
        if (a > b){
            max = a;
        }
        else{
            max = b;        
        }
        if (a == b){
            eqly = 1;
        }
        else{
            eqly = 0;
        }
        cout << sum << " " << diff << " " << abs_diff << " " << mul << " ";
        cout << div << " " << mod << " " << max << " " << eqly << endl;
    }
    inStream.close();
}
