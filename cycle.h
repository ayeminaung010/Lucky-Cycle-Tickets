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
        int current_index = 0;


        string arrId[100];
        string arrUsername[100];
        string arrPassword[100];
        string arrAmount[100];

        string r_username;
        string r_password;
        string c_password;
        string r_amount;

        string lusername;
        string lpassword;

        string choose_numuber;
        string luckyM_option;

        string luckyNumber[1000];
        int luckyNumberIndex = 0;



        //function declaration
        void welcome();
        int mainManu();
        void login();
        void Register();
        void loadingNumber(); // loading lucky number
        void userDataLoading(); //loading userData for admin
        void showUserData(); // show data for admin
        int userExist(string uName); //check user exist or not
        int luckyMainProject();
        void toRecordUserData(); //after program close ,store user data at file
        void luckyMOption(); // option for choose Lucky Number funciton
        void showAlltransition(); //show all record transition
        void loadingRecordTicket(); // loading already buy  tickets
    private:
    };

}
#endif //CYCLEPJ_CYCLE_H
