//
// Created by Aye MIn Aung on 11/10/2022.
//

#include "cycle.h"
#include "iostream"
#include "fstream"
using namespace  N;
using namespace  std;


void cycle::welcome() {
    cout<<"Welcome from our cycle lucky project"<<endl;
    userDataLoading();
    showUserData();
    mainManu();
}

void cycle::mainManu() {
    string  mainMenuOption;
    cout<<" \n This is main menu"<<endl;
    cout<<" Press 1 to Register \n Press 2 to Login \n Press 3 to Quit"<<endl;
    cin>>mainMenuOption;

    if(mainMenuOption == "1"){
        Register();
    }else if(mainMenuOption == "2"){
        login();
    }else if( mainMenuOption == "3"){
        cout<<"BYE BYE!!"<<endl;
        exit(1);
    }else{
        cout<<"Invalid input"<<endl;
        mainManu();
    }
}

void cycle::showAllRecordTransition() {
    cout<<"loading recorded data is running.."<<endl;

    string  recordFile = "recordTicketsBuy.txt";
    string recordData;

    ifstream datafile(recordFile);
    if(datafile.is_open()){
        while (getline(datafile,recordData)){
            cout<<recordData<<endl;
        }
        datafile.close();
    }else{
        cout<<"Don't have record!\nCannot open file"<<endl;
        adminView();
    }
}

void cycle::loadingRecordTicket() {
    cout<<"Record already buy tickets data are loading...."<<endl;
    int count = 0;

    string  recordFile = "recordTicketsBuy.txt";
    string  data ; // temporary  to store
    string dataLine; // to store data from one line
    ifstream datafile(recordFile);
    if(datafile.is_open()){
        while (getline(datafile,dataLine)){
            for(auto &ch :dataLine){
                if(ch == ' '){
                    if(count == 0){
                        data = "";
                        count++;
                    }else if(count == 1){
                        luckyNumber[luckyNumberIndex] = data;
                        cout<<"Already buy this number:"<<luckyNumber[luckyNumberIndex]<<endl;
                        luckyNumberIndex++;
                        data = "";
                        count++;
                    }else if(count == 2){
                        data = "";
                        count = 0;
                    }

                }else{
                    string st(1,ch);
                    data = data + st;
                }

            }
        }//end while

        datafile.close();
    }else{
        cout<<"cannot open file"<<endl;
    }


}
int cycle::luckyMainProject() {
    cout<<"This is to choose for lucky number ..Good Luck!"<<endl;
    loadingNumber();
    cout<<"Choose 3 digits Number You Want :"<<endl;
    cin>>choose_numuber;
    int status = toCheckLuckyNumber(choose_numuber);
    if(status == 1){
        cout<<"Already bought this number :"<<choose_numuber<<endl;
        cout<<"__________________________________"<<endl;
        luckyMainProject();
    }else{
        int number = 0;
        number = stoi(choose_numuber);
        if(number >= 100 &&  number < 1000){
            cout<<"Loading.....Please wait..!!"<<endl;
            cout<<"Checking your Balance..."<<endl;
            int balance = stoi(arrAmount[current_index]);
            if( balance >= 2500){
                int newBalance =  balance - 2500;
                balance = newBalance;
                arrAmount[current_index] = to_string(balance);
                toRecordUserData();

                string  recordFile = "recordTicketsBuy.txt"; //for admin file
                string  usernameFile = arrUsername[current_index]+".txt"; //user only file
                //to write file
                ofstream outfile; // open all record bought data file
                outfile.open(recordFile,ios::app);

                ofstream userFile; // open user file
                userFile.open(usernameFile,ios::app);
                if(outfile.is_open()){
                    string toRecord = to_string(current_index + 1)+" "+ to_string(number) +" bought-by "+arrUsername[current_index]+"\n";
                    outfile<<toRecord; //for admin file

                    string userTxtRecord = to_string(number) + " bought by you:"+arrUsername[current_index]+" \n";
                    userFile<<userTxtRecord; //user only file

                    userFile.close();// close userfile

                    outfile.close(); //close all data file
                    cout<<"Buy SuccessFully... \nGood choice..Good Luck Your Number :)"<<endl;

                    luckyMOption();
                }else{
                    cout<<"Enable to record data !"<<endl;
                    cout<<"Error 444"<<endl;
                    exit(444);
                }
            }else{
                cout<<"Insufficient Balance...\nFill your Balance to buy again!!"<<endl;
                cout<<"__________________________________"<<endl;
                userOption();
            }
        }else{
            cout<<"Invalid input..PLease Enter 3 digits...!"<<endl;
            luckyMOption();
        }
    }//end checking


}

void cycle::luckyMOption(){
    cout<<"Press 1 to Buy Tickets Again\nPress 2 to Quit \nPress any number to Log out "<<endl;
    cin>>luckyM_option;
    if(luckyM_option == "1"){
        luckyMainProject();
    }else if(luckyM_option == "2"){
        cout<<"BYE BYE..."<<endl;
        exit(1);
    }else{
        mainManu();
    }
}

void cycle::Register() {
    string r_option;
    cout<<"This is Register Page"<<endl;
    cout<<"Enter username to Register."<<endl;
    cin>>r_username;
    int status = userExist(r_username);
    if(status != -1){
        cout<<"Username Already Exists.. Try Again!!  "<<endl;
        cout<<"Press 1 to login \nPress 2 to continue Register"<<endl;
        cin>>r_option;
        if(r_option == "1"){
            login();
        }else if(r_option == "2"){
            Register();
        }else{
            cout<<"Invalid Input.. !"<<endl;
            mainManu();
        }
    }else{
        cout<<"Enter your password for "<<r_username<<endl;
        cin>>r_password;
        cout<<"Comfrim your password.."<<endl;
        cin>>c_password;
        if(r_password == c_password){
            cout<<"Register Success!!"<<endl;
            cout<<"Enter amount :"<<endl;
            cin>>r_amount;
            arrUsername[userNameIndex] = r_username;
            arrPassword[passwordIndex] = r_password;

            arrAmount[amountIndex] = r_amount;
            userNameIndex++;
            passwordIndex++;
            amountIndex++;
            idIndex++;
            toRecordUserData();
            mainManu();
        }else{
            cout<<"Password not match.."<<endl;
            Register();
        }
    }

}

void cycle::toRecordUserData(){
    string  userDatafile = "user.txt";

    //to write file
    ofstream outfile;
    outfile.open(userDatafile,ios::out);
    if(outfile.is_open()){
        for (int j = 0; j < userNameIndex ; ++j) {
            idIndex = j+1;
            string toRecord = to_string(idIndex)+" "+arrUsername[j]+" "+arrPassword[j]+" "+arrAmount[j]+" \n";

            outfile<<toRecord;
        }
        outfile.close();
    }else{
        cout<<"Enable to record data !"<<endl;
        cout<<"Error 444"<<endl;
        exit(444);
    }
}

void cycle::login() {
    string admin_pass;
    cout<<"This is Login Page"<<endl;
    cout<<"Enter your username to Login"<<endl;
    cin>>lusername;
    int adminStatus = toCheckAdmin(lusername);
    int ban_status = toCheckBanUser(lusername);

    if(adminStatus != -1){
            cout<<"Found!  You are Admin....Enter your password"<<endl;
            cin>>admin_pass;
            if(_arr_admin_password[adminStatus] == admin_pass){
                adminView();
            } else{
                cout<<"Wrong Password!"<<endl;
                mainManu();
            }
    }
    if(ban_status == -1){
        int status = userExist(lusername);
        if(status != -1){
            cout<<"UserName Found! .. \nEnter your password for "<<lusername<<endl;
            cin>>lpassword;
            if (lpassword == arrPassword[status]){
                cout<<"Login success..."<<endl;
                current_index = status; // to know current login user
                userOption();
                // here something// go to buy lucky number
            }else{
                cout<<"login failed! Wrong password!.."<<endl;
                login();
            }
        }else{
            cout<<"Username not found!"<<endl;
            mainManu();
        }
    }else{
        cout<<"********This account is Banned By admin*******\nContact Our Email Address ->> cyclepj@gmail.com"<<endl;
        login();
    }
}

void cycle::loadingNumber(){
    string luckynumber = "luckynumber.txt";

    cout<<"loading process is running.."<<endl;

    string numberData;
    //read file
    ifstream numberfile(luckynumber);
    if(numberfile.is_open()){
        while (getline(numberfile,numberData)){
            cout<<numberData<<endl;
        }
        numberfile.close();
    }else{
        cout<<"cannot open file"<<endl;
    }
}

int cycle::userExist(string uName) {
    for (int j = 0; j < userNameIndex ; j++) {
        if(arrUsername[j] == uName){
            return j; //found uName
        }
        if(_arr_admin_username[j] == uName){
            return j;
        }
    }
    return -1; //not found
}

void cycle::userDataLoading() {
    cout<<"user data are loading...."<<endl;
    int count = 0;

    string  userDatafile = "user.txt";
    string  data ; // temporary  to store
    string dataLine; // to store data from one line
    ifstream userfile(userDatafile);
    if(userfile.is_open()){
        while (getline(userfile,dataLine)){
//            dataLine = dataLine+" ";
            for(auto &ch :dataLine){
                if(ch == ' '){
                    if(count == 0){
                        arrId[idIndex] = data;
                        idIndex++;
                        data = "";
                        count++;
                    }else if(count == 1){
                        arrUsername[userNameIndex] = data;
                        userNameIndex++;
                        data = "";
                        count++;
                    }else if(count == 2){
                        arrPassword[passwordIndex] = data;
                        passwordIndex++;
                        data = "";
                        count++;
                    }else if (count == 3){
                        arrAmount[amountIndex] = data;
                        amountIndex++;
                        data = "";
                        count = 0;
                    }
                }else{
                    string st(1,ch);
                    data = data + st;
                }
            }
        }//end while

        userfile.close();
    }else{
        cout<<"cannot open file"<<endl;
    }
}

void cycle::showUserData() {
    for (int i = 0; i < idIndex ; i++) {
        cout<<"id : "<<arrId[i]<<" -"<<"username : "<<arrUsername[i]<<" -"<<"password : "<<arrPassword[i]<<" -"<<"amount : "<<arrAmount[i]<<endl;
    }
}

void cycle::userOption() {
    string u_option;
    cout<<"Press 1 to buy tickets\nPress 2 to Change Username\nPress 3 to Change Password\nPress 4 to see History\nPress 5 to Fill money\nPress 6 to see Balance\nPress 7 to Log Out\nPress 8 to Quit"<<endl;
    cin>>u_option;

    if(u_option == "1"){
        luckyMainProject();
    }else if (u_option == "2"){
        changeUserName();
    }else if (u_option == "3"){
        changeUserPass();
    }else if (u_option == "4"){
        toReadHistory();
        userOption();
    }else if (u_option == "5"){
        fillUserAmount();
    }else if (u_option == "6"){
        showBalance();
    }else if (u_option == "7"){
        mainManu();
    }else if (u_option == "8"){
        cout<<"BYE BYE GOOD LUCK"<<endl;
        exit(1);
    }else{
        cout<<"Invalid Input!"<<endl;
        userOption();
    }

}
void cycle::showBalance() {
    if(stoi(arrAmount[current_index]) <= 2000){
        cout<<"Your Balance is Low(fill money to buy more ):"<<arrAmount[current_index]<<endl;
        userOption();
    }else{
        cout<<"Your Balance is :"<<arrAmount[current_index]<<endl;
        userOption();
    }
}

void cycle::toReadHistory() {
    string filename = arrUsername[current_index] + ".txt";
    string historyData;
    ifstream History(filename);
    if(History.is_open()){
        while (getline(History,historyData)){
            cout<<historyData<<endl;
        }
        cout<<"Thank You For Your Support"<<endl;
        cout<<"__________________________________"<<endl;
        History.close();
    }else{
        cout<<"No data found!!\nCannot open file!"<<endl;
        userOption();
    }
}

void cycle::changeUserName() {
    string n_username;
    cout<<"Enter new Username for :"<<arrUsername[current_index]<<endl;
    cin>>n_username;
    int status = userExist(n_username);
    if(status != -1){
        cout<<"Username Already Exists.. Try Again!!  "<<endl;
        changeUserName();
    }else{
        arrUsername[current_index] = n_username; //changes
        cout<<"Your new username is -"<<arrUsername[current_index]<<endl;
        toRecordUserData();
        userOption();
    }
}

void cycle::changeUserPass() {
    string  ch_password;
    string n_password;
    string cp_option;
    cout<<"Enter your current Password "<<endl;
    cin>>ch_password;
    if(ch_password == arrPassword[current_index]){
        cout<<"Enter new Password for :"<<arrUsername[current_index]<<endl;
        cin>>n_password;
        arrPassword[current_index] = n_password;
        toRecordUserData();
        userOption();
    }else{
        cout<<"Wrong Password!!"<<endl;
        cout<<"Press 1 to go Option\nPress any number to Change Password again"<<endl;
        cin>>cp_option;
        if(cp_option == "1"){
            userOption();
        }else{
            changeUserPass();
        }
    }
}

void  cycle::fillUserAmount() {
    string n_amount;
    cout<<"Enter your amount:"<<endl;
    cin>>n_amount;
    arrAmount[current_index] = stoi(arrAmount[current_index])+ stoi(n_amount);
    toRecordUserData();
    cout<<"SuccessFully Added your Balance.."<<endl;
    cout<<"__________________________________"<<endl;
    userOption();
}

int cycle::toCheckLuckyNumber(string number) {
    for (int j = 0; j < luckyNumberIndex ; j++) {
        if(luckyNumber[j] == number){
            return 1; //found number
        }
    }
    return -1; //not found
}

int cycle::toCheckAdmin(string lname) {
    for (int j = 0; j < _adminIndex ; j++) {
        if(_arr_admin_username[j] == lname){
            return j; //found uName
        }
    }
    return -1; //not found
}

void cycle::adminView() {
    string admin_option;
    cout<<"Welcome from Admin Panel"<<endl;
    cout<<"Press 1 to see User Data\nPress 2 to see Tickets buy History\nPress 3 to manage User\nPress 4 to see Already buy number Only..\nPress 5 to Log out\nPress 6 to Quit"<<endl;
    cin>>admin_option;
    if(admin_option == "1"){
        showUserData();
        adminView();
    }else if(admin_option== "2"){
        showAllRecordTransition();
        adminView();
    }else if(admin_option == "3"){
        manageUser();
    }else if(admin_option == "4"){
        loadingRecordTicket();
        adminView();
    }else if(admin_option == "5"){
        mainManu();
    }else if(admin_option == "6"){
        cout<<"Bye Bye Admin..."<<endl;
        exit(1);
    }else{
        cout<<"Invalid input!!"<<endl;
        adminView();
    }
}

void cycle::manageUser() {
    string  m_option;
    cout<<"Press 1 to remove user account\nPress 2 to Ban User \nPress 3 to change User password\nPress 4 to see Banned user lists\nPress 5 to go back\nPress 6 to Quit"<<endl;
    cin>>m_option;
    if(m_option == "1"){
        remove_user();
    }else if(m_option == "2"){
        ban_user();
    }else if(m_option== "3"){
        _change_userPass();
    }else if(m_option == "4"){
        showBanUserlist();
    }else if(m_option == "5"){
        adminView();
    }else if(m_option == "6"){
        cout<<"Bye Bye Admin..."<<endl;
        exit(1);
    }else{
        cout<<"Invalid input!!"<<endl;
        manageUser();
    }
}

int cycle::remove_user() {
    string rm_username;
    string rm_option;

    cout<<"Enter username to remove"<<endl;
    cin>>rm_username;
    int status = userExist(rm_username);
    if(status != -1){
            cout<<"Found username...!! Are you sure to remove this user :"<<arrUsername[status]<<endl;
            cout<<"Press 1 to say YES\nPress 2 to say NO"<<endl;
            cin>>rm_option;

            if(rm_option == "1"){
                    for (int i = 0; i < 100; ++i) {
                        arrUsername[i] = arrUsername[i+1];
                        arrPassword[i] = arrPassword[i+1];
                        arrAmount[i] = arrAmount[i+1];
                        arrId[i] = arrId[i+1];
                    }
                    userNameIndex--;
                    passwordIndex--;
                    amountIndex--;
                    idIndex--;
                    cout<<"Successfully removed..."<<endl;
                    toRecordUserData();
                    optionForRemove();
            }else if(rm_option == "2"){
                optionForRemove();
            }else{
                cout<<"Invalid Input"<<endl;
                remove_user();
            }
    }else{
        cout<<"Username Not Found"<<endl;
        remove_user(); //something
    }
}
void cycle::optionForRemove(){
    string rm_option2;
    cout<<"Press 1 to go back\nPress 2 to remove  username again"<<endl;
    cin>>rm_option2;
    if(rm_option2 == "1"){
        adminView();
    }else if(rm_option2 =="2"){
        remove_user();
    }else{
        cout<<"Invalid Input"<<endl;
        optionForRemove();
    }
}

int cycle::ban_user(){
    string  b_username;
    string b_option;
    cout<<"Enter username to Ban from our program ..."<<endl;
    cin>>b_username;
    int status = userExist(b_username);

    if(status != 1){
        cout<<"Found username...!! Are you sure to ban this user :"<<arrUsername[status]<<endl;
        cout<<"Press 1 to say YES\nPress 2 to say NO"<<endl;
        cin>>b_option;

        if(b_option == "1"){
            _banUser[_banIndex] = b_username;
            _banIndex++;
            toRecordBanUser();
            cout<<"Successfully Banned.. !"<<endl;
            optionForBan();
        }else if(b_option == "2"){
            optionForBan();
        }else{
            cout<<"Invalid Input"<<endl;
            ban_user();
        }
    } else{
        cout<<"User not found "<<endl;
        ban_user();
    }
}

void cycle::toRecordBanUser() {
    string  ban_file = "BanUser.txt";

    //to write file
    ofstream outfile;
    outfile.open(ban_file,ios::out);
    if(outfile.is_open()){
        for (int i = 0; i < _banIndex ; ++i) {
            string toRecord = _banUser[i]+"\n";
            outfile<<toRecord;
        }
        outfile.close();
    }else{
        cout<<"Enable to record data !"<<endl;
        cout<<"Error 444"<<endl;
        exit(444);
    }

}
void cycle::optionForBan(){
    string b_option2;
    cout<<"Press 1 to go back\nPress 2 to ban  username again"<<endl;
    cin>>b_option2;
    if(b_option2 == "1"){
        adminView();
    }else if(b_option2 =="2"){
        ban_user();
    }else{
        cout<<"Invalid Input"<<endl;
        optionForRemove();
    }
}


int cycle::_change_userPass(){
    string ch_username;
    string n_pass;
    cout<<"Enter username to change password"<<endl;
    cin>>ch_username;
    int status = userExist(ch_username);
    if(status != -1){
        cout<<"Found username :"<<endl;
        cout<<"Enter new password for this user :"<<arrUsername[status]<<endl;
        cin>>n_pass;
        while (true){
            if(n_pass !=  arrPassword[status]){
                arrPassword[status] = n_pass;
                toRecordUserData();
                cout<<"Password changed SuccessFully .... "<<endl;
                manageUser();
            }else{
                cout<<"Password must not be same with current password..!!"<<endl;
                break;
            }
        }
    }else{
        cout<<"User not found "<<endl;
        _change_userPass();
    }
}

int cycle::toCheckBanUser(string ban_user) {
    for (int i = 0; i < _banIndex ; ++i) {
        if(_banUser[i] == ban_user){
            return i; //found
        }
    }
    return -1; //not found
}

void cycle::loadingBanUser() {
    string  ban_file = "BanUser.txt";

    string historyData;
    ifstream History(ban_file);
    if(History.is_open()){
        while (getline(History,historyData)){
            cout<<historyData<<endl;
            _banUser[_banIndex] = historyData;
            _banIndex++;
        }
        cout<<"__________________________________"<<endl;
        History.close();
    }else{
        cout<<"No Data History:(\nCannot open file "<<endl;
        exit(1);
    }
}
void cycle::showBanUserlist() {
    for (int i = 0; i < _banIndex; ++i) {
        cout<<i<<"time --"<<_banUser[i]<<endl;
    }
}