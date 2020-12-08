#include<iostream>
#include<fstream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
class book
{
    protected:
    int b_id;
    char b_name[100];
    float b_price;
    int b_stock;
public:
    int r_id()
    {
        return b_id;
    }
    int set_data()
    {
        book b;
        cout<<"Enter the book id : ";
        cin>>b_id;
        fstream fin("book_data.txt",ios::out | ios::in | ios::binary);
        if(fin)
        {
            while(!fin.eof())
            {
                fin.read((char*)&b,sizeof(b));
                if(fin)
                {
                    if(b.r_id()==b_id)
                    {
                        cout<<"This id is already there so Enter another book id."<<endl;
                        return 0;
                    }
                }
            }
        }
        fin.close();
        cout<<"Enter the book name : ";
        cin>> b_name;
        cout<<"Enter the book price : ";
        cin>> b_price;
        cout<<"Enter the book stock : ";
        cin>>b_stock;
        return 1;
    }
    void store_data()
    {
        ofstream fout;
        fout.open("book_data.txt",ios::app | ios::binary);
        cout<<fout.tellp();
        fout.write((char*)this,sizeof(*this));
        fout.close();
    }
    void show_book_data()
    {
        cout<<setw(20)<<b_id <<" "<<setw(20)<<b_name<<" "<<setw(20)<<b_price<<setw(20)<<b_stock<<endl;
    }
    void display()
    {
        ifstream fin("book_data.txt");
        fin.seekg(ios::beg);
        fin.read((char*)this,sizeof(*this));
        if(fin)
        {cout<<endl<<endl<<endl<<endl<<"-------------------------------------BOOK DETAIL----------------------------------"<<endl;
        cout<<setw(20)<<"Book Id"<<setw(20)<<"Book Name"<<setw(20)<<"Book Price"<<setw(20)<<"Book Stock"<<endl;

        while(!fin.eof())
        {
            show_book_data();
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();}
        else
            cout<<"Book is not available"<<endl;
    }
    void update_by_id(book &b)
    {
        cout<<"1. Change book name "<<endl;
        cout<<"2. Change book stock "<<endl;
        cout<<"3. Change price "<<endl;
        int n;
        cout<<"Enter the number : ";
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"Enter the book name : "; cin>>b.b_name;
            break;
        case 2:
            cout<<"Enter the stock : "; cin>>b.b_stock;
            break;
        case 3:
            cout<<"Enter the price : "; cin>>b.b_price;
            break;
        default:
            cout<<"Invalid Argument"<<endl;
        }
    }
    void update()
    {
        book b1;
        cout<<"Enter the id ";
        int r,loc;
        cin>>r;
        fstream f("book_data.txt",ios::ate | ios::in | ios::out);
        f.seekp(0,ios::beg);
        f.seekg(0,ios::beg);
        while(!f.eof())
        {
            loc = f.tellg();
            f.read((char*)&b1,sizeof(b1));
            if(r==b1.r_id())
            {
                update_by_id(b1);
                f.seekp(loc,ios::beg);
                f.write((char*)&b1,sizeof(b1));
                cout<<"successful"<<endl;
            }
        }
        f.close();
    }
    int update_stock(book &b)
    {
        if(b.b_stock>0)
        {
            cout<<"You Purchazed Successfully"<<endl;
            b.b_stock=b.b_stock-1;
            return 1;
        }
        else
        {
            cout<<"Out of Stock"<<endl;
            return 0;
        }
    }
    void buy_book()
    {
        book b1;
        int loc;
        cout<<"Enter the ID of the book : ";
        int id;
        cin>>id;
        fstream fin("book_data.txt",ios::binary | ios::in | ios::ate | ios::out);
        if(fin)
        {fin.seekg(0,ios::beg);
        fin.seekp(0,ios::beg);

        while(!fin.eof())
        {
            loc=fin.tellg();
            fin.read((char*)&b1,sizeof(b1));
            if(b1.r_id()==id)
            {
                if(update_stock(b1)==1)
                {
                    fin.seekp(loc,ios::beg);
                    fin.write((char*)&b1,sizeof(b1));
                }
            }
        }
        fin.close();
        }
        else
            cout<<"There is no data of book."<<endl;
    }

};

class sign_in
{
    char phone_no[50];
    char fname[20],lname[20];
    char pass[20];
public:
    char* r_phone_no()
    {
        return phone_no;
    }
    char* r_pass()
    {
        return pass;
    }
    int set_sign_in()
    {
        sign_in s;
        cout<<"Enter the phone number : ";
        cin>>phone_no;
        ifstream fin("signin_detail.txt",ios::in | ios::binary);
        if(fin)
        {
            while(!fin.eof())
            {
                fin.read((char*)&s,sizeof(s));
                if(!strcmp(phone_no,s.r_phone_no()))
                {
                    system("cls");
                    cout<<"The email ID is already exist."<<endl;
                    fin.close();
                    return 0;
                }
            }
        }
        fin.close();
        cout<<"Enter first name : ";
        cin>>fname;
        cout<<"Enter last name : ";
        cin>>lname;
        cout<<"Enter the password : ";
        cin>>pass;
        return 1;
    }
    int log_in()
    {
        sign_in s1;
        char e[50];
        cout<<"Enter the phone number ";
        cin>>e;
        cout<<"Enter the password ";
        cin>>pass;
        ifstream fin("signin_detail.txt",ios::in | ios::binary);
        if(fin)
        {
            while(!fin.eof())
            {
                fin.read((char*)&s1,sizeof(s1));
                if(!strcmp(e,s1.r_phone_no()) && !strcmp(pass,s1.r_pass()))
                {
                    system("cls");
                    cout<<"You are successfully Log In"<<endl;
                    fin.close();
                    return 1;
                }
            }
        }
        return 0;
    }
    int administrator_sign_in()
    {

    }
    void store_detail()
    {
        ofstream fout;
        fout.open("signin_detail.txt",ios::app | ios::binary);
        // cout<<fout.tellp();
        fout.write((char*)this,sizeof(*this));
        fout.close();
    }
};
class admin
{
    char mobile_no[11];
    char password[20];
public:
    int set_deta()
    {
        string s;
        cout<<"Enter the key";
        cin>>s;
        if(s=="AbCd")
        {cout<<"Enter the mobile number : "; cin>>mobile_no;
        cout<<"Enter the password : "; cin>>password;
        return 1;}
        else
            return 0;
    }
    void store_detail()
    {
        ofstream out("admin_detail.txt",ios::app | ios::binary);
        if(out)
        {
            out.write((char*)this,sizeof(*this));
        }
        out.close();
    }
    char* r_mobile_no()
    {
        return mobile_no;
    }
    char* r_password()
    {
        return password;
    }
    int administrator_detail()
    {
        admin a1;
        ifstream in("admin_detail.txt",ios::in | ios::binary);
        char mob[11],pass[20];
        if(in)
        {cout<<"Enter the mobile number : ";
        cin>>mobile_no;
        cout<<"Enter the password : ";
        cin>>password;
        // in.seekg(0,ios::beg);
        while(!in.eof())
        {
            in.read((char*)&a1,sizeof(a1));
            if(!strcmp(mobile_no,a1.r_mobile_no()) && !strcmp(password,a1.r_password()))
            {
                in.close();
                return 1;
            }
        }
        in.close();
        return 0;
        }
        else
            return 0;
    }
};
int main()
{
    admin a;
    book b;
    sign_in s;
    while(1)
    {
        system("cls");
        cout<<"1. Sign In"<<endl;
        cout<<"2. Log In"<<endl;
        cout<<"3. Administrator detail"<<endl;
        cout<<"4. Exit"<<endl;
        int t;
        cin>>t;
        if(t==1)
        {
            if(s.set_sign_in()==1)
            {
                s.store_detail();
            }
        }
        else if(t==2)
        {
            if(s.log_in()==1)
            {
                while(1)
                {
                    cout<<"1. display book data"<<endl;
                    cout<<"2. Buy book"<<endl;
                    cout<<"3. Exit"<<endl;
                    int n;
                    cin>>n;
                    switch(n)
                    {
                    case 1:
                    {
                        system("cls");
                        // getch();
                        b.display();
                    }
                    break;
                    case 2:
                    {
                        system("cls");
                        b.buy_book();
                    }
                    break;
                    case 3:
                        exit(0);
                        break;
                    default:
                        cout<<"Invalid";
                    }
                    cout<<endl<<"Enter Any Character to star :"<<endl;
                    getch();
                    system("cls");
                }
            }
            else
                cout<<"You entered wrong detail."<<endl;
        }
        else if(t==3)
        {
            cout<<"1. Sign In "<<endl;
            cout<<"2. Log In "<<endl;
            int num;
            cin>>num;
            if(num==1)
            {if(a.set_deta()==1)
            {
                a.store_detail();
            }
            else
                cout<<"Invalid Key"<<endl;
            }
            if(num==2)
            {if(a.administrator_detail()==1)
            {
                system("cls");
                cout<<"Successfully login "<<endl;
                int n1;
                cout<<"1. Add New book detail "<<endl;
                cout<<"2. Update book detail using book ID "<<endl;
                cout<<"3. Display book detail"<<endl;
                cout<<"4. Exit"<<endl;
                cin>>n1;
                switch(n1)
                {
                case 1:

                    while(1)
                    {
                        if(b.set_data()==1)
                        {
                            b.store_data();
                            break;
                        }
                    }
                    break;
                case 2:
                {
                    b.update();
                }
                break;
                case 3:
                {
                    system("cls");
                    // getch();
                    b.display();
                    cout<<"Enter any character to start"<<endl;
                    getch();
                }
                break;
                case 4:
                    exit(0);
                    break;
                default:
                    cout<<"Invalid Argument"<<endl;
                }
            }
            else
            {
                cout<<"Administrator is not exist"<<endl;
                getch();
            }
            }
        }
        else if(t==4)
            exit(0);
        else
            cout<<"Invalid Argument"<<endl;
    }
}

