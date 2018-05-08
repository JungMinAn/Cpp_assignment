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
        int a, avg;
        avg = 0;
        inStream >> a;
        int arr[a];
        for (int j = 0; j<a; j++){
            int b;
            inStream >> b;
            arr[j] = b;
        }
        int b;
        inStream >> b;
        cout << (a-b+1) << " ";
        for (int j = 0; j<=a-b; j++){
            avg = 0;
            for (int k = 0; k<b; k++){
                avg += arr[j+k];
            }
            avg /= b;
            cout << avg << " ";
        }
        cout <<endl;
    }
    inStream.close();
}
