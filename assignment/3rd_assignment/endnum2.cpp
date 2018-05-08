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
        int a, basicnum, endnum, count2, count5, r, tcount;
        inStream >> a;
        basicnum = 1;
        count2 = 0;
        count5 = 0;
        endnum = 1;
        for (int j = 0; j < a; j++){
            int b;
            inStream >> b;
            while (b%5 == 0){
                count5 += 1;
                b = b/5;
            }
            while (b%2 == 0){
                count2 += 1;
                b = b/2;
            }
            endnum  = (endnum * (b%10))%10;
        }
        if (count2 > count5){
            tcount = count5;
            r = (count2 - count5)%4;
            if (r == 3){endnum *= 8;}
            else if (r == 0){endnum *= 6;}
            else {endnum *= r*2;}
        }
        else if (count5 > count2){
            tcount = count2;
            endnum *= 5;
        }
        else {tcount = count2;}
        endnum = endnum%10;
        cout << endnum << " " << tcount <<endl;
    }
    inStream.close();
}
