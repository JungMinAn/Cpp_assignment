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
        int a, b, c;
        inStream >> a >> b;
        int arr1[a*b];
        int arr2[a*b];
        int arr3[a*b];
        for (int j = 0; j<a*b; j++){
            inStream >> c;
            arr1[j] = c;
        }
        for (int j = 0; j<a*b; j++){
            inStream >> c;
            arr2[j] = c;
        }
        int count = 1;
        for (int j = 0; j<a*b; j++){
            int p;
            p = arr1[j] + arr2[j];
            arr3[j] = p;
            cout << arr3[j] << " ";
            if (count == b){
                count = 0;
                cout <<endl;
            }
            count++;
        }
    }
    inStream.close();
}
