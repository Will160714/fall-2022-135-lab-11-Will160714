#include "network.h"
#include <string>
#include <cctype>
#include <iostream>

Network::Network(){
    numUsers = 0;
    for(int x = 0; x < MAX_USERS; x++){
        for(int y = 0; y < MAX_USERS; y ++){
            following[x][y] = false;
        }
    }
}

int Network::findID(std::string usrn){
    for(int y = 0; y < numUsers; y++){
        if(profiles[y].getUsername() == usrn){
            return y;
        }
    }
    return -1;
}

bool Network::addUser(std::string usrn, std::string dpsn){
    bool alpha = true;
    for(int x = 0; x < usrn.length(); x++){
        if(!isalpha(usrn[x])){
            alpha = false;
            break;
        }
    }

    bool unique = true;
    if(findID(usrn) >= 0)
        unique = false;

    if(alpha && numUsers < MAX_USERS && unique){
        numUsers++;
        profiles[numUsers] = {usrn, dpsn};
        return true;
    }
    return false;
}

bool Network::follow(std::string usrn1, std::string usrn2){
    int row = -1;
    int column = -1;
    for(int y = 0; y < MAX_USERS; y++){
        if(profiles[y].getUsername() == usrn1)
            row = y;
        if(profiles[y].getUsername() == usrn2)
            column = y;
    }

    if(row > -1 && column > -1){
        following[row][column] = true;
        return true;
    }
    return false;
}

void Network::printDot(){
    std::cout << "digraph {" << std::endl;
    for(int z = 0; z < MAX_USERS; z++){
        if(profiles[z].getUsername() != "")
            std::cout << "  \"" << profiles[z].getUsername() << "\"" << std::endl;
    }

    std::cout << std::endl;
    
    for(int x = 0; x < MAX_USERS; x++){
        for(int y = 0; y < MAX_USERS; y++){
            if(following[x][y] == true && x != y){
                std::cout << "  \"" << profiles[x].getUsername() << "\"" << " -> \"" << profiles[y].getUsername() << "\"" << std::endl;
            }
        }
    }
    std::cout << "}" << std::endl;
}