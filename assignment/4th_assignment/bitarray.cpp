#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
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
        bool *A;
        A = new bool[132];
        bool *B;
        B = new bool[132];
        inStream >> a;
        for (int j = 0; j<a; j++){
            int a1;
            inStream >> a1;
            A[a1] = true;
        }
        inStream >> b;
        for (int j = 0; j<b; j++){
            int b1;
            inStream >> b1;
            B[b1] = true;
        }
        int count;
        count = 0;
        for (int j = 0; j<132; j++){
            if ((A[j]) == 1 && (B[j] == 1)){
                count += 1;
            }
        }
        cout << count << " ";
        for (int j = 0; j<132; j++){
            if ((A[j]) == 1 && (B[j] == 1)){
                cout << j << " ";
            }
        }
        cout <<endl;
        count = 0;
        for (int j = 0; j<132; j++){
            if ((A[j]) == 1 || (B[j] == 1)){
                count += 1;
            }
        }
        cout << count << " ";
        for (int j = 0; j<132; j++){
            if ((A[j]) == 1 || (B[j] == 1)){
                cout << j << " ";
            }
        }
        cout <<endl;
        count = 0;
        for (int j = 0; j<132; j++){
            if ((A[j]) == 1 && (B[j] == 0)){
                count += 1;
            }
        }
        cout << count << " ";
        for (int j = 0; j<132; j++){
            if ((A[j]) == 1 && (B[j] == 0)){
                cout << j << " ";
            }
        }
        cout <<endl;
    }
    inStream.close();
}
