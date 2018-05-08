#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
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
        int a, a_sqrt, count;
        inStream >> a;
        a_sqrt = sqrt(a);
        count = 0;
        for (int j = 1; j <= a_sqrt; j++){
            if ((j>1) && (a%j == 0)){
                count += 1;
            }
        }
        if (count == 0){
            cout << "1" <<endl;
        }
        else {
            cout << "0" <<endl;
        }
    }
    inStream.close();
}
