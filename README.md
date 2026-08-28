# 🏥 e-Healthcare Management System

A C++ based **e-Healthcare Management System** developed as an Object-Oriented Programming course project. The system aims to digitally manage healthcare operations such as patient registration, doctor management, appointments, medical records, prescriptions, billing, and administrative activities.

The project is designed not only as a functional healthcare application but also as a practical demonstration of **Object-Oriented Programming concepts in C++**.

---

## 🎯 Project Objectives

* Develop a structured healthcare management system using C++.
* Apply Object-Oriented Programming principles to a real-world problem.
* Demonstrate all major OOP concepts covered in the course.
* Implement reusable, modular, and maintainable classes.
* Handle persistent data using file handling.
* Implement appropriate data structures and STL containers.
* Provide different functionalities for patients, doctors, and administrators.
* Demonstrate relationships between multiple classes through a realistic system.

---

# 📋 Work Plan

The project will be developed incrementally in the following phases.

## Phase 1 — Requirement Analysis & System Design

### Tasks

* Identify system users:

  * Administrator
  * Doctor
  * Patient
  * Receptionist
* Identify major system modules.
* Define relationships between entities.
* Design class hierarchy.
* Prepare UML/Class Diagram.
* Define data that needs to be stored persistently.

### Planned Modules

```text
e-Healthcare Management System
│
├── User Management
├── Patient Management
├── Doctor Management
├── Appointment Management
├── Medical Records
├── Prescription Management
├── Billing Management
├── Hospital/Department Management
├── Search & Reports
└── File/Data Management
```

---

# Phase 2 — Core Class Design

The initial class structure will be designed around a common base class.

### Proposed Class Hierarchy

```text
                         Person
                           │
              ┌────────────┼────────────┐
              │            │            │
           Patient       Doctor      Receptionist
                           │
                    ┌──────┴──────┐
                    │             │
              Specialist       GeneralDoctor
```

Additional independent classes:

```text
Appointment
MedicalRecord
Prescription
Medicine
Bill
Payment
Department
Hospital
Address
Date
```

### OOP Concepts

This phase will demonstrate:

* Classes
* Objects
* Data members
* Member functions
* Access specifiers
* Encapsulation
* Constructors
* Destructors
* `this` pointer
* Static data members
* Static member functions

---

# Phase 3 — Constructors & Object Lifecycle

Different types of constructors will be implemented wherever meaningful.

### Concepts to Cover

* Default constructor
* Parameterized constructor
* Copy constructor
* Constructor overloading
* Destructor
* Constructor chaining
* Dynamic object creation

### Example

```cpp
Patient();
Patient(int id, string name, int age);
Patient(const Patient& other);
~Patient();
```

The project will demonstrate how objects are created, copied, initialized, and destroyed.

---

# Phase 4 — Encapsulation & Data Validation

Sensitive healthcare information should not be directly accessible from outside the class.

### Implementation

Private data members will be used with public methods for controlled access.

```cpp
class Patient {
private:
    int patientId;
    string name;
    int age;

public:
    void setAge(int age);
    int getAge() const;
};
```

### Concepts

* `private`
* `public`
* `protected`
* Getters and setters
* Data validation
* Information hiding
* Const member functions

---

# Phase 5 — Inheritance

Inheritance will be used to model different types of users.

### Example

```text
Person
  │
  ├── Patient
  ├── Doctor
  └── Receptionist
```

Further specialization:

```text
Doctor
  │
  ├── GeneralDoctor
  ├── Cardiologist
  ├── Neurologist
  └── Orthopedic
```

### Types of Inheritance to Demonstrate

* Single inheritance
* Multilevel inheritance
* Hierarchical inheritance

Where appropriate, multiple inheritance can also be demonstrated through supporting classes.

---

# Phase 6 — Polymorphism

Polymorphism will be an important part of the project.

## Compile-Time Polymorphism

Implement:

* Function overloading
* Operator overloading

Example:

```cpp
void searchPatient(int id);
void searchPatient(string name);
```

## Run-Time Polymorphism

Virtual functions will be used with the `Person` hierarchy.

```cpp
class Person {
public:
    virtual void displayProfile();
    virtual ~Person();
};
```

Derived classes will override the function:

```cpp
class Doctor : public Person {
public:
    void displayProfile() override;
};
```

### Concepts

* Function overloading
* Method overriding
* Virtual functions
* Pure virtual functions
* Abstract classes
* Virtual destructors
* Dynamic binding
* Base-class pointers

---

# Phase 7 — Abstraction & Abstract Classes

Common behavior will be defined through abstract interfaces.

For example:

```text
Person
   │
   ├── Patient
   ├── Doctor
   └── Receptionist
```

`Person` can contain common attributes and abstract operations.

```cpp
class Person {
public:
    virtual void displayProfile() = 0;
    virtual ~Person() {}
};
```

This will demonstrate:

* Abstraction
* Abstract classes
* Pure virtual functions
* Interfaces through abstract classes

---

# Phase 8 — Friend Functions & Friend Classes

Friend functionality will be incorporated where it has a reasonable use case.

For example, a billing or reporting component may require controlled access to private information from another class.

### Concepts

* Friend function
* Friend class
* Accessing private members through friendship

Example:

```cpp
class Bill {
private:
    double amount;

    friend void generateInvoice(const Bill&);
};
```

Friend functionality will only be used where it makes architectural sense rather than being added artificially.

---

# Phase 9 — Operator Overloading

Operators will be overloaded for suitable domain objects.

Possible implementations:

```text
Appointment comparison
Bill comparison
Date comparison
Prescription/record operations
```

Example:

```cpp
bool operator==(const Appointment& other);
```

Possible operators:

* `==`
* `!=`
* `<`
* `>`
* `<<`
* `>>`

Stream operators may also be used to display or input objects.

---

# Phase 10 — Composition & Aggregation

Real-world relationships between healthcare entities will be represented using object relationships.

### Composition

```text
Patient
  └── Address
```

A patient's address can be modeled as a component of the patient.

### Aggregation

```text
Hospital
  ├── Doctors
  ├── Patients
  └── Departments
```

The system will demonstrate the difference between:

* Association
* Aggregation
* Composition

---

# Phase 11 — Templates

Templates will be introduced to demonstrate generic programming.

### Function Template

```cpp
template <typename T>
void display(T value);
```

### Class Template

A generic repository/container can be created for storing objects.

```cpp
template <class T>
class Repository {
    // Generic storage operations
};
```

This can be used for:

```text
Repository<Patient>
Repository<Doctor>
Repository<Appointment>
```

---

# Phase 12 — STL & Data Structures

The project will use appropriate C++ Standard Template Library containers.

### Planned STL Components

| STL Component    | Possible Usage                   |
| ---------------- | -------------------------------- |
| `vector`         | Patient/Doctor lists             |
| `list`           | Appointment records              |
| `map`            | ID-based lookup                  |
| `unordered_map`  | Fast record lookup               |
| `set`            | Unique specialties/IDs           |
| `queue`          | Patient queue                    |
| `stack`          | Operation/history handling       |
| `priority_queue` | Emergency patient prioritization |
| `string`         | Text data                        |
| Algorithms       | Searching/sorting                |

STL algorithms such as:

* `sort()`
* `find()`
* `count()`
* `remove()`
* `for_each()`

will be used where appropriate.

---

# Phase 13 — Exception Handling

The system will handle invalid operations and unexpected situations safely.

### Possible Exceptions

* Invalid patient ID
* Invalid doctor ID
* Invalid age
* Invalid appointment
* Appointment conflict
* Invalid billing amount
* File opening failure
* Duplicate record
* Record not found

### Concepts

* `try`
* `catch`
* `throw`
* Multiple catch blocks
* Custom exception classes
* Exception propagation

Example:

```cpp
class RecordNotFoundException : public exception {
public:
    const char* what() const noexcept override {
        return "Record not found.";
    }
};
```

---

# Phase 14 — File Handling & Persistent Storage

Since this is a standalone C++ application, data will be persisted using files.

### Files

```text
data/
├── patients.dat
├── doctors.dat
├── appointments.dat
├── medical_records.dat
├── prescriptions.dat
└── bills.dat
```

### Concepts

* File streams
* `ifstream`
* `ofstream`
* `fstream`
* Text files
* Binary files
* Reading objects
* Writing objects
* Append operations
* File validation
* Persistent storage

---

# Phase 15 — Search, Sorting & Reports

The system will provide useful operations for managing healthcare records.

### Search

Patients can be searched by:

* Patient ID
* Name
* Phone number
* Email

Doctors can be searched by:

* Doctor ID
* Name
* Specialization

### Sorting

Records can be sorted by:

* Name
* ID
* Appointment date
* Bill amount
* Priority

This phase will also demonstrate STL algorithms and comparator functions.

---

# Phase 16 — Appointment Management

The appointment subsystem will allow:

* Creating appointments
* Cancelling appointments
* Rescheduling appointments
* Viewing appointments
* Checking doctor availability
* Detecting appointment conflicts
* Maintaining appointment history

### Example Relationship

```text
Patient ─────── Appointment ─────── Doctor
```

This will demonstrate object interaction and association between classes.

---

# Phase 17 — Medical Records & Prescription Management

### Medical Records

Each patient can have:

* Diagnosis
* Symptoms
* Previous treatments
* Test results
* Doctor's notes
* Visit history

### Prescriptions

A prescription can contain:

* Medicine
* Dosage
* Frequency
* Duration
* Instructions

Example:

```text
Patient
   │
   ├── Medical Records
   │
   └── Prescriptions
           │
           └── Medicines
```

This section will demonstrate composition, aggregation, collections of objects, and file handling.

---

# Phase 18 — Billing & Payment System

The billing module will manage:

* Consultation charges
* Medicine charges
* Test charges
* Room charges
* Discounts
* Taxes
* Final bill
* Payment status

Example:

```text
Bill
 ├── Consultation
 ├── Medicines
 ├── Tests
 └── Other Charges
```

Operator overloading and friend functions can be incorporated naturally in this module.

---

# Phase 19 — Authentication & Role-Based Access

Different users will have different privileges.

```text
                    User
                      │
        ┌─────────────┼─────────────┐
        │             │             │
   Administrator     Doctor       Patient
```

### Example Permissions

**Administrator**

* Manage doctors
* Manage patients
* Manage departments
* View reports

**Doctor**

* View assigned patients
* Create medical records
* Create prescriptions
* Manage appointments

**Patient**

* View profile
* Book appointments
* View medical records
* View prescriptions
* View bills

---

# Phase 20 — Main Menu & User Interface

A console-based interface will be developed initially.

Example:

```text
========================================
       e-HEALTHCARE MANAGEMENT SYSTEM
========================================

1. Patient Management
2. Doctor Management
3. Appointment Management
4. Medical Records
5. Prescription Management
6. Billing & Payments
7. Search Records
8. Reports
9. Administration
0. Exit

Enter your choice:
```

The interface will connect all modules into one complete application.

---

# Phase 21 — Integration

All modules will be integrated into a single system.

### Integration Flow

```text
Login
  ↓
Role Identification
  ↓
Dashboard
  ↓
Module Selection
  ↓
Database/File Operations
  ↓
Validation
  ↓
Result
  ↓
Dashboard
```

Interactions between classes will be tested to ensure the system behaves consistently.

---

# Phase 22 — Testing & Debugging

Testing will be performed for:

### Functional Testing

* Patient registration
* Doctor registration
* Appointment booking
* Appointment cancellation
* Prescription creation
* Medical record creation
* Billing
* Searching
* File operations

### OOP Testing

* Constructor behavior
* Destructor behavior
* Inheritance
* Function overriding
* Virtual functions
* Operator overloading
* Exception handling
* Templates
* Object relationships

### Edge Cases

* Duplicate IDs
* Invalid input
* Missing records
* Full appointment slots
* Invalid dates
* Empty files
* File corruption/failure
* Invalid billing values

---

# 📚 C++ / OOP Concept Coverage

The project will intentionally cover the following concepts:

| Concept                | Implementation                    |
| ---------------------- | --------------------------------- |
| Classes & Objects      | All major entities                |
| Encapsulation          | Private/protected members         |
| Abstraction            | Abstract base classes             |
| Inheritance            | Person → Patient/Doctor/etc.      |
| Polymorphism           | Virtual functions & overriding    |
| Function Overloading   | Search/display functions          |
| Operator Overloading   | Date/Bill/Appointment operations  |
| Constructors           | Default/parameterized/copy        |
| Destructors            | Resource/object lifecycle         |
| Static Members         | Counters/system-wide data         |
| Friend Function        | Billing/reporting                 |
| Friend Class           | Controlled cross-class access     |
| `this` Pointer         | Member access                     |
| Virtual Functions      | Runtime polymorphism              |
| Pure Virtual Functions | Abstract interfaces               |
| Virtual Destructor     | Safe polymorphic destruction      |
| Composition            | Patient → Address, etc.           |
| Aggregation            | Hospital → Doctors/Patients       |
| Association            | Patient ↔ Doctor/Appointment      |
| Templates              | Generic Repository                |
| STL                    | `vector`, `map`, `set`, etc.      |
| Exception Handling     | Custom healthcare exceptions      |
| File Handling          | Persistent records                |
| Dynamic Memory         | Dynamic object management         |
| `const`                | Safe read-only methods            |
| References             | Efficient object passing          |
| Pointers               | Object relationships/polymorphism |
| Namespaces             | Code organization                 |
| Enumerations           | Roles/status/type values          |
| Recursion              | Where logically applicable        |
| Algorithms             | Search/sort/report generation     |

---

# 🗂️ Proposed Project Structure

```text
e-healthcare-management-system/
│
├── README.md
│
├── src/
│   ├── main.cpp
│   │
│   ├── models/
│   │   ├── Person.h
│   │   ├── Person.cpp
│   │   ├── Patient.h
│   │   ├── Patient.cpp
│   │   ├── Doctor.h
│   │   ├── Doctor.cpp
│   │   ├── Receptionist.h
│   │   ├── Receptionist.cpp
│   │   ├── Appointment.h
│   │   ├── Appointment.cpp
│   │   ├── MedicalRecord.h
│   │   ├── MedicalRecord.cpp
│   │   ├── Prescription.h
│   │   ├── Prescription.cpp
│   │   ├── Medicine.h
│   │   ├── Medicine.cpp
│   │   ├── Bill.h
│   │   ├── Bill.cpp
│   │   ├── Payment.h
│   │   └── Payment.cpp
│   │
│   ├── services/
│   │   ├── PatientService.h
│   │   ├── DoctorService.h
│   │   ├── AppointmentService.h
│   │   ├── MedicalRecordService.h
│   │   ├── PrescriptionService.h
│   │   └── BillingService.h
│   │
│   ├── repositories/
│   │   ├── Repository.h
│   │   ├── PatientRepository.h
│   │   ├── DoctorRepository.h
│   │   └── AppointmentRepository.h
│   │
│   ├── exceptions/
│   │   ├── HealthcareException.h
│   │   ├── RecordNotFoundException.h
│   │   └── ValidationException.h
│   │
│   ├── utils/
│   │   ├── Date.h
│   │   ├── Validator.h
│   │   └── FileManager.h
│   │
│   └── ui/
│       ├── Menu.h
│       ├── Menu.cpp
│       ├── PatientMenu.h
│       ├── DoctorMenu.h
│       └── AdminMenu.h
│
├── data/
│   ├── patients.dat
│   ├── doctors.dat
│   ├── appointments.dat
│   ├── records.dat
│   ├── prescriptions.dat
│   └── bills.dat
│
├── docs/
│   ├── class-diagram.png
│   ├── use-case-diagram.png
│   ├── flowchart.png
│   └── project-report.pdf
│
└── tests/
    └── test_cases.txt
```

---

# 👥 Development Strategy

The project will be developed module-by-module rather than writing the entire application at once.

### Step 1

Design classes and relationships.

### Step 2

Implement core OOP classes.

### Step 3

Implement inheritance and polymorphism.

### Step 4

Implement healthcare modules.

### Step 5

Add STL and templates.

### Step 6

Add exception handling.

### Step 7

Add file persistence.

### Step 8

Integrate all modules.

### Step 9

Build the user interface.

### Step 10

Test, debug, and document the complete system.

---

# ✅ Final Deliverables

By the end of the project, the repository will contain:

* Complete C++ source code
* OOP-based class architecture
* Healthcare management modules
* UML/Class diagrams
* File-based persistent storage
* Exception handling
* STL implementation
* Template implementation
* Test cases
* Project documentation
* Demonstration-ready console application

---

## 🎓 Academic Focus

The primary academic objective of this project is to demonstrate that **C++ Object-Oriented Programming concepts can be applied to design a realistic, modular, and maintainable software system**.

The healthcare domain provides sufficient complexity to demonstrate relationships between objects, inheritance hierarchies, runtime polymorphism, abstraction, encapsulation, operator overloading, templates, exception handling, STL, and file handling in a single integrated project.
