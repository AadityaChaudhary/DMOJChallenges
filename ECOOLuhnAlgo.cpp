//
// Created by aadi on 11/30/19.
//
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> sepString(string x) {
    vector<int> ints;
    for(char i : x) {
        ints.push_back(i-'0');
    }
    return ints;
}

int addDoubleDigit(int x) {
    int dub = x*2;
    int sum = 0;
    do{
        sum += dub%10;
        dub /= 10;
    }while(dub != 0);

    return sum;
}

int sumBase(vector<int> base) {
    int counter = 0;
    int sum = 0;

    for(int i = base.size() - 1; i >= 0; i--) {
        //cout << i << endl;
        if(counter % 2 == 0) {
           // cout << base[i] << " " << addDoubleDigit(base[i])<< endl;
            sum += addDoubleDigit(base[i]);
        }
        else {
         //   cout << base[i] << endl;
            sum += base[i];
        }
        counter++;
    }
    return sum;
}

int calcCheck(int baseSum) {
    int rem = baseSum %10;
   // cout << baseSum;
    return 10 - rem;
}

vector<int> check5(string bases[5]) {
    vector<int> checks;
    for(int i = 0; i < bases->size();i++) {
        checks.push_back(calcCheck(sumBase(sepString(bases[i]))));
    }
    return checks;
}


int main() {
//    vector<int> x = sepString("0123583");
//    for(int &i: x) {
//        cout << i;
//    }
//cout << calcCheck(sumBase(sepString("3543")));
//cout << sumBase(sepString("3543"));
string bases[5] = {"","","","",""};
cout << "bruh" << endl;
for(string & base : bases) {
    cin >> base;
}


cout << "bruh";
vector<int> checks = check5(bases);
cout << "ran prog";
for(int &i : checks) {
    cout << i;
}
return 0;
}


