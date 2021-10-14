#include<iostream>
#include<fstream>
#include"heap.h"
using namespace std;

void swap(ll* a, ll* b) 
{
    ll temp = *a; 
    *a = *b;
    *b = temp;
}

Heap::Heap(){
	N = 0;
	capacity = 1LL << 22;
	arr = new ll[capacity];
}

void Heap::insert(Event event){

	event_dict.insert(pair<int, Event> (event.get_time(),event));
	N++;
	ll i = N-1;
	arr[i] = event.get_time();
	while(i != 0 && arr[parent(i)] > arr[i]){
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void Heap::heapify(ll i){
	ll l = left(i);
	ll r = right(i);
	ll smallest = i;
	if(l < N && arr[l] < arr[i]){
		smallest = l;
	}
	if(r < N && arr[r] < arr[smallest]){
		smallest = r;
	}
	if(smallest != i){
		swap(&arr[i], &arr[smallest]);
		heapify(smallest);
	}
}

void Heap::deleteMin(){
	swap(&arr[0],&arr[N-1]);
	N--;
	heapify(0);
}

void transmit(ll N, Heap &heap,ll curr_time,ll period,ll Nt, ll Nr, map<ll,ll> &on_air){
	ll P = rand()%950 + 50; // ***4***
	heap.insert(Event(RECIEVE, curr_time + P, Nt , Nr)); // ***12a***

	cout << "Node " << Nt +1 << " transmitted a packet of size " << P << " bytes to the Node " << Nr + 1 << endl;
	// 1 means no_error/ succesfull transmission while 0 means error/failed transmission
	if(on_air.empty()) on_air.insert(make_pair(curr_time + P, 1)); // ***12b***
	else{
		map<ll,ll>::iterator itr;
      	for( itr = on_air.begin(); itr != on_air.end(); ++itr){
            itr->second = 0;      // ***12c(ii)***
      	}
      	on_air.insert(make_pair(curr_time + P, 0));
	}
	cout << on_air.size() << " packets are on air." << endl;

	heap.insert(Event(TRANSMIT, curr_time + period , Nt, rand()%N)); // ***12c(i)***
}

void recieve(Event event, map<ll,ll> &on_air){

	cout << "Node "<< event.get_Nr() +1 << " recieved the packet transmitted by Node " << event.get_Nt()+1 << endl; // ***13(ii)***
	auto itr = on_air.find(event.get_time());
	if(itr->second){
		cout << "Recieved without error." << endl;
	}
	else{
		cout << "Error while recieveing." << endl;
	}
	on_air.erase(event.get_time()); //***13(i)***
	cout << on_air.size() << " packets are on air." << endl;
}

int main(int argc,char* argv[]){

	srand(time(0));
	ll time_in_sec = atoi(argv[2]);
	ll T = time_in_sec*1000; // T is total time of simulation in milliseond ***5***
	ll N = atoi(argv[1]); // Number of nodes in the network ***1***
	ll period = 50; // periodicity of packet generation ***3***
	map<ll,ll> on_air;  // ***8***

	Heap my_heap;

	my_heap.insert(Event(SIMULATION_END, T, -1, -1));
	for(ll i=0;i<N;i++){ // ***11***
		int n = rand()%(10*time_in_sec);
		my_heap.insert(Event(TRANSMIT, n, i, rand()%N)); // ***2***
	}

	for(ll t=0;t<T;t++){

		while(t == my_heap.min().get_time()) {
			cout << "time = " << t << " ms" << endl;
			Event curr_event = my_heap.min();
			int type_enum = curr_event.get_type();
			switch(type_enum){
				case 1:
					transmit(N, my_heap, t, period, curr_event.get_Nt(), curr_event.get_Nr(), on_air);
					cout << endl;
					break;
				case 2:
					recieve(curr_event,on_air);
					cout << endl;
					break;
				default:
					break;
			}

			my_heap.deleteMin();
		}
	}

}