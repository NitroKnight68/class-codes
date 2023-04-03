#include<bits/stdc++.h>
using namespace std;
 
int pageFaults(vector<int> &pages, int numPages, int capacity)
{
    set<int> s;
    queue<int> indexes;
 
    int faults = 0;
    for (int i=0; i<numPages; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                faults++;
                indexes.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();

                s.erase(val);
                s.insert(pages[i]);

                indexes.push(pages[i]);
                faults++;
            }

        }
    }
    return faults;
}
 
int main()
{
    vector<int> pages = {7, 0, 1, 2, 0, 1};
    int capacity = 2;

    cout << "The number of page faults is " << pageFaults(pages, pages.size(), capacity) << endl;
    return 0;
}