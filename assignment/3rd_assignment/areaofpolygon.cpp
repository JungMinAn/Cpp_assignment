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
        int a, area, fx, fy, px, py, nx, ny;
        area = 0;
        inStream >> a >> fx >> fy;
        px = fx;
        py = fy;
        for (int j = 0; j<a; j++){
            if (j == a-1){
                area += (px + fx)*(fy-py);
            }
            else{
                int b, c;
                inStream >> b >> c;
                nx = b;
                ny = c;
                area += (px + nx)*(ny-py);
                px = nx;
                py = ny;
            }
        }
        if (area < 0){
                cout << -area << " -1" <<endl;
            }
            else{
                cout << area << " 1" <<endl;
            }
    }
    inStream.close();
}
