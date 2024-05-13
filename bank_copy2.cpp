#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;

/*
account numvber  = long long int 
user name  = string
balance long long int 
age  = int 
account type  = char */


// fucntion for searching the balance by account number 
long long int balance_search(long long int x){
    long long int a;// account number 
    int b; // age 
    char c;// account type
    long long int d;// balance
    string name;// account holder name 
    ifstream find;
    find.open("text.txt",ios::in | ios :: binary);
    if(!find){
        cout<<" \nerror in opening the file"<<endl;
    }
    else{
    while(find>>a>>b>>name>>c>>d){
        cout<<"THE ACOUNT NUMBER IS : "<<a<<endl;
        if (a == x){
            find.close();
            return d;
        }
       
    }
    find.close();
    return -1;
    };

    //chat gtp code

//     while (find>>a>>b>>name>>c>>d) {
//     cout << "THE ACOUNT NUMBER IS : " << a << endl;
//     if (a == x) {
//         find.close();
//         return d;
//     }
// }
// // Account number not found, close the file and return -1
// find.close();
// return -1;



}

class bank{
    string name;
    int age=0;
    char account_type;
    long long int acc=0,balance=0, debit,credit;


    public:
    void create_account();
    void deposit_money();
    void withdral_money();
    void display_latest();
    void display_all();
    void delete_account();
    void modify_account();
    void exit_account();
    

};

void bank :: create_account(){

    ofstream data_enter;
    // data_enter.open("text.txt",ios :: app);
cin.ignore();
    cout<<"\nENTER THE NAME OF THE ACCOUNT HOLDER WITHOUT THE SPACE : "<<endl;
    getline(cin,name);
    cout<<"\nenter the age of the account holder : "<<endl;
    cin>>age;
    cout<<"\nENTER THE ACCOUNT NO. : "<<endl;
    cin>>acc;
    cout<<"CHOOSE THE ACCOUNT TYPE S/C : "<<endl;
    cin>>account_type;
    cout<<"\nENTER THE AMOUNT OF THE FIRST DEPOSIT : "<<endl;
    cin>>balance;

    // OPENING THE FILE 
    data_enter.open("text.txt",ios :: app | ios::binary);

    data_enter<<acc<<" "<<age<<" "<<name<<" "<<account_type<<" "<<balance<<endl;

    data_enter.close();

}
void bank :: deposit_money(){

    cout<<"\nENTER THE ACCOUNT NUMBER : "<<endl;
    long long int x;
    cin>>x;
    balance  = balance_search(x);

    cout<<"THE CURRENT BALANCE IN THE ACCOUNT IS : "<<balance ;
   


    
    if(balance != -1){
     cout<<"\nENTER THE AMOUNT TO DEPOSIT : "<<endl;
     cin>>credit;
     balance += credit;
     cout<<"\nTHE CURRENT BALANCE AFTER THE DEPOSIT IS : "<<balance<<endl;
     cout<<"\n\t\t ***********DEPOSIT SUCCESSFULL************\t\t\n"<<endl;
     return;
    }
    else{
       cout<<"\nTHE ACCOUNT NUMBER IS INCORRECT OR DOES NOT EXIST.SO YOU ARE TRASWER TO MAIN MENU."<<endl;
      cout<<endl<<endl;
       return ;
    }
}
void bank :: withdral_money(){
    
    cout<<"\nENTER THE AMOUNT YOU WANT TO WITHDRAWAL : "<<endl;
    cin>>debit;
    balance-=debit;
}
void bank :: display_all(){
    cout<<"\nTHE NAME OF THE ACCOUNT HOLDER                : "<<name<<endl;
    cout<<"\nTHE AGE OF THE ACCOUNT HOLDER                 : "<<age<<endl;
    cout<<"\nTHE ACCOUNT NUMBER OF THE ACCOUNT HOLDER      : "<<acc<<endl;
    cout<<"\nTHE TOTAL BALANCE IN THE ACOUNT AT PRESENT IS : "<<balance<<endl;

}
void bank :: display_latest(){
    if(debit !=0 && credit != 0){
        cout<<"\nthe latest credit in the account is      : "<< credit<<endl;
        cout<<"\nthe latest withdreawal in th eaccount is : "<<debit<<endl;
    }
}

void bank :: modify_account(){
    int x;
    cout<<"\n CHOOSE THE DETAIL TO MODIFY FROM GIVEN BELOW : "<<endl;
    cout<<"\n 1. NAME "<<endl;
    cout<<"\n 2. AGE  "<<endl;
    cout<<"\n 3.ACCOUNT TYPE C/S "<<endl;
    cin>>x;

    switch(x){
        case 1:
        cout<<"\nENTER NEW NAME OF THE ACCOUNT HOLDER : "<<endl;
        cin>>name;
        break;

        case 2:
        cout<<"\nENTER THE NEW AGE OF THE ACCOUNT HOLDER : "<<endl;
        cin>>age; 
        break;

        case 3:
        cout<<"\nENTER THE TYPE OF ACCOUNT YOU CHOOSE C/S"<<endl;
        cin>>account_type;
        break;

        default:
        cout<<"\nYOU HAVE TYPE THE WRONG KEY ,PLEASE RE ENTER ."<<endl;
    }

}

void bank :: exit_account(){
    cout<<"THANKF FOR USEING THE BANK MANAGMENT SYSTEM I HOPE TO SEE YOU AGAIN ."<<endl;

}
 
int main(){
int choose,x =1;

cout<<"----------------------WELCOME TO THE PUNJAB NATIONAL BANK----------------------------"<<endl;
while(x==1){
cout<<"  CHOOSE THE OPTION BELOW : - "<<endl;
cout<<"1.TO CREATE AN NEW ACCOUNT. "<<endl;
cout<<"2.TO DEPOSIT MONEY IN CURRENT ACCOUNT."<<endl;
cout<<"3.TO WITHDRAWAL FROM CURRENT ACCOUNT."<<endl;
cout<<"4.DISPLAY THE LATEST TRANSECTIONS."<<endl;
cout<<"5.DISPLAY THE ALL DETAILS OF THE ACCOUT HOLDER ."<<endl;
cout<<"6.DELETE THE CURRENT ACCOUNT."<<endl;
cout<<"7.MODIFY THE CURRENT ACCOUNT. "<<endl;
cout<<"8.TO EXIT. "<<endl;

cout<<"\n ENTER CHOOSEN NUMBER : "<<endl;
// cin.ignore();
cin>>choose;
bank user1;


// choose option


switch(choose){
    case 1:
    user1.create_account();

    break;

    case 2:
    user1.deposit_money();

    break;

    case 3:
    user1.withdral_money();

    break;

    case 4:
     user1.display_latest();
     break;

    break;

    case 5:
    user1.display_all();
    break;

    break;

    case 6:

    break;

    case 7:
    user1.modify_account();
    break;

    break;

    case 8:
    user1.exit_account();
    x =0;
    break;

    

    default:
    system("cls");
    cout<<"PLEASE CHOOSE THE  RIGHT  OPTION ........"<<endl;

   
}};


return 0;
}