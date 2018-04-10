#include "Member.h"
using namespace std;

/* matsav hathalate*/
int Member::AllUsers = 0;

/*Constructor*/
/********************************************************************************************/
Member::Member()
{
	totalUsers++;
}

/*Destructor*/
/********************************************************************************************/
Member::~Member()
{
	totalUsers--;

	set<Member*>::iterator pointer;
	
	for(pointer = following.begin(); pointer != following.end(); pointer++){
		(*pointer)->followers.erase(this);
	}
	for(pointer = followers.begin(); pointer != followers.end(); pointer++){
		(*pointer)->following.erase(this);
	}
}

/********************************************************************************************/

void Member::add(Member& o) //o is for other
{
	followers.insert(&o);
}

void Member::delete(Member& o) //o is for other
{
	followers.erase(&o);
}

/********************************************************************************************/

int Member::count()
{
	return AllUsers;
}

/********************************************************************************************/

void Member::follow(Member& o) //o is for other
{
	if (following.find(&o) == following.end()){
		following.insert(&o);
		o.addToFollowers(*this);
	}
	else if (&o == this)
		return;
}


void Member::unfollow(Member& o) //o is for other
{
	if (following.find(&o) != following.end()){
		following.erase(&o);
		o.deleteFromFollowers(*this);
	}
	else if (&o == this)
		return;
}

int Member::numFollowers() const
{
	return followers.size();
}

int Member::numFollowing() const 
{
	return following.size();
}


