#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> hvector;

bool isinVec(int n){
    for (int i = 0; i<hvector.size(); i++){
        if (hvector.at(i) == n){
            return true;
        }
    }
    return false;
}
void allinvec(int n){
    if (isinVec(n*2) && isinVec(n*3) && isinVec(n*5)){
        hvector.erase(hvector.begin());
    }
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
        int a, min;
        min = 398580751;
        hvector.push_back(1);
        inStream >> a;
        int *fhlist;
        fhlist = new int[a];
        fhlist[0] = 1;
        if (a == 1){
            cout << "1" <<endl;
        }
        for (int j = 1; j<a; j++){
            for (int v = 0; v<hvector.size(); v++){
                int obj;
                obj = hvector[v]*2;
                if (obj >= min){
                    continue;
                }
                else{ 
                    if (obj > hvector.back()){
                        if (obj < min){
                            min = obj;
                            continue;
                        }
                    }
                    obj = hvector[v]*3;
                    if (obj > hvector.back()){
                        if (obj < min){
                            min = obj;
                            continue;
                        }
                    }
                    obj = hvector[v]*5;
                    if (obj > hvector.back()){
                        if (obj < min){
                            min = obj;
                            continue;
                        }
                    }
                }
            }
            hvector.push_back(min);
            fhlist[i] = min;
            min = 398580751;
            allinvec(hvector.at(0));
            if (j == a-1){
                cout << fhlist[i] <<endl;
            }
        }
        hvector.clear();
    }
    inStream.close();
}
