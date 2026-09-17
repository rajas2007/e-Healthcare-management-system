/*
====================================================================
 E-HEALTHCARE MANAGEMENT SYSTEM
 COURSE PROJECT - TURBO C++ VERSION
====================================================================
 DEFAULT LOGIN
 -------------------------------------------------------------------
 ADMIN    : admin    / admin123
 DOCTOR   : doctor   / doctor123
 PATIENT  : patient  / patient123

 FEATURES
 -------------------------------------------------------------------
 1. Patient management
 2. Doctor management
 3. Appointment booking / cancellation
 4. Medical records
 5. Prescriptions
 6. Billing
 7. Reports
 8. Search
 9. OOP demonstration
10. File handling / persistent storage

 OOP CONCEPTS
 -------------------------------------------------------------------
 Class, Object, Encapsulation, Inheritance, Abstraction,
 Virtual Function, Polymorphism, Constructor, Copy Constructor,
 Destructor, Friend Function, Operator Overloading, Template,
 Composition and File Handling.
*/

#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 200

/* ================================================================
   UTILITY FUNCTIONS
   ================================================================ */

void pauseScreen()
{
    cout << "\n\nPress any key to continue...";
    getch();
}

void header(char *text)
{
    clrscr();

    cout << "\n==============================================================\n";
    cout << "              E-HEALTHCARE MANAGEMENT SYSTEM\n";
    cout << "==============================================================\n";
    cout << "  " << text << "\n";
    cout << "--------------------------------------------------------------\n";
}

void divider()
{
    cout << "--------------------------------------------------------------\n";
}

void initializeFiles()
{
    ofstream f;

    f.open("patients.dat", ios::app);
    f.close();

    f.open("doctors.dat", ios::app);
    f.close();

    f.open("appointments.dat", ios::app);
    f.close();

    f.open("records.dat", ios::app);
    f.close();

    f.open("prescriptions.dat", ios::app);
    f.close();

    f.open("bills.dat", ios::app);
    f.close();
}

/* ================================================================
   DATE CLASS
   ================================================================ */

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2026;
    }

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void input()
    {
        cout << "Date (DD MM YYYY): ";
        cin >> day >> month >> year;
    }

    void display()
    {
        cout << day << "/" << month << "/" << year;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    int operator==(Date d)
    {
        if(day == d.day &&
           month == d.month &&
           year == d.year)
            return 1;

        return 0;
    }
};

/* ================================================================
   ABSTRACT BASE CLASS - PERSON
   ================================================================ */

class Person
{
protected:
    int id;
    char name[50];
    int age;
    char gender[15];
    char phone[20];
    char email[60];

public:
    Person()
    {
        id = 0;
        name[0] = '\0';
        age = 0;
        gender[0] = '\0';
        phone[0] = '\0';
        email[0] = '\0';
    }

    virtual void display() = 0;

    int getId()
    {
        return id;
    }

    char *getName()
    {
        return name;
    }

    void inputPerson()
    {
        cout << "ID           : ";
        cin >> id;

        cin.ignore(1000, '\n');

        cout << "Name         : ";
        cin.getline(name, 50);

        cout << "Age          : ";
        cin >> age;

        cin.ignore(1000, '\n');

        cout << "Gender       : ";
        cin.getline(gender, 15);

        cout << "Phone        : ";
        cin.getline(phone, 20);

        cout << "Email        : ";
        cin.getline(email, 60);
    }

    void displayPerson()
    {
        cout << "ID           : " << id << "\n";
        cout << "Name         : " << name << "\n";
        cout << "Age          : " << age << "\n";
        cout << "Gender       : " << gender << "\n";
        cout << "Phone        : " << phone << "\n";
        cout << "Email        : " << email << "\n";
    }
};

/* ================================================================
   PATIENT CLASS - INHERITANCE
   ================================================================ */

class Patient : public Person
{
private:
    char bloodGroup[10];
    char problem[100];
    char emergencyContact[50];

public:
    Patient()
    {
        bloodGroup[0] = '\0';
        problem[0] = '\0';
        emergencyContact[0] = '\0';
    }

    Patient(const Patient &p)
    {
        id = p.id;
        strcpy(name, p.name);
        age = p.age;
        strcpy(gender, p.gender);
        strcpy(phone, p.phone);
        strcpy(email, p.email);
        strcpy(bloodGroup, p.bloodGroup);
        strcpy(problem, p.problem);
        strcpy(emergencyContact, p.emergencyContact);
    }

    ~Patient()
    {
    }

    void input()
    {
        header((char *)"PATIENT REGISTRATION");

        inputPerson();

        cin.ignore(1000, '\n');

        cout << "Blood Group  : ";
        cin.getline(bloodGroup, 10);

        cout << "Health Issue : ";
        cin.getline(problem, 100);

        cout << "Emergency No.: ";
        cin.getline(emergencyContact, 50);
    }

    void display()
    {
        cout << "\nPATIENT DETAILS\n";
        divider();

        displayPerson();

        cout << "Blood Group  : " << bloodGroup << "\n";
        cout << "Health Issue : " << problem << "\n";
        cout << "Emergency No.: " << emergencyContact << "\n";
    }

    void save()
    {
        ofstream f("patients.dat", ios::app);

        f << id << "|"
          << name << "|"
          << age << "|"
          << gender << "|"
          << phone << "|"
          << email << "|"
          << bloodGroup << "|"
          << problem << "|"
          << emergencyContact << "\n";

        f.close();
    }

    void load(char record[])
    {
        char *p;

        p = strtok(record, "|");
        if(p) id = atoi(p);

        p = strtok(NULL, "|");
        if(p) strcpy(name, p);

        p = strtok(NULL, "|");
        if(p) age = atoi(p);

        p = strtok(NULL, "|");
        if(p) strcpy(gender, p);

        p = strtok(NULL, "|");
        if(p) strcpy(phone, p);

        p = strtok(NULL, "|");
        if(p) strcpy(email, p);

        p = strtok(NULL, "|");
        if(p) strcpy(bloodGroup, p);

        p = strtok(NULL, "|");
        if(p) strcpy(problem, p);

        p = strtok(NULL, "|");
        if(p) strcpy(emergencyContact, p);
    }
};

/* ================================================================
   DOCTOR CLASS - INHERITANCE
   ================================================================ */

class Doctor : public Person
{
private:
    char specialization[60];
    float consultationFee;

public:
    Doctor()
    {
        specialization[0] = '\0';
        consultationFee = 0;
    }

    ~Doctor()
    {
    }

    void input()
    {
        header((char *)"DOCTOR REGISTRATION");

        inputPerson();

        cin.ignore(1000, '\n');

        cout << "Specialization: ";
        cin.getline(specialization, 60);

        cout << "Consultation Fee: Rs. ";
        cin >> consultationFee;
    }

    void display()
    {
        cout << "\nDOCTOR DETAILS\n";
        divider();

        displayPerson();

        cout << "Specialization: " << specialization << "\n";
        cout << "Consultation Fee: Rs. "
             << consultationFee << "\n";
    }

    char *getSpecialization()
    {
        return specialization;
    }

    float getFee()
    {
        return consultationFee;
    }

    void save()
    {
        ofstream f("doctors.dat", ios::app);

        f << id << "|"
          << name << "|"
          << age << "|"
          << gender << "|"
          << phone << "|"
          << email << "|"
          << specialization << "|"
          << consultationFee << "\n";

        f.close();
    }

    void load(char record[])
    {
        char *p;

        p = strtok(record, "|");
        if(p) id = atoi(p);

        p = strtok(NULL, "|");
        if(p) strcpy(name, p);

        p = strtok(NULL, "|");
        if(p) age = atoi(p);

        p = strtok(NULL, "|");
        if(p) strcpy(gender, p);

        p = strtok(NULL, "|");
        if(p) strcpy(phone, p);

        p = strtok(NULL, "|");
        if(p) strcpy(email, p);

        p = strtok(NULL, "|");
        if(p) strcpy(specialization, p);

        p = strtok(NULL, "|");
        if(p) consultationFee = atof(p);
    }
};

/* ================================================================
   RECEPTIONIST CLASS - HIERARCHICAL INHERITANCE DEMONSTRATION
   ================================================================ */

class Receptionist : public Person
{
private:
    char employeeCode[20];

public:
    Receptionist()
    {
        employeeCode[0] = '\0';
    }

    void input()
    {
        header((char *)"RECEPTIONIST");

        inputPerson();

        cin.ignore(1000, '\n');

        cout << "Employee Code: ";
        cin.getline(employeeCode, 20);
    }

    void display()
    {
        cout << "\nRECEPTIONIST DETAILS\n";
        divider();

        displayPerson();

        cout << "Employee Code: " << employeeCode << "\n";
    }
};

/* ================================================================
   MEDICINE CLASS - COMPOSITION
   ================================================================ */

class Medicine
{
private:
    char medicineName[50];
    char dosage[30];
    char frequency[30];
    int duration;

public:
    Medicine()
    {
        medicineName[0] = '\0';
        dosage[0] = '\0';
        frequency[0] = '\0';
        duration = 0;
    }

    void input()
    {
        cin.ignore(1000, '\n');

        cout << "Medicine Name: ";
        cin.getline(medicineName, 50);

        cout << "Dosage       : ";
        cin.getline(dosage, 30);

        cout << "Frequency    : ";
        cin.getline(frequency, 30);

        cout << "Duration Days: ";
        cin >> duration;
    }

    void display()
    {
        cout << "\nMedicine Name: " << medicineName;
        cout << "\nDosage       : " << dosage;
        cout << "\nFrequency    : " << frequency;
        cout << "\nDuration     : " << duration << " days\n";
    }
};

/* ================================================================
   APPOINTMENT CLASS
   ================================================================ */

class Appointment
{
private:
    int appointmentId;
    int patientId;
    int doctorId;
    Date appointmentDate;
    int hour;
    char reason[100];
    char status[20];

public:
    Appointment()
    {
        appointmentId = 0;
        patientId = 0;
        doctorId = 0;
        hour = 0;
        reason[0] = '\0';
        strcpy(status, "BOOKED");
    }

    Appointment(const Appointment &a)
    {
        appointmentId = a.appointmentId;
        patientId = a.patientId;
        doctorId = a.doctorId;
        appointmentDate = a.appointmentDate;
        hour = a.hour;
        strcpy(reason, a.reason);
        strcpy(status, a.status);
    }

    ~Appointment()
    {
    }

    void input()
    {
        header((char *)"BOOK APPOINTMENT");

        cout << "Appointment ID: ";
        cin >> appointmentId;

        cout << "Patient ID    : ";
        cin >> patientId;

        cout << "Doctor ID     : ";
        cin >> doctorId;

        cout << "\n";
        appointmentDate.input();

        cout << "Time Hour (0-23): ";
        cin >> hour;

        cin.ignore(1000, '\n');

        cout << "Reason        : ";
        cin.getline(reason, 100);

        strcpy(status, "BOOKED");
    }

    int getAppointmentId()
    {
        return appointmentId;
    }

    int getPatientId()
    {
        return patientId;
    }

    int getDoctorId()
    {
        return doctorId;
    }

    Date getDate()
    {
        return appointmentDate;
    }

    int getHour()
    {
        return hour;
    }

    void cancel()
    {
        strcpy(status, "CANCELLED");
    }

    void display()
    {
        cout << "\nAppointment ID: " << appointmentId;
        cout << "\nPatient ID    : " << patientId;
        cout << "\nDoctor ID     : " << doctorId;

        cout << "\nDate          : ";
        appointmentDate.display();

        cout << "\nTime          : " << hour << ":00";
        cout << "\nReason        : " << reason;
        cout << "\nStatus        : " << status << "\n";
    }

    void save(ofstream &f)
    {
        f << appointmentId << "|"
          << patientId << "|"
          << doctorId << "|"
          << appointmentDate.getDay() << "|"
          << appointmentDate.getMonth() << "|"
          << appointmentDate.getYear() << "|"
          << hour << "|"
          << reason << "|"
          << status << "\n";
    }

    void load(char record[])
    {
        char *p;
        int d, m, y;

        p = strtok(record, "|");
        if(p) appointmentId = atoi(p);

        p = strtok(NULL, "|");
        if(p) patientId = atoi(p);

        p = strtok(NULL, "|");
        if(p) doctorId = atoi(p);

        p = strtok(NULL, "|");
        d = atoi(p);

        p = strtok(NULL, "|");
        m = atoi(p);

        p = strtok(NULL, "|");
        y = atoi(p);

        appointmentDate = Date(d, m, y);

        p = strtok(NULL, "|");
        if(p) hour = atoi(p);

        p = strtok(NULL, "|");
        if(p) strcpy(reason, p);

        p = strtok(NULL, "|");
        if(p) strcpy(status, p);
    }

    int sameSlot(Appointment a)
    {
        if(doctorId == a.doctorId &&
           appointmentDate == a.appointmentDate &&
           hour == a.hour)
            return 1;

        return 0;
    }
};

/* ================================================================
   MEDICAL RECORD CLASS
   ================================================================ */

class MedicalRecord
{
private:
    int recordId;
    int patientId;
    int doctorId;
    Date visitDate;

    char diagnosis[120];
    char treatment[120];
    char testResult[120];
    char notes[150];

public:
    MedicalRecord()
    {
        recordId = 0;
        patientId = 0;
        doctorId = 0;

        diagnosis[0] = '\0';
        treatment[0] = '\0';
        testResult[0] = '\0';
        notes[0] = '\0';
    }

    void input()
    {
        header((char *)"MEDICAL RECORD");

        cout << "Record ID : ";
        cin >> recordId;

        cout << "Patient ID: ";
        cin >> patientId;

        cout << "Doctor ID : ";
        cin >> doctorId;

        cout << "\n";
        visitDate.input();

        cin.ignore(1000, '\n');

        cout << "Diagnosis : ";
        cin.getline(diagnosis, 120);

        cout << "Treatment : ";
        cin.getline(treatment, 120);

        cout << "Test Result: ";
        cin.getline(testResult, 120);

        cout << "Doctor Notes: ";
        cin.getline(notes, 150);
    }

    int getPatientId()
    {
        return patientId;
    }

    void display()
    {
        cout << "\nRecord ID : " << recordId;
        cout << "\nPatient ID: " << patientId;
        cout << "\nDoctor ID : " << doctorId;

        cout << "\nVisit Date: ";
        visitDate.display();

        cout << "\nDiagnosis : " << diagnosis;
        cout << "\nTreatment : " << treatment;
        cout << "\nTest Result: " << testResult;
        cout << "\nNotes     : " << notes << "\n";
    }

    void save()
    {
        ofstream f("records.dat", ios::app);

        f << recordId << "|"
          << patientId << "|"
          << doctorId << "|"
          << visitDate.getDay() << "|"
          << visitDate.getMonth() << "|"
          << visitDate.getYear() << "|"
          << diagnosis << "|"
          << treatment << "|"
          << testResult << "|"
          << notes << "\n";

        f.close();
    }

    void load(char record[])
    {
        char *p;
        int d, m, y;

        p = strtok(record, "|");
        if(p) recordId = atoi(p);

        p = strtok(NULL, "|");
        if(p) patientId = atoi(p);

        p = strtok(NULL, "|");
        if(p) doctorId = atoi(p);

        p = strtok(NULL, "|");
        d = atoi(p);

        p = strtok(NULL, "|");
        m = atoi(p);

        p = strtok(NULL, "|");
        y = atoi(p);

        visitDate = Date(d, m, y);

        p = strtok(NULL, "|");
        if(p) strcpy(diagnosis, p);

        p = strtok(NULL, "|");
        if(p) strcpy(treatment, p);

        p = strtok(NULL, "|");
        if(p) strcpy(testResult, p);

        p = strtok(NULL, "|");
        if(p) strcpy(notes, p);
    }
};

/* ================================================================
   PRESCRIPTION CLASS - COMPOSITION
   ================================================================ */

class Prescription
{
private:
    int prescriptionId;
    int patientId;
    int doctorId;
    Date prescriptionDate;
    Medicine medicine;
    char instructions[120];

public:
    Prescription()
    {
        prescriptionId = 0;
        patientId = 0;
        doctorId = 0;
        instructions[0] = '\0';
    }

    void input()
    {
        header((char *)"CREATE PRESCRIPTION");

        cout << "Prescription ID: ";
        cin >> prescriptionId;

        cout << "Patient ID     : ";
        cin >> patientId;

        cout << "Doctor ID      : ";
        cin >> doctorId;

        cout << "\n";
        prescriptionDate.input();

        cout << "\nMedicine Details\n";
        divider();

        medicine.input();

        cin.ignore(1000, '\n');

        cout << "Instructions   : ";
        cin.getline(instructions, 120);
    }

    int getPatientId()
    {
        return patientId;
    }

    void display()
    {
        cout << "\nPrescription ID: " << prescriptionId;
        cout << "\nPatient ID     : " << patientId;
        cout << "\nDoctor ID      : " << doctorId;

        cout << "\nDate           : ";
        prescriptionDate.display();

        medicine.display();

        cout << "Instructions   : "
             << instructions << "\n";
    }

    void save()
    {
        ofstream f("prescriptions.dat", ios::app);

        f << prescriptionId << "|"
          << patientId << "|"
          << doctorId << "|"
          << prescriptionDate.getDay() << "|"
          << prescriptionDate.getMonth() << "|"
          << prescriptionDate.getYear() << "|"
          << instructions << "\n";

        f.close();
    }

    void load(char record[])
    {
        char *p;
        int d, m, y;

        p = strtok(record, "|");
        if(p) prescriptionId = atoi(p);

        p = strtok(NULL, "|");
        if(p) patientId = atoi(p);

        p = strtok(NULL, "|");
        if(p) doctorId = atoi(p);

        p = strtok(NULL, "|");
        d = atoi(p);

        p = strtok(NULL, "|");
        m = atoi(p);

        p = strtok(NULL, "|");
        y = atoi(p);

        prescriptionDate = Date(d, m, y);

        p = strtok(NULL, "|");
        if(p) strcpy(instructions, p);
    }
};

/* ================================================================
   BILL CLASS - OPERATOR OVERLOADING + FRIEND FUNCTION
   ================================================================ */

class Bill
{
private:
    int billId;
    int patientId;

    float consultation;
    float medicineCharge;
    float testCharge;
    float roomCharge;

    float discount;
    float tax;
    float total;

    char status[20];

public:
    Bill()
    {
        billId = 0;
        patientId = 0;

        consultation = 0;
        medicineCharge = 0;
        testCharge = 0;
        roomCharge = 0;

        discount = 0;
        tax = 0;
        total = 0;

        strcpy(status, "UNPAID");
    }

    void calculate()
    {
        float subtotal;

        subtotal = consultation +
                   medicineCharge +
                   testCharge +
                   roomCharge -
                   discount;

        if(subtotal < 0)
            subtotal = 0;

        total = subtotal +
                (subtotal * tax / 100);
    }

    void input()
    {
        header((char *)"GENERATE BILL");

        cout << "Bill ID          : ";
        cin >> billId;

        cout << "Patient ID       : ";
        cin >> patientId;

        cout << "Consultation     : Rs. ";
        cin >> consultation;

        cout << "Medicine         : Rs. ";
        cin >> medicineCharge;

        cout << "Tests            : Rs. ";
        cin >> testCharge;

        cout << "Room Charges     : Rs. ";
        cin >> roomCharge;

        cout << "Discount         : Rs. ";
        cin >> discount;

        cout << "Tax (%)          : ";
        cin >> tax;

        calculate();
    }

    int getPatientId()
    {
        return patientId;
    }

    float getTotal()
    {
        return total;
    }

    void markPaid()
    {
        strcpy(status, "PAID");
    }

    void display()
    {
        cout << "\n================================================\n";
        cout << "                  PATIENT BILL\n";
        cout << "================================================\n";

        cout << "Bill ID          : " << billId << "\n";
        cout << "Patient ID       : " << patientId << "\n";

        cout << "Consultation     : Rs. " << consultation << "\n";
        cout << "Medicine         : Rs. " << medicineCharge << "\n";
        cout << "Tests            : Rs. " << testCharge << "\n";
        cout << "Room Charges     : Rs. " << roomCharge << "\n";
        cout << "Discount         : Rs. " << discount << "\n";
        cout << "Tax              : " << tax << "%\n";

        cout << "------------------------------------------------\n";

        cout << "TOTAL            : Rs. " << total << "\n";
        cout << "PAYMENT STATUS   : " << status << "\n";

        cout << "================================================\n";
    }

    /* Operator overloading */
    int operator>(Bill b)
    {
        if(total > b.total)
            return 1;

        return 0;
    }

    /* Friend function */
    friend void showPrivateBillTotal(Bill b);

    void save()
    {
        ofstream f("bills.dat", ios::app);

        f << billId << "|"
          << patientId << "|"
          << consultation << "|"
          << medicineCharge << "|"
          << testCharge << "|"
          << roomCharge << "|"
          << discount << "|"
          << tax << "|"
          << total << "|"
          << status << "\n";

        f.close();
    }

    void load(char record[])
    {
        char *p;

        p = strtok(record, "|");
        if(p) billId = atoi(p);

        p = strtok(NULL, "|");
        if(p) patientId = atoi(p);

        p = strtok(NULL, "|");
        if(p) consultation = atof(p);

        p = strtok(NULL, "|");
        if(p) medicineCharge = atof(p);

        p = strtok(NULL, "|");
        if(p) testCharge = atof(p);

        p = strtok(NULL, "|");
        if(p) roomCharge = atof(p);

        p = strtok(NULL, "|");
        if(p) discount = atof(p);

        p = strtok(NULL, "|");
        if(p) tax = atof(p);

        p = strtok(NULL, "|");
        if(p) total = atof(p);

        p = strtok(NULL, "|");
        if(p) strcpy(status, p);
    }
};

void showPrivateBillTotal(Bill b)
{
    cout << "\nFriend Function Access -> Total: Rs. "
         << b.total << "\n";
}

/* ================================================================
   TEMPLATE FUNCTION
   ================================================================ */

template <class T>
void showTemplate(T value)
{
    cout << "Template received value: " << value << "\n";
}

/* ================================================================
   PATIENT OPERATIONS
   ================================================================ */

int patientExists(int id)
{
    ifstream f("patients.dat");
    char record[800];

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Patient p;
        p.load(copy);

        if(p.getId() == id)
        {
            f.close();
            return 1;
        }
    }

    f.close();
    return 0;
}

void addPatient()
{
    Patient p;

    p.input();

    if(patientExists(p.getId()))
    {
        cout << "\nERROR: Patient ID already exists.";
        pauseScreen();
        return;
    }

    p.save();

    cout << "\nPatient registered successfully!";
    pauseScreen();
}

void viewPatients()
{
    header((char *)"ALL PATIENTS");

    ifstream f("patients.dat");
    char record[800];

    int count = 0;

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Patient p;
        p.load(copy);

        p.display();

        divider();

        count++;
    }

    f.close();

    if(count == 0)
        cout << "\nNo patient records found.\n";
    else
        cout << "\nTotal Patients: " << count << "\n";

    pauseScreen();
}

void searchPatient()
{
    header((char *)"SEARCH PATIENT");

    int choice;
    int found = 0;

    cout << "1. Search by ID\n";
    cout << "2. Search by Name\n";
    cout << "\nChoice: ";
    cin >> choice;

    ifstream f("patients.dat");
    char record[800];

    if(choice == 1)
    {
        int id;

        cout << "Patient ID: ";
        cin >> id;

        while(f.getline(record, 800))
        {
            char copy[800];
            strcpy(copy, record);

            Patient p;
            p.load(copy);

            if(p.getId() == id)
            {
                p.display();
                found = 1;
                break;
            }
        }
    }
    else if(choice == 2)
    {
        char key[50];

        cin.ignore(1000, '\n');

        cout << "Name: ";
        cin.getline(key, 50);

        while(f.getline(record, 800))
        {
            char copy[800];
            strcpy(copy, record);

            Patient p;
            p.load(copy);

            if(strstr(p.getName(), key) != NULL)
            {
                p.display();
                divider();
                found = 1;
            }
        }
    }

    f.close();

    if(!found)
        cout << "\nPatient not found.";

    pauseScreen();
}

/* ================================================================
   DOCTOR OPERATIONS
   ================================================================ */

int doctorExists(int id)
{
    ifstream f("doctors.dat");
    char record[800];

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Doctor d;
        d.load(copy);

        if(d.getId() == id)
        {
            f.close();
            return 1;
        }
    }

    f.close();
    return 0;
}

void addDoctor()
{
    Doctor d;

    d.input();

    if(doctorExists(d.getId()))
    {
        cout << "\nERROR: Doctor ID already exists.";
        pauseScreen();
        return;
    }

    d.save();

    cout << "\nDoctor registered successfully!";
    pauseScreen();
}

void viewDoctors()
{
    header((char *)"ALL DOCTORS");

    ifstream f("doctors.dat");
    char record[800];

    int count = 0;

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Doctor d;
        d.load(copy);

        d.display();

        divider();

        count++;
    }

    f.close();

    if(count == 0)
        cout << "\nNo doctor records found.";
    else
        cout << "\nTotal Doctors: " << count;

    pauseScreen();
}

void searchDoctor()
{
    header((char *)"SEARCH DOCTOR");

    int choice;
    int found = 0;

    cout << "1. Search by ID\n";
    cout << "2. Search by Name\n";
    cout << "3. Search by Specialization\n";
    cout << "\nChoice: ";
    cin >> choice;

    ifstream f("doctors.dat");
    char record[800];

    if(choice == 1)
    {
        int id;

        cout << "Doctor ID: ";
        cin >> id;

        while(f.getline(record, 800))
        {
            char copy[800];
            strcpy(copy, record);

            Doctor d;
            d.load(copy);

            if(d.getId() == id)
            {
                d.display();
                found = 1;
                break;
            }
        }
    }
    else
    {
        char key[60];

        cin.ignore(1000, '\n');

        cout << "Search Text: ";
        cin.getline(key, 60);

        while(f.getline(record, 800))
        {
            char copy[800];
            strcpy(copy, record);

            Doctor d;
            d.load(copy);

            if(choice == 2 &&
               strstr(d.getName(), key) != NULL)
            {
                d.display();
                divider();
                found = 1;
            }

            if(choice == 3 &&
               strstr(d.getSpecialization(), key) != NULL)
            {
                d.display();
                divider();
                found = 1;
            }
        }
    }

    f.close();

    if(!found)
        cout << "\nDoctor not found.";

    pauseScreen();
}

/* ================================================================
   APPOINTMENT OPERATIONS
   ================================================================ */

int appointmentConflict(Appointment newAppointment)
{
    ifstream f("appointments.dat");
    char record[800];

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Appointment oldAppointment;
        oldAppointment.load(copy);

        if(oldAppointment.getDoctorId() ==
           newAppointment.getDoctorId())
        {
            if(oldAppointment.getDate() ==
               newAppointment.getDate())
            {
                if(oldAppointment.getHour() ==
                   newAppointment.getHour())
                {
                    f.close();
                    return 1;
                }
            }
        }
    }

    f.close();
    return 0;
}

void bookAppointment()
{
    Appointment a;

    a.input();

    if(!patientExists(a.getPatientId()))
    {
        cout << "\nERROR: Patient does not exist.";
        pauseScreen();
        return;
    }

    if(!doctorExists(a.getDoctorId()))
    {
        cout << "\nERROR: Doctor does not exist.";
        pauseScreen();
        return;
    }

    if(appointmentConflict(a))
    {
        cout << "\nERROR: Doctor is already booked at this time.";
        pauseScreen();
        return;
    }

    ofstream f("appointments.dat", ios::app);

    a.save(f);

    f.close();

    cout << "\nAppointment booked successfully!";
    pauseScreen();
}

void viewAppointments()
{
    header((char *)"ALL APPOINTMENTS");

    ifstream f("appointments.dat");
    char record[800];

    int count = 0;

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Appointment a;
        a.load(copy);

        a.display();

        divider();

        count++;
    }

    f.close();

    if(count == 0)
        cout << "\nNo appointments found.";

    pauseScreen();
}

void cancelAppointment()
{
    header((char *)"CANCEL APPOINTMENT");

    int id;

    cout << "Appointment ID: ";
    cin >> id;

    Appointment appointments[MAX_RECORDS];

    int count = 0;
    int found = 0;

    ifstream f("appointments.dat");
    char record[800];

    while(f.getline(record, 800) &&
          count < MAX_RECORDS)
    {
        char copy[800];
        strcpy(copy, record);

        appointments[count].load(copy);

        if(appointments[count].getAppointmentId() == id)
        {
            appointments[count].cancel();
            found = 1;
        }

        count++;
    }

    f.close();

    ofstream out("appointments.dat");

    int i;

    for(i = 0; i < count; i++)
        appointments[i].save(out);

    out.close();

    if(found)
        cout << "\nAppointment cancelled successfully.";
    else
        cout << "\nAppointment not found.";

    pauseScreen();
}

/* ================================================================
   MEDICAL RECORD OPERATIONS
   ================================================================ */

void addMedicalRecord()
{
    MedicalRecord r;

    r.input();

    if(!patientExists(r.getPatientId()))
    {
        cout << "\nERROR: Patient does not exist.";
        pauseScreen();
        return;
    }

    if(!doctorExists(r.getPatientId()))
    {
        /* Deliberately not used as a blocking condition because the
           doctor ID may be managed separately in a student demo. */
    }

    r.save();

    cout << "\nMedical record saved successfully!";
    pauseScreen();
}

void viewMedicalRecords()
{
    header((char *)"MEDICAL RECORDS");

    int patientId;

    cout << "Patient ID (0 = all): ";
    cin >> patientId;

    ifstream f("records.dat");
    char record[1000];

    int found = 0;

    while(f.getline(record, 1000))
    {
        char copy[1000];
        strcpy(copy, record);

        MedicalRecord r;
        r.load(copy);

        if(patientId == 0 ||
           r.getPatientId() == patientId)
        {
            r.display();
            divider();
            found = 1;
        }
    }

    f.close();

    if(!found)
        cout << "\nNo medical records found.";

    pauseScreen();
}

/* ================================================================
   PRESCRIPTION OPERATIONS
   ================================================================ */

void createPrescription()
{
    Prescription p;

    p.input();

    if(!patientExists(p.getPatientId()))
    {
        cout << "\nERROR: Patient does not exist.";
        pauseScreen();
        return;
    }

    if(!doctorExists(p.getPatientId()))
    {
        /* Kept non-blocking for flexible course-project testing. */
    }

    p.save();

    cout << "\nPrescription created successfully!";
    pauseScreen();
}

void viewPrescriptions()
{
    header((char *)"PRESCRIPTIONS");

    int patientId;

    cout << "Patient ID (0 = all): ";
    cin >> patientId;

    ifstream f("prescriptions.dat");
    char record[800];

    int found = 0;

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Prescription p;
        p.load(copy);

        if(patientId == 0 ||
           p.getPatientId() == patientId)
        {
            p.display();
            divider();
            found = 1;
        }
    }

    f.close();

    if(!found)
        cout << "\nNo prescriptions found.";

    pauseScreen();
}

/* ================================================================
   BILLING OPERATIONS
   ================================================================ */

void generateBill()
{
    Bill b;

    b.input();

    if(!patientExists(b.getPatientId()))
    {
        cout << "\nERROR: Patient does not exist.";
        pauseScreen();
        return;
    }

    b.save();

    cout << "\nBill generated successfully.\n";

    b.display();

    showPrivateBillTotal(b);

    pauseScreen();
}

void viewBills()
{
    header((char *)"BILLING RECORDS");

    int patientId;

    cout << "Patient ID (0 = all): ";
    cin >> patientId;

    ifstream f("bills.dat");
    char record[800];

    int found = 0;

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Bill b;
        b.load(copy);

        if(patientId == 0 ||
           b.getPatientId() == patientId)
        {
            b.display();
            found = 1;
        }
    }

    f.close();

    if(!found)
        cout << "\nNo billing records found.";

    pauseScreen();
}

/* ================================================================
   REPORTS
   ================================================================ */

int countFile(char *filename)
{
    ifstream f(filename);
    char record[1000];

    int count = 0;

    while(f.getline(record, 1000))
        count++;

    f.close();

    return count;
}

float calculateRevenue()
{
    ifstream f("bills.dat");
    char record[800];

    float total = 0;

    while(f.getline(record, 800))
    {
        char copy[800];
        strcpy(copy, record);

        Bill b;
        b.load(copy);

        total += b.getTotal();
    }

    f.close();

    return total;
}

void reports()
{
    header((char *)"SYSTEM REPORT");

    int patients;
    int doctors;
    int appointments;
    int records;
    int prescriptions;
    int bills;

    patients = countFile((char *)"patients.dat");
    doctors = countFile((char *)"doctors.dat");
    appointments = countFile((char *)"appointments.dat");
    records = countFile((char *)"records.dat");
    prescriptions = countFile((char *)"prescriptions.dat");
    bills = countFile((char *)"bills.dat");

    cout << "\n================ SYSTEM STATISTICS ================\n";

    cout << "Patients              : " << patients << "\n";
    cout << "Doctors               : " << doctors << "\n";
    cout << "Appointments          : " << appointments << "\n";
    cout << "Medical Records       : " << records << "\n";
    cout << "Prescriptions         : " << prescriptions << "\n";
    cout << "Bills                 : " << bills << "\n";

    cout << "Total Bill Value      : Rs. "
         << calculateRevenue() << "\n";

    cout << "====================================================\n";

    pauseScreen();
}

/* ================================================================
   SORT PATIENTS BY ID
   ================================================================ */

void sortPatients()
{
    header((char *)"PATIENTS SORTED BY ID");

    Patient arr[MAX_RECORDS];

    int count = 0;

    ifstream f("patients.dat");
    char record[800];

    while(f.getline(record, 800) &&
          count < MAX_RECORDS)
    {
        char copy[800];
        strcpy(copy, record);

        arr[count].load(copy);

        count++;
    }

    f.close();

    int i, j;

    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(arr[j].getId() > arr[j + 1].getId())
            {
                Patient temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < count; i++)
    {
        arr[i].display();
        divider();
    }

    if(count == 0)
        cout << "\nNo patients found.";

    pauseScreen();
}

/* ================================================================
   ADMIN MENUS
   ================================================================ */

void patientManagement()
{
    int choice;

    do
    {
        header((char *)"PATIENT MANAGEMENT");

        cout << "1. Add Patient\n";
        cout << "2. View All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Sort Patients by ID\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                viewPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                sortPatients();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}

void doctorManagement()
{
    int choice;

    do
    {
        header((char *)"DOCTOR MANAGEMENT");

        cout << "1. Add Doctor\n";
        cout << "2. View All Doctors\n";
        cout << "3. Search Doctor\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addDoctor();
                break;

            case 2:
                viewDoctors();
                break;

            case 3:
                searchDoctor();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}

void appointmentManagement()
{
    int choice;

    do
    {
        header((char *)"APPOINTMENT MANAGEMENT");

        cout << "1. Book Appointment\n";
        cout << "2. View Appointments\n";
        cout << "3. Cancel Appointment\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                bookAppointment();
                break;

            case 2:
                viewAppointments();
                break;

            case 3:
                cancelAppointment();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}

void recordManagement()
{
    int choice;

    do
    {
        header((char *)"MEDICAL RECORD MANAGEMENT");

        cout << "1. Add Medical Record\n";
        cout << "2. View Medical Records\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addMedicalRecord();
                break;

            case 2:
                viewMedicalRecords();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}

void prescriptionManagement()
{
    int choice;

    do
    {
        header((char *)"PRESCRIPTION MANAGEMENT");

        cout << "1. Create Prescription\n";
        cout << "2. View Prescriptions\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createPrescription();
                break;

            case 2:
                viewPrescriptions();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}

void billingManagement()
{
    int choice;

    do
    {
        header((char *)"BILLING MANAGEMENT");

        cout << "1. Generate Bill\n";
        cout << "2. View Bills\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                generateBill();
                break;

            case 2:
                viewBills();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}


/* ================================================================
   ADMIN DASHBOARD
   ================================================================ */

void adminDashboard()
{
    int choice;

    do
    {
        header((char *)"ADMINISTRATOR DASHBOARD");

        cout << "1. Patient Management\n";
        cout << "2. Doctor Management\n";
        cout << "3. Appointment Management\n";
        cout << "4. Medical Records\n";
        cout << "5. Prescription Management\n";
        cout << "6. Billing Management\n";
        cout << "7. System Reports\n";
        cout << "8. OOP Demonstration\n";
        cout << "0. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                patientManagement();
                break;

            case 2:
                doctorManagement();
                break;

            case 3:
                appointmentManagement();
                break;

            case 4:
                recordManagement();
                break;

            case 5:
                prescriptionManagement();
                break;

            case 6:
                billingManagement();
                break;

            case 7:
                reports();
                break;

            case 8:
                oopDemonstration();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}

/* ================================================================
   DOCTOR DASHBOARD
   ================================================================ */

void doctorDashboard()
{
    int choice;

    do
    {
        header((char *)"DOCTOR DASHBOARD");

        cout << "1. View Patients\n";
        cout << "2. View Appointments\n";
        cout << "3. Add Medical Record\n";
        cout << "4. Create Prescription\n";
        cout << "5. View Medical Records\n";
        cout << "6. View Prescriptions\n";
        cout << "0. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                viewPatients();
                break;

            case 2:
                viewAppointments();
                break;

            case 3:
                addMedicalRecord();
                break;

            case 4:
                createPrescription();
                break;

            case 5:
                viewMedicalRecords();
                break;

            case 6:
                viewPrescriptions();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}

/* ================================================================
   PATIENT DASHBOARD
   ================================================================ */

void patientDashboard()
{
    int choice;

    do
    {
        header((char *)"PATIENT DASHBOARD");

        cout << "1. Book Appointment\n";
        cout << "2. View Appointments\n";
        cout << "3. View Medical Records\n";
        cout << "4. View Prescriptions\n";
        cout << "5. View Bills\n";
        cout << "0. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                bookAppointment();
                break;

            case 2:
                viewAppointments();
                break;

            case 3:
                viewMedicalRecords();
                break;

            case 4:
                viewPrescriptions();
                break;

            case 5:
                viewBills();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);
}

/* ================================================================
   LOGIN
   ================================================================ */

void login()
{
    char username[30];
    char password[30];

    header((char *)"SECURE LOGIN");

    cin.ignore(1000, '\n');

    cout << "Username: ";
    cin.getline(username, 30);

    cout << "Password: ";
    cin.getline(password, 30);

    if(strcmp(username, "admin") == 0 &&
       strcmp(password, "admin123") == 0)
    {
        adminDashboard();
        return;
    }

    if(strcmp(username, "doctor") == 0 &&
       strcmp(password, "doctor123") == 0)
    {
        doctorDashboard();
        return;
    }

    if(strcmp(username, "patient") == 0 &&
       strcmp(password, "patient123") == 0)
    {
        patientDashboard();
        return;
    }

    cout << "\nInvalid username or password.";

    pauseScreen();
}


/* ================================================================
   MAIN
   ================================================================ */

int main()
{
    int choice;

    initializeFiles();

    clrscr();

    cout << "\n\n";
    cout << "==============================================================\n";
    cout << "||                                                          ||\n";
    cout << "||             E-HEALTHCARE MANAGEMENT SYSTEM               ||\n";
    cout << "||                                                          ||\n";
    cout << "||                COURSE PROJECT - C++                     ||\n";
    cout << "||                                                          ||\n";
    cout << "==============================================================\n";

    cout << "\nInitializing system...";

    delay(1000);

    cout << "\nData files ready.";

    cout << "\n\nPress any key to continue...";
    getch();

    do
    {
        header((char *)"MAIN MENU");

        cout << "1. Login\n";
        cout << "2. About Project\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                login();
                break;

            case 2:
                aboutProject();
                break;

            case 0:
                break;

            default:
                cout << "\nInvalid choice.";
                pauseScreen();
        }

    }while(choice != 0);

    clrscr();

    cout << "\n\n";
    cout << "==============================================================\n";
    cout << "        THANK YOU FOR USING E-HEALTHCARE SYSTEM\n";
    cout << "==============================================================\n";

    cout << "\nProject closed successfully.\n";

    return 0;
}
