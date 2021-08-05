#include<iostream>
#include"DynamicDequeue.h"
#include<time.h>
#include<fstream>
using namespace std;

typedef unsigned long long ull;

int main(){
	
	/*
	# How my main works
		* First I have made two executables linear and exponential and this was achieved by 
		  mannually commenting the functions offstream here in this file and a function in grow of DynamicDequeue.cpp
		* Automating this was difficult as we were not supposed to pass any flag through the grow function which limited the execution 
		  to manual commenting
		* I have stored the run-time after every 100 elements are stored in the dynamicdequeue.
		* The two files execution.txt and linear.txt contains "<i> <run-time>" for each execution
		* Further these two files are read in the plot.py and a plot is made using matplotlib 

	# How to run
		twice run these (taking care of changing comments in this and DynamicDequeue.cpp)
		* g++ -o exponential(linear) main.cpp DynamicDequeue.cpp
		* ./exponential(linear)
		* python3 plot.py
		* save plot thus shown.
	*/


	ull FINAL_SIZE = 20000;
	ull N_experiment = 50;
	
	ofstream Myfile("linear.txt");
	// ofstream Myfile("exponential.txt");
	
	double avg_time[100005];
	for(ull i=0;i<N_experiment;i++){
		DynamicDequeue myDequeue;
		clock_t tStart = clock();	
			// rand take O(1) time complexity
			for(ull j=0;j<FINAL_SIZE;j++){
				myDequeue.insertRear(rand()%100);
				if(j%100 == 0){
					avg_time[j/100] +=  (double)(clock() - tStart)/CLOCKS_PER_SEC;
				}
			}
	}
	for(ull i=0;i<FINAL_SIZE/100;i++){
		avg_time[i] = avg_time[i]/N_experiment;
		Myfile << i*100 << " " << avg_time[i] << endl;
	}
	Myfile.close();
}