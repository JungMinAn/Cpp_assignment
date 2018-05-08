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
        int a1, a2, b1, b2, c1, c2, area;
        inStream >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
        area = (b1-a1)*(c2-a2) - (c1-a1)*(b2-a2);
        if (area > 0){
            cout << area;
            cout << " 1" <<endl;
        }
        else if (area < 0){
            area = -area;
            cout << area;
            cout << " -1" <<endl;
        }
        else {
            cout << area;
            cout << " 0" <<endl;
        }
        
    }
    inStream.close();
}
