#include <vector>
#include <set>
#include <iostream>

using namespace std;

class user{

public:
	int id;
	set <int> followers;
	set <int> following;
	user();

};
user::user():id(0){}
class Member{
public:
	user person;

	static int nummembers;
	static vector<user*> alluser;

	Member();
	~Member();
	int numFollowers(){
		return person.followers.size();
	}
	int numFollowing(){
		return person.following.size();
	}
	void follow(Member& n){
		person.following.insert(n.person.id);
		n.person.followers.insert(person.id);
	}
	void unfollow(Member& n){
		person.following.erase(n.person.id);
		n.person.followers.erase(person.id);
	}
	static int count(){return nummembers;}
};
vector <user*> Member::alluser={};
int Member::nummembers=0;
Member::Member(){

	nummembers++;
	person.id=nummembers;
    alluser.push_back(&person);
}
Member::~Member(){

	nummembers--;
	for(unsigned int i=0;i<alluser.size();i++){
		alluser.at(i)->followers.erase(person.id);
		alluser.at(i)->following.erase(person.id);
	}
	alluser.pop_back();
}