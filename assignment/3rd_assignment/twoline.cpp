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
        int a1, a2, a3, a4, b1, b2, b3, b4;
        inStream >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4;
        if ((a3 - a1) == 0){
            swap(a1, b1);
            swap(a2, b2);
            swap(a3, b3);
            swap(a4, b4);
        }
        if (((a1 < b1)&&(a3 < b1)) || ((a1 > b1)&&(a3 > b1)) || ((a2 > b2)&&(a2 > b4)) || ((a2 < b2)&&(a2 < b4))){
            cout << "0" <<endl;
        }
        else if ((a2 == b2) || (a2 == b4) || (b1 == a1) || (b1 == a3)){
            cout << "2" <<endl;
        }
        else{
            cout << "1" <<endl;
        }
    }
    inStream.close();
}
