#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
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
        int a, fnum;
        vector<int> v;
        v.clear();
        inStream >> a;
        for (int j = 2; j<=sqrt(a); j++){
            if (j == a){
                break;
            }
            bool isf = true;
            for (int k = 2; k<j; k++){
                if (j % k == 0){
                    isf = false;
                    break;
                }
            }
            if ((isf == true) && (a % j == 0)){
                v.push_back(j);
            }
        }
        if (v.size() == 0){
            cout << "1 " << a << " 1" <<endl;
            continue;
        }
        int b = a;
        for (int j = 0; j<v.size(); j++){
            while (b % v[j] == 0){
                b /= v[j];
            }
        }
        if (b == 1){
             cout << v.size() << " ";
        }
        else{
            cout << v.size() + 1 << " ";
        }
        for (int j = 0; j<v.size(); j++){
            int count = 0;
            if (a % v[j] == 0){
                cout << v[j] << " ";
                while (a % v[j] == 0){
                    a /= v[j];
                    count++;
                }
                cout << count << " ";
            }
        }
        if (a != 1){
            cout << a << " 1";
        }
        cout <<endl;
    }
    inStream.close();
}
