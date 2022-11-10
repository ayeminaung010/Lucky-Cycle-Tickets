//
// Created by Aye MIn Aung on 11/10/2022.
//
#include "iostream"
using namespace std;
#ifndef CYCLEPJ_CYCLE_H
#define CYCLEPJ_CYCLE_H

namespace  N {

    class cycle {
    public:

        //variable declare
        int idIndex = 0;
        int userNameIndex = 0;
        int passwordIndex = 0;
        int amountIndex = 0;
        string arrId[100];
        string arrUsername[100];
        string arrPassword[100];
        string arrAmount[100];


        //function declaration
        void welcome();
        int mainManu();
        int login();
        int Register();
        void loadingNumber();
        void userDataLoading();
        int showUserData();

    private:
    };

}
#endif //CYCLEPJ_CYCLE_H
