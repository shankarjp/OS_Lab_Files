#include <iostream>
#include <vector>

using namespace std;

bool search(int key, vector<int> &frames) {
    for(int i=0; i<frames.size(); i++) {
        if(frames[i] == key)
            return true;
    }
    return false;
}
int predict(int pages[], vector<int> &frames, int n, int index) {
    int result=-1, farthest = index;
    for(int i=0; i<frames.size(); i++) {
        int j;
        for(j=index; j<n; j++) {
            if(frames[i] == pages[j]) {
                if(j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if(j == n)
            return i;
    }
    if(result == -1) {
        return 0;
    }
    return result;
}

void pageFaultOptimal(int pages[], int n, int capacity) {
    vector<int> frames;
    int hit=0;
    // int page_fault=0;
    for(int i=0; i<n; i++) {
        if(search(pages[i], frames)) {
            hit++;
            continue;
        }
        if(frames.size() < n) {
            frames.push_back(pages[i]);
            // page_fault++;
        }
        else {
            int j = predict(pages, frames, n, i+1);
            frames[j] = pages[i];
            // page_fault++;
        }
    }
    cout << "Hits : " << hit << endl;
    // cout << "Page Fault : " << page_fault << endl;
}

int main() {
    int pages[] = {3,2,1,2,3,6,4,7,2,3,4,2,1,5,7,6,2,6,2,2,3,3};
    int capacity = 4;
    int n = sizeof(pages)/sizeof(pages[0]);
    pageFaultOptimal(pages, n, capacity);
    return 0;
}