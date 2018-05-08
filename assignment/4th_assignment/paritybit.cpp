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
        int a, count, temp;
        inStream >> a;
        temp = a;
        count = 0;
        while (a > 0){
            int r = a%2;
            if (r == 1){
                count += 1;
            }
            a /= 2;
        }
        if (count%2 == 1){
            cout << temp + 2147483648 <<endl;
        }
        else {
            cout << temp <<endl;
        }
    }
    inStream.close();
}
