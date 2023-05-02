//Preemptive Priority Scheduling

/*
	Process|Arrival|Burst
	P1     |0      |3    
	P2     |1      |4    
	P3     |3      |6    
	P4     |3      |4    
	P5     |5      |2

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct Process {
	int id, arrival, burst, exec;
	bool arrived, dead;
} p[5];

int n = 5;

bool arrivalSort(Process a, Process b) {
    if(a.arrival < b.arrival) {
        return true;
    }
    return false;
}

int main() {
	//Setting processes
	p[0].id = 0, p[0].arrival = 0, p[0].burst = 3, p[0].exec = 0, p[0].arrived = false, p[0].dead = false;
	p[1].id = 1, p[1].arrival = 1, p[1].burst = 4, p[1].exec = 0, p[1].arrived = false, p[1].dead = false;
	p[2].id = 2, p[2].arrival = 3, p[2].burst = 6, p[2].exec = 0, p[2].arrived = false, p[2].dead = false;
	p[3].id = 3, p[3].arrival = 3, p[3].burst = 4, p[3].exec = 0, p[3].arrived = false, p[3].dead = false;
	p[4].id = 4, p[4].arrival = 2, p[4].burst = 2, p[4].exec = 0, p[4].arrived = false, p[4].dead = false;

    queue<int> readyQueue;	
	
	int time = 0, tq = 3, temp = 0, current;
	
	while(time < 19) {
		//Checks if a process has arrived or not
		for(int i = 0; i < n; i++) {
			if(p[i].arrival <= time && !p[i].dead && !p[i].arrived) {
				p[i].arrived = true;
                readyQueue.push(p[i].id);
			}
		}
        
        //Increase Execution for Current Process
        current = readyQueue.front();
        p[current].exec++;
		time++;

        //Declare dead processes
        if(p[current].exec == p[current].burst) {
            p[current].dead = true;
            p[current].arrived = false;
        }

        //If process is done with time quantum but still alive, pop and push
        if(p[current].exec % tq == 0 && !p[current].dead) {
            readyQueue.pop();
            readyQueue.push(current);
        }

        //If process is dead, just pop
        else if (p[current].dead){
            readyQueue.pop();
        }

        //Printing in Original Order (not sorted order)
		cout << "Processes = ( ";
		for(int i = 0; i < 5; i++) {
			cout << p[p[i].id].exec << " ";
		}
		cout << ") -> ";
		cout << "Time = " << time << endl;
	}	

	return 0;
}
