#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void sortint(int &a, int &b, int &c) {
    int maxnum, temp;
    maxnum = 0;
    temp = 0;
    int list1[3] = {a, b, c};
    for (int i = 0; i < 3; i++){
        if (list1[i] > maxnum){
            maxnum = list1[i];
        }
    }
    for (int i = 0; i<3; i++){
        if (list1[i] == maxnum){
            temp = list1[i];
            list1[i] = list1[2];
            list1[2] = temp;
        }
    }
    a = list1[0];
    b = list1[1];
    c = list1[2];
}
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
        int a1, a2, b1, b2, c1, c2, l1, l2, l3, m, k;
        inStream >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
        l1 = (b1-a1)*(b1-a1) + (b2-a2)*(b2-a2);
        l2 = (c1-a1)*(c1-a1) + (c2-a2)*(c2-a2);
        l3 = (b1-c1)*(b1-c1) + (b2-c2)*(b2-c2);
        k = (b2-a2)*(c1-a1) - (b1-a1)*(c2-a2);
        sortint(l1, l2, l3);
        if (k == 0){
            cout << "0" <<endl;
        }
        else{
            if (l1 + l2 == l3){
                cout << "1" <<endl;
            }
            else if (l1 + l2 < l3){
                cout << "2" <<endl;
            }
            else if (l1 + l2 > l3){
                cout << "3" <<endl;
            }
        }
        
    }
    inStream.close();
}
