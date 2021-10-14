#include<iostream>
#include<vector>
#include <map>
using namespace std;

typedef long long ll;
enum EventType { SIMULATION_END , TRANSMIT , RECIEVE }; // ***10***

class Event{
	EventType type; // 1 means transmit / 2 means recieve / 0 means simulation end
	ll time; // time for which this event is Scheduled
	ll Nt; // Transmitting node of this event (if its not a simulation end event)
	ll Nr; // Receiving node of this event (if its not a simulation end event) 

	public:
		Event(EventType type, ll time, ll Nt, ll Nr){
			this->type = type;
			this->time = time;
			this->Nt = Nt;
			this->Nr = Nr;
		}

		ll get_time(){ return time;}
		EventType get_type(){ return type;}
		ll get_Nt(){ return Nt;}
		ll get_Nr(){ return Nr;}
};


class Heap{

	private:
		ll capacity;
		ll *arr; // this stores the time in the priority queue
		map<int, Event> event_dict;

	public:
		ll N;

		Heap();

		ll parent(ll i) {return (i-1)/2;}
		ll left(ll i) {return 2*i+1;}
		ll right(ll i) {return 2*i+2;}

		void insert(Event event);
		Event min(){ 
			auto search =  event_dict.find(arr[0]);
			return search->second;
		}
		void heapify(ll i);
		void deleteMin();

};