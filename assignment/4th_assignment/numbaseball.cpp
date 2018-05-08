#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
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
        int a, s_count, b_count, final_count;
        final_count = 0;
        int num_array[4];
        bool base_array[10000] = {0};
        inStream >> a;
        for (int j = 0; j<a; j++){
            int num, s_num, b_num;
            inStream >> num >> s_num >> b_num;
            final_count = 0;
            for (int n = 0; n<4; n++){
                num_array[n] = (num / (int)pow(10, 3-n)) % 10;
            }
            for (int idx = 0; idx<10000; idx++){
                if (base_array[idx] == 1){
                    continue;
                }
                s_count = 0;
                b_count = 0;
                bool ischecked[4] = {0};
                for (int k = 0; k<4; k++){
                    if (num_array[k] == (idx / (int)pow(10, 3-k) % 10)){
                        s_count += 1;
                        ischecked[k] = 1;
                    }
                }
                for (int k = 0; k<4; k++){
                    for (int l = 0; l<4; l++){
                        if ((ischecked[k] == 0) && (ischecked[l] == 0) && (num_array[k] == (idx / (int)pow(10, 3-l) % 10))){
                            b_count += 1;
                            break;
                        }
                    }
                }
                if ((s_count != s_num) || (b_count != b_num)){
                    base_array[idx] = 1;
                }
                else if ((s_count == s_num) && (b_count == b_num)){
                    final_count += 1;
                }
            }
        }
        if (final_count == 1){
            for (int j = 0; j<10000; j++){
                if (base_array[j] != 1){
                    cout << j <<endl;
                    break;
                }
            }
        }
        else if (final_count > 1){
            cout << -1 <<endl;
        }
        else{
            cout << -2 <<endl;
        }
    }
    inStream.close();
}
