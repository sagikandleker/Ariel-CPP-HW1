#include "Member.h"

/**
 * Tests File.
 */ 
Member Michael, Sowyer, John;

void member_Follow_himself()
{

    cout << Michael.numFollowing()  << endl; // 0
    Michael.follow(Michael);
    cout << Michael.numFollowing()  << endl; // 0

}

void member_Unfollow_himself()
{
    cout << Sowyer.numFollowing()  << endl; // 0
    Sowyer.unfollow(Sowyer);
    cout << Sowyer.numFollowing()  << endl; // 0
}

void member_Destructor(){
    Member Elizabeth;
    
    cout << Member::count() << endl; // 4

    Elizabeth.follow(Michael);
    Elizabeth.follow(Sowyer);
    Elizabeth.follow(John);

    cout << Elizabeth.numFollowers() << " " <<  Elizabeth.numFollowing() << endl; // 0 3
    cout << Michael.numFollowers() << " " <<  Michael.numFollowing() << endl; // 1 0
    cout << Sowyer.numFollowers() << " " <<  Sowyer.numFollowing() << endl; // 1 0
    cout << John.numFollowers() << " " <<  John.numFollowing() << endl; // 1 0

}

int main() {
    member_Follow_himself();
    member_Unfollow_himself();
    cout << Member::count() << endl; // 3
    member_Destructor();
    cout << Member::count() << endl; // 3

}