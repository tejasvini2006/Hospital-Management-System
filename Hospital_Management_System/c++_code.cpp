#include <iostream>
#include<ctime>
//#include <graphics.h>
#include<iomanip>
#include<string>
#include<vector>
#include<cstring>
#include<conio.h>


using namespace std;

    time_t ti=time(NULL);
    tm* dataptr =localtime(&ti);
   int  date=(dataptr->tm_mday);
   int  month=(dataptr->tm_mon)+1;
   int  year=(dataptr->tm_year)+1900;

void menu();
void menu_view_pat();

void validinfor()
    {
    cout<<endl<<"\t"<<"ENTER VALID INFORMATION WHICH IS ASKED:"<<endl;
    }
void aboutus()
{
     cout<<"\n \t\t\t\t ABOUT US";
        cout<<"\n \t\t\t\t ---------";
        cout<<"\n\n\n\n";
        cout<<endl<<"\t"<< left << setw(30)<<"PROJECT FOR"<<":";
        cout<<" HOSPITAL MAMAGEMENT SYSTEM";
        cout<<endl<<endl<<endl<<"\t"<< left << setw(30)<<"PROJECT CREATED BY"<<":";
        cout<<" GOSWAMI PRIYA HARESHBHARTHI";
        cout<<endl<<"\t"<< left << setw(30)<<""<<":";
        cout<<" KANANI TEJASVINI";
        cout<<endl<<endl<<endl<<"\t"<< left << setw(30)<<"GUIDED BY"<<":";
        cout<<" JIGNESHKUMAR SHAH ";
        cout<<endl<<endl<<endl<<"\t"<< left << setw(30)<<"USERS OF PROJECT"<<":";
        cout<<" DOCTORS AND RECEPTIONIST";
        cout<<endl<<endl<<endl<<"\t"<< left << setw(30)<<"MAIN PURPOSE OF DEVELOPEMENT"<<":";
        cout<<"the development of Hospital Management System aims to modernize and optimize";
        cout<<endl<<"\t"<< left << setw(30)<<"";
        cout<<"operations of hospitals, ultimately leading to improved patient outcomes,better ";
        cout<<endl<<"\t"<< left << setw(30)<<"";
        cout<<"  resource management, and enhanced overall efficiency.";
        cout<<endl<<endl<<endl<<"\t"<< left << setw(30)<<"USES OF THE PROJECT"<<":";
        cout<<" Registration,Appointment Scheduling,Billing and Invoicing,Data Analytics";
        cout<<endl<<"\t"<< left << setw(30)<<"";
        cout<<"  information for visitors,Staff Scheduling and Pharmacy Management";
        cout<<endl<<endl<<endl<<"\t"<< left << setw(30)<<"OUR CONTACT NUMBER"<<":";
        cout<<" 8780732104";
        cout<<endl<<"\t"<< left << setw(30)<<""<<":";
        cout<<" 6353896459";
        cout<<endl<<endl<<endl<<"\t"<< left << setw(30)<<"OUR EMAIL ID"<<":";
        cout<<" priyahgoswami1981@gmail.com";
        cout<<endl<<"\t"<< left << setw(30)<<""<<":";
        cout<<" tejkanani2006@gmail.com";
        cout<<"\n\n IF ANYONE WANT TO GIVE US SUGETIONS THEN PLEASE CONTACT US\n\n ";
}




class validation
{
    protected:
    int check_age(unsigned int);
    int check_gender(string );
    int check_bdate(int, int, int);
    int check_mobile_no(char con[11]);
    int check_Mdate(int, int, int);
    int check_adhar(char adhar[13]);
};
 int validation:: check_mobile_no(char contact[11])
 {
    int i=0;
    while (contact[i] != '\0' && isdigit(contact[i])) {
        i++;
    }
    return (i == 10);
}
 int validation:: check_adhar(char adhar[13])
 {
    int i=0;
    for( i=0;(adhar[i]!='\0')&&(isdigit(adhar[i]));i++);
    while (adhar[i] != '\0' && isdigit(adhar[i])) {
        i++;
    }
    return (i == 12);
 }

int validation:: check_age(unsigned int  age)
{
    return (age <= 100);
}
int validation::  check_bdate(int Bdate, int Bmonth, int Byear)
{
    return !(Bdate > 31 || Bmonth > 12 || Byear < 1950 || Byear > 2024);
}



int validation:: check_gender(string gender1){
       return (gender1 == "female" || gender1 == "male" || gender1 == "FEMALE" || gender1 == "MALE");


}
class admin;

class person: virtual public validation
{   protected :

   string full_name;
   unsigned int age;
   string gender;
   string depart;

   int Bdate;
   int Byear;
   int Bmonth;

   char contact[11]={};


   float fees;
   char aadhar[13]={};

   string adress;
   public:
   person()
   {

    }

    void getinfor();
    void putinfor();

    string take_dep();
    string get_dep();

    void change_depart();

    person&  operator=(const person& other);


};
 string person::get_dep()
 {
    return depart;
 }
person& person:: operator=(const person& other) {
        if (this != &other) {
            // Copy members from 'other' to 'this'
            full_name = other.full_name;
            age = other.age;
            gender = other.gender;
            depart = other.depart;
            Bdate = other.Bdate;
            Byear = other.Byear;
            Bmonth = other.Bmonth;
            fees = other.fees;

            adress = other.adress;
            // Copy arrays
           for (int i = 0; i < 11; i++) {
            contact[i] = other.contact[i];
        }
        for (int i = 0; i < 13; i++) {
            aadhar[i] = other.aadhar[i];
        }
        }
        return *this;
    }

 void person::change_depart()
 {
    depart=take_dep();
 }


void person:: getinfor()
{
    cout<<"\n\n\t"<< left << setw(40) <<"ENTER YOUR FULL NAME"<<":";
    getline(cin>>ws,full_name);

    cout<<endl<<"\t"<< left << setw(40)<<"ENTER YOUR AGE"<<":";
    cin>>age;
    while (!check_age(age))
    {
        validinfor();
            cout<<endl<<"\t"<< left << setw(40)<<"ENTER YOUR AGE AGAIN"<<":";
            cin>>age;
    }



    cout<<endl<<"\t"<< left << setw(40)<<"ENTER YOUR GENDER"<<":";
    getline(cin>>ws,gender);

    while (!check_gender(gender))
    {
        validinfor();
        cout<<endl<<"\t"<< left << setw(40)<<"ENTER YOUR GENDER AGAIN"<<":";
        getline(cin>>ws,gender);
    }


     cout<<endl<<"\t"<< left << setw(40)<<"ENTER YOUR DATE OF BIRTH"<<":";
    cin>>Bdate>>Bmonth>>Byear;
    while (!check_bdate(Bdate,Bmonth,Byear))
    {
        validinfor();
        cout<<endl<<"\t"<< left << setw(40)<<" ENTER BIRTH DATE MONTH YEAR AGAIN  "<<":";
        cin>>Bdate>>Bmonth>>Byear;
    }

    cout<<endl<<"\t"<< left << setw(40)<<"ENTER YOUR EMERGENCY CONTACT NO "<<":";
    cin>>contact;
     while(!check_mobile_no(contact))
     {
        validinfor();
         cout<<endl<<"\t"<< left << setw(40)<<"ENTER YOUR EMERGENCY CONTACT NO  AGAIN"<<":";
        cin>>contact;
     }







    cout<<endl<<"\t"<< left << setw(40)<<"ENTER  AADHAR CARD NUMBER"<<":";

     cin>>aadhar;

     while(!check_adhar(aadhar))
     {
        validinfor();
         cout<<endl<<"\t"<< left << setw(40)<<"ENTER  AADHAR CARD ANUMBER AGAIN"<<":";

        cin>>aadhar;
     }

     cout<<endl<<"\t"<< left << setw(40)<<"ENTER YOUR CURRENT ADRESS"<<":";
    getline(cin>>ws,adress);

}


void person:: putinfor()
    {


            cout<<"\n";

    cout <<"\n\t\t\t"<< left << setw(40) << "FULL NAME" << ": " << full_name << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "AGE" << ": " << age << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "GENDER" << ": " << gender << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "DATE OF BIRTH" << ": " << Bdate << "/" << Bmonth << "/" << Byear << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "CONTACT NO" << ": " << contact << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "DEPARTMENT VISIT" << ": " << depart << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "MEETING DATE MONTH YEAR" << ": " << date << "/" << month << "/" << year << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "ID PROOF AS AADHAR NUMBER" << ": " << aadhar << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "CURRENT ADDRESS" << ": " << adress << endl;
    cout <<"\n\t\t\t"<< left << setw(40) << "FEES" << ": " << fees << endl;
    }

 string  person::  take_dep()
    {
        string dep[]={
                       "general opd",
                       "skin department",
                       "orthology department",
                       "gynecology department",
                       "pediatricks department",
                       "neurology department" ,
                       "dental department"
                       };

        cout<<"\n\n\t\t\tLIST OF DEPARTMENT"<<":"<<endl;
         for (int i = 0; i < 7; i++) {
        cout << "\t" << i + 1 << ")" << dep[i] << endl;
        }

        cout<<"\n\n\tENTER YOUR CHOICE"<<":";
        int num;
        cin>>num;
        while(num < 1 || num > 7)
        {
            cin>>num;
        }
        return dep[num-1];
    }


class emergency;

class patient :public virtual person
{
    protected:
   string visited_doctor;

    static int id;
   int reg_id;
    friend int search_oldp(vector <patient> pat ,int reg_id,int cnt);
    friend int search_emregency(vector <emergency> pat ,int reg_id,int cnt);


    public:
    patient()
    {
        reg_id=id;
        id++;
         fees=500;
    }
    int get_id();
    void putinfor();
    friend class admin;
};
int  patient::get_id()
{
    return reg_id;
}
int patient::id=100;
void   patient::putinfor()
{
cout<<"\t"<<"   -------------------------------------------------------------------------------------"<<endl;

    cout <<"\n\t\t\t"<< left << setw(40) << "YOUR REGISTRATION ID IS" << ": " << reg_id << endl;

       cout <<"\n\t\t\t"<<left << setw(40) << "YOUR VISITING DOCTORS IS" << ": " << visited_doctor<< endl;

     person::putinfor();
        cout<<"\t"<<"   -------------------------------------------------------------------------------------"<<endl;

}

 int search_oldp(vector <patient> pat,int reg,int cnt)
{
    for (int i = 0; i < cnt; i++) {
        if (pat[i].reg_id == reg)
            return i;
    }
    return -1;
}

class emergency :virtual public patient
{
    public:
    string stutas ;
    int room;
    emergency()
    {
        depart="emergency department";
    }
    void putinfor(){
        cout<<"\t"<<"   -------------------------------------------------------------------------------------"<<endl;

        patient::putinfor();
        cout<<"\n\t\t\t"<< left << setw(40) << "status of admition" << ": " << stutas<< endl;
            cout <<"\n\t\t\t" << left << setw(40) << "ROOM NUMBER" << ": " << room << endl;
    cout<<"\t"<<"   -------------------------------------------------------------------------------------"<<endl;

    }
        friend int search_emregency(vector <emergency> pat ,int reg_id,int cnt);
        void set_fees();

};

//    cout<<"\t"<<"   -------------------------------------------------------------------------------------"<<endl;

void emergency:: set_fees()
{
     int ER_visit_fee_max = 500;
    int diagnostic_tests_max = 1000;

    int procedures_max = 500;
    int hospital_admission_max = 5000;
    fees = ER_visit_fee_max+diagnostic_tests_max+procedures_max+hospital_admission_max;
    // Display the fee ranges in a tabular format
    std::cout<<"\n\t\t\t" << std::left << std::setw(25) << "Service" << std::setw(20) << "Maximum Fee (INR)" << std::endl;
    std::cout<<"\t\t\t" << std::setw(25) << std::setfill('-') << "" << std::setw(20) << "" << std::setw(20) << "" << std::setfill(' ') << std::endl;
    std::cout <<"\t\t\t"<< std::left << std::setw(25) << "doctor Visit Fee"<< std::setw(20) << ER_visit_fee_max << std::endl;
    std::cout <<"\t\t\t"<< std::left << std::setw(25) << "Diagnostic Tests"  << std::setw(20) << diagnostic_tests_max << std::endl;
    std::cout <<"\t\t\t"<< std::left << std::setw(25) << "Procedures" << std::setw(20) << procedures_max << std::endl;
    std::cout <<"\t\t\t"<< std::left << std::setw(25) << "Hospital Admission "  << std::setw(20) << hospital_admission_max << std::endl;
    std::cout <<"\t\t\t"<< std::left << std::setw(25) << "total fees  "  << std::setw(20) << fees << " per day" << std::endl;


}

int search_emregency(vector <emergency> pat,int reg,int cnt)
{
    for (int i = 0; i < cnt; i++) {
        if (pat[i].reg_id == reg)
            return i;
    }
    return -1;
}





class doctor:public virtual person
{  char *doc_password;
   protected:
        string degree;
        string id;
        vector<int >patient_id;
        vector <string> patient_name;
        static int count_patient;

 friend class admin;
 public:
 doctor(): doc_password ("doctor@161981")
{}
    doctor(string full_name,unsigned int age,string gender,string depart, int Bdate,int Byear,int Bmonth,
    const char* contact,float fees,const char* aadhar,string adress,string degree,string id)
    {
        this->full_name = full_name;
        this->age = age;
        this->gender = gender;
        this->depart = depart;
        this->Bdate = Bdate;
        this->Byear = Byear;
        this->Bmonth = Bmonth;
        strcpy(this->contact, contact);
        this->fees = fees;
        strcpy(this->aadhar, aadhar);
        this->adress = adress;
        this->degree = degree;
        this->id = id;
    }
    void putinfor();
    void putinfor_patient();
    char * ret_doc_password();
    string ret_doc_id();
};
string  doctor::ret_doc_id()
{
    return id;
}
 char *  doctor::  ret_doc_password()
 {
    return doc_password;
 }
int doctor:: count_patient=0;

void doctor::putinfor_patient()
{
            for(int i=0;i<count_patient;i++)
             {
                  cout <<"\n\t\t\t"<< left << setw(40) << "patient id" << ": " <<patient_id[i]<< endl;
                 cout <<"\n\t\t\t"<< left << setw(40) << "patient  name" << ": " << patient_name[i]<< endl;
             }
}
void doctor::putinfor()
    {cout<<"\t"<<"   -------------------------------------------------------------------------------------"<<endl;

             cout <<"\n\t\t\t"<< left << setw(40) << "doctor id" << ": " <<id << endl;
             cout <<"\n\t\t\t"<< left << setw(40) << "doctor quilifide degree" << ": " << degree<< endl;

            person::putinfor();
            cout<<"\t"<<"   -------------------------------------------------------------------------------------"<<endl;

    }


class medicine
{
    public:
    int num;
    string name;
    string usage;
    string dose;
    int day;
    int price;
   void put_infor_madi();
   void put_header();
};

void medicine::put_header()
{
cout <<"\t\t\t\t"<< left << setw(5) <<"CODE"<<"|   "
             << left << setw(20) <<"MEDICINE"<<"|   "
             << left << setw(15) <<"USAGE"<<"|   "
             << left << setw(8) <<"DOSE"<<"|   "
             << left << setw(6) <<"DAYS"<<"|   "
             << left << setw(3) <<"PRICE"<<endl;
           cout<<"\t"<<"   -------------------------------------------------------------------------------------"<<endl;

}
 void medicine::put_infor_madi()
 {


               cout <<"\t\t\t\t"<< left << setw(5) << num<<"|   "
             << left << setw(20) << name<<"|   "
             << left << setw(15) << usage<<"|   "
             << left << setw(8) << dose<<"|   "
             << left << setw(6) << day<<"|   "
             << left << setw(3) << price
            << endl;

 }



class visitor;
class admin
{
    char admin_password[15];
    public:
    vector<doctor>doc;

    int count_doc;
     admin();

    doctor & set_doctor(int index);
    friend class visitor;
    int search_doc(string id1);
    char * ret_password()
    {
        return admin_password;
    }
    int take_patient (int index,vector<patient> &pat,int patient_cnt);
    int  take_emr_patient(int index ,vector<emergency> &epat,int emp_cnt);
    void take_madicine(string depart,patient & p);

};


 admin::admin():admin_password("admine@161981")
 {
    doc.push_back( doctor("Dr. John Smith" ,45 ,"male","general opd",15,1981,06,"9876543210",1000,"9876543210987","456 Oak Avenue, Town,rajkot","MBBS, Dermatology","Doctor@121"));

   doc.push_back ( doctor("Dr. Emily Johnson", 40, "female", "orthology department", 20, 1982, 8, "9871234560", 1200, "9876543210123",
               "789 Elm Street, City, Mumbai", "MBBS, Orthopedics", "Doctor@122"));

     doc.push_back (doctor("Dr. Michael Brown", 50, "Male", "skin department", 10, 1974, 11, "7654321098", 1500, "4567890123456",
               "789 Pine Street, Village", "MBBS, MS Orthopedics","Doctor@123"));

        doc.push_back (doctor("Dr. Sophia Wilson", 42, "Female", "gynecology department", 5, 1982, 9, "6543210987", 1800, "3456789012345",
               "890 Cedar Avenue, County", "MBBS, MD Obstetrics and Gynecology","Doctor@124"));

        doc.push_back(doctor("Dr. Benjamin Garcia", 48, "Male", "pediatricks department", 12, 1976, 7, "5432109876", 1300, "2345678901234",
               "678 Elm Street, District", "MBBS, Pediatrics","Doctor@125"));

        doc.push_back (doctor("Dr. Olivia Martinez", 40, "Female", "neurology department", 28, 1984, 4, "4321098765", 1600, "1234567890123",
               "123 Maple Avenue, State", "MBBS, Neurology","Doctor@126"));

        doc.push_back (doctor("Dr. Daniel Lee", 55, "Male", "dental department", 18, 1969, 2, "3210987654", 2000, "0123456789012",
               "456 Walnut Street, Province", "BDS, MDS","Doctor@127"));

       doc.push_back ( doctor("Dr. Isabella Thompson", 37, "Female", "general opd", 9, 1987, 12, "2109876543", 1100, "9012345678901",
               "789 Birch Avenue, Region", "MBBS, General Medicine","Doctor@128"));

       doc.push_back ( doctor("Dr. Samuel Harris", 47, "Male", "skin department", 25, 1977, 8, "1098765432", 1400, "8901234567890",
               "234 Cherry Street, Zone", "MBBS, Dermatology","Doctor@129"));

        doc.push_back (doctor("Dr. Mia Rodriguez", 39, "Female", "emergency department", 30, 1985, 1, "9876543210", 1550, "7890123456789",
               "567 Pineapple Avenue, Sector", "MBBS, MS Orthopedics","Doctor@130"));
     doc.push_back ( doctor("Dr. Radhe mohan", 47, "Male", "emergency department", 25, 1977, 8, "1098765432", 1400, "8901234567890",
               "234 Cherry Street, Zone", "MBBS, Dermatology","Doctor@131"));

        doc.push_back (doctor("Dr. shivangi  joshi", 39, "Female", "emergency department", 30, 1985, 1, "9876543210", 1550, "7890123456789",
               "567 Pineapple Avenue, Sector", "MBBS, MS Orthopedics","Doctor@132"));


    count_doc=12;
}

int admin:: search_doc(string id1){
            for(int i=0;i<count_doc;i++)
            {
                if(id1==doc[i].ret_doc_id())
                {
                    return i;
                    break;
                }
            }
            return -1;
 }

    doctor &admin::set_doctor(int index)
    {

        return  doc[index];
    }


   void  admin::take_madicine(string depart,patient & p)
   {

    int f=0;
        if(depart =="general opd")
        {
                medicine med1[5]={
                        {1,"ACETAMINOPHENE","FEVER","325mg",3,12},
                        {2,"PARACETAMOL","HEAADACHE","500mg",2,20},
                        {3,"ASSPIRIN","ARTHRITIS","250mg",4,12},
                        {4,"FENOPROFEN","HEADACHE","250mg",3,20},
                        {5,"ANTIHISTAMINES","COLD-COUGH","250mg",4,15}
                    };
            cout<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t"<<"GENERAL DEPARTMENT"<<endl<<endl<<endl;
            med1[1].put_header();
            for(int i=0;i<5;i++)
            {
              med1[i].put_infor_madi();
            }
            int ch;
            cout<<"\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:"<<endl<<endl ;
            cin>>ch;
            while(ch<0||ch>55555)
            {
                cout<<"\n\nENTER VALID NUMBER:";
                cin>>ch;
            }
            while(ch!=0)
            {
                int rem=ch%10;
                if((rem==1)|| (rem==3))
                        p.fees += 12;
                else if((rem==4)||(rem==2))
                        p.fees += 20;
                else
                      p.fees += 15;
            ch /= 10;}

        }

        else if(depart =="skin department")
        {

                    medicine med2[5]={
                        {1,"PENICILENE","PIMPES","325mg",3,25},
                        {2,"DICLOXALINE","DARK-CIRCLES","500mg",2,15},
                        {3,"AMOXISILIN","VITILIGO","250mg",4,20},
                        {4,"CEFDINIR","ALERGY","250mg",3,15},
                        {5,"CEPHALOSPORINS","INFECTION","250mg",4,25}
                    };
                    cout<<endl<<endl<<endl;
                    cout<<"\t\t\t\t\t\t\t\t"<<"SKIN DEPARTMENT"<<endl<<endl<<endl;
                     med2[1].put_header();
                     for(int i=0;i<5;i++)
                        {
                            med2[i].put_infor_madi();
                         }

                        int ch;
            cout<<"\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:"<<endl<<endl ;
            cin>>ch;

            while(ch!=0)
            {
                int rem=ch%10;
                if((rem==1)|| (rem==5))
                        p.fees += 25;
                else if((rem==4)||(rem==2))
                        p.fees += 20;
                else
                      p.fees += 20;
                     ch /= 10;
            }

        }


         else if(depart =="orthology department")
        {

                    medicine med3[5]={
                        {1,"ASPIRPN","MUSCULER-PAIN","325mg",3,15},
                        {2,"NUPRIN","BACK-PAIN","500mg",2,15},
                        {3,"IBUPROFEN","ARTHRITIS","250mg",4,20},
                        {4,"MOTRIN","OSTEOARTHRITIS","250mg",3,14},
                        {5,"ROFECOXIB","FRACTURE","250mg",4,14}
                    };
            cout<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t"<<"ORTHOLOGY DEPARTMENT"<<endl<<endl<<endl;
            med3[1].put_header();
            for(int i=0;i<5;i++)
            {
              med3[i].put_infor_madi();
            }

                        int ch;
            cout<<"\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:"<<endl<<endl ;
            cin>>ch;
            while(ch<0||ch>55555)
            {
                cout<<"\n\nENTER VALID NUMBER:";
                cin>>ch;
            }
            while(ch!=0)
            {
                int rem=ch%10;
                if((rem==1)|| (rem==2))
                        p.fees += 15;
                else if((rem==4)||(rem==5))
                        p.fees += 14;
                else
                      p.fees += 20;
            ch /= 10;}

        }


         else if(depart =="gynecology department")
        {

                     medicine med4[5]={
                        {1,"ACTIVELLA","ENDOMETRIOSIS","325mg",3,24},
                        {2,"ALORA","FIBOROIDS","500mg",2,20},
                        {3,"AREDIA","CANSER","250mg",4,21},
                        {4,"ARIMIDEX","PCOS","250mg",3,20},
                        {5,"CLEOCIN","MENOPOSE","250mg",4,24}
                    };
            cout<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t"<<"GYNECOLOGY DEPARTMENT"<<endl<<endl<<endl;
            med4[1].put_header();
            for(int i=0;i<5;i++)
            {
              med4[i].put_infor_madi();
            }

                        int ch;
            cout<<"\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:"<<endl<<endl ;
            cin>>ch;
            while(ch<0||ch>55555)
            {
                cout<<"\n\nENTER VALID NUMBER:";
                cin>>ch;
            }
            while(ch!=0)
            {
                int rem=ch%10;
                if((rem==1)|| (rem==5))
                        p.fees += 24;
                else if((rem==4)||(rem=2))
                        p.fees += 20;
                else
                      p.fees += 21;
            ch /= 10;}

        }


         else if(depart =="pediatricks department")
        {

                      medicine med5[5]={
                        {1,"CEPHALEXIN","AMENIA","325mg",3,44},
                        {2,"IBUPROFEN","ASTHMA","500mg",2,20},
                        {3,"AZITHROMYCIN","PNEUMONIA","250mg",4,25},
                        {4,"ARIMIDEX","DOWNS-SYNDROME","250mg",3,20},
                        {5,"PREDNISONE","POLIO","250mg",4,25}
                    };
            cout<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t"<<"PEDIATRICKS DEPARTMENT"<<endl<<endl<<endl;
            med5[1].put_header();
            for(int i=0;i<5;i++)
            {
              med5[i].put_infor_madi();
            }


                        int ch;
            cout<<"\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:"<<endl<<endl ;
            cin>>ch;
            while(ch<0||ch>55555)
            {
                cout<<"\n\nENTER VALID NUMBER:";
                cin>>ch;
            }
            while(ch!=0)
            {
                int rem=ch%10;
                if((rem==3)|| (rem==5))
                        p.fees += 25;
                else if((rem==4)||(rem=2))
                        p.fees += 20;
                else
                      p.fees += 44;
            ch /= 10;}

        }

      else if(depart =="neurology department" )
        {
medicine med6[5]={
                        {1,"TAPOMAX","EPILEPSY","325mg",3,50},
                        {2,"KEPPRA","AUTISM","500mg",2,40},
                        {3,"DEPAKOTE","BARIN-CANSER","250mg",4,45},
                        {4,"LAMOCTAL","ADD","250mg",3,45},
                        {5,"LEVETIRACETAM","MEMORY-LOSS","250mg",4,40}
                    };

            cout<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t"<<"NEUROLOGY DEPARTMENT"<<endl<<endl<<endl;
            med6[1].put_header();
            for(int i=0;i<5;i++)
            {
              med6[i].put_infor_madi();
            }

                        int ch;
            cout<<"\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:"<<endl<<endl ;
            cin>>ch;
            while(ch<0||ch>55555)
            {
                cout<<"\n\nENTER VALID NUMBER:";
                cin>>ch;
            }
            while(ch!=0)
            {
                int rem=ch%10;
                if((rem==2)|| (rem==5))
                        p.fees += 40;
                else if((rem==4)||(rem=3))
                        p.fees += 45;
                else
                      p.fees += 50;
            ch /= 10;}

        }



    //                    "dental department"

     else if(depart =="dental department" )
        {
medicine med7[5]={
                        {1,"AMOXICILIN","EPILEPSY","325mg",3,15},
                        {2,"PENICINE","AUTISM","500mg",2,30},
                        {3,"CEVIMELINE","BARIN-CANSER","250mg",4,23},
                        {4,"NAPROXEN","ADD","250mg",3,30},
                        {5,"CLINDAMYCINE","MEMORY-LOSS","250mg",4,23}
                    };
            cout<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t"<<"DENTAL DEPARTMENT"<<endl<<endl<<endl;
            med7[1].put_header();
            for(int i=0;i<5;i++)
            {
              med7[i].put_infor_madi();
            }

                        int ch;
            cout<<"\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:"<<endl<<endl ;
            cin>>ch;
            while(ch<0||ch>55555)
            {
                cout<<"\n\nENTER VALID NUMBER:";
                cin>>ch;
            }
            while(ch!=0)
            {
                int rem=ch%10;
                if((rem==2)|| (rem==4))
                        p.fees += 30;
                else if((rem==5)||(rem=3))
                        p.fees += 23;
                else
                      p.fees += 15;
            ch /= 10;}

        }

   }
int admin:: take_emr_patient(int index ,vector<emergency> &epat,int emp_cnt)
    {
        emergency p;
        int in=-1;
        doctor& d= doc[index];
        for(int i=0;i<emp_cnt;i++)
        {
            if((d.depart==epat[i].depart)&&((epat[i].visited_doctor).empty()))
            {
               p=epat[i];
               in=i;
                break;
            }
        }
        if(in!=-1)
            {   system("cls");
                  p.putinfor();
                   cout<<"\n\tYOUR PATIENT INFORMATION";
                   cout<<"PRESS ANY KEY FOR FURTHER:";
                 _getch();
                 p.visited_doctor  =  d.full_name;
                //(d.patient_id).push_back(p.id);

                d.count_patient++;

                epat[in]=p;
      }
        return in;

    }

int  admin::take_patient (int index,vector<patient> &pat,int patient_cnt)
{        patient p;
        int in=-1;
        doctor& d= doc[index];
        for(int i=0;i<patient_cnt;i++)
        {
            if((d.depart==pat[i].depart)&&((pat[i].visited_doctor).empty()))
            {
               p=pat[i];
               in=i;
                break;
            }

         }



      if(in!=-1)
      { system("cls");
      cout<<"\n\tYOUR PATIENT INFORMATION";
         p.putinfor();
         cout<<"PRESS ANY KEY FOR FURTHER:";
         _getch();
         p.visited_doctor  =  d.full_name;
        (d.patient_id).push_back(p.id);
        (d.patient_name).push_back(p.full_name);
        d.count_patient++;
        system("cls");
       take_madicine(p.depart,p);
         pat[in]=p;
      }
       return in;
}







class visitor
{
    public:
   void put_infor_visitor();
   void menu_visitor();

};
 void visitor::menu_visitor()
{ system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t1) OUR FACILITIES"<<endl<<"\t\t\t2) OUR LABORATORY"<<endl<<
    "\t\t\t3) INSTRUMENTS"<<endl<<"\t\t\t4) DOCTORS INFORMATIONS"<<endl<<"\t\t\t5) BACK"<<endl<<endl;
}

void visitor::put_infor_visitor()
{


    menu_visitor();
    int n_visitor;
    cout<<"\tENTER YOUR CHOICE: ";
    cin>>n_visitor;


    switch(n_visitor)
  {
    case 1:

    {
        system("cls");

              cout<<"\t\t\t\t\t\t\t\tOUR FACILITIES "<<endl;cout<<endl<<endl;cout<<endl<<endl;

    cout <<"\n\t"<< left << setw(30) << "Emergency Department (ED)" <<"  |   the first point of contact for people who are experiencing a medical emergency." ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   staffed by specially trained doctors and nurses who can provide immediate care\n";
    cout <<"\t"<< left << setw(30)<<" "<<"  |    for a wide range of conditions\n";

    cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";

    cout <<"\n\t"<< left << setw(30) << "Operating Rooms (ORs)" <<"  |   ORs are sterile rooms where surgeons perform operations.They are" ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   equipped with specialized equipment, such as surgical tables,anesthesia machines,\n ";
    cout <<"\t"<< left << setw(30)<<" "<<"  |   range of conditions\n";

       cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";

    cout <<"\n\t"<< left << setw(30) << "Intensive Care Units (ICUs)" <<"  |   ICUs are for patients who are critically ill or" ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   injured and require constant monitoring and care. \n";
    cout <<"\t"<< left << setw(30)<<" "<<"  |   They are staffed by specially trained nurses and respiratory therapists.\n";

        cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";

    cout <<"\n\t"<< left << setw(30) << "Medical-Surgical Units (MSUs)" <<"  |   MSUs are where patients are admitted for a variety of medical and surgical conditions." ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   They are staffed by nurses who provide care for patients before, during,\n";
    cout <<"\t"<< left << setw(30)<<" "<<"  |   and after their stay in the hospital.\n";

        cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";

    cout <<"\n\t"<< left << setw(30) << "Outpatient Departments (OPDs)" <<"  |   OPDs provide care for patients who do not require an overnight" ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   stay in the hospital.They may offer a variety of services,\n";
    cout <<"\t"<< left << setw(30)<<" "<<"  |    such as primary care, specialty care, and diagnostic testing.\n";

        cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";


    cout <<"\n\t"<< left << setw(30) << "Diagnostic and Treatment Facilities" <<"  |   Hospitals also have a variety of diagnostic and" ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   treatment facilities, such as radiology departments,\n";
    cout <<"\t"<< left << setw(30)<<" "<<"  |   laboratories, and pharmacies.\n";


      _getch();
    break;
    }


    case 2:
    {
        system("cls");
     cout<<"\t\t\t\t\t\t\t\tOUR LABORATORY "<<endl;cout<<endl<<endl;cout<<endl<<endl;
        cout<<"\t---> There are many different types of hospital laboratory tests, which can be done in our hospital"<<endl<<endl;

    cout <<"\n\t"<< left << setw(30) << "Blood tests" <<"  |   These tests can provide information about a wide range of health conditions" ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   including anemia, infection, diabetes, and kidney disease. at Rs.150\n";

    cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";

    cout <<"\n\t"<< left << setw(30) << "Urinalysis" <<"  |   This test analyzes urine to check for abnormalities that may indicate a urinary " ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   tract infection,indicate a urinary tract infection,kidney stones, or diabetes.at Rs.450\n ";

       cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";

    cout <<"\n\t"<< left << setw(30) << "Microbiology tests" <<"  |   These tests are used to identify bacteria, viruses, and other microorganisms that " ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   may be causing an infection.at Rs.200\n";

        cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";

    cout <<"\n\t"<< left << setw(30) << "Histology and cytology" <<"  |   These tests involve examining tissues or cells under a microscope to look for" ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   such as cancer.at Rs.200 \n";

        cout<<"     -------------------------------------------------------------------------------------------------------------------------------------";

    cout <<"\n\t"<< left << setw(30) << "Chemistry tests" <<"  |   These tests measure the levels of chemicals in the blood, such as electrolytes, hormones," ;
    cout <<"\n\t"<< left << setw(30)<<" "<<"  |   and enzymes.at Rs.200\n";
 cout<<endl<<endl<<endl;
        _getch();
        break;
    }


        case 3:
    {
            system("cls");
      cout << "\n\n\t\t\t\t\t\t\t INSTRUMENTS\n\n";

    cout << left << setw(35) << "* TECHNICAL INSTRUMENTS" << "| X-ray machines: Generate images of bones and soft tissues." << endl << endl;
    cout << left << setw(35) << " " << "| CT scanners (Computed Tomography): Provide detailed cross-sectional images." << endl << endl;
    cout << left << setw(35) << " " << "| Ultrasound machines: Use sound waves to generate images of organs and tissues." << endl << endl;
    cout << left << setw(35) << " " << "| MRI machines (Magnetic Resonance Imaging): Create detailed images of organs." << endl << endl;

    cout << "-----------------------------------------------------------------------------" << endl << endl;

    cout << left << setw(35) << "* Surgical Instruments:" << "| X-ray machines: Generate images of bones and soft tissues." << endl << endl;
    cout << left << setw(35) << " " << "| Scalpels: Sharp blades for precise cutting of tissues." << endl << endl;
    cout << left << setw(35) << " " << "| Forceps: Grasping instruments for holding tissues or sutures (stitches)." << endl << endl;
    cout << left << setw(35) << " " << "| Scissors: Specialized scissors for cutting different types of tissues." << endl << endl;
    cout << left << setw(35) << " " << "| Sutures (stitches) and Needles: Used to close wounds and connect tissues." << endl << endl;
    cout << left << setw(35) << " " << "| Electrosurgical Unit (ESU): Uses electrical current for surgical purposes." << endl << endl;
    cout << left << setw(35) << " " << "| Retractors: Hold tissues apart for better visibility during surgery." << endl << endl;

    cout << "-----------------------------------------------------------------------------" << endl << endl;

    cout << left << setw(35) << "* General Hospital Instruments:" << "| Thermometers: Measure body temperature." << endl << endl;
    cout << left << setw(35) << " " << "| Sphygmomanometers: Measure blood pressure." << endl << endl;
    cout << left << setw(35) << " " << "| Otoscopes and Ophthalmoscopes: Examine ears and eyes, respectively." << endl << endl;
    cout << left << setw(35) << " " << "| Syringes and Needles: Used for injecting medications or withdrawing fluids." << endl << endl;
    cout << left << setw(35) << " " << "| Blood Collection Tubes and Needles: Used for blood sample collection." << endl << endl;

    _getch();
        break;
    }

     case 4:
    {
        //doctor

        admin a;
        for(int i=0;i<a.count_doc;i++)
        { system("cls");
            (a.doc[i]).putinfor();
            cout<<endl<<endl;
            cout<<" ENTER ANY KEY TO VISIT NEXT DOCTOR ";
            _getch();
        }

        break;
    }

    case 5:
    {

        break;
    }

    default:
    {
        cout<<"\tENTER VALID INFORMATION:";
       _getch();
        break;
    }

   }
}







int  available_room(int arr[],int n)
{   int flage=-1;
    cout<<"\n\n\t\tAVAILABLE ROOMS\t:\t";
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            cout<<i+1<<" ";
            flage=1;
        }
        return flage;
}

int  add_room(int arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
          if(arr[i]==0)
          { arr[i]=1;
            break;
          }
    }
    return i;
}

int main()
{




      vector <patient> pat;




   int patient_cnt=0;
   int room_num[5]={0};
    int emp_cnt=0;

   vector <emergency> epat;
   while(1)
  {
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t ----------------------------";
        cout<<"\n \t\t\t\t   MAHAKAL HOSPITAL  ";
        cout<<"\n \t\t\t\t ----------------------------";
        cout<<"\n\n\t\t WHO ARE YOU?:";
        cout<<"\n\n\t\t 1)RECEPTIONIST"
            <<"\n\t\t 2)DOCTOR"
            << "\n\t\t 3)ABOUT US"
              << "\n\t\t 4)EXIT "<<"\n\n";
            cout<<setw(40)<<"ENTER YOUR CHOICE HERE: ";
            unsigned int n;
            cin>>n;
    if(n==1)
    {
        //ADMINE
        system("cls");
                cout<<"\n\n\t\t\tRECEPTIONIST";
        char password[20]={};
         cout<<"\n\n\n\t\tIF YOU ARE RECEPTIONIST THEN ENTER YOUR PASSWORD:";
         int i = 0;
            char ch;
            while (true) {
                                    ch = _getch();
                         if (ch == '\r')
                                break;
                        else if (ch == '\b' && i > 0) {
                                cout << "\b \b";
                                i--;
                        }
                        else if (i < 19) {
                             password[i++] = ch;
                             cout << '*';
                                }
                    }
    password[i] = '\0'; // Null-terminate the password string
        admin a;
    if(!strcmp(password,a.ret_password()))
    {

        cout<<"\n\n\n\t\t\tYOUR PASSWORD VERIFIED PERFACTLY PLECE ENTER ANY KEY TO CONTINEU FURTHER ....." <<endl<<endl;
            _getch();
        while(true)
        {   system("cls");
            menu();
            cout<<setw(40)<<"\tENTER YOUR CHOICE HERE: ";
            unsigned int n;
            cin>>n;
            while(n < 1 || n > 7)
            { system("cls");
                menu();
                cout<<"\tenter vadild information:";
                cin>>n;
            }

                if(n==1)
                //for new patient
                {

                     patient temp;
                     admin t;
                     system("cls");
                    temp.getinfor();
                    pat.push_back(temp);

                pat[patient_cnt].change_depart();
                patient_cnt++;

                 system("cls");
                cout<<"\n\n\t\t\tYOUR REGISTER ID IS "<<pat[patient_cnt-1].get_id()<<endl;


                    cout<<"\t\t\tYOU ARE RESISTERED SUCSESSFULLY YOUR DETAILS :"<<endl<<endl;
                     pat[patient_cnt-1].putinfor();
                     cout<<"PRESS ANY KEY...";
                     _getch();

                }
                else if(n==2)
                {
                    int reg;
                    //for old patient
                    system("cls");
                    cout<<"\n\tPLEASE ENTER YOUR REG_ID"<<"\t\t";
                    cin>>reg;
                    int index = search_oldp(pat, reg, patient_cnt);
                    if (index != -1)
                     {
                        patient temp = pat[index];
                        pat.push_back(temp);

                         cout<<"\n\n\t\t\tSELECT RIGHT ONE WHICH IS ASKED:"<<endl<<endl;
                        cout<<"\n\t\t\t1)DOCTOR HAD GIVEN YOU AN APPOINTMENT EARLIER."<<endl;
                         cout<<"\t\t\t2)YOU WANT TO GO FOR ANOTHER DEPARTEMENT."<<endl;

                        int choice;
                        cout<<"\n\n\tENTER YOUR CHOICE:\t";
                        cin>>choice;


                         if(choice==2)
                        {
                            pat[patient_cnt].change_depart();
                        }
                        else if(choice == 1)
                        {
                         //for apointment
                         }

                        else {continue;}

                            system("cls");
                         cout << "\n\n\t\tYOUR REGISTER ID IS " << pat[patient_cnt].get_id() << endl;

                         patient_cnt++;
                            cout << "\t\tYOU ARE REGISTERED SUCCESSFULLY. YOUR DETAILS:" << endl << endl;
                        pat[patient_cnt-1].putinfor();
                            _getch();
                           cout<<"PRESS ANY KEY...";

                        }
                    else {
                        cout << "\t\t\t\tPATIENT NOT FOUND PLESE ENTER ANY KEY FOR MENU." << endl;
                        _getch();
                         }
            }


                else if(n==7)
                {  //for exit

                    break;
                }

                else if(n==4)
                {
                //for emergency
                system("cls");
                   int y= available_room(room_num,5);
                   _getch();
                    if(y==-1)
                        {
                           cout<<"\n\n\tSORRY,THERE ARE NO AVAILABLE EMERGENCY ROOMS TODAY PRESS TO CONTINEUE"<<endl;
                            _getch();
                            continue;
                        }
                         y=add_room(room_num,5);

                         emergency temp;
                         system("cls");
                         cout<<"\n\n\t YOU ARE ALLOCATED ROOM NUMBER :"<<y+1;
                        temp.getinfor();
                        temp.set_fees();
                        temp.stutas="admited";
                        epat.push_back(temp);
                        epat[emp_cnt].room=y+1;

                             system("cls");
                        cout<<"\n\n\t\t\tYOUR REGISTER ID IS "<<epat[emp_cnt].get_id()<<endl;
                        temp.set_fees();

                         epat[emp_cnt].putinfor();
                         cout<<"ENTER ANY KEY FOR FURTHER:"<<endl;
                         _getch();
                        emp_cnt++;


                }

                else if(n==3)
                {
                //for visitor
                  visitor v;

                  v.put_infor_visitor();
                }

                else if(n==6)
                {   int reg;
                //for checkout patient
                 system("cls");
                    cout<<"\n\tPLEASE ENTER YOUR REG_ID"<<"\t\t";
                    cin>>reg;
                    int index=search_emregency(epat,reg,emp_cnt);
                    if(index==-1)
                    {
                        cout<<"\n\tPATIENT NOT FOUND PRESS ANY KEY FOR FURTHER PROCESS";
                        _getch();
                        continue;
                    }
                    if( epat[index].stutas=="checkout")
                    {
                        cout<<"\n\tPATIENT IS ALREADY CHECKOUT PRESS ANY KEY FOR FURTHER PROCESS ";
                        _getch();
                        continue;
                    }
                    epat[index].stutas="checkout";
                    room_num[epat[index].room-1]=0;
                         cout<<"\n\tYOU ARE  CHECKOUT SUCSESSFULY PRESS ANY KEY FOR FURTHER PROCESS ";
                        _getch();
                }

                 else if(n==5)
                {
                    //FOR VIEW PATIENT
                    system("cls");
                    cout<<"\n\n\n\n\t\t\tWHICH INFORMATION YOU WANT TO VIEW :"<<endl;
                    menu_view_pat();
                    int v_p=0;
                    cout<<"\tENTER YOUR CHOICE HERE:\t";
                    cin>>v_p;
//------------------------------------------------------------------------------------------
                    while((v_p<0) || (v_p>6))
                    {
                        cout<<"\tENTER VALID CHOICE HERE:\t";
                        cin>>v_p;
                       }

                        if(v_p==1)
                        {
                                //for normal list
                            if(patient_cnt !=0 )
                           {
                                cout<<"\t\tVISITED NORMAL PATIENT  LIST IS:"<<endl << endl;
                                for (int i = 0; i < patient_cnt; i++)
                                { system("cls");
                                     cout << "\n\n\n\tpatient " << i + 1 << ":" << endl;
                                    pat[i].putinfor();
                                    cout<<"press any key for next...";
                                    _getch();
                                }
                            }
                            else{
                                cout<<"\t AT THIS TIME PATIENT IS NOT COME"<<endl;
                                 cout<<"press any key for menu...";
                                    _getch();
                            }
                        }

                       else if(v_p==2)
                        {
                                 //for emergency list
                                if(emp_cnt!=0 )
                                   { cout<<"\t\tVISITED EMERGENCY  PATIENT  LIST IS:"<<endl << endl;
                                            for (int i = 0; i < emp_cnt; i++)
                                        {           system("cls");
                                                cout << "\n\n\temergency patient " << i + 1 << ":" << endl;
                                                epat[i].putinfor();
                                                 cout<<"press any key for next...";
                                                   _getch();
                                        }
                                   }
                                 else{
                                cout<<"\t AT THIS TIME PATIENT IS NOT COME"<<endl;
                            }
                        }

                        else if(v_p==3)
                        {
                                 //for all list

                           if(patient_cnt !=0 )
                           {
                                cout<<"\t\tVISITED NORMAL PATIENT  LIST IS:"<<endl << endl;
                                for (int i = 0; i < patient_cnt; i++)
                                { system("cls");
                                     cout << "\n\n\n\tpatient " << i + 1 << ":" << endl;
                                    pat[i].putinfor();
                                     cout<<"press any key for next...";
                                    _getch();
                                }
                            }
                            else{
                                cout<<"\t AT THIS TIME PATIENT IS NOT COME"<<endl;
                                 cout<<"press any key for next...";
                                    _getch();
                            }

                             if(emp_cnt!=0 )
                                   { cout<<"\t\tVISITED EMERGENCY  PATIENT  LIST IS:"<<endl << endl;
                                            for (int i = 0; i < emp_cnt; i++)
                                        {       system("cls");
                                                cout << "\n\n\temergency patient " << i + 1 << ":" << endl;
                                                epat[i].putinfor();
                                                 cout<<"press any key for next...";
                                                _getch();
                                        }
                                   }
                                 else{
                                cout<<"\t AT THIS TIME PATIENT IS NOT COME"<<endl;
                                 cout<<"press any key for next...";
                                    _getch();
                            }
                        }

                        else if(v_p==5)
                        {
                                  //for  one emergency  list
                                  if(emp_cnt!=0)

                                    {    int reg_id;
                                            cout<<"\t ENTER REGISTER ID OF EMERGANCY PATIENT :\t";
                                            cin>>reg_id;
                                            int index = search_emregency(epat, reg_id, emp_cnt);
                                            if(index != -1)
                                            {    system("cls");
                                            epat[index].putinfor();
                                             cout<<"press any key for next...";
                                             _getch();
                                            }
                                            else
                                            {
                                                cout<<"\tEMERGENCY PATIENT NOT FOUND OF THAT REGIDTERED ID PLEASE TRY AGAIN...."<<endl;
                                                   cout<<"press any key for continue..";
                                             _getch();
                                                continue;
                                            }
                                    }
                                    else{
                                         cout<<"\t AT THIS TIME PATIENT IS NOT COME"<<endl;
                                            cout<<"press any key for continue..";
                                             _getch();
                                        }
                        }

                        else if(v_p==4)
                        {//for  one normal list

                                if(patient_cnt != 0)

                                    {    int reg_id;
                                        cout<<"\t ENTER REGISTER ID OF PATIENT :\t";
                                        cin>>reg_id;
                                        int index = search_oldp(pat, reg_id, patient_cnt);
                                        if(index != -1)
                                        { system("cls");
                                        pat[index].putinfor();
                                           cout<<"press any key for continue..";
                                             _getch();
                                        }
                                        else
                                        {
                                            cout<<"PATIENT NOT FOUND OF THAT REGIDTERED ID PLEASE TRY AGAIN...."<<endl;
                                               cout<<"press any key for continue..";
                                             _getch();
                                            continue;
                                        }
                                    }
                                    else{
                                         cout<<"\t AT THIS TIME PATIENT IS NOT COME"<<endl;
                                            cout<<"press any key for continue..";
                                             _getch();
                                        }
                        }

                       else
                       {
                                //exit
                                continue;
                       }

                }

        }
    }
    else
    {
        cout<<"\n\n\t\tYOUR PASSWORD ID INCORRECT PLEASE PRESS ANY KEY AND RETURN TO THE MENU......"<<endl;
        _getch();
    }
 }







    else if(n==2)
    {
             //for doctor
                char password[20]={};
            system("cls");
            cout<<"\n\t\t IF YOU ARE DOCTOR THEN ENTER YOUR PASSWORD:";
                int i = 0;
            char ch;
            while (true) {
             ch = _getch();
                if (ch == '\r')
                        break;
                else if (ch == '\b' && i > 0) {
                        cout << "\b \b";
                         i--;
                        }
                    else if (i < 19)
                     {
                             password[i++] = ch;
                             cout << '*';
                     }
    }
    password[i] = '\0';
        doctor d;
    if(!strcmp(password,d.ret_doc_password()))
    {
        cout<<"\n\n\t\t your password is verified successfully please enter any key for further"<<endl;
        _getch();
        system("cls");
        cout<<"\n\n\tENTER YOUR IDENTITY ID:";
            string id;
            cin>>id;
            admin a;
          int index= a.search_doc(id);

            if(index==-1)
            {
                cout<<endl<< " \tid was not found ..pleace try again with corrrect id,";
                _getch();
                continue;
            }
            else
            {   while(1)
                {
                    system("cls");
                    doctor d=a.set_doctor(index);
                    cout<<"\n\n\t\t WHICH OPTIONT YOU WANT: "<<endl;
                    cout<<"\t\t 1)TO SHOW YOUR INFORMATION :"<<endl;
                    cout<<"\t\t 2)TAKE YOUR PATIENT :"<<endl;
                    cout<<"\t\t 3)BACK "<<endl;
                    cout<<endl<<"\tENTER YOU CHOCE HERE:";
                            int choice;
                            cin>>choice;
                        if(choice==1)
                        {
                            doctor d=a.set_doctor(index);
                                system("cls");
                            d.putinfor();
                            _getch();
                        }

                        else if(choice==2)
                        {
                           doctor d=a.set_doctor(index);
                           if(d.get_dep()!="emergency department")
                           // take your patient
                         {  admin a;
                            int in= a.take_patient(index ,pat,patient_cnt);
                                if(in!=-1)
                               {system("cls");
                                 pat[in].putinfor();
                                 cout<<"press any key for further";
                                 _getch();
                                 }
                                 else
                                cout<<"\tPATIENT OF YOUR DEPARTMENT TILL NOT COME PLEASE PRESS ANY KEY FOR FURTHER...";
                                _getch();
                           }

                           else
                           {
                            //for emergency department
                                    admin a;
                                     int in= a.take_emr_patient(index ,epat,emp_cnt);
                                        if(in!=-1)
                                       {
                                        system("cls");
                                        epat[in].set_fees();
                                        epat[in].putinfor();
                                         cout<<"PRESS ANY KEY FOR FURTHER:";
                                            _getch();
                                        }
                                         else
                                        cout<<"\tPATIENT OF YOUR DEPARTMENT TILL NOT COME PLEASE TRY AGAIN LATER...";
                                         cout<<"PRESS ANY KEY FOR FURTHER:";
                                             _getch();

                           }
                        }

                        else if(choice==3)
                        {
                            //exit
                            break;
                        }
                        else {
                            cout<<"\tENTER VALIDE CHOICE";
                        }
                }
            }


    }
    else
    {
            cout<<"\n\t\t your password is invalid please try again later..\n\n";
             cout<<"PRESS ANY KEY FOR FURTHER:";
                 _getch();
            continue;

     }

    }



    else if(n==4)
    { //exit
            system("cls");
            cout<<"\n\n\n\n\t\t\tARE YOU REALY WANT TO EXIT ?";
            cout<<"\n\t\t\tPRESS 'Y' FOR EXIT OR PRESS 'N' FOR EXIT :  ";
            char c;
            cin>>c;
            while((c!='y')&&(c!='n')&&(c!='Y')&&(c!='N'))
            {   getchar();
                validinfor();

                cin>>c;
            }
                if(c=='y'||c=='Y')
                {
                    _getch();
                    break;
                }

                else{
                    continue;
                }

    }
        else if(n==3)
        {
            system("cls");
            aboutus();
            cout<<"PLESE ENTER  FOR MENU :";
            _getch();
        }

    else
    {
            cout<<"\t PRESS ANY KEY AND ENTER VALID CHOICE.....";

           _getch();
           continue;
    }

}




 return 0;
}
void menu ()
{
    cout<<"\n\n\n\n\t\t\t\t ------------";
    cout<<"\n \t\t\t\t WHO ARE YOU?";
    cout<<"\n \t\t\t\t ------------";
    cout<<"\n\t\t 1)NEW PATIENT"
        <<"\n\t\t 2)OLD PATIENT"
        <<"\n\t\t 3)VISITOR "
        <<"\n\t\t 4)EMERGENCY PATIENT "
        << "\n\t\t 5)VIEW RECORD"
        << "\n\t\t 6)CHECKOUT EMERGENCY PATIENT "
        << "\n\t\t 7)BACK"<<"\n\n";
}

void menu_view_pat()
{
     cout<<"\n\n";

    cout<<"\n\t\t 1)NORMAL PATIENTS LIST "
        <<"\n\t\t 2)EMERGENCY PATIENTS LIST"
        <<"\n\t\t 3)ALL PATIENTS  LIST"
        <<"\n\t\t 4)PERTICULAR  ANY ONE NORMAL PATIENT "
        <<"\n\t\t 5)PERTICULAR  ANY ONE EMERGENCY  PATIENT "
        << "\n\t\t 6)BACK"<<"\n\n\n\n";

}