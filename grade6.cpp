#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
string  answer[] = {"2", "-1", "10", "6", "0", "96", "-1", "19", "15"};

int i = 0;
int wrong = 0;
int main(int argc, char** argv) {
    ifstream in;
    string ans;

    if (argc < 2) {
	cout << "Usage: grade1 <student_program.c/.cpp> \n";
	exit(0);
    }
    string prog(argv[1]);
    string run_test;
    if (argv[1][strlen(argv[1]) - 1] == 'c')
        run_test = "gcc " + prog + " -lm";
    else 
 	run_test = "g++ " + prog + " -lm";
    system((run_test).c_str()); 
    puts((run_test).c_str()); 
    run_test = "./a.out < t > r";
    system((run_test).c_str()); 

    in.open("r", ifstream::in);
    for (; i < 3; ++i) {
        while (in >> ans && (!isdigit(ans[0]) || stoi(ans, NULL, 10) == i+1)) {
           if (ans == "-1") break; 
        }
        if (in.eof())
            ans = "-2";
              
        cout << "<<<<< TEST " << i + 1 << " >>>>>" << endl;
        if (ans == answer[i])
            cout << "PASSED\n";
        else {
            cout << "FAILED\n";
            cout << "Student answer: " << ans << endl;
            cout << "Correct answer: " << answer[i] << endl;
            ++wrong;
        }
    }
    in.close();


    run_test = "./a.out < t2 > r2";
    system((run_test).c_str()); 

    in.open("r2", ifstream::in);
    for (; i < 6; ++i) {
        while (in >> ans && (!isdigit(ans[0]) || stoi(ans, NULL, 10) == i+1)) {
           if (ans == "-1") break; 
        } 
        if (in.eof())
            ans = "-2";
              
        cout << "<<<<< TEST " << i + 1 << " >>>>>" << endl;
        if (ans == answer[i])
            cout << "PASSED\n";
        else {
            cout << "FAILED\n";
            cout << "Student answer: " << ans << endl;
            cout << "Correct answer: " << answer[i] << endl;
            ++wrong;
        }
    }
    in.close();
     

    run_test = "./a.out < t3 > r3";
    system((run_test).c_str()); 

    in.open("r3", ifstream::in);
    for (; i < 9; ++i) {
        while (in >> ans && (!isdigit(ans[0]) || stoi(ans, NULL, 10) == i+1)) {
           if (ans == "-1") break; 
        } 
        if (in.eof())
            ans = "-2";
              
        cout << "<<<<< TEST " << i + 1 << " >>>>>" << endl;
        if (ans == answer[i])
            cout << "PASSED\n";
        else {
            cout << "FAILED\n";
            cout << "Student answer: " << ans << endl;
            cout << "Correct answer: " << answer[i] << endl;
            ++wrong;
        }
    }
    in.close();
    if (wrong > 0)
        cout << "INCORRECT: " << wrong << endl;
    system("cat a");
    system("cat r");
    system("cat r2");
    system("cat r3");
}
