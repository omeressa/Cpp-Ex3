#pragma once

#ifndef MEMBER_HPP_
#define MEMBER_HPP_

#include <set>

class Member {
	
	static int AllUsers;//Number of members

	std::set<Member*> followers;//List of followers for this member
	std::set<Member*> following;//List of following for this member

	void add(Member& o);//Add to following
	void delete(Member& o);//Remove from following

public:
	Member();
	~Member();
	
	static int allMembers();//gives back the number of all members

	void Follow(Member& o);//function to follow a member
	void Unfollow(Member& o);//function to unfollow a member
	int numberOfFollowers() const;//function to give the number of followers
	int numberOfFollowing() const;//function to give the number of following

};

#endif /* MEMBER_HPP_ */
