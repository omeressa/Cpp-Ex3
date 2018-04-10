#include "Member.h"
using namespace std;

int Member::AllUsers = 0;

Member::Member()
{
	totalUsers++;
}

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

int Member::count()
{
	return AllUsers;
}

int Member::numberOfFollowers() const
{
	int numberOfFollowers = followers.size();
	return numberOfFollowers;
}

int Member::numberOfFollowing() const 
{
	int numberOfFollowing = following.size();
	return numberOfFollowing;
}

void Member::add(Member& o) //o is for other
{
	followers.insert(&o);
}

void Member::delete(Member& o) //o is for other
{
	followers.erase(&o);
}


void Member::Follow(Member& o) //o is for other
{

	if (&o == this)
		return;

	if (following.find(&o) == following.end()) {
		following.insert(&o);
		o.addToFollowers(*this);
	}
}


void Member::Unfollow(Member& o) //o is for other
{

	if (&o == this)
		return;

	if (following.find(&o) != following.end())
	{
		following.erase(&o);
		o.deleteFromFollowers(*this);
	}
}
