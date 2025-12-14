#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ASSIGNMENT 1
//1. Write a program that writes an integer, a floating-point value, and a string to a text file
void AS1writeToFile(string fileName) {
    fstream file;
    file.open(fileName, ios::out); 

    if (file.good()) {
        int intValue;
        float floatValue;
        string stringValue;

        cout << "Enter an integer: ";
        cin >> intValue;
        cout << "Enter a floating-point value: ";
        cin >> floatValue;
        cout << "Enter a string: ";

        cin.ignore(); 
        getline(cin, stringValue);

        file << intValue << endl;
        file << floatValue << endl;
        file << stringValue << endl;
    }
    file.close();
}
//2. Write a program that reads an integer, a floating-point value, and a string from a text file & prints the values to the user
void AS1readFromFile(string fileName) {
    fstream file;
    file.open(fileName, ios::in);

    if (file.good()) {
        int intValue;
        float floatValue;
        string stringValue;

        file >> intValue;
        file >> floatValue;

        file.ignore();
        getline(file, stringValue);

        cout << "Integer: " << intValue << endl;
        cout << "Floating-point value: " << floatValue << endl;
        cout << "String: " << stringValue << endl;
    }
    file.close();
}
//3. Write a C++ program that writes your own data to a text file closes this file & then reopen the file and appends more data in it again
void AS1writeAndAppend(string filename) {
    // write
    ofstream out(filename);
    out << "First data:";
    out.close();

    // reopen
    ofstream app(filename, ios::app);
    app << "second data:";
    app.close();
}

// ASSIGNMENT 2
//1. Write C++ Program read data from file character by character with spaces
void AS2readFromFile(string filename) {
    ifstream in(filename);
    char c;
    while (in.get(c)) {
        cout << c;
    }
    in.close();
}
//2. Write C++ Program to read and count some words
int AS2countWords(string filename) {
    ifstream in(filename);
    char c;
    int words = 0;
    bool inWord = false;

    while (in.get(c)) {
        if (isspace(c)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            words++;
        }
    }

    in.close();
    return words;
}
//3. Write C++ Program to read and count some lines
int AS2countLines(string filename) {
    ifstream in(filename);
    string line;
    int lines = 0;

    while (getline(in, line)) {
        lines++;
    }

    in.close();
    return lines;
}

// ASSIGNMENT FS2
// 1a. Function to read file till EOF using eof()
void ASF2readFileWordByWord(string filename) {
    fstream file;
    file.open(filename, ios::in);
    if (file.good()) {
        string l;
        cout << "----- File Content -----\n";
        while (!file.eof()) {
            getline(file, l);
            cout << l << endl;
        }
    }
    file.close();

}
// 1b.Function to count all characters using get(ch)
void ASF2countCharacters(string filename) {
    ifstream in(filename);
    char ch;
    int count = 0;

    while (in.get(ch)) {
        count++;
    }

    in.close();
    cout << count;
}
// 2. Function to write to file
void ASF2writeToFile(string filename) {
    ofstream out(filename);
    char ch;

    while (cin.get(ch)) {
        if (ch == '.')
            break;
        out.put(ch);
    }

    out.close();
}
// 3. Function to write data to file
void ASF2writeData(string filename) {
    string name, phone, year;

    cout << "Enter name:";
    getline(cin, name);
    cout << "Enter phone number:";
    getline(cin, phone);
    cout << "Enter academic year:";
    getline(cin, year);

    ofstream out(filename);
    out << name << endl;
    out << phone << endl;
    out << year << endl;
    out.close();

    ifstream in(filename);

    string word;
    int wordCount = 0;
    while (in >> word) {
        wordCount++;
    }
    in.close();

    cout << "Word count: " << wordCount << endl;

    in.open(filename);
    string line;
    if (getline(in, line)) {
        cout << "One line: " << line << endl;
    }
    in.close();

    in.open(filename);
    int lineCount = 0;
    while (getline(in, line)) {
        lineCount++;
    }
    in.close();

    cout << "Line count: " << lineCount << endl;

}

// ASSIGNMENT FS3
//1. Function to test erros above
void ASF3testErrors(string filename) {
    ifstream in(filename);
    char ch;

    if (in.is_open())
        cout << "open\n";
    else
        cout << "not open\n";

    while (in.get(ch)) {
        cout << ch;
    }

    if (in.eof())
        cout << "\neof\n";

    if (in.fail())
        cout << "fail\n";

    if (in.bad())
        cout << "bad\n";

    if (in.good())
        cout << "good\n";

    in.clear();

    if (in.good())
        cout << "cleared\n";

    in.close();
}
//2. Function to test Tellp
void ASF3testTellFunctions(string filename) {
    ofstream out(filename);
    cout << "tellp at open: " << out.tellp() << endl;

    out << "first ";
    cout << "tellp while writing: " << out.tellp() << endl;

    out << "second";
    cout << "tellp after writing: " << out.tellp() << endl;

    out.close();

    ifstream in(filename);
    cout << "tellg at open: " << in.tellg() << endl;

    string word;
    in >> word;
    cout << "tellg while reading: " << in.tellg() << endl;

    while (in >> word) {}

    cout << "tellg after reading: " << in.tellg() << endl;

    in.close();
}
//3. Writing with seekp()
void ASF3testSeekp(string filename) {
    ofstream out(filename, ios::in | ios::out | ios::trunc);

    out.seekp(0, ios::beg);
    out.put('A');

    out.seekp(5, ios::beg);
    out.put('B');

    out.seekp(10, ios::beg);
    out.put('C');

    out.close();
}
//4. Reading with seekp()
void testSeekg(string filename) {
    ifstream in(filename);
    char ch;

    in.seekg(0, ios::beg);
    in.get(ch);
    cout << ch << endl;

    in.seekg(5, ios::beg);
    in.get(ch);
    cout << ch << endl;

    in.seekg(10, ios::beg);
    in.get(ch);
    cout << ch << endl;

    in.close();
}
//5. Calculate size
void fileSize(string filename) {
    ifstream in(filename, ios::binary | ios::ate);
    cout << in.tellg();
    in.close();
}


// Main function
int main() {

    return 0;
}
