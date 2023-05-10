#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cctype>
#include <conio.h>

using namespace std;

ifstream ifile;
ofstream ofile;

void showContentsOfTxt() {
    string line;
    while (!ifile.eof()) {
        getline(ifile, line);
        cout << line << '\n';
    }
}

int getLastIndex() {
    string iline, temp;
    while (getline(ifile, temp)) {
        if(!ifile.eof()) iline = temp;
    }
    if (iline.empty()) return 0;
    int spacePos = iline.find(' ');
    return stoi(iline.substr(0, spacePos));
}


void checkOpenOutputFile() {
    if(ofile.fail()) {
        cout << "Error in ofstream. cdsLog.txt is not opened.\n";
        cout << "Maybe there is no file named cdsLog.txt. Should I create it? y or any_other_to_no\n";
        char answer = getch();

        if (answer == 'y') {
            ofstream createFile("cdsLog.txt");
            createFile.close();
            cout << "File created in directory where this program is located.\n";
        }
        exit(-1);
    }
}

void checkOpenInputFile() {
    if(ifile.fail()) {
        cout << "Error in ifstream. cdsLog.txt is not opened.\n";
        cout << "Maybe there is no file named cdsLog.txt. Should I create it? y or any_other_to_no\n";
        char answer = getch();

        if (answer == 'y') {
            ofstream createFile("cdsLog.txt");
            createFile.close();
            cout << "File created in directory where this program is located.\n";
        }
        exit(-1);
    }
}

bool strIsDigit(string& s) {
    for(auto& ch : s) {
        if(!isdigit(ch))
            return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    //const string nameOfTxtFile = "C:\\Users\\user\\UserDefinedExe\\cdsLog.txt";
    const string nameOfTxtFile = "cdsLog.txt";

    if (argc < 2) {
        string usage =  "usage:\n"
                        "cds --add or -a C:\\User\\user\\somedir \n\tappends path to a file and returns index \n"
                        "cds index command1 command2 ... \n\texecutes cd dir_with_index && commmand1 && command2 ...\n"
                        "cds --show or -s \n\tshows content of txt \n"
                        "cds --del or -d index \n\tdeletes specified index \n";
        cout << usage;
        return 0;
    }
    string arg1 = argv[1];

    if (arg1 == "-s" || arg1 == "--show") {
        ifile.open(nameOfTxtFile);
        checkOpenInputFile();
        showContentsOfTxt();
        ifile.close();
    } else if (arg1 == "-a" || arg1 == "--add" ) {
        if (argc < 3) {
            cout << "Error. Path is not entered.\n";
            return -1;
        }

        ifile.open(nameOfTxtFile);
        checkOpenInputFile();
        int lastIndex = getLastIndex();
        ifile.close();

        ofile.open(nameOfTxtFile, ios::app);
        checkOpenOutputFile();
        ofile << lastIndex+1 << " " << argv[2] << '\n';
        ofile.close();
        cout << "New index: " << lastIndex+1;

    } else if (arg1 == "-d" || arg1 == "--del") {
        if (argc < 3) {
            cout << "Error. Index is not entered.\n";
            return -1;
        }
        int indexToBeDeleted = stoi(argv[2]);

        ifile.open(nameOfTxtFile);
        checkOpenInputFile();
        ofile.open("temp.txt");
        checkOpenOutputFile();
        string iline;
        int i = 1;
        while (getline(ifile, iline)) {
            if (i == indexToBeDeleted) {indexToBeDeleted = 0;continue;}
            int spacePos = iline.find(' ');
            ofile << i << ' ' << iline.substr(spacePos+1) << '\n';
            ++i;
        }

        ofile.close();
        ifile.close();
        remove(nameOfTxtFile.c_str());
        rename("temp.txt", nameOfTxtFile.c_str());
    } else if (strIsDigit(arg1)) {
        int index = stoi(arg1);

        ifile.open(nameOfTxtFile);
        checkOpenInputFile();
        for (int i = 0; i < index-1 && !ifile.eof(); ++i) {
            ifile.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (ifile.eof()) {
            cout << "Error. Index is longer than max index.\n";
            return -1;
        }

        string iline;
        getline(ifile, iline);
        ifile.close();
        int spacePos = iline.find(' ');

        string command = "cd \"" + iline.substr(spacePos+1) + "\"";
        for (int i = 2; i<argc; ++i) command = command + "&&" + argv[i];
        cout << "command: " << command << '\n';
        system(command.c_str());

    }

    return 0;
}
