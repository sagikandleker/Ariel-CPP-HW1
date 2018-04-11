#include <iostream>
using namespace std;

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

    if(Michael.numFollowing() != 0)
    {
        cout << "Member follow himself ERROR" << endl;
    }

}

void member_Unfollow_himself()
{
    cout << Sowyer.numFollowing()  << endl; // 0
    Sowyer.unfollow(Sowyer);
    cout << Sowyer.numFollowing()  << endl; // 0

    if(Sowyer.numFollowing() != 0)
    {
        cout << "Member unfollow himself ERROR" << endl;
    }
}

void member_Destructor(){
    Member Elizabeth;
    
    cout << Member::count() << endl; // 4

    if(Member::count() != 4)
    {
        cout << "ERROR with the Constructor function." << endl;
    }

    Elizabeth.follow(Michael);
    Elizabeth.follow(Sowyer);
    Elizabeth.follow(John);

    cout << Elizabeth.numFollowers() << " " <<  Elizabeth.numFollowing() << endl; // 0 3
    cout << Michael.numFollowers() << " " <<  Michael.numFollowing() << endl; // 1 0
    cout << Sowyer.numFollowers() << " " <<  Sowyer.numFollowing() << endl; // 1 0
    cout << John.numFollowers() << " " <<  John.numFollowing() << endl; // 1 0

    if(Elizabeth.numFollowing() != 3)
    {
        cout << "ERROR with the numFollowing function." << endl;
    }

    if(John.numFollowers() != 1)
    {
        cout << "ERROR with the numFollowers function." << endl;
    }
}

int main() {
    member_Follow_himself();
    member_Unfollow_himself();
    member_Destructor();
    cout << Member::count() << endl; // 3
    
    return 0;
}