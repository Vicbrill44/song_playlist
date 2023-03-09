/*
 * DNode.cpp
 *
 *  Created on: Mar 8, 2023
 *      Author: victo
 */
#include <stdlib.h>
#include "DNode.hpp"
using namespace std;

DNode::DNode(){
	song = new Song();
	prev = NULL;
	next = NULL;
}
DNode::DNode(string s, string a, int lenmin, int lensec){
	song = new Song(s, a, lenmin, lensec);
	prev = NULL;
	next = NULL;

}


