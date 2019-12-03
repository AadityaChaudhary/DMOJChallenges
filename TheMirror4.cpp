//
// Created by aadi on 11/30/19.
//
#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    int counts[N];

    for (int &i : counts) {
        i = 0;
    }

    for(int x = 0; x < N;x++) { //for each min/max
        int min, cap;
        cin >> min >> cap;
        //int count = 0;

        for (int c = min; c < cap; c++) { //check every number between them
            bool isPrime = true;
            for (int p = 2; p < c; p++) { //check every number
                if (c % p == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime && c != 1) {
               // cout << "current: " << c << endl;
                counts[x]++;
            }

        }
    }

    for(int &i : counts) {
            cout << i << endl;
    }

}
