#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
string a[] = {"2", "12", "56", "123", "65432", "9898989898", "123123123123123123123123123123",  "42"};
string b[] = {"4", "34", "89", "91", "13579", "56789123456789123456", "72",  "987654321"};
string answer[] = {"8", "408", "4984", "11193", "888501128", "562154959415030372607218847488",
                    "8864864864864864864864864864856",  "41481481482"};
int num_tests = 8;

int main(int argc, char** argv) {
    ifstream in;
    ofstream out;
    string ans, ans2;
    bool save_all = false;

    if (argc < 2) {
	cout << "Usage: grade1 <student_program.c/.cpp> \n";
	exit(0);
    }
    string prog(argv[1]);
    string run_test;
    /*if (argc == 3 && !strcmp(argv[2], "-s")) {
        save_all = true;
        out.open("tests.txt", ofstream::out);
    }*/
    if (argv[1][strlen(argv[1]) - 1] == 'c')
        run_test = "gcc " + prog + " -lm";
    else 
 	run_test = "g++ " + prog + " -lm";
    system((run_test).c_str()); 
    puts((run_test).c_str()); 
    for (int i = 0; i < num_tests; ++i) {
	out.open("tests.txt", ofstream::out);
	out << a[i] << " " << b[i];
	out.close();
        run_test = "./a.out < tests.txt > results.txt";
        system((run_test).c_str()); 
        puts((run_test).c_str()); 
    
        in.open("results.txt", ifstream::in);

	ans2 = "-1";
        while (in >> ans && strcmp(ans.c_str(), "z")); 
        //while (in >> ans && strcmp(ans.c_str(), "*")); 
	if (in.eof())
	    ans = "-1";
	else in >> ans >> ans;
	in >> ws;
	//        in >> ans2 >> ws;
	// Check whether there are two answers in a row because the program still prints the 
	// result of "add" before doing "mult"
	if (in.peek() == 'z') 
	    in >> ans2 >> ans2 >> ans2;
	   
	cout << "<<<<< TEST " << i + 1 << " >>>>>" << endl;
	if (ans == answer[i] || ans2 == answer[i])
	    cout << "PASSED\n";
	else {
	    cout << "FAILED\n";
	  //  if (ans == "-1")
	        cout << "Student answer: " << ans << endl;
	  //  else
	  //      cout << "Student answer: " << ans << endl;
	    cout << "Correct answer: " << answer[i] << endl;
	}
	in.close();
    }
}
