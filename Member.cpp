#include "Member.h"
using namespace std;

/* matsav hathalate*/
int Member::AllMembers = 0;

/*Constructor*/
Member::Member()
{
	AllMembers++;
}

/*Destructor*/
Member::~Member()
{
	AllMembers--;

	set<Member*>::iterator pointer;
	
	for(pointer = following.begin(); pointer != following.end(); pointer++){
		(*pointer)->followers.erase(this);
	}
	for(pointer = followers.begin(); pointer != followers.end(); pointer++){
		(*pointer)->following.erase(this);
	}
}


int Member::count(){
	return AllMembers;
}


void Member::follow(Member& other){
	following.insert(&other);
	other.adding(*this);
}

void Member::unfollow(Member& other){
	following.erase(&other);
	other.deleting(*this);
}

int Member::numFollowers() const{
	return followers.size();
}

int Member::numFollowing() const{
	return following.size();
}

/* Helping Functions*/

void Member::adding(Member& other){
	followers.insert(&other);
}

void Member::deleting(Member& other){
	followers.erase(&other);
}


