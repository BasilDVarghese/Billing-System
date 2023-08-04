#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Shopping{
    int pcode;
    string pname;
    float price;
    float disc;
    int code[20],quant[20];
    int size=0;
    int size1=0;

    public:
    void menu();
    void administator();
    void add();
    void modify();
    void del();
    void buyer(string);
    void list();
    void receipt();
};

void Shopping:: menu(){
    m:
    cout<<"\t\t\t ________________________________________________________\n";
    cout<<"\t\t\t|                                                        |\n";
    cout<<"\t\t\t|                Welcome to Shopping Complex             |\n";
    cout<<"\t\t\t|                                                        |\n";
    cout<<"\t\t\t|________________________________________________________|\n\n";
    cout<<"\n\t\t1. Administrator\n\t\t2. Buyer\n\t\t3. Exit\n\n\t\tEnter Choice:";
    int choice;
    cin>>choice;

    switch(choice){
        case 1:
        {
            cout<<"\n\t\tEnter Email ID:";
            string mail;
            cin>>mail;
            cout<<"\n\t\tEnter Password:";
            string pass;
            cin>>pass;

            if(mail=="basil" && pass=="1234"){
                administator();
            }
            else{
                cout<<"\n\n\t\tInvalid Entries\n\n";
            }
            break;
        }

        case 2:
        {   
            cout<<"Enter Name:";
            string name;
            cin>>name;
            buyer(name);
            break;
        }

        case 3:{
            exit(0);
        }

        default: cout<<"Enter Valid Number";

    }goto m;
    
}

void Shopping :: administator(){
    m:
    cout<<"\t\t\t ________________________________________________________\n";
    cout<<"\t\t\t|                                                        |\n";
    cout<<"\t\t\t|             Welcome to Administrator Portal            |\n";
    cout<<"\t\t\t|                                                        |\n";
    cout<<"\t\t\t|________________________________________________________|\n\n";
    
    cout<<"\n\t\t1. Add items\n\t\t2. Modify Items\n\t\t3. Remove Items\n\t\t4. List Items\n\t\t5. Main Menu\n\n";
    cout<<"\t\tEnter Choice:";
    int choice;
    cin>>choice;

    switch (choice)
    {
    case 1:{
        add();
        break;
        }
    case 2:{
        modify();
        break;
    }
    case 3:{
        del();
        break;
    }

    case 4:{
        list();
        break;
    }
    
    case 5:{
        menu();
        break;
    }

    default:
        cout<<"Enter Valid Number";
        break;
    }goto m;
}

void Shopping:: list(){
    ifstream fin("/Users/basildanielvarghese/Desktop/C++/database.txt");
    int a;
    string b;
    float c,d;
    cout<<"\n\n\t\t"<<"P_CODE"<<"   "<<"P_NAME"<<" "<<"  P_PRICE"<<setw(15)<<" P_DISCOUNT"<<endl<<endl;
    while (!fin.eof())
    {
        fin>>a>>b>>c>>d;
        
        cout<<"\t\t"<<setw(6)<<a<<setw(9)<<b<<setw(10)<<c<<setw(15)<<d<<endl;
    }

    fin.close();
    
}

void Shopping::add(){
    cout<<"\n\t\t\t\t\tADD NEW PRODUCT";
    cout<<"\n\t\tEnter P-Code:";
    cin>>pcode;
    cout<<"\t\tEnter P-Name:";
    cin>>pname;
    cout<<"\t\tEnter Price:";
    cin>>price;
    cout<<"\t\tEnter Discount Price:";
    cin>>disc;
    ifstream fin("/Users/basildanielvarghese/Desktop/C++/database.txt");
    int a;
    string b;
    float c,d;
    int token=0;

    while (!fin.eof())
    {
        fin>>a>>b>>c>>d;
    
        if(a==pcode)
        {
            token++;
        }

    }
    fin.close();

    if(token==0){
        ofstream fout;
        fout.open("/Users/basildanielvarghese/Desktop/C++/database.txt",ios::app|ios::out);
        fout<<endl<<pcode<<" "<<pname<<" "<<price<<" "<<disc;
        fout.close();
        cout<<"\n\t\t\tAdded Successfully\n\n";
    }
    else{
        cout<<"\n\t\t\tWrong P-code\n\n";
    }

}

void Shopping::del(){
    ifstream fin("/Users/basildanielvarghese/Desktop/C++/database.txt");
    ofstream fout;
    fout.open("/Users/basildanielvarghese/Desktop/C++/database2.txt",ios::out);

    int a,e;
    float c,d,f,g;
    string b,h;

    cout<<"\n\n\t\t\tDELETE PRODUCTS";
    cout<<"\n\t\tEnter P-Code for deletion:";
    cin>>e;
    
    int token =0;

    while(!fin.eof()){

        fin>>a>>b>>c>>d;
        if(a==e){
            
            token++;
            continue;
        }
        else
        fout<<a<<" "<<b<<" "<<c<<" "<<d;

        if(!fin.eof()){
            fout<<endl;
        }
    }

    fin.close();
    fout.close();
    remove("/Users/basildanielvarghese/Desktop/C++/database.txt");
    rename("/Users/basildanielvarghese/Desktop/C++/database2.txt","/Users/basildanielvarghese/Desktop/C++/database.txt");
    if(token>0)
    cout<<"\t\tDeleted Successfully";
    else cout<<"\n\n\t\tDeletion Unsuccessful\n\n";
}

void Shopping::modify(){
    ifstream fin("/Users/basildanielvarghese/Desktop/C++/database.txt");
    ofstream fout;
    fout.open("/Users/basildanielvarghese/Desktop/C++/database2.txt",ios::out);

    int a,e;
    float c,d,f,g;
    string b,h;

    cout<<"\n\n\t\t\tMODIFY PRODUCTS";
    cout<<"\n\t\tEnter P-Code:";
    cin>>e;
    cout<<"\t\tEnter New P-Name:";
    cin>>h;
    cout<<"\t\tEnter New Price:";
    cin>>f;
    cout<<"\t\tEnter New Discount:";
    cin>>g;
    int token =0;

    while(!fin.eof()){

        fin>>a>>b>>c>>d;
        if(a==e){
            fout<<e<<" "<<h<<" "<<f<<" "<<g;
            token++;
        }
        else
        fout<<a<<" "<<b<<" "<<c<<" "<<d;
        if(!fin.eof()){
            fout<<endl;
        }
    }

    fin.close();
    fout.close();
    remove("/Users/basildanielvarghese/Desktop/C++/database.txt");
    rename("/Users/basildanielvarghese/Desktop/C++/database2.txt","/Users/basildanielvarghese/Desktop/C++/database.txt");
    if(token>0)
    cout<<"\t\tModified Succesfully\n\n";
    else cout<<"\n\n\t\tModification Unsuccessful\n\n";
}

void Shopping::buyer(string n){
    cout<<"\t\t\t ________________________________________________________\n";
    cout<<"\t\t\t|                                                        |\n";
    cout<<"\t\t\t|             Welcome"  <<" "<<n<<"                      \n";
    cout<<"\t\t\t|                                                        |\n";
    cout<<"\t\t\t|________________________________________________________|\n\n";
    m:
    cout<<"\n\t\t1. List of Products\n\t\t2. Add Products to Cart\n\t\t3. Create Bill\n\t\t4. Main menu\n\n\t\tEnter Choice:";
    int choice;
    cin>>choice;

    switch (choice)
    {
    case 1: 
    list();
        break;
    case 2:{
        while(1){
        cout<<"\t\tEnter the Code Number of Product:";
        int a;
        cin>>a;
        cout<<"\t\tEnter the Quantity of Product:";
        int q;
        cin>>q;
        code[size++]=a;
        quant[size1++]=q;
        
        
        cout<<"\t\tEnter 0 to Exit Cart or 1 to add more Products";
        int c;
        cin>>c;
        if(c==0){
            break;
        }
        }

        break;
    }
    case 3:{
        float sum=0;
        int a;
        string b;
        float c,d;


        ifstream fin("/Users/basildanielvarghese/Desktop/C++/database.txt");
        while (!fin.eof())
        {
            fin>>a>>b>>c>>d;

            for(int j=0;j<size;j++){
                if (code[j]==a){
                    cout<<"\t\t"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<(c-d)*quant[j] <<endl;
                    sum=sum+(c-d)*quant[j];

                }
            }
        }cout<<"\n\t\t\tTotal:"<<sum<<endl;
        
        break;
    }
    case 4:{
        menu();
        break;
    }
    default:
        break;
    }
    goto m;
}



int main()
{
Shopping s;
s.menu();
}

    


