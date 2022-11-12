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

int cycle::mainManu() {
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

void cycle::showAlltransition() {
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
        cout<<"cannot open file"<<endl;
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
//            dataLine = dataLine+" ";
            for(auto &ch :dataLine){
                if(ch == ' '){
                    if(count == 0){
                        data = "";
                        count++;
                    }else if(count == 1){
                        luckyNumber[luckyNumberIndex] = data;
                        luckyNumberIndex++;
                        cout<<"Already buy "<<luckyNumber[luckyNumberIndex]<<endl;
                        data = "";
                        count++;
                    }else if(count == 2){
                        data = "";
                        count++;
                    }else if (count == 3){
                        data = "";
                        count++;
                    }else if(count == 4 ){
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
    int number = 0;
    number = stoi(choose_numuber);
    if(number >= 100 &&  number < 1000){
        cout<<"Loading.....Please wait..!!"<<endl;
        cout<<"Buy SuccessFully... \nGood choice..Good Luck Your Number :)"<<endl;

        string  recordFile = "recordTicketsBuy.txt";
        string  usernameFile = arrUsername[current_index]+".txt";
        //to write file
        ofstream outfile; // open all record bought data file
        outfile.open(recordFile,ios::app);

        ofstream userFile; // open userfile
        userFile.open(usernameFile,ios::app);
        if(outfile.is_open()){
            string toRecord = to_string(current_index + 1)+" "+ to_string(number) +" bought-by "+arrUsername[current_index]+" \n";
            outfile<<toRecord;

            string userTxtRecord = to_string(number) + " bought by you:"+arrUsername[current_index]+" \n";
            userFile<<userTxtRecord;

            userFile.close();// close userfile

            outfile.close(); //close all data file

            luckyMOption();
        }else{
            cout<<"Enable to record data !"<<endl;
            cout<<"Error 444"<<endl;
            exit(444);
        }

    }else{
        cout<<"Invalid input..PLease Enter 3 digits...!"<<endl;
        luckyMOption();
    }

}

void cycle::luckyMOption(){
    cout<<"Press 1 to Buy Tickets Again\nPress 2 to Quit \nPress any number to Log out "<<endl;
    cin>>luckyM_option;
    if(luckyM_option == "1"){
        luckyMainProject();
    }else if(luckyM_option == "2"){
        exit(1);
    }else{
        mainManu();
    }
}

void cycle::Register() {
    string r_option =0;
    cout<<"This is Register Page"<<endl;
    cout<<"Enter username to Register."<<endl;
    cin>>r_username;
    int status = userExist(r_username);
    if(status != -1){
        cout<<"Username Already Exists.. Try Again!!  "<<endl;
        cout<<"Press 1 to login \nPress 2 to continue Register"<<endl;
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
//    //to clean file
//    std::ofstream ofs;
//    ofs.open(userDatafile, std::ofstream::out | std::ofstream::trunc);
//    ofs.close();

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

    cout<<"This is Login Page"<<endl;
    cout<<"Enter your username to Login"<<endl;
    cin>>lusername;
    int status = userExist(lusername);
    if(status != -1){
        cout<<"UserName Found! .. \nEnter your password for "<<lusername<<endl;
        cin>>lpassword;
        if (lpassword == arrPassword[status]){
            cout<<"Login success..."<<endl;
            current_index = status; // to know current login user

            luckyMainProject(); // go to buy lucky number
        }else{
            cout<<"login failed! Wrong password!.."<<endl;
            login();
        }
    }else{
        cout<<"Username not found!"<<endl;
        login();
    }

}

void cycle::loadingNumber(){
    cout<<"loading process is running.."<<endl;

    string luckynumber = "luckynumber.txt";
    string numberData;

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