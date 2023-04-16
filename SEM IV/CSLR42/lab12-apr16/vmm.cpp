#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Process {
    int vAddress;
    int pageNum;
    int offset;
    int frameNum;
    int pAddress;
} p[1000];

int main()
{
    int input, i = 0;

    ifstream file;
    file.open("virtual.txt");

    // while (file >> input)
    // {
    //     p[i].vAddress = input;
    //     cout << "Virtual Address: " << input << endl;
    //     if(input >= 1048576) {
    //         cout << "Page: Invalid" << endl;
    //         cout << "Offset: Invalid" << endl;
    //     }
    //     else {
    //         cout << "Page: " << (input / 1024) << endl;
    //         cout << "Offset: " << (input % 1024) << endl;
    //     }
    //     cout << endl;
    // }

    while (file >> input)
    {
        p[i].vAddress = input;
        if(input >= 1048576) {
            p[i].pageNum = -1;
            p[i].offset = -1; 
        }
        else {
            p[i].pageNum = input / 1024;
            p[i].offset = input % 1024; 
        }
        i++;
    }

    file.close();

    fstream outFile;
    outFile.open("output.txt", ios::out);

    i = 0;
    file.open("correct.txt");

    while (file >> input)
    {
        p[i].pAddress = input;
        p[i].frameNum = (input - p[i].offset) / 1024;
        outFile << "Virtual Address " << i + 1 << " = " << p[i].vAddress << endl;
        outFile << "Page Number " << i + 1 << " = " << p[i].pageNum << endl;
        outFile << "Offest " << i + 1 << " = " << p[i].offset << endl;
        outFile << "Frame " << i + 1 << " = " << p[i].frameNum << endl;
        outFile << "Physical Address " << i + 1 << " = " << p[i].pAddress << endl;
        i++;
        outFile << endl;
    }

    file.close();

    outFile.close();
    
    return 0;
}