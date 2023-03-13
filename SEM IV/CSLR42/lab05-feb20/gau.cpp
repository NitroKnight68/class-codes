#include<iostream>

using namespace std;

int main(){
	int smallest,time,n,count=0;
	double end,avg=0,tt=0;
	
	cin>>n;
	
	int arrival[n],burst[n],temp[n];
	int wait[n],completion[n],turnaround[n];
	
	cout<<"arrival"<<endl;
	for(int i=0;i<n;i++){
		cin>>arrival[i];
	}
	
	cout<<"burst"<<endl;
	for(int i=0;i<n;i++){
		cin>>burst[i];
	}
	
	for(int i=0;i<n;i++){
		temp[i]=burst[i];
	}
	
	for(time=0;count!=n;time++){
		smallest=0;
		for(int i=0;i<n;i++){
			if(arrival[i]<=time && burst[i]<burst[smallest] && burst[i]>0){
				smallest=i;
			}
		}
		
		burst[smallest]--;
		
		if(burst[smallest]==0){
			count++;
			end=time+1;
			completion[smallest]=end;
			wait[smallest]=end-arrival[smallest]-temp[smallest];
			turnaround[smallest]=end-arrival[smallest];
		}
	}
	
	cout<<"Process\tBurst\tArrival\tWait\tTurnaround\tCompletion"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<"P"<<i+1<<"\t\t"<<temp[i]<<"\t\t"<<arrival[i]<<"\t\t"<<wait[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
		avg=avg+wait[i];
		tt=tt+turnaround[i];
	}
	
	cout<<"Avg wait time = "<<avg<<endl;
	cout<<"Avg turnaround time = "<<tt<<endl; 
}

