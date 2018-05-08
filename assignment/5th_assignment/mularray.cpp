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
        int a, b, c, d;
        inStream >> a >> b >> c;
        int arr1[a][b];
        int arr2[b][c];
        int arr3[a][c];
        for (int j = 0; j<a; j++){
            for (int k = 0; k<b; k++){
                inStream >> d;
                arr1[j][k] = d;
            }
        }

        for (int j = 0; j<b; j++){
            for (int k = 0; k<c; k++){
                inStream >> d;
                arr2[j][k] = d;
            }
        }
        for (int j = 0; j<a; j++){
            for (int k = 0; k<c; k++){
                d = 0;
                for (int l = 0; l<b; l++){
                    d += (arr1[j][l] * arr2[l][k]);
                }
                arr3[j][k] = d;
                cout << arr3[j][k] << " ";
            }
            cout <<endl;
        }

    }
    inStream.close();
}
