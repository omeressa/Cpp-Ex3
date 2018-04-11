#pragma once

//#ifndef MEMBER_HPP_
//#define MEMBER_HPP_

#include <set>

class Member {
	
	static int AllUsers;// total number of members
	
	/**************************************************************************************/

	std::set<Member*> followers;// members which I'm following
	std::set<Member*> following;// members which are following me
	
	/**************************************************************************************/
             /*both adding and deleting functions r to ease the insert and erase procsess*/
	
	void adding(Member& other);//Add to following
	void deleting(Member& other);//Remove from following
	
	/**************************************************************************************/

public:
	Member(); // This is the constructor declaration
	~Member(); // This is the destructor declaration
	/**************************************************************************************/
	
	static int count();//gives back the number of all members
	
	/**************************************************************************************/

	void follow(Member& o);//function to follow a member
	void unfollow(Member& o);//function to unfollow a member
	int numFollowers() const;//function to give the number of followers
	int numFollowing() const;//function to give the number of following

};

//#endif /* MEMBER_HPP_ */
