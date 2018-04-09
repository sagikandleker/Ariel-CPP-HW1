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

Member avi, beni, chana;

void test1() {

	Member dana;

	chana.follow(dana);

	dana.follow(avi);

	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1

	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0

	cout << "  " << Member::count() << endl; // 4

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

	cout << Member::count() << endl; // 3

	return 0;
}
