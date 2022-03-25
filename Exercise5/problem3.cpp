#include <iostream>
#define MAX_SIZE 20

using namespace std;
int matrix[MAX_SIZE][6];

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void FCFSAlgorithm(int n, int M[][6]) {
    // Arranging Arrivals
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(M[j][1] > M[j+1][1]) {
                for(int k=0; k<5; k++) {
                    swap(&M[j][k], &M[j+1][k]);
                }
            }
        }
    }

    int temp;
    for(int i=0; i<n; i++) {
        if(i==0) {
            temp = M[0][1];
        } else {
            temp = M[i-1][3];
            while(temp < M[i][1]) {
                temp = M[i][1];
            }
        }
        M[i][3] = temp + M[i][2];
        M[i][5] = M[i][3] - M[i][1];
        M[i][4] = M[i][5] - M[i][2];
    }
}

int main() {
    int n;
    cout << "Enter Number of Processes: ";
    cin >> n;

    cout << "Enter Process Details\n";
    for(int i=0; i<n; i++) {
        cout << "\nProcess " << i+1 << endl;
        cout << "Process ID: ";
        cin >> matrix[i][0];
        cout << "Arrival Time: ";
        cin >> matrix[i][1];
        cout << "Burst Time: ";
        cin >> matrix[i][2];
    }

    cout << "\nGiven Data" << endl;
    cout << "Process ID\tArrival Time\tBurst Time\n";
    for(int j=0; j<n; j++) {
        cout << matrix[j][0] << "\t\t" << matrix[j][1] << "\t\t" << matrix[j][2] << endl;
    }

    FCFSAlgorithm(n, matrix);

    cout << endl << "Gantt Chart" << endl;
    for(int m=0; m<n; m++) {
        cout << "P" << matrix[m][0] << "\t";
    }
    cout << endl;

    cout << "\nResult" << endl;
    cout << "Process ID\tExecution Time\tWaiting Time\tTimearound Time\n";
    for(int k=0; k<n; k++) {
        cout << matrix[k][0] << "\t\t" << matrix[k][3] << "\t\t" << matrix[k][4] << "\t\t" << matrix[k][5] << endl;
    }

    int total_waiting_time = 0, total_turnaround_time=0;
    for(int l=0; l<n; l++) {
        total_waiting_time += matrix[l][4];
        total_turnaround_time += matrix[l][5];
    }
    cout << "Average Waiting Time: " << (float)total_waiting_time/n << endl;
    cout << "Average Turnaround Time: " << (float)total_turnaround_time/n << endl;

    return 0;
}