
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Check Playlist.cpp for instructions of what to write here and how to test it


DLL::DLL(){  // constructor - initializes an empty list
	last = NULL;
	first = NULL;
	numSongs = 0;

}
DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
	DNode *n = new DNode (t,l,m,s);
	first = n;
	last = n;
	numSongs=1;
}
//here I'm pushing to the end of the list
void DLL::push(string n, string a, int m, int s) {  // does what you'd think
	DNode *newNode = new DNode(n,a,m,s);

	if(numSongs == 0){
		first = newNode;
		last = newNode;
	}
	else{
		newNode->prev = last;
		last->next = newNode;
		last = newNode;

	}
	numSongs += 1;

}
//pops the last node in list and returns that node
Song *DLL::pop() { //does what you'd think
	Song *lastSong = last->song;
	last = last->prev; //if no songs before last, then last will be NULL
	numSongs -= 1;

	if(numSongs == 0){
		first = NULL;
	}
	else{
		last->next=NULL; //memory clean up
	}

	return lastSong;

}


void DLL::printList() {
	DNode *temp = first;
	while(temp != NULL){
		temp->song->printSong();
		temp = temp->next;
	}

}

void DLL::moveUp(string s) {
}

void DLL::listDuration(int *tm, int *ts) {
}
void DLL::moveDown(string s) {
}
void DLL::makeRandom() {
}

int DLL::remove(string s) {
// note that the int returned is the index - this is standard for a remove, but we won't be using it.
	DNode *temp = first;
	int counter = 0;
	if(numSongs > 0){
		//find the node
		while(temp->song->title != s){
			temp = temp->next;
			counter += 1;
			cout<<"while loop?"<<endl;
		}

		if(temp->prev == NULL){
			//do code for if the song is the first song
			first = first->next;
			numSongs -= 1;
			if(numSongs == 0){
				last = NULL;
			}
			else{
				first->prev = NULL; //whatever was behind us now needs to equal null
			}
			return 0;

		}
		else if(temp->next == NULL){
			//run the code if the song is the last song
			pop();
			return counter;
		}
		else{
			//run the code if we are somewhere in the middle
			cout<<"middle check"<<endl;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			//memory clean
			temp->song = NULL;
			temp = temp->prev = temp->next = NULL;

			numSongs -= 1;
			return counter;
		}

	}
	return -1;

}


DLL::~DLL(){
}
