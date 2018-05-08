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
        int fday, y, m, d;
        fday = 5;
        inStream >> y >> m >> d;
        for (int j = 1582; j<y; j++){
            if ((j%400 == 0) || ((j%100 != 0) && (j%4 == 0))){
                fday += 2;
            }
            else{
                fday += 1;
            }
        }
        for (int j = 1; j<m; j++){
            if (j == 2){
                if ((m > 2) && ((y%400 == 0) || ((y%100 != 0) && (y%4 == 0)))){
                    fday += 1;
                }
            }
            else if (j%2 == 1){
                if (j<8){
                    fday += 3;
                }
                else{
                    fday += 2;
                }
            }
            else if (j<7){
                fday += 2;
            }
            else{
                fday += 3;
            }
        }
        fday += d-1;
        fday = fday%7;
        cout << fday <<endl;
    }
    inStream.close();
}
