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
        int b;
        inStream >> a;
        b = a/2;
        for (int j = 0; j<a; j++){
            if (j <= b){        
                for (int k1 = 0; k1<b-j; k1++){
                    cout << "*";
                }
                for (int k2 = 0; k2<(2*j+1); k2++){
                    cout << "+";
                }
                for (int k3 = 0; k3<b-j; k3++){
                    cout << "*";
                }
                cout << endl;
            }
            else{
                for (int k4 = 0; k4<j-b; k4++){
                    cout << "*";
                }
                for (int k5 = 0; k5<(a-2*(j-b)); k5++){
                    cout << "+";
                }
                for (int k6 = 0; k6<j-b; k6++){
                    cout << "*";
                }
                cout << endl;
            }
        }
    }
    inStream.close();
}
