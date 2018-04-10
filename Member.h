
#include <vector>
#include <set>
#include <iostream>

using namespace std;


class Member{

public:
static vector<Member*> members;
set<Member*> following;
set<Member*> followers;

Member();
~Member();

int numFollowers();
int numFollowing();

void follow(Member &m);
void unfollow(Member &m);

static int count();
};

