#include <iostream>
#include "network.h"
#include "profile.h"

int main(){
    std::cout << "Task A" << std::endl;
    Profile p1("William", "Lin");    
    std::cout << p1.getUsername() << std::endl; // Will
    std::cout << p1.getFullName() << std::endl; // Lin (@William)

    p1.setDisplayName("Ryan Law"); 
    std::cout << p1.getFullName() << std::endl; // Ryan Law (@William)
    
    Profile p2;    
    std::cout << p2.getUsername() << std::endl; // 
    std::cout << p2.getFullName() << std::endl; // (@)
    std::cout << std::endl;

    std::cout << "Task B" << std::endl;
    Network net;
    std::cout << net.addUser("Will", "test") << std::endl;     // true (1)
    std::cout << net.addUser("Vincent", "test1") << std::endl;     // true (1)
    std::cout << net.addUser("Isaac", "test3") << std::endl; // true (1)
    std::cout << net.addUser("Will", "test3") << std::endl;    // false (0)
    std::cout << net.addUser("Will 1", "test4") << std::endl;  // false (0)
    std::cout << net.addUser(" ", "test5") << std::endl;  // false (0)
    std::cout << std::endl;

    std::cout << "Task C" << std::endl;
    std::cout << net.follow("Will", "Vincent") << std::endl; //true (1)
    std::cout << net.follow("Vincent", "Isaac") << std::endl; //true (1)
    std::cout << net.follow("Isaac", "Will") << std::endl; //true (1)
    std::cout << net.follow("Lawerance", "Ryan") << std::endl; //false (0)

    net.printDot();


    std::cout << std::endl;
    

    return 0;
}