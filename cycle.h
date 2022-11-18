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

        string luckyNumber[1000];//already buy numbers (sorry I was wrong naming :<)
        int luckyNumberIndex = 0;

        string numberAvailable[1000]; //  numbers
        int numberAvailableIndex = 0;

        //function declaration
        void welcome();
        void mainManu();
        void login();
        void Register();
        void loadingNumber(); // loading lucky number
        void numberSet();
        void numberGet(); //loading
        void rm_number(string num); // to remove not available numbers
        void toRecordAvailableNo(); //record left numbers in another file

        int userExist(string uName); //check user exist or not
        void luckyMainProject();  //to buy lucky tickets
        void userOption(); //user option //user first view
        void login_option();
        void toRecordUserData(); //after program close ,store user data at file
        void luckyMOption(); // option for choose Lucky Number func
        void toReadHistory(); //to show user buy data history
        void changeUserName(); // change username
        void changeUserPass(); //change user pass
        void fillUserAmount(); // fill money user
        int toCheckLuckyNumber(string number); // already buy or not
        void loadingRecordTicket(); // loading already buy  tickets
        void showBalance();

        //for admin
        string admin_username;
        string admin_password;
        string _arr_admin_username[10] = {"admin"};
        string _arr_admin_password[10] = {"admin123"};
        string _arr_admin_id[10];
        string  _banUser[100];

        int _banIndex = 0;
        int _admin_nameIndex = 1;
        int _admin_passIndex = 1;
        int _admin_idIndex = 1;
        void userDataLoading(); //loading userData
        void adminView();
        void showAllRecordTransition(); //show record all transition
        void showUserData(); // show data for admin
        int toCheckAdmin(string lname); // login check  admin or not
        void manageUser(); //manage user
        void remove_user(); //remove user or delete use acc
        void ban_user(); //ban user for admin
        void unban_user(); //unban user /remove from ban list
        void  optionForBan();
        void toRecordBanUser(); // record ban user
        int toCheckBanUser(string ban_user); //check ban use or not
        void loadingBanUser(); //loading from file/ ban users
        void showBanUserlist();//to show ban user for admin

        void _change_userPass(); //change user pass for admin /what if user contact to admin,user not remember pass
        void optionForRemove();

        void newAdminAdd(); // admin can add new admins
        void toRecordAdminData(); //record admin data
        void loadingAdminData(); //load admin data
        void removeFromAdminList(); //remove admin from  list
        void optionForadminRemove(); //remove option for admin removing
        void toShowAdminList(); //admin list
        void adminChangePw(); //change pw for admin
        void adminChangeUname(); //change name for admin

        void user_name_history();// to show users name change history

    };
}
#endif //CYCLEPJ_CYCLE_H
