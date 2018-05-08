#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int getMaxInt(int* l1, int size) {
  int max = l1[0];

  for (int i = 1; i < size; i++)
    if (l1[i] > max){
         max = l1[i];
    }

  return max;
}

int findint(int* l2, int obj){
    int l2_index;
    l2_index = -1;
    for (int i = 0; i<100; i++){
        if (l2[i] == obj){
            l2_index = i;
            break;
        }
    }
    return l2_index;
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
        int a, maxint, cmax, last_index;
        inStream >> a;
        cmax = 0;
        last_index = 1;
        int *list1 = new int[100];
        int *list2 = new int[100];
        for (int j = 0; j<a; j++){
            int b, yorn;
            yorn = 0;
            inStream >> b;
            yorn = findint(list1, b);
            if (yorn != -1){
                int position;
                position = findint(list1, b);
                list2[position] += 1;
            }
            else{
                list1[last_index] = b;
                list2[last_index] = 1;
                last_index++;
            }
        }
        maxint = getMaxInt(list2, last_index);
        for (int j = 0; j<last_index; j++){
            if (list2[j] == maxint){
                cmax += 1;
            }
        }
        int *R_list = new int[cmax];
        int R_Position;
        R_Position = 0;
        for (int j = 0; j<last_index; j++){
            if (list2[j] == maxint){
                R_list[R_Position] = list1[j];
                R_Position++;
            }
        }
        sort(R_list, R_list + cmax);
        cout << cmax << " " << maxint << " ";
        for (int j = 0; j<cmax; j++){
            cout << R_list[j] << " ";
        }
        cout <<endl;

    }
    inStream.close();
}
