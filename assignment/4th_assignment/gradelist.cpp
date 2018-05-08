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
        int *garray = new int[101]; 
        inStream >> a;
        for (int j = 0; j<a; j++){
            int b;
            inStream >> b;
            garray[b] += 1;
        }
        for (int j = 0; j<101; j++){
            if (garray[j] > 0){
                cout << j << " " << garray[j] << " ";
            }
        }
        cout <<endl;

    }
    inStream.close();
}
