#include "Member.h"

using namespace std;

/**
 * Global Vector with Member pointer
 */
vector<Member*> Member::members = {};

/**
 * Constructor function.
 * for each Member set with Following and set with Followers.
 * Finally, push this Member to the Vector.
 */
Member::Member()
{
    members.push_back(this);
}

/**
 * Destructor function.
 * One loop to erase this Member from all other Members.
 * And the second loop to search this Member index inside the Vector and erase him.
 */
Member::~Member()
{

for(unsigned int i = 0; i < members.size(); i++)
{
    members.at(i)->followers.erase(this);
    members.at(i)->following.erase(this);
}

int des_index = 0;
for(unsigned int j = 0; j < members.size(); j++)
{
    if(this == members.at(j))
    {
        des_index = j;
    }
}

    members.erase(members.begin() + des_index);

}

/**
 * numFollowers function.
 * return the size of followers list for "this" Member.
 */
int Member::numFollowers()
{
    return this->followers.size();
}

/**
 * numFollowing function.
 * return the size of following list for "this" Member.
 */
int Member::numFollowing()
{
    return this->following.size();
}

/**
 * follow function.
 * First check if this Member want to add himself.
 * if not, add the received Member to "this" Member following.
 * and add "this" Member to the followers list of received Member.
 */
void Member::follow(Member &m)
{
    if(this != &m)
    {
        this->following.insert(&m);
        m.followers.insert(this);
    }
}

/**
 * unfollow function.
 * First check if this Member want remove himself.
 * if not, remove the received Member from "this" Member following.
 * and remove "this" Member from the followers list of received Member.
 */
void Member::unfollow(Member& m)
{
    if(this != &m)
    {
        this->following.erase(&m);
        m.followers.erase(this);
    }
}

/**
 * Count function to return the size of all Members Vector.
 */
int Member::count()
{
    return members.size();
}
