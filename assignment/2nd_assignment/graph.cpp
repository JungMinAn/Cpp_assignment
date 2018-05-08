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
        b = a/2;
        for (int j = 0; j<a; j++){  
            for (int k = 1; k<=a; k++){
                if (j == b){
                    if (k == b+1){
                        cout << "O";
                    }
                    else {
                        cout << "+";
                    }
                }
                else {
                    if (k == a-j){
                    cout << "*";
                    }
                    else if (k == b+1){
                        cout << "I";
                    }
                    else {
                        cout << ".";
                    }
                }
            }
            cout << endl;
        }
    }
    inStream.close();
}

