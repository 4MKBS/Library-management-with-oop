#include <bits/stdc++.h>
#include "book.h"
using namespace std;

int main()
{
    while(1){
        book bk;
        cout<<"===== Manage Books ====="<<endl;
        cout<<"1 create book"<<endl;
        cout<<"2 show all book"<<endl;
        cout<<"3 show specific book"<<endl;
        cout<<"4 modify book"<<endl;
        cout<<"5 delete book"<<endl;
        cout<<"to exit enter 0"<<endl;
        cout<<"enter your choice: ";
        int n;
        cin>>n;

        if(n==0){
            break;
        }

        switch(n){
        case 1:
            bk.create_book();

            break;
        case 2:
            bk.show_all_book();

            //system("pause");

            break;
        case 3:
            bk.bsearch();
            break;
        case 4:
            bk.modify_book();
            break;
        case 5:
            bk.delete_book();
            break;
        default:
            cout<<"wrong input"<<endl;
            system("pause");
            system("cls");
            break;
        }



    }
    return 0;
}
