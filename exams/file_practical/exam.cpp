#include <iostream>
#include <fstream>

using namespace std;

// q1
void writeInFile(string filename, string txttowrite)
{
    ofstream out(filename, ios::out);

    out << txttowrite;

}

//q2
int readCharByCharAndReturnCount(string filename)
{
    ifstream in(filename);

    in.seekg(0, ios::beg);


    int count = 0;
    char c;
    while(in.get(c)) {
        cout << c; 
        if(c == 'c') count++;
    }

    cout << endl;

    return count;
}


int main()
{
    //q1
    writeInFile("file1.txt", "Practical file structure");

    //q2
    int count = readCharByCharAndReturnCount("file1.txt");
    cout << "totalNumber of the character 'C'= " << count;
    cout << endl << endl << endl;
    

    return 0;
}