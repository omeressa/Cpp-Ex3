#include "Member.h"
using namespace std;

/* matsav hathalate*/
int Member::AllUsers = 0;

/*Constructor*/
Member::Member()
{
	totalUsers++;
}
/*Destructor*/
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
void Member::add(Member& o) //o is for other
{
	followers.insert(&o);
}

void Member::delete(Member& o) //o is for other
{
	followers.erase(&o);
}

/********************************************************************************************/

int Member::allMembers()
{
	return AllUsers;
}

/********************************************************************************************/

void Member::Follow(Member& o) //o is for other
{
	if (following.find(&o) == following.end()){
		following.insert(&o);
		o.addToFollowers(*this);
	}
	else if (&o == this)
		return;
}


void Member::Unfollow(Member& o) //o is for other
{
	if (following.find(&o) != following.end()){
		following.erase(&o);
		o.deleteFromFollowers(*this);
	}
	else if (&o == this)
		return;
}

int Member::numberOfFollowers() const
{
	return followers.size();
}

int Member::numberOfFollowing() const 
{
	return following.size();
}


