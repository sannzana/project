
#include<iostream>
#include <fstream>
#include<string>
//#include "movie.h"
//#include "ticket.h"
//#include "customer.h"
//#include "time.h"
//#include "member.h"


//membership will be valid for 10203, 10207,20204,56009,45907

/*this program will also save the information in a file named Booked. Booked.txt is also uploaded after running the code*/
using namespace std;

class person{
string name;;
long long cell,cnic;
public:
    person();
    person(string n, long long c, long long e);
    void setName(string n);
    string getName();
    void setCnic(long long c);
    long long getCnic();
    void setCell(long long e);
    long long getCell();
    void insertinfo();
    void display();
};



person::person()
{
    this->cell=0;// cell phone number initialization
    this->name="";
    this ->cnic=0; // voter id num
}
person::person(string s, long long e, long long c)
{
    s="user";
      c=4499;
    e=454;
    this->cell=e;
    this->cnic=c;
    this->name=s;
}

void person::setName(string s)
{
    this->name=s;
}
string person:: getName()
{
    return name;
}


void person::setCell(long long e)
{
    this->cell=e;
}
long long person:: getCell()
{
    return cell;
}


void person::setCnic(long long c)
{
    this->cnic=c;
}
long long person:: getCnic()
{
    return cnic;
}

void person::insertinfo()
{
    cout<<"\t\t\tEnter Your Name-"<<endl;
    getline(cin,name);
    setName(name);
    cout<<"\t\t\tEnter Your CNIC number-"<<endl;
    cin>>cnic;
    cout<<"\t\t\tEnter Your Phone Number-"<<endl;
    cin>>cell;
}

void person::display()
{

    cout<<"\t\t\t\t\t__________________________"<<endl;
    cout<<"\t\t\t\t\tYour Name- "<<name<<endl;
    cout<<"\t\t\t\t\tYour Cell Phone Number- "<<cell<<endl;
    cout<<"\t\t\t\t\tYour Cnic Number- "<<cnic<<endl;
    cout<<"\t\t\t\t\t__________________________"<<endl;
    ofstream file("Booked.txt",ios_base::app); //Movie.txt
    if (file.is_open())
    {
        file<<"By Your Given Information"<<endl;
            file<<"__________________________"<<endl;
        file<<"Your Name- "<<name<<endl;
       file<<"Your Cell Phone Number- "<<cell<<endl;
       file<<"Your Cnic Number- "<<cnic<<endl;
        file<<"__________________________"<<endl;
        file.close();
    }



}
class customer:public person
{
    int customerId;
public:
    customer();
    void setCustomerId(int );
    int getCustomerId();
    void checkCustomer();
    void oldCustomer();
    void menu();
    void getInfo();

};


customer::customer()
{
    this->customerId=0;
}


void customer::setCustomerId(int cId)
{
    this->customerId=cId;
}
int customer::getCustomerId()
{
    return customerId;
}
void customer::checkCustomer()
{
    char check;
    int arr[10];
    int serial=1001;// memberid is located from 1001 to 1010
    int right=0;
    int ver;
    cout<<"Are YOU A New Customer Or A Member"<<endl;
    cout<<"Press N For New Member or If You Have A Old Membership Which Is Expired // Press M For Member"<<endl;
        cin>>check;
    for(int n=0; n<10; n++)
    {
        arr[n]=serial;// memberid's serially saved in array 'arr'
        serial++;
    }

    if(check=='n'||check=='N')
    {
        // if not a member, no additional task is required
        oldCustomer();
    }
    if(check=='m'||check=='M')
    {
        cout<<"Enter Your Customer Id:- "<<endl;
            cin>>ver;



        for(int n=0; n<10; n++)
        {
            if (ver==arr[n])
            {
                right++;
                break;//
            }
        }

        if(right>0)
        {
            cout<<"Customer Verified\nYou Will Get A Additional 10% Off!! "<<endl;
            ofstream neww("Customer_Info.txt",ios_base::app);

            if(neww.is_open())
            {
                neww<<"You Are a Member"<<endl;
                neww<<"Your Member Id Is:- " <<ver<<endl;
                neww<<"You Will Get Additional 10% Off!!"<<endl;
                    neww.close();
            }
        }
        else
        {
            cout<<"Invalid Id"<<endl;
            cout<<"You are Not A Member!"<<endl;

            ofstream file("Booked.txt",ios_base::app); //Movie.txt
    if (file.is_open())
            {
                file<<"Invalid Id"<<endl;
                file<<"You Are Not a Member"<<endl;
                file.close();
            }

        }


    }

}

void customer::oldCustomer()
{
    cout<<"\t\t\tIf You Have A Old Membership Press Y Else Press N "<<endl;
        char m;
    cin>>m;

     if(m=='y'||m=='Y')
    {
        int idd;
        cout<<"\t\t\tEnter Your Id"<<endl;
        cin>>idd;
        cout<<"\t\t\tDo You Want To Renew Your Membership? "<<endl;
        cout<<"\t\t\tType Y To Renew || Type N Not To Renew  "<<endl; // |||Booking Details|||
            char y;
        cin>>y;
        if(y=='y'||y=='Y')
        {
            cout<<"\t\t\tCongratulation!!! Your Membership Is Renewed. Your Membership id: "<<idd<<endl;
            cout<<"\t\t\tYou Can Use Your Membership Id From The Next Purchase. Thank you "<<endl;
        }}
         else if(m=='n'||m=='N')

    {cout<<"\t\t\t\t\t----------------------------"<<endl;
  cout<<"\t\tIf You Want To Buy A Membership Card, Please Fill up The Form And Fulfill The Other Conditions  "<<endl;
  cout<<"\t\tYou Can Find The Form In New Members sector of Our Website Or visit The Office,Thank you"<<endl;
    }

   // {

   // }

    }



class member
{
    string userName;
    string passWord;
public:
    member();
    void setUn(string);
    string getUn();
    void setPass(string);
    string getPass();
    void memberShip();
    void admin();
void memberop();
};

member::member()
{
  this->userName="";//username;
  this->passWord="";
}
void member::setPass(string pas)
{
    this->passWord=pas;
}
string member::getPass()
{
    return passWord;
}

void member::setUn(string unn)
{
   this->userName=unn;
}
string member::getUn()
{
    return userName;
}

void member::memberShip()
{
    cout<<"\t\t\tMembers Benefits:- "<<endl;
    cout<<"\t\t\t1)Discount On Drinks and Snacks"<<endl;
    cout<<"\t\t\t2)5% Additional Discount On Tickets"<<endl;
    cout<<"\t\t\t3)FREE 3D Glass\n\n"<<endl;

   ofstream file("Booked.txt",ios_base::app); //Movie.txt
    if (file.is_open())
    {
        file<<"As Per Your Interest, These Are The Benefits Of Being A Member"<<endl;
        file<<"Members Benefits:- "<<endl;
    file<<"1)Discount On Drinks and Snacks"<<endl;
   file<<"2)5% Additional Discount On Tickets"<<endl;
    file<<"3)FREE 3D Glass"<<endl;
   file.close();
    }
}

void member::memberop()
{member m;
    m.memberShip();
}

class movie
{
    string movieName, dimension, director,runtime,type,release ;
public:
    movie();
    customer cu;
    member m;
    int time;
    void setMoviename(string movieName);
    string getMoviename();
    void setDimension(string dimension);
    string getDimension();
    void setRuntime(string runtime);
    string getRuntime();
    void setType(string type);
    string getType();
    void setRelease(string release);
    string getRelease();
    void setDirect(string director);
    string getDirect();
    void menu();
    void memberop();
    void playing();
    void schedule();
    void movieSelected();
    void viewb();
    void addMovie();
    void listt();



};



movie::movie()
{
    this->time=0;
    this->movieName="";
    this->dimension="";
    this->director="";
    this->type="";
    this->release="";
    this->runtime="";


}
void movie::setMoviename(string nm)
{
    this->movieName=nm;
}
string movie::getMoviename()
{
    return movieName;
}

void movie::setRuntime(string rt)
{
    this->runtime=rt;
}
string movie::getRuntime()
{
    return runtime;
}

void movie::setRelease(string rr)
{
    this->release=rr;
}
string movie:: getRelease()
{
    return release;
}

void movie::setDirect(string sd)
{
    this->director=sd;
}
string movie::getDirect()
{
    return director;
}

void movie::setDimension(string ds)
{
    this->dimension=ds;
}
string movie::getDimension()
{
    return dimension;
}


void movie::setType(string st)
{
    this->type=st;
}
string movie::getType()
{
    return type;
}

void movie::playing()
{
    movie m[4];
    int i;
    m[0].setMoviename("Fast X");
    m[0].setRuntime("2 h 32 min");
    m[0].setRelease("19 May 2023");
    m[0].setDirect("Louis Leterrier");
    m[0].setDimension("3D");
    m[0].setType("Action · Adventure · Mystery · Thriller");

    m[1].setMoviename("Guaedians Of The Galaxy Volume 3");
    m[1].setRuntime("2 h 26 min");
    m[1].setRelease("5 May 2023");
    m[1].setDirect("James Gunn");
    m[1].setDimension("3D");
    m[1].setType("Action · Adventure · Comedy · Science Fiction.");

    m[2].setMoviename("Avatar:The Way Of Water");
    m[2].setRuntime("2 h 14 min");
    m[2].setRelease("22 December 2022");
    m[2].setDirect("James Cameron");
    m[2].setDimension("2D");
    m[2].setType(" Sci-fi · Adventure · Action · Fantasy");


    m[3].setMoviename("The Little Mermaid");
    m[3].setRuntime("2 h 46 min");
    m[3].setRelease("25 May 2023");
    m[3].setDirect("Rob Marshall");
    m[3].setDimension("3D");
    m[3].setType("Adventure · Family · Fantasy · Musical · Romance");

    cout<<"\t\t\tSelect Movie__"<<endl;
    cout<<"\t\t======================================"<<endl;
    // ofstream file("Movie.txt", app);
    for(int  i=0; i<4; i++)
    {
        cout<<"\t\t\t\t_______________________"<<endl;
        cout<<"\t\tMovie Number-"<<i+1<<endl;
        cout<<"\n\t\t\t\t_______________________"<<endl;
        cout<<"\t\tMovie Title::"<<m[i].getMoviename()<<endl;
        cout<<"\t\tRelease Date::"<<m[i].getRelease()<<endl;
        cout<<"\t\tRuntime::"<<m[i].getRuntime()<<endl;
        cout<<"\t\tDirector's Name::"<<m[i].getDirect()<<endl;
        cout<<"\t\tGenre::"<<m[i].getType()<<endl;
        cout<<"\t\tScreen::"<<m[i].getDimension()<<endl;


    }
     cout<<"\t\t======================================"<<endl;


cout<<"\n\n"<<endl;
cout<<endl;
    cout<<"\t\t\tPress 1 For Movie No. 1"<<endl;
    cout<<"\t\t\tPress 2 For Movie No. 2"<<endl;
    cout<<"\t\t\tPress 3 For Movie No. 3"<<endl;
    cout<<"\t\t\tPress 4 For Movie No. 4"<<endl;
    int n;
    cin>>n;
    cout<<endl;
    cout<<"\n\n\t\t\tPress Y If You Are Sure About Your Selection-"<<endl;
    cout<<"\t\t\tPress N If You Want To Select Another Movie"<<endl;
    char c;
    cin>>c;
    if(c=='n'||c=='N')
    {
    cout<<"\t\t\tPress 1 For Movie No. 1"<<endl;
    cout<<"\t\t\tPress 2 For Movie No. 2"<<endl;
    cout<<"\t\t\tPress 3 For Movie No. 3"<<endl;
    cout<<"\t\t\tPress 4 For Movie No. 4"<<endl;
    cin>>n;
    c='y';
    }
    if (n==1 && (c=='Y'||c=='y'))
    {
        cout<<"\t\tYour Selected Movie-"<<m[0].getMoviename()<<endl;
        cout<<"\t\tRuntime::"<<m[0].getRuntime()<<endl;
        cout<<"\t\tDirector's Name::"<<m[0].getDirect()<<endl;
        cout<<"\t\tScreen::"<<m[0].getDimension()<<endl;
        ofstream file("Booked.txt",ios_base::app); //Movie.txt
    if (file.is_open())
        {
           file<<"Your Selected Movie-"<<m[0].getMoviename()<<endl;
            file<<"Release Date::"<<m[0].getRelease()<<endl;
            file<<"Runtime::"<<m[0].getRuntime()<<endl;
            file<<"Director's Name::"<<m[0].getDirect()<<endl;
           file<<"Screen::"<<m[0].getDimension()<<endl;
          file<<"Genre::"<<m[0].getType()<<endl;
          file.close();
        }


        setMoviename("Fast X");
        setRuntime("2 h 32 min");
        setRelease("19 May 2023");
        setDirect("Louis Leterrier");
        setDimension("3D");
        setType("Action · Adventure · Mystery · Thriller");
        time=1;
    }
    if (n==2 &&(c=='Y'||c=='y'))
    {
        cout<<"\t\tYour Selected Movie-"<<m[1].getMoviename()<<endl;
        cout<<"\t\tRuntime::"<<m[1].getRuntime()<<endl;
        cout<<"\t\tDirector's Name::"<<m[1].getDirect()<<endl;
        cout<<"\t\tScreen::"<<m[1].getDimension()<<endl;

       ofstream file("Booked.txt",ios_base::app); //Movie.txt
    if (file.is_open())
        {
           file<<"Your Selected Movie-"<<m[1].getMoviename()<<endl;
            file<<"Release Date::"<<m[1].getRelease()<<endl;
           file<<"Runtime::"<<m[1].getRuntime()<<endl;
           file<<"Director's Name::"<<m[1].getDirect()<<endl;
            file<<"Screen::"<<m[1].getDimension()<<endl;
            file<<"Genre::"<<m[1].getType()<<endl;
            file.close();
        }
        setMoviename("Guaedians Of The Galaxy Volume 3");
        setRuntime("2 h 26 min");
        setRelease("5 May 2023");
        setDirect("James Gunn");
        setDimension("3D");
        setType("Action · Adventure · Comedy · Science Fiction.");


        time=2;
    }

    if (n==3 && (c=='Y'||c=='y'))
    {
        cout<<"\t\tYour Selected Movie-"<<m[2].getMoviename()<<endl;
        cout<<"\t\tRuntime::"<<m[2].getRuntime()<<endl;
        cout<<"\t\tDirector's Name::"<<m[2].getDirect()<<endl;
        cout<<"\t\tScreen::"<<m[2].getDimension()<<endl;

       ofstream file("Booked.txt",ios_base::app); //Movie.txt
    if (file.is_open())
        {
           file<<"Your Selected Movie-"<<m[2].getMoviename()<<endl;
            file<<"Release Date::"<<m[2].getRelease()<<endl;
           file<<"Runtime::"<<m[2].getRuntime()<<endl;
           file<<"Director's Name::"<<m[2].getDirect()<<endl;
            file<<"Screen::"<<m[2].getDimension()<<endl;
            file<<"Genre::"<<m[2].getType()<<endl;
            file.close();
        }
        setMoviename("Avatar:The Way Of Water");
        setRuntime("2 h 14 min");
        setRelease("22 December 2022");
        setDirect("James Cameron");
        setDimension("2D");
        setType(" Sci-fi · Adventure · Action · Fantasy");

        time=3;
    }

    if (n==4 && (c=='Y'||c=='y'))
    {
        cout<<"\t\tYour Selected Movie-"<<m[3].getMoviename()<<endl;
        cout<<"\t\tRuntime::"<<m[3].getRuntime()<<endl;
        cout<<"\t\tDirector's Name::"<<m[3].getDirect()<<endl;
        cout<<"\t\tScreen::"<<m[3].getDimension()<<endl;

       ofstream file("Booked.txt",ios_base::app); //Movie.txt
    if (file.is_open())
        {
           file<<"Your Selected Movie-"<<m[3].getMoviename()<<endl;
            file<<"Release Date::"<<m[3].getRelease()<<endl;
            file<<"Runtime::"<<m[3].getRuntime()<<endl;
           file<<"Director's Name::"<<m[3].getDirect()<<endl;
            file<<"Screen::"<<m[3].getDimension()<<endl;
            file<<"Genre::"<<m[3].getType()<<endl;
            file.close();
        }
        time=4;
        setMoviename("The Little Mermaid");
        setRuntime("2 h 46 min");
        setRelease("25 May 2023");
        setDirect("Rob Marshall");
        setDimension("3D");
        setType("Adventure · Family · Fantasy · Musical · Romance");

    }


}

void movie::movieSelected()
{
    cout<<"\t\t\t\t\tDetails About Your Selected Movie::"<<endl;
 cout<<"\t\t\t\t\tYour Selected Movie's Name-"<<getMoviename()<<endl;
    cout<<"\t\t\t\t\tRelease Date::"<<getRelease()<<endl;
    cout<<"\t\t\t\t\tRuntime::"<<getRuntime()<<endl;
    cout<<"\t\t\t\t\tDirector's Name::"<<getDirect()<<endl;
    cout<<"\t\t\t\t\tGenre::"<<getType()<<endl;
    cout<<"\t\t\t\t\tScreen::"<<getDimension()<<endl;

    ofstream cnn("Booked.txt",ios_base::app);
 if(cnn. is_open())
 {
    cnn<<"\t\t\tDetails About Your Selected Movie::"<<endl;
    cnn<<"\t\tRelease Date::"<<getRelease()<<endl;
    cnn<<"\t\tRuntime::"<<getRuntime()<<endl;
    cnn<<"\t\tDirector's Name::"<<getDirect()<<endl;
    cnn<<"\t\tGenre::"<<getType()<<endl;
    cnn<<"\t\tScreen::"<<getDimension()<<endl;
    cnn.close();
 }

}

void movie ::viewb()
{
    cout<<"\t\t\tYour Bookings:-"<<endl;
    cout<<"\t\t\tMovie Details "<<endl;
     cout<<"\t\t\tYour Selected Movie-  "<<getMoviename()<<endl;
            cout<<"\t\t\tRelease Date::  "<<getRelease()<<endl;
            cout<<"\t\t\tRuntime::  "<<getRuntime()<<endl;
            cout<<"\t\t\tDirector's Name::  "<<getDirect()<<endl;
            cout<<"\t\t\tScreen::  "<<getDimension()<<endl;
            cout<<"\t\t\tGenre::  "<<getType()<<endl;


}

void movie::listt()
{movie m[4];
    m[0].setMoviename("Fast X");
    m[0].setRuntime("2 h 32 min");
    m[0].setRelease("19 May 2023");
    m[0].setDirect("Louis Leterrier");
    m[0].setDimension("3D");
    m[0].setType("Action · Adventure · Mystery · Thriller");

    m[1].setMoviename("Guaedians Of The Galaxy Volume 3");
    m[1].setRuntime("2 h 26 min");
    m[1].setRelease("5 May 2023");
    m[1].setDirect("James Gunn");
    m[1].setDimension("3D");
    m[1].setType("Action · Adventure · Comedy · Science Fiction.");

    m[2].setMoviename("Avatar:The Way Of Water");
    m[2].setRuntime("2 h 14 min");
    m[2].setRelease("22 December 2022");
    m[2].setDirect("James Cameron");
    m[2].setDimension("2D");
    m[2].setType(" Sci-fi · Adventure · Action · Fantasy");


    m[3].setMoviename("The Little Mermaid");
    m[3].setRuntime("2 h 46 min");
    m[3].setRelease("25 May 2023");
    m[3].setDirect("Rob Marshall");
    m[3].setDimension("3D");
    m[3].setType("Adventure · Family · Fantasy · Musical · Romance");

     for(int  i=0; i<4; i++)
    {
        cout<<"\t\t\t\t_______________________"<<endl;
        cout<<"\t\t\tMovie Number-"<<i+1<<endl;
        cout<<"\n\t\t\t\t_______________________"<<endl;
        cout<<"\t\tMovie Title::"<<m[i].getMoviename()<<endl;
        cout<<"\t\tRelease Date::"<<m[i].getRelease()<<endl;
        cout<<"\t\tRuntime::"<<m[i].getRuntime()<<endl;
        cout<<"\t\tDirector's Name::"<<m[i].getDirect()<<endl;
        cout<<"\t\tGenre::"<<m[i].getType()<<endl;
        cout<<"\t\tScreen::"<<m[i].getDimension()<<endl;


    }

       ofstream file("Booked.txt", ios_base::app);

    if (file.is_open()) {
        // Write the movie information to the file
        for (int i = 0; i < 4; i++) {
            file << "Movie Name: " << m[i].getMoviename() << endl;
            file << "Runtime: " << m[i].getRuntime() << endl;
            file << "Release Date: " << m[i].getRelease() << endl;
            file << "Director: " << m[i].getDirect() << endl;
            file << "Dimension: " << m[i].getDimension() << endl;
            file << "Type: " << m[i].getType() << endl;
            file << endl;
        }

        // Close the file
        file.close();

}}

void movie::menu()
{
    cout<<"\t\t\t==================================="<<endl;
    cout<<"\t\t\t||Welcome To Movie Ticket Booking||"<<endl;
    cout<<"\t\t\t==================================="<<endl;
    cout<<"\t\t\tPress 1 To Book Ticket: "<<endl;
cout<<"\t\t\tPress 2 To View Booking: "<<endl;
    cout<<"\t\t\tPress 3 To View Price Of Tickets: "<<endl;
    cout<<"\t\t\tPress 4 To Check Available Seats: "<<endl;
    cout<<"\t\t\tPress 5 To Show Movies List: "<<endl;
    cout<<"\t\t\tPress 6 To Check Movie Timings: "<<endl;
    //cout<<"\t\t\tPress 6 To Add A New Movie Or To Add More Tickets: "<<endl;
   // cout<<"\t\t\tPress 6 To Show Movies List: "<<endl;
    cout<<"\t\t\tPress 7 To Get A Membership: "<<endl;
    cout<<"\t\t\tPress 8 To Exit: "<<endl;
    cout<<"\t\t\t________________________"<<endl;



}



class time
{
    string movieTime;
public:
    time();
    void setmovietime(string);
    string getmovietime();
    void schedule1();
    void schedule2();
    void schedule3();
    void schedule4();
};
time::time()
{
    this->movieTime="";

}

void time::setmovietime(string a)
{
    this->movieTime=a;
}
string time:: getmovietime()
{
    return movieTime;
}
void time::schedule1()
{
    ofstream file("Booked.txt",ios_base::app); //Movie.txt
    if (file.is_open())
    {file<<"Selected Movie's Timing:: "<<endl;
        file << "Day         Timing\n"<<endl;
        file << "Monday     11 am" << endl;
        file << "Monday     8 pm" << endl;
        file << "Wednesday  11 am" << endl;
        file << "Thursday   8 pm" << endl;
        file << "Friday     11 am" << endl;
        file.close();

    }
    cout<<"\t\t\t\t\t\t  Day        Timing\n";
    cout<<"\t\t\t\t\t1)\tMonday     11 am\n";
    cout<<"\t\t\t\t\t2)\tMonday     8 pm\n";
    cout<<"\t\t\t\t\t3)\tWednesday  11 am\n";
    cout<<"\t\t\t\t\t4)\tThursday   8 pm\n";
    // cout<<"\t\t\t\t\t5)\tFriday     11 am\n";


}


/*void time::schedule2() {
    ofstream file("Movie.txt");
    if (file.is_open()) {
        file << "Monday     3 pm" << endl;
        file << "Tuesday    7 pm" << endl;
        file << "Wednesday  8 pm" << endl;
        file << "Thursday   11 am" << endl;
        file.close();

    }
}*/
void time::schedule2()
{

    ofstream file("Booked.txt",ios_base::app);
    if (file.is_open())
    {file<<"Selected Movie's Timing:: "<<endl;
        file << "Day         Timing\n"<<endl;
        file << "Monday     3 pm" << endl;
        file << "Tuesday    7 pm" << endl;
        file << "Wednesday  8 pm" << endl;
        file << "Thursday   11 am" << endl;
        file.close();

    }
    //  cout<<"\t\t\t\t\t1)\tMonday     3 pm\n";
    // cout<<"\t\t\t\t\t2)\tMonday     7 pm\n";
    cout<<"\t\t\t\t\t\t  Day        Timing\n";
    cout<<"\t\t\t\t\t1)\tWednesday  8 pm\n";
    cout<<"\t\t\t\t\t2)\tThursday   11 am\n";
    cout<<"\t\t\t\t\t3)\tFriday     8 pm\n";
    cout<<"\t\t\t\t\t4)\tSaturday   8 pm\n";


}
void time::schedule3()
{
   ofstream file("Booked.txt",ios_base::app);//Movie.txt
    if (file.is_open())
    {file<<"Selected Movie's Timing:: "<<endl;
        file << "Day         Timing\n"<<endl;
        file << "Sunday     3 pm" << endl;
        file << "Wednesday  3 pm" << endl;
        file << "Thursday   3 pm" << endl;
        file << "Friday     3 pm" << endl;
        file.close();
    }
    cout<<"\t\t\t\t\t\t  Day        Timing\n";
    cout<<"\t\t\t\t\t1)\tSunday     3 pm\n";
    // cout<<"\t\t\t\t\t2)\tMonday      pm\n";
    cout<<"\t\t\t\t\t2)\tWednesday  3 pm\n";
    cout<<"\t\t\t\t\t3)\tThursday   3 pm\n";
    cout<<"\t\t\t\t\t4)\tFriday     3 pm\n";


}
void time::schedule4()
{
    ofstream file("Booked.txt",ios_base::app);
    if (file.is_open())
    {file<<"Selected Movie's Timing:: "<<endl;
        file << "Day         Timing\n"<<endl;
        file << "Sunday     11 am" << endl;
        file << "Sunday     8 pm" << endl;
        file << "Wednesday  11 am" << endl;
        file << "Monday     3 pm" << endl;
        file << "Saturday   11 am" << endl;
        file.close();
    }
    cout<<"\t\t\t\t\t\t  Day        Timing\n";
    cout<<"\t\t\t\t\t1)\tSunday     11 am\n";
    cout<<"\t\t\t\t\t2)\tSunday     8 pm\n";
    //cout<<"\t\t\t\t\t3)\tWednesday  11 am\n";
    //  cout<<"\t\t\t\t\t4)\tthursday   7 pm\n";
    cout<<"\t\t\t\t\t3)\tMonday     3 pm\n";
    cout<<"\t\t\t\t\t4)\tSaturday   11 am\n";
    // cout<<"\t\t\t\t\t5)\tSaturday   3 pm\n";


}


class ticket
{
    int id;
    double price ;
    char GoldorSilver;
    int  numbert;
    int availableseats;
public:
    time t;
    movie m;
    ticket();
    void setid(int);
    int getid();
    void timings();
    void settickettype(char);
    char gettickettype();
    void setseat(int);
    int getseat();
    void availableseat();
    void setprice(float);
    // double(getprice);
    float getprice();
    void movie1();
    void movie2();
    void movie3();
    void movie4();
    void display();
    void schedule();
    void tickettype();
    void ticketview();
    void pricet();
    void number();
    void setnumber(int);
    int getnumber();
    //void sttickettype(char );
    void ticketd();
     //void settickettype(string)
};

ticket::ticket()
{
    this->id=11100;
    this ->price= 5;
    this->availableseats=300;
    this->GoldorSilver='n';

}
void ticket:: setid(int id)
{
    this->id=id;
}
int ticket::getid()
{
    return id;
}
void ticket::setnumber(int n)
{
    this->numbert=n;
}
int ticket::getnumber()
{
    return numbert;
}
void ticket::setprice(float pri)
{
    this->price=pri;
}

float ticket::getprice()
{
    return price;
}
void ticket::settickettype(char tt)
{
  GoldorSilver=tt;
}
char ticket::gettickettype()
{
    return GoldorSilver;
}
void ticket::setseat(int n)
{
    this->availableseats=n;
}

int ticket::getseat()
{
    return availableseats;
}
void ticket::movie1()
{
     cout<<"\t\t\t_____________________________________\n"<<endl;
    cout<<"\t\t\tMovie Timing:-\n"<<endl;
    cout<<"\t\t\tDay:    Time:"<<endl;
    t.schedule1();
    cout<<"\t\t\t_____________________________________\n"<<endl;
    cout<<"Enter Your Choice Please-"<<endl; //choices can be 1/2/3/4
    int x;
    cin>>x;
   cout<<"\t\t\t_____________________________________\n"<<endl;
    if(x==1)
    {
        /*cout<<"\t\t\t\t\t1)\tMonday     11 am\n";
        cout<<"\t\t\t\t\t2)\tMonday     8 pm\n";
        cout<<"\t\t\t\t\t3)\tWednesday    11 am\n";
        cout<<"\t\t\t\t\t4)\tThursday    8 pm\n";*/
        cout<<"\t\t\tTimings:Monday    11 am"<<endl;
        t.setmovietime("Monday    11 am");
    }
    else if(x==2)
    {
        cout<<"\t\t\tTimings:Monday     8 pm"<<endl;
        t.setmovietime("Monday    8 pm");
    }
    else if(x==3)
    {

        cout<<"\t\t\tTimings:Wednesday    11 am"<<endl;
        t.setmovietime("Wednesday    11 am");
    }
    else if(x==4)
    {

        cout<<"\t\t\tTimings:Thursday    8 pm"<<endl;
        t.setmovietime("Thursday    8 pm");
    }

   cout<<"\t\t\t_____________________________________\n"<<endl;


}
void ticket::movie2()
{
    /* cout<<"\t\t\t\t\t1)\tWednesday    8 pm\n";
     cout<<"\t\t\t\t\t2)\tThursday    11 am\n";
     cout<<"\t\t\t\t\t3)\tFriday    8 pm\n";
     cout<<"\t\t\t\t\t4)\tSaturday    8 pm\n";*/

    cout<<"\t\t\t_____________________________________\n"<<endl;
    cout<<"\t\t\tMovie Timing:-\n"<<endl;
    cout<<"\t\t\tDay:    Time:"<<endl;
    t.schedule2();
     cout<<"\t\t\t_____________________________________\n"<<endl;
    cout<<"Enter Your Choice Please-"<<endl ;//choices can be 1/2/3/4
    int x;
    cin>>x;
       cout<<"\t\t\t_____________________________________\n"<<endl;
    if(x==1)
    {
        cout<<"\t\t\tTimings:Wednesday    8 pm"<<endl;
        t.setmovietime("Wednesday    8 pm");
    }
    else if(x==2)
    {
        cout<<"\t\t\tTimings:Thursday    11 am"<<endl;
        t.setmovietime("Thursday    11 am");
    }
    else if(x==3)
    {

        cout<<"\t\t\tTimings:Friday    8 pm"<<endl;
        t.setmovietime("Friday    8 pm");
    }
    else if(x==4)
    {

        cout<<"\t\t\tTimings:Saturday    8 pm"<<endl;
        t.setmovietime("Saturday    8 pm");
    }

     cout<<"\t\t\t_____________________________________\n"<<endl;


}

void ticket::movie3()
{
    /* cout<<"\t\t\t\t\t1)\tSunday    3 pm\n";
     cout<<"\t\t\t\t\t2)\tWednesday    3 pm\n";
     cout<<"\t\t\t\t\t3)\tThursday    3 pm\n";
     cout<<"\t\t\t\t\t4)\tFriday    3 pm\n";*/
   cout<<"\t\t\t_____________________________________\n"<<endl;
    cout<<"\t\t\tMovie Timing___\n"<<endl;
    cout<<"\t\t\tDay:    Time:"<<endl;
    t.schedule3();
     cout<<"\t\t\t_____________________________________\n"<<endl;
    cout<<"Enter Your Choice Please-"<<endl ;//choices can be 1/2/3/4
    int x;
    cin>>x;
    cout<<"\t\t\t\t\t\t\________________________"<<endl;
    if(x==1)
    {
        cout<<"\t\t\tTimings:Sunday    3 pm"<<endl;
        t.setmovietime("Sunday    3 pm");
    }
    else if(x==2)
    {
        cout<<"\t\t\tTimings:Wednesday    3 pm"<<endl;
        t.setmovietime("Wednesday    3 pm");
    }
    else if(x==3)
    {

        cout<<"\t\t\tTimings:Thursday    3 pm"<<endl;
        t.setmovietime("Thursday    3 pm");
    }
    else if(x==4)
    {

        cout<<"\t\t\tTimings:Friday    3 pm"<<endl;
        t.setmovietime("Friday    3 pm");
    }

   cout<<"\t\t\t_____________________________________\n"<<endl;


}

void ticket::movie4()
{
    /*cout<<"\t\t\t\t\t1)\tSunday    11 am\n";
    cout<<"\t\t\t\t\t2)\tSunday    8 pm\n";

    cout<<"\t\t\t\t\t3)\tMonday    3 pm\n";
    cout<<"\t\t\t\t\t4)\tSaturday    11 am\n";*/


      cout<<"\t\t\t_____________________________________\n"<<endl;
    cout<<"\t\t\tMovie Timing___\n"<<endl;
    cout<<"\t\t\tDay:    Time:"<<endl;
    t.schedule4();
      cout<<"\t\t\t_____________________________________\n"<<endl;
    cout<<"Enter Your Choice Please-"<<endl; //choices can be 1/2/3/4
    int x;
    cin>>x;
    cout<<"\t\t\t_____________________________________\n"<<endl;
    if(x==1)
    {
        cout<<"\t\t\tTimings:Sunday    11 am"<<endl;
        t.setmovietime("Sunday    11 amm");
    }
    else if(x==2)
    {
        cout<<"\t\t\tTimings:Sunday    8 pm"<<endl;
        t.setmovietime("Sunday    8 pm");
    }
    else if(x==3)
    {

        cout<<"\t\t\tTimings:Monday    3 pm"<<endl;
        t.setmovietime("Monday    3 pm");
    }
    else if(x==4)
    {

        cout<<"\t\t\tTimings:Saturday    11 am"<<endl;
        t.setmovietime("Saturday    11 am");
    }
 cout<<"\t\t\t_____________________________________\n"<<endl;


}

void ticket::ticketd()
{cout<<"\t\t\t======================================================="<<endl;
    m.viewb();
    cout<<"\t\t\tTicket Id  "<<getid()<<endl;
   // cout<<"\t\t\tTicket Type"<<getickettype()<<endl;
   // cout<<"\t\t\tTicket Price"<<getticketprice()<<endl;
}

void ticket::schedule()
{
    m.playing();
    if(m.time==1)
    {
        movie1();
    }
    if(m.time==2)
    {
        movie2();
    }
    if(m.time==3)
    {
        movie3();
    }
    if(m.time==4)
    {
        movie4();
    }
}
void ticket::tickettype()
{ cout<<"\t\t\t======================================================="<<endl;
    cout<<"\t\t\t\t\tEnter Your Ticket Type Please"<<endl;
    cout<<"\t\t\t\t\tSilver Costs Rs.500 taka+ 5% vat"<<endl;
    cout<<"\t\t\t\t\tGold Costs Rs.1000 taka+ 5% vat"<<endl;
    cout<<"\t\t\t\t\tPress S For Silver"<<endl;
    cout<<"\t\t\t\t\tPress G For Gold"<<endl;
    cout<<"\t\t\t\t\tEnter Your Choice"<<endl;
    char s;
    cin>>s;
    cout<<"\t\t\t\t\t__________________________"<<endl;
    if (s=='s'||s=='s')
    {
        cout<<"\t\t\t\t\t\Silver Ticket Is Selected"<<endl;
        setprice(525.00);
        settickettype('S');
    }
    else if(s=='G'||s=='g')
    {

        cout<<"\t\t\t\t\t\Gold Ticket Is Selected"<<endl;
        setprice(1050.00);
        settickettype('G');
    }
  cout<<"\t\t\t======================================================="<<endl;

}

void ticket::display()
{
    number();
    cout<<"\t\t\t\t\t____________________"<<endl;
     cout<<"\t\t\t======================================================="<<endl;
    cout<<"\t\t\t\t\tYour Ticket Is Successfully Bokked\n"<<endl;
    cout<<"\t\t\t\t\t|||Booking Details|||\n"<<endl;
    cout<<"\t\t\t\t\tTicket Id:-"<<getid()<<endl;
    m.movieSelected();
    cout<<"\t\t\t\t\tTicket Type:-"<<gettickettype()<<endl;
    cout<<"Do You Have A Membership? Press Y If You Are A Member||Or Press N If You Are Not A Member"<<endl;
    char p;
    cin>>p;
    if(p=='Y'||p=='y')
    {cout<<"\t\t\t\t\tYour Membership Id Number Please-"<<endl;
    long long k;
    cin>>k;
    if(k==10203||k==10207||k==56009||k==20204||k==45907)// it will be valid for 10203, 10207,20204,56009,45907
        {
            cout<<"\t\t\t\t=========================================="<<endl;
            cout<<"\t\t\t\t\tYou Will Get A Additional 10% Off"<<endl;
            float r=(getprice()-getprice()*.1);
            //float f=getprice()-getprice*.1;
            cout<<"\t\t\t\t\tTicket Total Cost Without 10% Discount Is "<<getprice()<<" BDT"<<endl;
        cout<<"\t\t\t\t\tTicket Price:- "<<r<<" BDT"<<endl;
        setprice(r );}
        else
            {cout<<"\t\t\t\t=========================================="<<endl;
                cout<<"\t\t\t\t\tSorry Invalid Id"<<endl;
                cout<<"\t\t\t\t\tTicket Price:-"<<getprice()<<endl;}
        }
         else
            {
cout<<"\t\t\t\t=========================================="<<endl;
                cout<<"\t\t\t\t\tTicket Price:-"<<getprice()<<endl;}
    cout<<endl;
    cout<<endl;



}
void ticket::number()
{
    cout<<"Number Of Tickets:-";
    int i;
    cin>>i;
    setnumber(i);
    setseat(availableseats-i);
    if(getprice()==525)
    {
        cout<<"\t\t\t\t\tPrice Of Each Ticket Including Vat Is 525 BDT"<<endl;
        setprice(525*i);
    }
    else if(getprice()==1050)
    {
        cout<<"\t\t\t\t\tPrice Of Each Ticket Including Vat Is 1050 BDT"<<endl;
        setprice(1050*i);
    }
    cout<<"\t\t\t\t\tTotal Price Of Ticket:- "<<getprice()<< " BDT"<<endl;

    ofstream file("Booked.txt", ios_base::app);
    if(file.is_open())
    {
        file<<"Total Seat Booked:- "<<i<<endl;
        file<<"Total Price Of Ticket :-"  <<getprice()<< " BDT"<<endl;
        file.close();

    }

}

void ticket::availableseat()
{
    cout<<endl<<endl;
    cout<<"\t\t\t::Available Seats Of The Theater::"<<endl;
    cout<<"\t\t\t==============================="<<endl;
    cout<<"\t\t\tTotal Seats Of The Theater : 300"<<endl;
    cout<<"\t\t\tSeats Booked:- "<< getnumber()<<endl;
    cout<<"\t\t\tAvailable Seats::  "<<300-getnumber()<<endl;
    cout<<"\t\t\t==============================="<<endl;


}

void ticket::timings()
{
    cout<<"\t\t\t======================================================="<<endl;
    cout<<"\t\t\t________________"<<endl;
    cout<<"\t\t\tMovie Timings:-"<<endl;
    cout<<"\t\t\tMovie Playing"<<endl;

    cout<<"\t\t\t1) Fast X"<<endl;
    cout<<"\t\t\tRelease date:- 19 May 2023 "<<endl;
    cout<<"\t\t\tDirector:- Louis Leterrier"<<endl;
        cout<<"\t\t\tCast - Vin Diesel, Brie Larson, Jason Momoa\n\n"<<endl;

    cout<<"\t\t\t2) Guaedians Of The Galaxy Volume 3 "<<endl;
    cout<<"\t\t\tDirector:- James Gunn"<<endl;
        cout<<"\t\t\tRelease date:- 5 May 2023 "<<endl;
    cout<<"\t\t\tCast - Dave Dautiata, Karen Gillan, Elizabeth Debicki\n\n"<<endl;

    cout<<"\t\t\t3) Avatar:The Way Of Water"<<endl;
    cout<<"\t\t\tDirector:- James Cameron"<<endl;
        cout<<"\t\t\tRelease date:- 22 December 2022  "<<endl;
    cout<<"\t\t\tCast - Zoe Saldana, Sam Worthington, Stephen Lang\n\n"<<endl;

    cout<<"\t\t\t4) The Little Mermaid"<<endl;
    cout<<"\t\t\tDirector:- Rob Marshall"<<endl;
        cout<<"\t\t\tRelease date:- 25 May 2023 "<<endl;
    cout<<"\t\t\tCast - Halle Bailey, Jonah King, Melissa McCarthy\n\n"<<endl;

    ofstream file("Booked.txt",ios_base:: app);
    if(file.is_open())
    {
        file<<"\t\t\t________________"<<endl;
        file<<"\t\t\tMovie Timings:-"<<endl;
        file<<"\t\t\tMovie Playing"<<endl;

        file<<"\t\t\t1) Fast X"<<endl;
        file<<"\t\t\tRelease date:- 19 May 2023 "<<endl;
        file<<"\t\t\tDirector:- Louis Leterrier"<<endl;
            cout<<"\t\t\tCast - Vin Diesel, Brie Larson, Jason Momoa\n\n"<<endl;

        file<<"\t\t\t2) Guaedians Of The Galaxy Volume 3 "<<endl;
        file<<"\t\t\tDirector:- James Gunn"<<endl;
            file<<"\t\t\tRelease date:- 5 May 2023 "<<endl;
        file<<"\t\t\tCast - Dave Dautiata, Karen Gillan, Elizabeth Debicki\n\n"<<endl;

        file<<"\t\t\t3) Avatar:The Way Of Water"<<endl;
        file<<"\t\t\tDirector:- James Cameron"<<endl;
            file<<"\t\t\tRelease date:- 22 December 2022  "<<endl;
        file<<"\t\t\tCast - Zoe Saldana, Sam Worthington, Stephen Lang\n\n"<<endl;

        file<<"\t\t\t4) The Little Mermaid"<<endl;
        file<<"\t\t\tDirector:- Rob Marshall"<<endl;
            file<<"\t\t\tRelease date:- 25 May 2023 "<<endl;
        file<<"\t\t\tCast - Halle Bailey, Jonah King, Melissa McCarthy\n\n"<<endl;
    }


    cout<<"\t\t\tEnter 1/2/3/4 According To Which Movie's Time You Want To Know,Thank You"<<endl;
    cout<<"\t\t\t======================================================="<<endl;
    int v;
    cin>>v;
    if(v==1)
    {
        t.schedule1();
    }
    else if(v==2)
    {
        t.schedule2();
    }
    else if(v==3)
    {
        t.schedule3();
    }
    else if(v==4)
    {
        t.schedule4();
    }
}

void ticket::pricet(){
cout<<"\t\t\t Choose Your Preferable Type Of Ticket"<<endl;
cout<<"\t\t\tSelect S For Silver And G For Golden"<<endl;
char c;
cin>>c;
if(c=='s'||c=='S')
{cout<<"\t\t\tPrice Of Silver Ticket is 525 BDT Including 5% Vat"<<endl;}
if(c=='G'||c=='g')
{cout<<"\t\t\tPrice Of Golden Ticket is 1050 BDT Including 5% Vat"<<endl;}


}




int main()
{
    movie m;
    ticket t;
    customer cu;
    member me;
    int x;
    int lop=1;
    do
    {
        m.menu();
        cout<<"\t\t\tEnter Your Choice  "<<endl;
            cin>>x;
        switch(x)
        {
        case 1:
        {
            cout<<"\t\t\tMovie list-"<<endl;
                t.schedule();
            t.tickettype();
            //t.number();
            t.display();
            break;
        }
        case 2:
        {
            t.ticketd();
            break;
        }
        case 3:
        {
            t.pricet();
            break;
        }


        case 4:
        {
            t.availableseat();
            break;
        }

        case 5:
        {
            m.listt();
            break;
        }
        case 6:
        {
            t.timings();
            break;
        }

        case 7:
        {
            me.memberShip();
            cin.ignore();
            cu.insertinfo();
        cu.oldCustomer();
            cu.display();
            break;


        }
        case 8:
            {return 0;}
default:
        {
            break;
        }
        }
        cout<<"\t\t\t======================================================="<<endl;
      cout<<"\t\t\tPress 1 To Go To Main Menu "<<endl;
      cout<<"\t\t\tPress 0 To Exit "<<endl;
      //int p;
      cin>>lop;

    }while(lop==1);
    system("pause");
    return 0;
}

