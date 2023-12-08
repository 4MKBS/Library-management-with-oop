using namespace std;
class book
{
    string bno;
    string bname;
    string aname;
  public:
    void show(book);
    void create_book();
    void bsearch();
    void show_all_book();
    void delete_book();
    void modify_book();

};


void book::create_book()
{
    book b;
    //cout<<"\n";
    cout<<"\nNEW BOOK ENTRY...\n";

    cout<<"\nEnter The book no.";

    cin>>b.bno;

    cout<<"\nEnter The Name of The Book ";

    cin.ignore();

    getline(cin,b.bname);

    cout<<"\nEnter The Author's Name ";

    getline(cin,b.aname);

    ofstream bks;

    bks.open("book-list.txt",ios::app);

    bks<<"\n"<<b.bno<<"\n"<<b.bname<<"\n"<<b.aname;

    bks.close();
    cout<<"\nBook Created And saved...";

    cout<<"\n";

    system("pause");
    system("cls");
}

void book::bsearch()
{
    cout<<"\n";
    ifstream all("book-list.txt");

    if (!all.is_open()) {
        cerr << "Error opening file" << endl;
    }

    string tbook;
    cout<<"enter the name of the book: ";
    cin.ignore();
    getline(cin,tbook);

    book b;

    bool check=1;
    while(!all.eof()){
        all>>b.bno;
        all.ignore();
        getline(all,b.bname);
        getline(all,b.aname);
        if(tbook==b.bname){
            cout<<"  Book No.\t\t Book Name\t\t|\t Author Name\n";
            cout<<" ----------------------------------------------------\n";
            show(b);
            check=0;
        }
    }

    if(check){
        cout<<"Book is not found"<<endl;
    }


    all.close();
    cout<<"\n";
    system("pause");
    system("cls");
}

void book::show_all_book()
{
    cout<<"\n";
    ifstream all("book-list.txt");
    book b;
    cout<<"  Book No.\t\t Book Name\t\t Author Name\n";
    cout<<" ------------------------------------------------------------\n";
    while(!all.eof()){
        all>>b.bno;
        all.ignore();
        getline(all,b.bname);
        getline(all,b.aname);

        show(b);
    }

    cout<<"\n";
    system("pause");
    system("cls");
}
void book::show(book b){
    cout<<"\t"<<b.bno<<"\t\t "<<b.bname<<"\t\t "<<b.aname<<endl;
}
void book::modify_book()
{
    cout<<"\n";
    ifstream all("book-list.txt");
    ofstream outputFile("temp.txt");

    if (!all.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        //return 1;
        //break;
    }

    string tbook;
    cout<<"enter the name of the book: ";
    cin.ignore();
    getline(cin,tbook);

    book b;
    bool check=1;
    while(!all.eof()){
        all>>b.bno;
        all.ignore();
        getline(all,b.bname);
        getline(all,b.aname);

        if(tbook==b.bname){
            cout<<"\nEnter The updated book no.";
            cin>>b.bno;
            cout<<"\nEnter The updated Name of The Book ";

            cin.ignore();
            getline(cin,b.bname);
            cout<<"\nEnter The updated Author's Name ";
            getline(cin,b.aname);
            outputFile<<"\n"<<b.bno<<"\n"<<b.bname<<"\n"<<b.aname;
            check=0;
        }else{
            outputFile<<"\n"<<b.bno<<"\n"<<b.bname<<"\n"<<b.aname;
        }
    }
    if(check){
        cout<<"Book is not found"<<endl;
    }

    // If the target number is not found, print an error message

    all.close();
    outputFile.close();
    std::remove("book-list.txt");
    std::rename("temp.txt", "book-list.txt");
    cout<<"\n";
    system("pause");
    system("cls");
}

void book::delete_book()
{
    cout<<"\n";
    std::ifstream all("book-list.txt");
    std::ofstream outputFile("temp.txt");
    book b;

    if (!all.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }

    string tbook;
    cout<<"enter the number of the book: ";
    cin.ignore();
    getline(cin,tbook);

    int currentLineNumber = 0;
    bool dcheck=0;
    while(!all.eof()){
        ++currentLineNumber;
        all>>b.bno;
        all.ignore();
        getline(all,b.bname);
        getline(all,b.aname);
        if(tbook==b.bname){
            dcheck=1;
        }else{
            /*
            if(currentLineNumber==1){
                outputFile<<b.bno<<"\n"<<b.bname<<"\n"<<b.aname;
            }else{
                outputFile<<"\n"<<b.bno<<"\n"<<b.bname<<"\n"<<b.aname;
            }*/
            outputFile<<"\n"<<b.bno<<"\n"<<b.bname<<"\n"<<b.aname;
        }
    }
    if(dcheck){
        cout<<"successfully deleted"<<endl;
    }else{
        cout<<"number of book is not found"<<endl;
    }
    // If the target number is not found, print an error message

    all.close();
    outputFile.close();
    std::remove("book-list.txt");
    std::rename("temp.txt", "book-list.txt");
    cout<<"\n";
    system("pause");
    system("cls");
}
