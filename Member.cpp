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
	followers.insert(&this);
}

void Member::unfollow(Member& other){
	following.erase(&other);
	followers.erase(&this);
}

int Member::numFollowers() const{
	return followers.size();
}

int Member::numFollowing() const{
	return following.size();
}


