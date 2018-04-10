#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Member{

public:
static vector<Member*> allUsers;
set<Member*> following;
set<Member*> followers;

Member();
~Member();

int numFollowers(){
    return this->followers.size();
}

int numFollowing(){
    return this->following.size();
}

void follow(Member &m){
    if(this != &m){
        this->following.insert(&m);
        m.followers.insert(this);
    }
}

void unfollow(Member& m){
    if(this != &m){
        this->following.erase(&m);
        m.followers.erase(this);
    }
}

static int count(){
    return allUsers.size();
}

};

vector<Member*> Member::allUsers = {};

Member::Member(){
    allUsers.push_back(this);
}


Member::~Member(){

for(unsigned int i = 0; i < allUsers.size(); i++){
    allUsers.at(i)->followers.erase(this);
    allUsers.at(i)->following.erase(this);
    }

int del = 0;
for(unsigned int j = 0; j < allUsers.size(); j++){
    if(this == allUsers.at(j)){
            del = j;
        }
    }

    allUsers.erase(allUsers.begin() + del);

}
