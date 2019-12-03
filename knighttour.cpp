#include <iostream>
#include <iomanip>

#define K 8

using namespace std;

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };



bool move(int x, int y, int i, int sol[K][K]);
bool isPossible(int x, int y, int sol[K][K]);
void printSolution(int sol[K][K]);

bool isPossible(int x, int y, int sol[K][K]) {
    return !(x < 0 || x >= K || y < 0 || y >= K || sol[y][x] != -1);
}

void printSolution(int sol[K][K]) {
    for(int x = 0; x < K; x++) {
        cout << "| ";
        for(int y = 0; y < K; y++) {
            cout << setw(2) << sol[y][x] << " | ";
        }
        cout << endl;
    }
}

bool move(int x, int y, int i, int sol[K][K]) {

    if(i == K*K) {
        return true;
    }
    cout << x <<" , " << y << " , " << i << endl;

    for(int z = 0;z < 8; z++) {
        int nX = x + xMove[z];
        int nY = y + yMove[z];

        if(isPossible(nX,nY,sol)) {
            sol[nY][nX] = i+1;
            if(move(nX,nY,i+1,sol)) {
                return true;
            }
            else {
                sol[nY][nX] = -1;
            }
        }
    }
    return false;
}



int main() {
    int sol[K][K];

    for(auto & y : sol) {
        for(int & x : y) {
            x = -1;
        }
    }
    //sol[0][0] = 0;
    cout << "starting" << endl;

    if(move(0,0,0,sol)) {
        cout <<"done" << endl;
        printSolution(sol);
    }
    else {
        cout << "no solution" << endl;
    }

    return 0;
}


