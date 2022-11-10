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
    loadingNumber();
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


int cycle::Register() {
    cout<<"This is Register Page"<<endl;

}

int cycle::login() {
    cout<<"This is Login Page"<<endl;


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

void cycle::userDataLoading() {
    cout<<"user data are loading...."<<endl;
    int count = 0;

    string  userDatafile = "user.txt";
    string  data ; // temporary  to store
    string dataLine; // to store data from one line
    ifstream userfile(userDatafile);
    if(userfile.is_open()){
        while (getline(userfile,dataLine)){
            dataLine = dataLine+" ";
            for(auto &ch :dataLine){
                if(ch == ' '){
                    if(count == 0){
                        arrId[idIndex] = data;
                        idIndex++;
//                        cout<<"one space..."<<endl;
                        data = "";
                        count++;
                    }else if(count == 1){
                        arrUsername[userNameIndex] = data;
                        userNameIndex++;
//                        cout<<"two space..."<<endl;
                        data = "";
                        count++;
                    }else if(count == 2){
                        arrPassword[passwordIndex] = data;
                        passwordIndex++;
//                        cout<<"three space..."<<endl;
                        data = "";
                        count++;
                    }else if (count == 3){
                        arrAmount[amountIndex] = data;
                        amountIndex++;
//                        cout<<"four space..."<<endl;
                        data = "";
                        count = 0;
                    }

                }else{
                    string st(1,ch);
                    data = data + st;
                }

            }
        }

        userfile.close();


    }else{
        cout<<"cannot open file"<<endl;
    }
    
}

int cycle::showUserData() {
    for (int i = 0; i < idIndex ; i++) {
        cout<<"id is "<<arrId[i]<<" -"<<"username is "<<arrUsername[i]<<" -"<<"password is "<<arrPassword[i]<<" -"<<"amount is "<<arrAmount[i]<<endl;
    }

}