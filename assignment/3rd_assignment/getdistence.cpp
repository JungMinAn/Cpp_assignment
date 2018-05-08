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
        int x1, x2, y1, y2, a1, a2;
        inStream >> x1 >> y1 >> x2 >> y2 >> a1 >> a2;
        if ((x1 <= a1)&&(a1 <= x2)){
            if (a2 < y1){
                cout << (y1-a2)*(y1-a2) << " " << (y1-a2) <<endl;
            }
            else if (a2 > y2){
                cout << (a2-y2)*(a2-y2) << " " << (a2-y2) <<endl;
            }
            else{cout << "0 0" <<endl;}
        }
        else if ((y1 <= a2)&&(a2 <= y2)){
            if (a1 < x1){
                cout << (x1-a1)*(x1-a1) << " " << (x1-a1) <<endl;
            }
            else if (a1 > x2){
                cout << (a1-x2)*(a1-x2) << " " << (a1-x2) <<endl;
            }
            else{cout << "0 0" <<endl;}
        }
        else if (a1 < x1){
            if (a2 < y1){
                cout << (x1-a1)*(x1-a1) + (y1-a2)*(y1-a2) << " " << (x1-a1) + (y1-a2) <<endl;
                }
            else if (a2 > y2){
                cout << (x1-a1)*(x1-a1) + (a2-y2)*(a2-y2) << " " << (x1-a1) + (a2-y2) <<endl;
                }
        }
        else if (a1 > x2){
            if (a2 < y1){
                cout << (a1-x2)*(a1-x2) + (y1-a2)*(y1-a2) << " " << (a1-x2) + (y1-a2) <<endl;
            }
            else if (a2 > y2){
                cout << (a1-x2)*(a1-x2) + (a2-y2)*(a2-y2) << " " << (a1-x2) + (a2-y2) <<endl;
            }
        }

    }
    inStream.close();
}
