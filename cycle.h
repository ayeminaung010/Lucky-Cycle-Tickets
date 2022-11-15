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
        void mainManu();
        void login();
        void Register();
        void loadingNumber(); // loading lucky number

        int userExist(string uName); //check user exist or not
        int luckyMainProject();  //to buy lucky tickets
        void toRecordUserData(); //after program close ,store user data at file
        void luckyMOption(); // option for choose Lucky Number func
        void userOption(); //user option
        void toReadHistory(); //to show user buy data
        void changeUserName(); // change username
        void changeUserPass(); //change user pass
        void fillUserAmount(); // fill money user
        int toCheckLuckyNumber(string number); // already buy or not
        void loadingRecordTicket(); // loading already buy  tickets

        //for admin
        string admin_username;
        string admin_password;
        string _arr_admin_username[3] = {"admin1@gmail.com","admin2@gmail.com","admin3@gmail.com"};
        string _arr_admin_password[3] = {"admin1","admin2","admin3"};

        int _adminIndex = 3;
        void userDataLoading(); //loading userData for admin
        void adminView();
        void showAllRecordTransition(); //show record all transition
        void showUserData(); // show data for admin
        int toCheckAdmin(string lname); // login check  admin or not
        void manageUser(); //manage user
        int remove_user();
        int ban_user();
        int _change_userPass();
        void optionForRemove();
        void  optionForBan();
        void toRecordBanUser( string bname);
    };

}
#endif //CYCLEPJ_CYCLE_H
