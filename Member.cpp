#include "Member.h"
using namespace std;

/* matsav hathalate*/
int Member::AllUsers = 0;

/*Constructor*/
/********************************************************************************************/
Member::Member()
{
	AllUsers++;
}

/*Destructor*/
/********************************************************************************************/
Member::~Member()
{
	AllUsers--;

	set<Member*>::iterator pointer;
	
	for(pointer = following.begin(); pointer != following.end(); pointer++){
		(*pointer)->followers.erase(this);
	}
	for(pointer = followers.begin(); pointer != followers.end(); pointer++){
		(*pointer)->following.erase(this);
	}
}

/********************************************************************************************/

void Member::addToFollowers(Member& other){
	followers.insert(&other);
}

void Member::deleteFromFollowers(Member& other){
	followers.erase(&other);
}

/********************************************************************************************/

int Member::count(){
	return AllUsers;
}

/********************************************************************************************/

void Member::follow(Member& other){
	if( &other != this)
{
	following.insert(&other);
	other.followers.insert(this);
}
}

void Member::unfollow(Member& other){
	following.erase(&other);
	other.followers.erase(this);
}

int Member::numFollowers() const{
	return followers.size();
}

int Member::numFollowing() const{
	return following.size();
}


