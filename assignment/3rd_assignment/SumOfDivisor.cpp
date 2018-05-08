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
        int a, sum, count;
        inStream >> a;
        sum = 1;
        count = 1;
        for (int j = 2; j <= sqrt(a); j++){
            if (a%j == 0){
                if (j*j != a){
                    count += 2;
                    sum += (j + a/j);
                }
                else {
                    count += 1;
                    sum += j;
                }
            }
        }
        
        cout << count << " " << sum <<endl;
    }
    inStream.close();
}
