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
        int fday, y, m, dcount, daynum;
        dcount = 1;
        fday = 5;
        inStream >> y >> m;
        cout << y << " " << m <<endl;
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
        fday = fday%7;
        for (int j = 0; j<fday; j++){
            cout << "0 ";
        }
        if (m == 2){
            if ((y%400 == 0) || ((y%100 != 0) && (y%4 == 0))){
                daynum = 29;
            }
            else{
                daynum = 28;
            }
        }
        else if (m%2 == 1){
                if (m<8){
                    daynum = 31;
                }
                else{
                    daynum = 30;
                }
            }
        else if (m<7){
            daynum = 30;
        }
        else{
            daynum = 31;
        }
        while (dcount <= daynum){
            cout << dcount << " ";
            fday++;
            if (fday == 7){
                cout <<endl;
                fday = 0;
            }
            dcount++;
        }
        while ((fday != 7) && (fday != 0)){
            cout << "0 ";
            fday++;
            if (fday == 7){
                cout <<endl;
            }
        }
    }
    inStream.close();
}
