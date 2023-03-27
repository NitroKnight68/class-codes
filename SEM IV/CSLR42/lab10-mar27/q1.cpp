#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void nextFit(vector<int> &blocks, vector<int> &processes) {
    int blen = blocks.size(), plen = processes.size();
    int i = 0 , j = 0;
    while(i < blen) {
        while(j < plen) {
            if(processes[j] <= blocks[i]) {
                cout << "Process " << j + 1 << "(" << processes[j] << ") is allocated to Block " << i + 1 << endl; 
                j++;
                i++;
            }
            else {
                i++;
            }
        }
    }
}

int main()
{
    int n, input, thirdLine;
    vector<int> processes;
    vector<int> blocks;

    ifstream file;
    file.open("input.txt");

    file >> n;

    for(int i = 0; i < n; i++) {
        file >> input;
        processes.push_back(input);
    }

    while (file >> input)
    {
        blocks.push_back(input);
    }

    file.close();
    
    nextFit(blocks, processes);
    return 0;
}