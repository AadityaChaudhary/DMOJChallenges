//
// Created by aadi on 12/3/19.
//
#include <iostream>
#include <vector>

using namespace std;

int nextNum;
int studentsLate;
int studentsLeft;


int main() {
    cin >> nextNum;
    vector<string> outputs;

    string com;
    while(com != "EOF") {
        cin >> com;
        //cout << com;
        if(com == "SERVE") {
            //cout << "SERVE" <<endl;
            studentsLeft--;
        }
        else if(com == "TAKE") {
            //cout << "TAKE" <<endl;
            studentsLate++;
            studentsLeft++;
            nextNum++;
            if(nextNum == 1000) {
                nextNum = 1;
            }
        }
        else if(com == "CLOSE") {
            //cout << "CLOSE" <<endl;
           // cout <<  studentsLate << " " << studentsLeft << " " << nextNum << endl;
            outputs.push_back(to_string(studentsLate) + " " +to_string(studentsLeft) + " " + to_string(nextNum));
            studentsLate = 0;
            studentsLeft = 0;
        }
        else {}
    }

    for(auto &str : outputs) {
        cout << str << endl;
    }

    return 0;
}

