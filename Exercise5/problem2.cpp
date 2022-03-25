#include <iostream>
#define MAX_SIZE 20

using namespace std;
int matrix[MAX_SIZE][6];

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SJFAlgorithm(int n, int M[][6]) {
    // Arranging Arrivals
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(M[j][2] > M[j+1][2]) {
                for(int k=0; k<5; k++) {
                    swap(&M[j][k], &M[j+1][k]);
                }
            }
        }
    }

    int temp, val;
    // Completion Time = Arrival Time + Burst Time
    M[0][3] = M[0][1] + M[0][2];
    // Turn Around Time = Completion Time - Arrival Time
    M[0][5] = M[0][3] - M[0][1];
    // Waiting Time = Turn Around Time - Burst Time
    M[0][4] = M[0][5] - M[0][2];

    for(int i=1; i<n; i++) {
        temp = M[i-1][3];
        int low = M[i][2];
        for(int j=i; j<n; j++) {
            if(temp >= M[j][1] && low >= M[j][2]) {
                low = M[j][2];
                val = j;
            }
        }
        M[val][3] = temp + M[val][2];
        M[val][5] = M[val][3] - M[val][1];
        M[val][4] = M[val][5] - M[val][2];
        for(int k=0; k<6; k++) {
            swap(&M[i][k], &M[val][k]);
        }
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
        cout << "Burst Time: ";
        cin >> matrix[i][2];
        matrix[i][1] = 0;
    }

    cout << "\nGiven Data" << endl;
    cout << "Process ID\tBurst Time\n";
    for(int j=0; j<n; j++) {
        cout << matrix[j][0] << "\t\t" << matrix[j][2] << endl;
    }

    SJFAlgorithm(n, matrix);

    cout << "\nResult" << endl;
    cout << "Process ID\tWaiting Time\tTurn Around Time\n";
    for(int k=0; k<n; k++) {
        cout << matrix[k][0] << "\t\t" << matrix[k][4] << "\t\t" << matrix[k][5] << endl;
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