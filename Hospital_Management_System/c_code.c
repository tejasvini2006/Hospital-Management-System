#include <stdio.h>
#include <time.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>


 int date,month,year;
 // Get the current time
 void set_time()
 {
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);         // Get the current time
    localTime = localtime(&currentTime); // Convert the current time to the local time

    // Extract date, month, and year
     date = localTime->tm_mday;       // Day of the month (1-31)
     month = localTime->tm_mon + 1;  // Month (0-11, add 1 for January being 1)
     year = localTime->tm_year + 1900; // Year since 1900



}

void menu() {
    printf("\n\n\n\n\t\t\t\t ------------");
    printf("\n \t\t\t\t WHO ARE YOU?");
    printf("\n \t\t\t\t ------------");
    printf("\n\t\t 1)NEW PATIENT"
        "\n\t\t 2)OLD PATIENT"
        "\n\t\t 3)VISITOR "
        "\n\t\t 4)EMERGENCY PATIENT "
        "\n\t\t 5)VIEW RECORD"
        "\n\t\t 6)CHECKOUT EMERGENCY PATIENT"
        "\n\t\t 7)BACK" "\n\n");
}

void menu_view_pat() {
    printf("\n\n");

    printf("\n\t\t 1)NORMAL PATIENTS LIST "
        "\n\t\t 2)EMERGENCY PATIENTS LIST"
        "\n\t\t 3)ALL PATIENTS  LIST"
        "\n\t\t 4)PERTICULAR  ANY ONE NORMAL PATIENT "
        "\n\t\t 5)PERTICULAR  ANY ONE EMERGENCY  PATIENT "
        "\n\t\t 6)BACK" "\n\n\n\n");
}

void validinfor() {
    printf("\n\tENTER VALID INFORMATION WHICH IS ASKED:\n");
}

void aboutus() {
   printf("\n \t\t\t\t ABOUT US");
    printf("\n \t\t\t\t ---------");
    printf("\n\n\n\n");
    printf("\t%-30s: %s\n", "PROJECT FOR", "HOSPITAL MANAGEMENT SYSTEM");
    printf("\n\n\n\t%-30s: %s\n", "PROJECT CREATED BY", "GOSWAMI PRIYA HARESHBHARTHI");
    printf("\t%-30s: %s\n", "", "KANANI TEJASVINI RAKESHBHAI");
    printf("\n\n\n\t%-30s: %s\n", "GUIDED BY", "JIGNESHKUMAR SHAH");
    printf("\n\n\n\t%-30s: %s\n", "USERS OF PROJECT", "DOCTORS AND RECEPTIONIST");
    printf("\n\n\n\t%-30s: %s\n", "MAIN PURPOSE OF DEVELOPMENT", "the development of Hospital Management System aims to modernize and optimize");
    printf("\t%-30s%s\n", "", "operations of hospitals, ultimately leading to improved patient outcomes, better");
    printf("\t%-30s%s\n", "", "resource management, and enhanced overall efficiency.");
    printf("\n\n\n\t%-30s: %s\n", "USES OF THE PROJECT", "Registration, Appointment Scheduling, Billing and Invoicing, Data Analytics");
    printf("\t%-30s%s\n", "", "information for visitors, Staff Scheduling and Pharmacy Management");
    printf("\n\n\n\t%-30s: %s\n", "OUR CONTACT NUMBER", "8780732104");
    printf("\t%-30s: %s\n", "", "6353896459");
    printf("\n\n\n\t%-30s: %s\n", "OUR EMAIL ID", "priyahgoswami1981@gmail.com");
    printf("\t%-30s: %s\n", "", "tejkanani2006@gmail.com");
    printf("\n\n IF ANYONE WANT TO GIVE US SUGGESTIONS THEN PLEASE CONTACTUS\n\n");
}


int check_mobile_no(char contact[11]) {
    int i = 0;
    while (contact[i] != '\0' && isdigit(contact[i])) {
        i++;
    }
    return (i == 10);
}


int check_adhar(char adhar[13]) {
    int i = 0;
    for (i = 0; (adhar[i] != '\0') && (isdigit(adhar[i])); i++);
    while (adhar[i] != '\0' && isdigit(adhar[i])) {
        i++;
    }
    return (i == 12);
}

int check_age(unsigned int age) {
    return (age <= 100);
}

int check_bdate(int Bdate, int Bmonth, int Byear) {
    return !(Bdate > 31 || Bmonth > 12 || Byear < 1950 || Byear > 2024);
}

int check_gender(char* gender) {
    return (strcmp(gender, "female") == 0 || strcmp(gender, "male") == 0 || strcmp(gender, "FEMALE") == 0 || strcmp(gender, "MALE") == 0);
}



typedef struct person
 {
    char full_name[100];
    unsigned int age;
    char gender[10];
    char depart[100];
    int Bdate;
    int Byear;
    int Bmonth;
    char contact[11];
    float fees;
    char aadhar[13];
    char adress[100];
}person;

void getinfor(struct person* p)
{
    getchar();
    printf("\n\n\t%-40s", "ENTER YOUR FULL NAME:");
    fgets(p->full_name, sizeof(p->full_name), stdin);

    printf("\n\t%-40s", "ENTER YOUR AGE:");
    scanf("%u", &p->age);
    while (!check_age(p->age)) {
        validinfor();
        printf("\n\t%-40s", "ENTER YOUR AGE AGAIN:");
        scanf("%u", &p->age);
    }
    getchar();
    printf("\n\t%-40s", "ENTER YOUR GENDER:");
    scanf("%s",p->gender);
    while (!check_gender(p->gender)) {
        validinfor();
         getchar();
        printf("\n\t%-40s", "ENTER YOUR GENDER AGAIN:");
       scanf("%s",p->gender);
    }
         getchar();
    printf("\n\t%-40s", "ENTER YOUR DATE OF BIRTH:");
    scanf("%d%d%d", &p->Bdate, &p->Bmonth, &p->Byear);
    while (!check_bdate(p->Bdate, p->Bmonth, p->Byear)) {
        validinfor();
        printf("\n\t%-40s", "ENTER BIRTH DATE MONTH YEAR AGAIN:");
        scanf("%d%d%d", &p->Bdate, &p->Bmonth, &p->Byear);
    }
     getchar();
    printf("\n\t%-40s", "ENTER YOUR EMERGENCY CONTACT NO:");
    scanf("%s", p->contact);

    while (!check_mobile_no(p->contact)) {
        validinfor();
         getchar();
        printf("\n\t%-40s", "ENTER YOUR EMERGENCY CONTACT NO AGAIN:");
        scanf("%s", p->contact);
    }
 getchar();
    printf("\n\t%-40s", "ENTER AADHAR CARD NUMBER:");
    scanf("%s", p->aadhar);
    while (!check_adhar(p->aadhar)) {
        validinfor();
        printf("\n\t%-40s", "ENTER AADHAR CARD ANUMBER AGAIN:");
        scanf("%s", p->aadhar);
    }
 getchar();
    printf("\n\t%-40s", "ENTER YOUR CURRENT ADRESS:");
    fgets(p->adress, sizeof(p->adress), stdin);
}

void putinfor(struct person* p) {
    set_time();
    printf("\n");

    printf("\n\t%-40s%s\n", "FULL NAME:", p->full_name);
    printf("\n\t%-40s%u\n", "AGE:", p->age);
    printf("\n\t%-40s%s\n", "GENDER:", p->gender);
    printf("\n\t%-40s%d/%d/%d\n", "DATE OF BIRTH:", p->Bdate, p->Bmonth, p->Byear);
    printf("\n\t%-40s%s\n", "CONTACT NO:", p->contact);
    printf("\n\t%-40s%s\n", "DEPARTMENT VISIT:", p->depart);
    printf("\n\t%-40s%d/%d/%d\n", "MEETING DATE MONTH YEAR:", date, month, year);
    printf("\n\t%-40s%s\n", "ID PROOF AS AADHAR NUMBER:", p->aadhar);
    printf("\n\t%-40s%s\n", "CURRENT ADDRESS:", p->adress);
    printf("\n\t%-40s%f\n", "FEES:", p->fees);
}

char* take_dep() {
    char* dep[] = {
        "general opd",
        "skin department",
        "orthology department",
        "gynecology department",
        "pediatricks department",
        "neurology department",
        "dental department"
    };

    printf("\n\n\t\t\tLIST OF DEPARTMENT:\n");
    for (int i = 0; i < 7; i++) {
        printf("\t%d)%s\n", i + 1, dep[i]);
    }

    printf("\n\n\tENTER YOUR CHOICE:");
    int num;
    scanf("%d", &num);
    while (num < 1 || num > 7) {
        scanf("%d", &num);
    }
    return dep[num - 1];
}

static int id=100;
typedef struct patient {
    struct person p;
    char visited_doctor[100];
    int reg_id;

}patient;

void putinfor_patient(struct patient *this) {
    printf("\t   -------------------------------------------------------------------------------------\n");

    printf("\n\t\t\t%-40s: %d\n", "YOUR REGISTRATION ID IS", this->reg_id);
    printf("\n\t\t\t%-40s: %s\n", "YOUR VISITING DOCTORS IS", this->visited_doctor);

    putinfor(&this->p);

    printf("\t   -------------------------------------------------------------------------------------\n");
}


void set_id(struct patient* pat)
{
        pat->reg_id=id++;
        pat->p.fees=500;
}

int search_oldp(struct patient* pat, int reg, int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (pat[i].reg_id == reg)
            return i;
    }
    return -1;
}
struct emergency {
    struct patient p;
    char stutas[100];
    int room;
};
void set_emergency_depart(struct emergency * epat)
{
   strcpy(epat->p.p.depart,"emergency department");
}

int search_emregency(struct emergency* pat, int reg_id, int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (pat[i].p.reg_id == reg_id)
            return i;
    }
    return -1;
}

void putinfor_emeregency_pat(struct emergency* e){
    printf("\t   -------------------------------------------------------------------------------------\n");

    putinfor_patient(&e->p);

    printf("\n\t\t\t%-40s: %s\n", "status of admission", e->stutas);
    printf("\n\t\t\t%-40s: %d\n", "ROOM NUMBER", e->room);

    printf("\t   -------------------------------------------------------------------------------------\n");
}


void set_fees(struct emergency* e) {

    int ER_visit_fee_max = 500;
    int diagnostic_tests_max = 1000;
    int procedures_max = 500;
    int hospital_admission_max = 5000;
    e->p.p.fees = ER_visit_fee_max + diagnostic_tests_max + procedures_max + hospital_admission_max;
    printf("\n\t\t\t%-25s%-20s\n", "Service", "Maximum Fee (INR)");
    printf("\t\t\t%-25s%-20s\n", "", "");
    printf("\t\t\t%-25s%-20d\n", "doctor Visit Fee", ER_visit_fee_max);
    printf("\t\t\t%-25s%-20d\n", "Diagnostic Tests", diagnostic_tests_max);
    printf("\t\t\t%-25s%-20d\n", "Procedures", procedures_max);
    printf("\t\t\t%-25s%-20d\n", "Hospital Admission", hospital_admission_max);
    printf("\t\t\t%-25s%-20.2f per day\n", "total fees", e->p.p.fees);
}



//----------------------------------------------------------------




typedef struct Doctor {
    person p;

    char degree[50];
    char id[50];
    int patient_id[100];
    char patient_name[100][50];
    int count_patient;
    char doc_password[14];
} Doctor;

typedef struct {
    char admin_password[15];
    Doctor doc[20];
    int count_doc;
} Admin;



void putinfor_doctor(Admin *a,int p_doc)
   {
     printf("\t   -------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t%-40s: %s\n", "doctor id", a->doc[p_doc].id);
    printf("\n\t\t\t%-40s: %s\n", "doctor qualified degree", a->doc[p_doc].degree);


           putinfor(&a->doc[p_doc].p);
    printf("\t   -------------------------------------------------------------------------------------\n");


    }


int search_doc(Doctor *doc, char *id1, int count_doc) {
    for (int i = 0; i < count_doc; i++) {
        if (strcmp(id1, doc[i].id) == 0) {
            return i;
            break;
        }
    }
    return -1;
}

struct medicine
{
    int num;
    char name[20];
    char usage[15];
    char dose[8];
    int day;
    int price;
};

void put_header()
{
    printf("\t\t\t\t%5s|   %20s|   %15s|   %8s|   %6s|   %3s\n", "CODE", "MEDICINE", "USAGE", "DOSE", "DAYS", "PRICE");
    printf("\t   -------------------------------------------------------------------------------------\n");
}

void put_infor_madi(struct medicine med)
{
    printf("\t\t\t\t%5d|   %20s|   %15s|   %8s|   %6d|   %3d\n", med.num, med.name, med.usage, med.dose, med.day, med.price);
}

void take_madicine(char* depart, struct patient* p)
{
    int f = 0;
    if (strcmp(depart, "general opd") == 0)
    {
        struct medicine med1[5] = {
            {1, "ACETAMINOPHENE", "FEVER", "325mg", 3, 12},
            {2, "PARACETAMOL", "HEAADACHE", "500mg", 2, 20},
            {3, "ASSPIRIN", "ARTHRITIS", "250mg", 4, 12},
            {4, "FENOPROFEN", "HEADACHE", "250mg", 3, 20},
            {5, "ANTIHISTAMINES", "COLD-COUGH", "250mg", 4, 15}
        };
        printf("\n\n\n\t\t\t\t\t\t\t\tGENERAL DEPARTMENT\n\n\n");
        put_header();
        for (int i = 0; i < 5; i++)
        {
            put_infor_madi(med1[i]);
        }
        int ch;
        printf("\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:\n\n");
        scanf("%d", &ch);
        while (ch < 0 || ch > 55555)
        {
            printf("\n\nENTER VALID NUMBER:");
            scanf("%d", &ch);
        }
        while (ch != 0)
        {
            int rem = ch % 10;
            if ((rem == 1) || (rem == 3))
                p->p.fees += 12;
            else if ((rem == 4) || (rem == 2))
                p->p.fees += 20;
            else
                p->p.fees += 15;
            ch /= 10;
        }
    }
    else if (strcmp(depart, "skin department") == 0)
    {
        struct medicine med2[5] = {
            {1, "PENICILENE", "PIMPES", "325mg", 3, 25},
            {2, "DICLOXALINE", "DARK-CIRCLES", "500mg", 2, 15},
            {3, "AMOXISILIN", "VITILIGO", "250mg", 4, 20},
            {4, "CEFDINIR", "ALERGY", "250mg", 3, 15},
            {5, "CEPHALOSPORINS", "INFECTION", "250mg", 4, 25}
        };
        printf("\n\n\n\t\t\t\t\t\t\t\tSKIN DEPARTMENT\n\n\n");
        put_header();
        for (int i = 0; i < 5; i++)
        {
            put_infor_madi(med2[i]);
        }
        int ch;
        printf("\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:\n\n");
        scanf("%d", &ch);
        while (ch != 0)
        {
            int rem = ch % 10;
            if ((rem == 1) || (rem == 5))
                p->p.fees += 25;
            else if ((rem == 4) || (rem == 2))
                p->p.fees += 20;
            else
                p->p.fees += 20;
            ch /= 10;
        }
    }
    else if (strcmp(depart, "orthology department") == 0)
    {
        struct medicine med3[5] = {
            {1, "ASPIRPN", "MUSCULER-PAIN", "325mg", 3, 15},
            {2, "NUPRIN", "BACK-PAIN", "500mg", 2, 15},
            {3, "IBUPROFEN", "ARTHRITIS", "250mg", 4, 20},
            {4, "MOTRIN", "OSTEOARTHRITIS", "250mg", 3, 14},
            {5, "ROFECOXIB", "FRACTURE", "250mg", 4, 14}
        };
        printf("\n\n\n\t\t\t\t\t\t\t\tORTHOLOGY DEPARTMENT\n\n\n");
        put_header();
        for (int i = 0; i < 5; i++)
        {
            put_infor_madi(med3[i]);
        }
        int ch;
        printf("\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:\n\n");
        scanf("%d", &ch);
        while (ch < 0 || ch > 55555)
        {
            printf("\n\nENTER VALID NUMBER:");
            scanf("%d", &ch);
        }
        while (ch != 0)
        {
            int rem = ch % 10;
            if ((rem == 1) || (rem == 2))
                p->p.fees += 15;
            else if ((rem == 4) || (rem == 5))
                p->p.fees += 14;
            else
                p->p.fees += 20;
            ch /= 10;
        }
    }
    else if (strcmp(depart, "gynecology department") == 0)
    {
        struct medicine med4[5] = {
            {1, "ACTIVELLA", "ENDOMETRIOSIS", "325mg", 3, 24},
            {2, "ALORA", "FIBOROIDS", "500mg", 2, 20},
            {3, "AREDIA", "CANSER", "250mg", 4, 21},
            {4, "ARIMIDEX", "PCOS", "250mg", 3, 20},
            {5, "CLEOCIN", "MENOPOSE", "250mg", 4, 24}
        };
        printf("\n\n\n\t\t\t\t\t\t\t\tGYNECOLOGY DEPARTMENT\n\n\n");
        put_header();
        for (int i = 0; i < 5; i++)
        {
            put_infor_madi(med4[i]);
        }
        int ch;
        printf("\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:\n\n");
        scanf("%d", &ch);
        while (ch < 0 || ch > 55555)
        {
            printf("\n\nENTER VALID NUMBER:");
            scanf("%d", &ch);
        }
        while (ch != 0)
        {
            int rem = ch % 10;
            if ((rem == 1) || (rem == 5))
                p->p.fees += 24;
            else if ((rem == 4) || (rem = 2))
                p->p.fees += 20;
            else
                p->p.fees += 21;
            ch /= 10;
        }
    }
    else if (strcmp(depart, "pediatricks department") == 0)
    {
        struct medicine med5[5] = {
            {1, "CEPHALEXIN", "AMENIA", "325mg", 3, 44},
            {2, "IBUPROFEN", "ASTHMA", "500mg", 2, 20},
            {3, "AZITHROMYCIN", "PNEUMONIA", "250mg", 4, 25},
            {4, "ARIMIDEX", "DOWNS-SYNDROME", "250mg", 3, 20},
            {5, "PREDNISONE", "POLIO", "250mg", 4, 25}
        };
        printf("\n\n\n\t\t\t\t\t\t\t\tPEDIATRICKS DEPARTMENT\n\n\n");
        put_header();
        for (int i = 0; i < 5; i++)
        {
            put_infor_madi(med5[i]);
        }
        int ch;
        printf("\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:\n\n");
        scanf("%d", &ch);
        while (ch < 0 || ch > 55555)
        {
            printf("\n\nENTER VALID NUMBER:");
            scanf("%d", &ch);
        }
        while (ch != 0)
        {
            int rem = ch % 10;
            if ((rem == 3) || (rem == 5))
                p->p.fees += 25;
            else if ((rem == 4) || (rem = 2))
                p->p.fees += 20;
            else
                p->p.fees += 44;
            ch /= 10;
        }
    }
    else if (strcmp(depart, "neurology department") == 0)
    {
        struct medicine med6[5] = {
            {1, "TAPOMAX", "EPILEPSY", "325mg", 3, 50},
            {2, "KEPPRA", "AUTISM", "500mg", 2, 40},
            {3, "DEPAKOTE", "BARIN-CANSER", "250mg", 4, 45},
            {4, "LAMOCTAL", "ADD", "250mg", 3, 45},
            {5, "LEVETIRACETAM", "MEMORY-LOSS", "250mg", 4, 40}
        };
        printf("\n\n\n\t\t\t\t\t\t\t\tNEUROLOGY DEPARTMENT\n\n\n");
        put_header();
        for (int i = 0; i < 5; i++)
        {
            put_infor_madi(med6[i]);
        }
        int ch;
        printf("\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:\n\n");
        scanf("%d", &ch);
        while (ch < 0 || ch > 55555)
        {
            printf("\n\nENTER VALID NUMBER:");
            scanf("%d", &ch);
        }
        while (ch != 0)
        {
            int rem = ch % 10;
            if ((rem == 2) || (rem == 5))
                p->p.fees += 40;
            else if ((rem == 4) || (rem = 3))
                p->p.fees += 45;
            else
                p->p.fees += 50;
            ch /= 10;
        }
    }
    else if (strcmp(depart, "dental department") == 0)
    {
        struct medicine med7[5] = {
            {1, "AMOXICILIN", "EPILEPSY", "325mg", 3, 15},
            {2, "PENICINE", "AUTISM", "500mg", 2, 30},
            {3, "CEVIMELINE", "BARIN-CANSER", "250mg", 4, 23},
            {4, "NAPROXEN", "ADD", "250mg", 3, 30},
            {5, "CLINDAMYCINE", "MEMORY-LOSS", "250mg", 4, 23}
        };
        printf("\n\n\n\t\t\t\t\t\t\t\tDENTAL DEPARTMENT\n\n\n");
        put_header();
        for (int i = 0; i < 5; i++)
        {
            put_infor_madi(med7[i]);
        }
        int ch;
        printf("\n\n\t\t PLEACE ENTER CODE OF MADICINCE IN ONE NUMBER:\n\n");
        scanf("%d", &ch);
        while (ch < 0 || ch > 55555)
        {
            printf("\n\nENTER VALID NUMBER:");
            scanf("%d", &ch);
        }
        while (ch != 0)
        {
            int rem = ch % 10;
            if ((rem == 2) || (rem == 4))
                p->p.fees += 30;
            else if ((rem == 5) || (rem = 3))
                p->p.fees += 23;
            else
                p->p.fees += 15;
            ch /= 10;
        }
    }
}

int take_emr_patient(Admin *a,int  index, struct emergency* epat, int emp_cnt)
{
    struct emergency p;
    int in = -1;
    struct Doctor* d = &a->doc[index];
    for (int i = 0; i < emp_cnt; i++)
    {
        if ((strcmp(d->p.depart, epat[i].p.p.depart) == 0) && (strlen(epat[i].p.visited_doctor)==0))
        {
            p = epat[i];
            in = i;
            break;
        }
    }
    if (in != -1)
    {
        putinfor_emeregency_pat(&p);
        strcpy(p.p.visited_doctor, d->p.full_name);
        //(d.patient_id).push_back(p.id);

        d->count_patient++;

        epat[in] = p;
    }
    return in;
}

int take_patient(Admin *a,int  index, struct patient* pat, int patient_cnt)
{
    struct patient p;
    int in = -1;
    struct Doctor* d = &(a->doc[index]);
    for (int i = 0; i < patient_cnt; i++)
    {
        if ((strcmp(d->p.depart, pat[i].p.depart) == 0) && (strlen(pat[i].visited_doctor)==0))
        {
            p = pat[i];
            in = i;
            break;
        }
    }

    if (in != -1)
    {
        putinfor_patient(&p);
        strcpy(p.visited_doctor, d->p.full_name);

        d->count_patient++;

       take_madicine(p.p.depart, &p);
        pat[in] = p;
    }
    return in;
}

void menu_visitor();
void put_infor_visitor(Admin a);
void graph_thankyou();

void menu_visitor() {
    system("cls"); // For Unix-based systems, use "clear" instead of "cls"
    printf("\n\n\n\n\n\t\t\t1) OUR FACILITIES\n\t\t\t2) OUR LABORATORY\n\t\t\t3) TECHNICAL INSTRUMENTS\n\t\t\t4) DOCTORS INFORMATIONS\n\t\t\t5) BACK\n\n");

}

void put_infor_visitor(Admin a) {
    menu_visitor();
    int n_visitor;
    printf("\tENTER YOUR CHOICE: ");
    scanf("%d", &n_visitor);

    switch (n_visitor) {
        case 1: {
            system("cls");
            printf("\t\t\t\t\t\t\t\tOUR FACILITIES \n\n\n\n\n");
            printf("\n\t%-30s  |   %s", "Emergency Department (ED)", "the first point of contact for people who are experiencing a medical emergency.");
            printf("\n\t%-30s  |   %s\n", "", "staffed by specially trained doctors and nurses who can provide immediate care");
            printf("\t%-30s  |   %s\n", "", "for a wide range of conditions");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Operating Rooms (ORs)", "ORs are sterile rooms where surgeons perform operations.They are");
            printf("\n\t%-30s  |   %s\n", "", "equipped with specialized equipment, such as surgical tables,anesthesia machines,");
            printf("\t%-30s  |   %s\n", "", "range of conditions");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Intensive Care Units (ICUs)", "ICUs are for patients who are critically ill or");
            printf("\n\t%-30s  |   %s\n", "", "injured and require constant monitoring and care.");
            printf("\t%-30s  |   %s\n", "", "They are staffed by specially trained nurses and respiratory therapists.");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Medical-Surgical Units (MSUs)", "MSUs are where patients are admitted for a variety of medical and surgical conditions.");
            printf("\n\t%-30s  |   %s\n", "", "They are staffed by nurses who provide care for patients before, during,");
            printf("\t%-30s  |   %s\n", "", "and after their stay in the hospital.");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Outpatient Departments (OPDs)", "OPDs provide care for patients who do not require an overnight");
            printf("\n\t%-30s  |   %s\n", "", "stay in the hospital.They may offer a variety of services,");
            printf("\t%-30s  |   %s\n", "", "such as primary care, specialty care, and diagnostic testing.");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Diagnostic and Treatment Facilities", "Hospitals also have a variety of diagnostic and");
            printf("\n\t%-30s  |   %s\n", "", "treatment facilities, such as radiology departments,");
            printf("\t%-30s  |   %s\n", "", "laboratories, and pharmacies.");
            _getch();
            break;
        }

        case 2: {
            system("cls");
            printf("\t\t\t\t\t\t\t\tOUR LABORATORY \n\n\n\n\n");
            printf("\t---> There are many different types of hospital laboratory tests, which can be done in our hospital\n\n");
            printf("\n\t%-30s  |   %s", "Blood tests", "These tests can provide information about a wide range of health conditions");
            printf("\n\t%-30s  |   %s\n", "", "including anemia, infection, diabetes, and kidney disease. at Rs.150");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Urinalysis", "This test analyzes urine to check for abnormalities that may indicate a urinary ");
            printf("\n\t%-30s  |   %s\n", "", "tract infection,indicate a urinary tract infection,kidney stones, or diabetes.at Rs.450");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Microbiology tests", "These tests are used to identify bacteria, viruses, and other microorganisms that ");
            printf("\n\t%-30s  |   %s\n", "", "may be causing an infection.at Rs.200");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Histology and cytology", "These tests involve examining tissues or cells under a microscope to look for");
            printf("\n\t%-30s  |   %s\n", "", "such as cancer.at Rs.200 ");
            printf("     -------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t%-30s  |   %s", "Chemistry tests", "These tests measure the levels of chemicals in the blood, such as electrolytes, hormones,");
            printf("\n\t%-30s  |   %s\n", "", "and enzymes.at Rs.200");
            printf("\n\n\n");
             _getch();
            break;
        }

        case 3: {
            system("cls");
            printf("\n\n\t\t\t\t\t\t\tTECHNICAL INSTRUMENTS\n\n");
            printf("%-35s| %s\n\n", "* TECHNICAL INSTRUMENTS", "X-ray machines: Generate images of bones and soft tissues.");
            printf("%-35s| %s\n\n", "", "CT scanners (Computed Tomography): Provide detailed cross-sectional images.");
            printf("%-35s| %s\n\n", "", "Ultrasound machines: Use sound waves to generate images of organs and tissues.");
            printf("%-35s| %s\n\n", "", "MRI machines (Magnetic Resonance Imaging): Create detailed images of organs.");
            printf("-----------------------------------------------------------------------------\n\n");
            printf("%-35s| %s\n\n", "* Surgical Instruments:", "X-ray machines: Generate images of bones and soft tissues.");
            printf("%-35s| %s\n\n", "", "Scalpels: Sharp blades for precise cutting of tissues.");
            printf("%-35s| %s\n\n", "", "Forceps: Grasping instruments for holding tissues or sutures (stitches).");
            printf("%-35s| %s\n\n", "", "Scissors: Specialized scissors for cutting different types of tissues.");
            printf("%-35s| %s\n\n", "", "Sutures (stitches) and Needles: Used to close wounds and connect tissues.");
            printf("%-35s| %s\n\n", "", "Electrosurgical Unit (ESU): Uses electrical current for surgical purposes.");
            printf("%-35s| %s\n\n", "", "Retractors: Hold tissues apart for better visibility during surgery.");
            printf("-----------------------------------------------------------------------------\n\n");
            printf("%-35s| %s\n\n", "* General Hospital Instruments:", "Thermometers: Measure body temperature.");
            printf("%-35s| %s\n\n", "", "Sphygmomanometers: Measure blood pressure.");
            printf("%-35s| %s\n\n", "", "Otoscopes and Ophthalmoscopes: Examine ears and eyes, respectively.");
            printf("%-35s| %s\n\n", "", "Syringes and Needles: Used for injecting medications or withdrawing fluids.");
            printf("%-35s| %s\n\n", "", "Blood Collection Tubes and Needles: Used for blood sample collection.");
             _getch();
            break;
        }

        case 4: {
            // doctor
                for (int i = 0; i < a.count_doc; i++)
                {
                    system("cls");
                    putinfor_doctor(&a,i);
                    printf("\n\n ENTER ANY KEY TO VISIT NEXT DOCTOR ");
                    _getch();
             }

             break;
        }

        case 5: {
            break;
        }

        default: {
            printf("\tENTER VALID INFORMATION:");
            getchar();
            break;
        }
    }
}

void graph_thankyou() {
   printf("\n\n\n\n\t\t thank you");
}

void display_menu() {
    printf("\n\n\n\n\t\t\t\t ----------------------------");
    printf("\n \t\t\t\t   MAHAKAL HOSPITAL  ");
    printf("\n \t\t\t\t ----------------------------");
    printf("\n\n\t\t WHO ARE YOU?:");
    printf("\n\n\t\t 1)RECEPTIONIST"
           "\n\t\t 2)DOCTOR"
           "\n\t\t 3)ABOUT US"
           "\n\t\t 4)EXIT \n\n");
    //printf("%40s", "ENTER YOUR CHOICE HERE: ");
}

void change_depart(person *p)
 {
    strcpy(p->depart,take_dep());
 }
int  available_room(int arr[],int n)
{   int flage=-1;
    printf("\n\n\t\tAVAILABLE ROOMS\t:\t");
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            printf("%d  ",i+1
        );
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


int main() {
    set_time();

    Admin a;
    strcpy(a.admin_password, "admine@161981");

    strcpy(a.doc[0].p.full_name, "Dr. John Smith");
    a.doc[0].p.age = 45;
    strcpy(a.doc[0].p.gender, "male");
    strcpy(a.doc[0].p.depart, "general opd");
    a.doc[0].p.Bdate = 15;
    a.doc[0].p.Byear = 1981;
    a.doc[0].p.Bmonth = 6;
    strcpy(a.doc[0].p.contact, "9876543210");
    a.doc[0].p.fees = 1000;
    strcpy(a.doc[0].p.aadhar, "9876543210987");
    strcpy(a.doc[0].p.adress, "456 Oak Avenue, Town,rajkot");
    strcpy(a.doc[0].degree, "MBBS, Dermatology");
    strcpy(a.doc[0].id, "Doctor@121");

    strcpy(a.doc[1].p.full_name, "Dr. Emily Johnson");
    a.doc[1].p.age = 40;
    strcpy(a.doc[1].p.gender, "female");
    strcpy(a.doc[1].p.depart, "orthology department");
    a.doc[1].p.Bdate = 20;
    a.doc[1].p.Byear = 1982;
    a.doc[1].p.Bmonth = 8;
    strcpy(a.doc[1].p.contact, "9871234560");
    a.doc[1].p.fees = 1200;
    strcpy(a.doc[1].p.aadhar, "9876543210123");
    strcpy(a.doc[1].p.adress, "789 Elm Street, City, Mumbai");
    strcpy(a.doc[1].degree, "MBBS, Orthopedics");
    strcpy(a.doc[1].id, "Doctor@122");

    strcpy(a.doc[2].p.full_name, "Dr. Michael Brown");
    a.doc[2].p.age = 50;
    strcpy(a.doc[2].p.gender, "Male");
    strcpy(a.doc[2].p.depart, "skin department");
    a.doc[2].p.Bdate = 10;
    a.doc[2].p.Byear = 1974;
    a.doc[2].p.Bmonth = 11;
    strcpy(a.doc[2].p.contact, "7654321098");
    a.doc[2].p.fees = 1500;
    strcpy(a.doc[2].p.aadhar, "4567890123456");
    strcpy(a.doc[2].p.adress, "789 Pine Street, Village");
    strcpy(a.doc[2].degree, "MBBS, MS Orthopedics");
    strcpy(a.doc[2].id, "Doctor@123");

    strcpy(a.doc[3].p.full_name, "Dr. Sophia Wilson");
    a.doc[3].p.age = 42;
    strcpy(a.doc[3].p.gender, "Female");
    strcpy(a.doc[3].p.depart, "gynecology department");
    a.doc[3].p.Bdate = 5;
    a.doc[3].p.Byear = 1982;
    a.doc[3].p.Bmonth = 9;
    strcpy(a.doc[3].p.contact, "6543210987");
    a.doc[3].p.fees = 1800;
    strcpy(a.doc[3].p.aadhar, "3456789012345");
    strcpy(a.doc[3].p.adress, "890 Cedar Avenue, County");
    strcpy(a.doc[3].degree, "MBBS, MD Obstetrics and Gynecology");
    strcpy(a.doc[3].id, "Doctor@124");

    strcpy(a.doc[4].p.full_name, "Dr. Benjamin Garcia");
    a.doc[4].p.age = 48;
    strcpy(a.doc[4].p.gender, "Male");
    strcpy(a.doc[4].p.depart, "pediatricks department");
    a.doc[4].p.Bdate = 12;
    a.doc[4].p.Byear = 1976;
    a.doc[4].p.Bmonth = 7;
    strcpy(a.doc[4].p.contact, "5432109876");
    a.doc[4].p.fees = 1300;
    strcpy(a.doc[4].p.aadhar, "2345678901234");
    strcpy(a.doc[4].p.adress, "678 Elm Street, District");
    strcpy(a.doc[4].degree, "MBBS, Pediatrics");
    strcpy(a.doc[4].id, "Doctor@125");

    strcpy(a.doc[5].p.full_name, "Dr. Olivia Martinez");
    a.doc[5].p.age = 40;
    strcpy(a.doc[5].p.gender, "Female");
    strcpy(a.doc[5].p.depart, "neurology department");
    a.doc[5].p.Bdate = 28;
    a.doc[5].p.Byear = 1984;
    a.doc[5].p.Bmonth = 4;
    strcpy(a.doc[5].p.contact, "4321098765");
    a.doc[5].p.fees = 1600;
    strcpy(a.doc[5].p.aadhar, "1234567890123");
    strcpy(a.doc[5].p.adress, "123 Maple Avenue, State");
    strcpy(a.doc[5].degree, "MBBS, Neurology");
    strcpy(a.doc[5].id, "Doctor@126");

    strcpy(a.doc[6].p.full_name, "Dr. Daniel Lee");
    a.doc[6].p.age = 55;
    strcpy(a.doc[6].p.gender, "Male");
    strcpy(a.doc[6].p.depart, "dental department");
    a.doc[6].p.Bdate = 18;
    a.doc[6].p.Byear = 1969;
    a.doc[6].p.Bmonth = 2;
    strcpy(a.doc[6].p.contact, "3210987654");
    a.doc[6].p.fees = 2000;
    strcpy(a.doc[6].p.aadhar, "0123456789012");
    strcpy(a.doc[6].p.adress, "456 Walnut Street, Province");
    strcpy(a.doc[6].degree, "BDS, MDS");
    strcpy(a.doc[6].id, "Doctor@127");

    strcpy(a.doc[7].p.full_name, "Dr. Isabella Thompson");
    a.doc[7].p.age = 37;
    strcpy(a.doc[7].p.gender, "Female");
    strcpy(a.doc[7].p.depart, "general opd");
    a.doc[7].p.Bdate = 9;
    a.doc[7].p.Byear = 1987;
    a.doc[7].p.Bmonth = 12;
    strcpy(a.doc[7].p.contact, "2109876543");
    a.doc[7].p.fees = 1100;
    strcpy(a.doc[7].p.aadhar, "9012345678901");
    strcpy(a.doc[7].p.adress, "789 Birch Avenue, Region");
    strcpy(a.doc[7].degree, "MBBS, General Medicine");
    strcpy(a.doc[7].id, "Doctor@128");

    strcpy(a.doc[8].p.full_name, "Dr. Samuel Harris");
    a.doc[8].p.age = 47;
    strcpy(a.doc[8].p.gender, "Male");
    strcpy(a.doc[8].p.depart, "skin department");
    a.doc[8].p.Bdate = 25;
    a.doc[8].p.Byear = 1977;
    a.doc[8].p.Bmonth = 8;
    strcpy(a.doc[8].p.contact, "1098765432");
    a.doc[8].p.fees = 1400;
    strcpy(a.doc[8].p.aadhar, "8901234567890");
    strcpy(a.doc[8].p.adress, "234 Cherry Street, Zone");
    strcpy(a.doc[8].degree, "MBBS, Dermatology");
    strcpy(a.doc[8].id, "Doctor@129");

    strcpy(a.doc[9].p.full_name, "Dr. Mia Rodriguez");
    a.doc[9].p.age = 39;
    strcpy(a.doc[9].p.gender, "Female");
    strcpy(a.doc[9].p.depart, "emergency department");
    a.doc[9].p.Bdate = 30;
    a.doc[9].p.Byear = 1985;
    a.doc[9].p.Bmonth = 1;
    strcpy(a.doc[9].p.contact, "9876543210");
    a.doc[9].p.fees = 1550;
    strcpy(a.doc[9].p.aadhar, "7890123456789");
    strcpy(a.doc[9].p.adress, "567 Pineapple Avenue, Sector");
    strcpy(a.doc[9].degree, "MBBS, MS Orthopedics");
    strcpy(a.doc[9].id, "Doctor@130");

    strcpy(a.doc[10].p.full_name, "Dr. Radhe mohan");
    a.doc[10].p.age = 47;
    strcpy(a.doc[10].p.gender, "Male");
    strcpy(a.doc[10].p.depart, "emergency department");
    a.doc[10].p.Bdate = 25;
    a.doc[10].p.Byear = 1977;
    a.doc[10].p.Bmonth = 8;
    strcpy(a.doc[10].p.contact, "1098765432");
    a.doc[10].p.fees = 1400;
    strcpy(a.doc[10].p.aadhar, "8901234567890");
    strcpy(a.doc[10].p.adress, "234 Cherry Street, Zone");
    strcpy(a.doc[10].degree, "MBBS, Dermatology");
    strcpy(a.doc[10].id, "Doctor@131");

    strcpy(a.doc[11].p.full_name, "Dr. shivangi  joshi");
    a.doc[11].p.age = 39;
    strcpy(a.doc[11].p.gender, "Female");
    strcpy(a.doc[11].p.depart, "emergency department");
    a.doc[11].p.Bdate = 30;
    a.doc[11].p.Byear = 1985;
    a.doc[11].p.Bmonth = 1;
    strcpy(a.doc[11].p.contact, "9876543210");
    a.doc[11].p.fees = 1550;
    strcpy(a.doc[11].p.aadhar, "7890123456789");
    strcpy(a.doc[11].p.adress, "567 Pineapple Avenue, Sector");
    strcpy(a.doc[11].degree, "MBBS, MS Orthopedics");
    strcpy(a.doc[11].id, "Doctor@132");

    a.count_doc = 12;

     patient pat[100];
    struct emergency epat[100];
    int patient_cnt = 0;
    int room_num[5]={0,0,0,0,0};
    int emp_cnt = 0;

    while (1)
     {
        system("cls");
        display_menu();
        printf("\nENTER YOUR CHOICE HERE: ");
        unsigned int n;
        scanf("%u", &n);

        if (n == 1)
        {
            //ADMINE
            system("cls");
            printf("\n\n\t\t\tRECEPTIONIST");
            char password[20] = {};
            printf("\n\n\n\t\tIF YOU ARE RECEPTIONIST THEN ENTER YOUR PASSWORD:");
            int i = 0;
            char ch;
            while (1) {
                ch = _getch();
                if (ch == '\r')
                    break;
                else if (ch == '\b' && i > 0) {
                    printf("\b \b");
                    i--;
                }
                else if (i < 19) {
                    password[i++] = ch;
                    printf("*");
                }
            }
            password[i] = '\0'; // Null-terminate the password string

            if (!strcmp(password, a.admin_password))
            {
                printf("\n\n\n\t\t\tYOUR PASSWORD VERIFIED PERFECTLY PLEASE ENTER ANY KEY TO CONTINUE FURTHER .....\n\n");
                _getch();
                while (1)
                {
                    system("cls");
                    menu();
                    printf("\tENTER YOUR CHOICE HERE: ");
                    unsigned int n;
                    scanf("%u", &n);
                    while (n < 1 || n > 7) {
                        system("cls");
                        menu();
                        printf("\tenter valid information: ");
                        scanf("%u", &n);
                    }

                    if (n == 1)
                     {
                        //for new patient
                        patient temp;
                        Admin t;
                        system("cls");
                        getinfor(&temp.p);
                        set_id(&temp);
                        pat[patient_cnt] = temp;

                       change_depart(&pat[patient_cnt].p);
                        patient_cnt++;

                        system("cls");
                        printf("\n\n\t\t\tYOUR REGISTER ID IS %d\n", pat[patient_cnt - 1].reg_id);

                        printf("\t\t\tYOU ARE REGISTERED SUCCESSFULLY YOUR DETAILS:\n\n");
                        putinfor_patient(&pat[patient_cnt - 1]);
                        printf("PRESS ANY KEY...");
                        _getch();
                    }
                    else if (n == 2) {
                        int reg;
                        //for old patient
                        system("cls");
                        printf("\n\tPLEASE ENTER YOUR REG_ID\t\t");
                        scanf("%d", &reg);
                        int index = search_oldp(pat, reg, patient_cnt);
                        if (index != -1) {

                            patient temp = pat[index];
                            set_id(&temp);
                            pat[patient_cnt] = temp;

                            printf("\n\n\t\t\tSELECT RIGHT ONE WHICH IS ASKED:\n\n");
                            printf("\n\t\t\t1)DOCTOR HAD GIVEN YOU AN APPOINTMENT EARLIER.\n");
                            printf("\t\t\t2)YOU WANT TO GO FOR ANOTHER DEPARTMENT.\n");

                            int choice;
                            printf("\n\n\tENTER YOUR CHOICE:\t");
                            scanf("%d", &choice);

                            if (choice == 2) {
                                change_depart(&pat[patient_cnt].p);
                            }
                            else if (choice == 1) {
                                //for appointment
                            }
                            else {
                                continue;
                            }

                            system("cls");
                            printf("\n\n\t\tYOUR REGISTER ID IS %d\n", pat[patient_cnt].reg_id);

                            patient_cnt++;
                            printf("\t\tYOU ARE REGISTERED SUCCESSFULLY. YOUR DETAILS:\n\n");
                            putinfor_patient(&pat[patient_cnt - 1].p);
                            _getch();
                            printf("PRESS ANY KEY...");
                        }
                        else {
                            printf("\t\t\t\tPATIENT NOT FOUND PLEASE ENTER ANY KEY FOR MENU.\n");
                            _getch();
                        }
                    }
                    else if (n == 7) {
                        //for exit
                        break;
                    }
                    else if (n == 6) {
                                    //for check out
                                    int reg;
                            //for checkout patient
                                system("cls");
                                printf("\n\tPLEASE ENTER YOUR REG_IDt\t");
                                scanf("%d",&reg);
                                int index=search_emregency(epat,reg,emp_cnt);
                                if(index==-1)
                                {
                                    printf("\n\tPATIENT NOT FOUND PRESS ANY KEY FOR FURTHER PROCESS");
                                    _getch();
                                    continue;
                                }
                                if( epat[index].stutas=="checkout")
                                {
                                    printf("\n\tPATIENT IS ALREADY CHECKOUT PRESS ANY KEY FOR FURTHER PROCESS ");
                                    _getch();
                                    continue;
                                }
                               strcpy( epat[index].stutas,"checkout");
                                room_num[epat[index].room-1]=0;
                                        printf("\n\tYOU ARE  CHECKOUT SUCSESSFULY PRESS ANY KEY FOR FURTHER PROCESS ");
                                    _getch();

                    }
                    else if (n == 4) {
                        //for emergency
                        system("cls");
                        int y =  available_room(room_num,5);
                         _getch();
                          if(y==-1)
                        {
                           printf("\n\n\tSORRY,THERE ARE NO AVAILABLE EMERGENCY ROOMS TODAY PRESS TO CONTINEUE\n");
                            _getch();
                            continue;
                        }
                         y=add_room(room_num,5);


                         struct emergency temp;
                        system("cls");
                        set_id(&temp.p);
                       getinfor(&temp);
                        set_fees(&temp);
                        strcpy(temp.p.p.depart,"emergency department");
                        strcpy(temp.stutas, "admited");
                        epat[emp_cnt] = temp;
                        epat[emp_cnt].room = y+ 1;

                        system("cls");
                        printf("\n\n\t\t\tYOUR REGISTER ID IS %d\n", epat[emp_cnt].p.reg_id);
                       set_fees(& temp);

                        putinfor_emeregency_pat(&epat[emp_cnt]);
                        printf("ENTER ANY KEY FOR FURTHER:\n");
                        _getch();
                        emp_cnt++;
                    }
                    else if (n == 3) {
                        //for visitor
                       put_infor_visitor(a);
                    }
                    //system("cls");
                    else if (n == 5) {
                        //FOR VIEW PATIENT
                        system("cls");
                        printf("\n\n\n\n\t\t\tWHICH INFORMATION YOU WANT TO VIEW :\n");
                        menu_view_pat();
                        int v_p = 0;
                        printf("\tENTER YOUR CHOICE HERE:\t");
                        scanf("%d", &v_p);

                        while ((v_p < 0) || (v_p > 6)) {
                            printf("\tENTER VALID CHOICE HERE:\t");
                            scanf("%d", &v_p);
                        }

                        if (v_p == 1) {
                            //for normal list
                            if (patient_cnt != 0) {
                                printf("\t\tVISITED NORMAL PATIENT  LIST IS:\n\n");
                                for (int i = 0; i < patient_cnt; i++) {
                                    system("cls");
                                    printf("\n\n\n\tpatient %d:\n", i + 1);
                                    putinfor_patient(&pat[i]);
                                    printf("press any key for next...");
                                    _getch();
                                }
                            }
                            else {
                                printf("\t AT THIS TIME PATIENT IS NOT COME\n");
                                printf("press any key for menu...");
                                _getch();
                            }
                        }
                        else if (v_p == 2) {
                            //for emergency list
                            if (emp_cnt != 0) {
                                printf("\t\tVISITED EMERGENCY  PATIENT  LIST IS:\n\n");
                                for (int i = 0; i < emp_cnt; i++) {
                                    system("cls");
                                    printf("\n\n\temergency patient %d:\n", i + 1);
                                   putinfor_emeregency_pat(&epat[i]);
                                    printf("press any key for next...");
                                    _getch();
                                }
                            }
                            else {
                                printf("\t AT THIS TIME PATIENT IS NOT COME\n");
                            }
                        }
                        else if (v_p == 3) {
                            //for all list
                            if (patient_cnt != 0) {
                                printf("\t\tVISITED NORMAL PATIENT  LIST IS:\n\n");
                                for (int i = 0; i < patient_cnt; i++) {
                                    system("cls");
                                    printf("\n\n\n\tpatient %d:\n", i + 1);
                                    putinfor_patient(&pat[i]);
                                    printf("press any key for next...");
                                    _getch();
                                }
                            }
                            else {
                                printf("\t AT THIS TIME PATIENT IS NOT COME\n");
                                printf("press any key for next...");
                                _getch();
                            }

                            if (emp_cnt != 0) {
                                printf("\t\tVISITED EMERGENCY  PATIENT  LIST IS:\n\n");
                                for (int i = 0; i < emp_cnt; i++) {
                                    system("cls");
                                    printf("\n\n\temergency patient %d:\n", i + 1);
                                   putinfor_emeregency_pat( &epat[i]);
                                    printf("press any key for next...");
                                    _getch();
                                }
                            }
                            else {
                                printf("\t AT THIS TIME PATIENT IS NOT COME\n");
                                printf("press any key for next...");
                                _getch();
                            }
                        }
                        else if (v_p == 5) {
                            //for one emergency list
                            if (emp_cnt != 0) {
                                int reg_id;
                                printf("\t ENTER REGISTER ID OF EMERGENCY PATIENT :\t");
                                scanf("%d", &reg_id);
                                int index = search_emregency(epat, reg_id, emp_cnt);
                                if (index != -1) {
                                    system("cls");
                                    putinfor_emeregency_pat(&epat[index]);
                                    printf("press any key for next...");
                                    _getch();
                                }
                                else {
                                    printf("\tEMERGENCY PATIENT NOT FOUND OF THAT REGISTERED ID PLEASE TRY AGAIN....\n");
                                    printf("press any key for continue..\n");
                                    _getch();
                                    continue;
                                }
                            }
                            else {
                                printf("\t AT THIS TIME PATIENT IS NOT COME\n");
                                printf("press any key for continue..\n");
                                _getch();
                            }
                        }
                        else if (v_p == 4) {
                            //for one normal list
                            if (patient_cnt != 0) {
                                int reg_id;
                                printf("\t ENTER REGISTER ID OF PATIENT :\t");
                                scanf("%d", &reg_id);
                                int index = search_oldp(pat, reg_id, patient_cnt);
                                if (index != -1) {
                                    system("cls");
                                   putinfor_patient(&pat[index]);
                                    printf("press any key for continue..\n");
                                    _getch();
                                }
                                else {
                                    printf("PATIENT NOT FOUND OF THAT REGISTERED ID PLEASE TRY AGAIN....\n");
                                    printf("press any key for continue..\n");
                                    _getch();
                                    continue;
                                }
                            }
                            else {
                                printf("\t AT THIS TIME PATIENT IS NOT COME\n");
                                printf("press any key for continue..\n");
                                _getch();
                            }
                        }
                        else {
                            //exit
                            continue;
                        }
                    }
                }
            }
            else {
                printf("\n\n\t\tYOUR PASSWORD ID FALSE PLEASE PRESS ANY KEY AND RETURN TO THE MENU......\n");
                _getch();
            }
        }
        else if (n == 2) {
            //for doctor
            char password[20] = {};
                system("cls");
            printf("\n\t\t IF YOU ARE DOCTOR THEN ENTER YOUR PASSWORD:");
            int i = 0;
            char ch;
            while (1) {
                ch = _getch();
                if (ch == '\r')
                    break;
                else if (ch == '\b' && i > 0) {
                    printf("\b \b");
                    i--;
                }
                else if (i < 19) {
                    password[i++] = ch;
                    printf("*");
                }
            }
            password[i] = '\0';
            Doctor d;
            strcpy(d.doc_password,"doctor@161981");
            if (!strcmp(password, d.doc_password)){
                printf("\n\t\t your password is verified successfully\n");
                printf("\n\n\tENTER YOUR IDENTITY ID:");
                char id[50];
                scanf("%s", id);

                int index = search_doc(a.doc,id,a.count_doc);

                if (index == -1) {
                    printf("\n\tid was not found ..please try again with correct id,\n");
                    continue;
                }
                else {
                    while (1) {
                        Doctor d = a.doc[index];
                        printf("\n\t\t WHICH OPTION YOU WANT: \n");
                        printf("\t\t 1)TO SHOW YOUR INFORMATION :\n");
                        printf("\t\t 2)TAKE YOUR PATIENT :\n");
                        printf("\t\t 3)BACK \n");
                        printf("\n\tENTER YOUR CHOICE HERE:");
                        int choice;
                        scanf("%d", &choice);
                        if (choice == 1) {
                            putinfor_doctor(&a,index);
                        }
                        else if (choice == 2) {

                            if (strcmp(d.p.depart, "emergency department") != 0)
                             {

                                int in = take_patient(&a,index, pat, patient_cnt);
                                if (in != -1) {
                                    putinfor_patient(&pat[in]);
                                }
                                else
                                {
                                    printf("\tPATIENT OF YOUR DEPARTMENT TILL NOT COME PLEASE TRY AGAIN LATER...\n");
                                }
                            }
                            else {
                                //for emergency department

                                int in = take_emr_patient(&a,index, epat, emp_cnt);
                                if (in != -1) {
                                    putinfor_emeregency_pat(&epat[in]);
                                }
                                else {
                                    printf("\tPATIENT OF YOUR DEPARTMENT TILL NOT COME PLEASE TRY AGAIN LATER...\n");
                                }
                            }
                        }
                        else if (choice == 3) {
                            //exit
                            break;
                        }
                        else {
                            printf("\tENTER VALID CHOICE\n");
                        }
                    }
                }
            }
            else {
                printf("\n\t\t your password is invalid please try again later..\n\n");
                continue;
            }
        }
        else if (n == 4) {
            //exit
            system("cls");
            printf("\n\n\n\n\t\t\tARE YOU REALLY WANT TO EXIT ?");
            printf("\n\t\t\tPRESS 'Y' FOR EXIT OR PRESS 'N' FOR EXIT :  ");
            char c;
            scanf(" %c", &c);
            while ((c != 'y') && (c != 'n') && (c != 'Y') && (c != 'N')) {
                getchar();
                validinfor();

                scanf(" %c", &c);
            }
            if (c == 'y' || c == 'Y') {
                graph_thankyou();
                _getch();
                break;
            }
            else {
                continue;
            }
        }
        else if (n == 3) {
            system("cls");
            aboutus();
            printf("PLESE ENTER  FOR MENU :");
            _getch();
        }
        else {
            printf("\t PRESS ANY KEY AND ENTER VALID CHOICE.....\n");
            _getch();
            continue;
        }
    }



    return 0;
}




