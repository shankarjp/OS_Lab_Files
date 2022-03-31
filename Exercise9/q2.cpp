#include <iostream>
using namespace std;

int main() {
    int n=5, m=4;
    int allocation[5][4] = {
        {0,0,1,2},
        {1,0,0,0},
        {1,3,5,4},
        {0,6,3,2},
        {0,0,1,4}
    };
    int max_demand[5][4] = {
        {0,0,1,2},
        {1,7,5,0},
        {2,3,5,6},
        {0,6,5,2},
        {0,6,5,6}
    };
    int available[4] = {1,5,2,0};
    int flag[n], final[n], index=0;
    for(int i=0; i<n; i++) {
        flag[i] = 0;
    }
    int need[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            need[i][j] = max_demand[i][j] - allocation[i][j];
        }
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            if(flag[i]==0) {
                int f=0;
                for(int j=0; j<m; j++) {
                    if(need[i][j] > available[j]) {
                        f = 1;
                        break;
                    }
                }
                if(f==0) {
                    final[index++] = i;
                    for(int l=0; l<m; l++) {
                        available[l] += allocation[i][l];
                    }
                    flag[i] = 1;
                }
            }
        }
    }

    int f=1;
    for(int i=0; i<n; i++) {
        if(flag[i]==0) {
            f=0;
            cout << "Not Safe\n";
            break;
        }
    }
    if(f==1) {
        cout << "Safe\n";
        for(int i=0; i<n; i++) {
            cout << "P" << final[i] << " ";
        }
        cout << endl;
    }
    return 0;
}