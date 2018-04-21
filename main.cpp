
#include <iostream>
using namespace std;

#include "Member.h"

bool test(int a,int b){
  if(a==b)return true;
  return false;
}

Member avi, beni, chana;

/*assiment tester*/
void test1() {
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}


/*Testing the changes of the number of all users*/
void test2() {
  Member a;
  cout<<"Number of all users is :"<< Member::count()<<endl;
  Member b;
  cout<<"Number of all users is :"<< Member::count()<<endl;
  Member c;
  cout<<"Number of all users is :"<< Member::count()<<endl;
}

/*Testing the follow functiong , following and followers*/
void test3() {
  Member a,b,c;
  int ans = a.numFollowing();
  cout<<"is a following one person? (true = 1, false = 0) :"<< test(ans,3)<<endl;
  a.follow(b);
  cout<< "is a following one person? (true = 1, false = 0) :"<<test(a.numFollowing(),1)<<endl;
  a.follow(c);
  cout<<"is a following two persons? (true = 1, false = 0) :"<<test(a.numFollowing(),2)<<endl<<endl;
  cout<<"number of members following a: "<<a.numFollowers()<<endl;
  cout<<"number of members following b: "<<b.numFollowers()<<endl;
  cout<<"number of members following c: "<<c.numFollowers()<<endl<<endl;
  cout<<"what happens after a unfollowing both b,c :"<<endl;
  a.unfollow(b);
  a.unfollow(c);
  cout<< "is a following one person? (true = 1, false = 0) :"<<test(a.numFollowing(),1)<<endl;
  cout<<"is a following two persons? (true = 1, false = 0) :"<<test(a.numFollowing(),2)<<endl<<endl;
    cout<<"number of members following b: "<<b.numFollowers()<<endl;
  cout<<"number of members following c: "<<c.numFollowers()<<endl<<endl;
}

int main() {
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;

	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	test1();
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
	
	cout<<endl<<"Testing the changes of the number of all users :"<<endl;
        test2();
        cout<<"Testing the follow functiong , following and followers :"<<endl;
        test3();
	cout << Member::count() << endl; // 3
}
