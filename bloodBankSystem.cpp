#include <iostream>
#include <cstring>
using namespace std;

// BloodBank Class
class BloodBank
{
public:
    static int bloodGroup[8];
};

int BloodBank::bloodGroup[] = {0, 0, 0, 0, 0, 0, 0, 0};
// Patient Class
class Patient
{
    char name[50];
    char bloodGroup[20];

public:
    void save();
    void show(int);
};
// Patient Save Function
void Patient::save()
{
    int choice;

    cout << "Enter your name: ";
    cin >> name;
    cout << "\nAvailable Blood Groups: " << endl;
    cout << "0. A+" << endl;
    cout << "1. O+" << endl;
    cout << "2. B+" << endl;
    cout << "3. AB+" << endl;
    cout << "4. A-" << endl;
    cout << "5. O-" << endl;
    cout << "6. B-" << endl;
    cout << "7. AB-" << endl;
    cout << "Enter the type of blood group you are looking for (0-7): ";
    cin >> choice;
    show(choice);
}
// Blood Availability Checking Function
void Patient::show(int choice)
{
    char bloodGroups[8][5] = {"A+", "O+", "B+", "AB+", "A-", "O-", "B-", "AB-"};
    cout << "---------------------------------------" << endl;
    cout << "Available blood groups compatible with the entered blood group:" << endl;
    cout << bloodGroups[choice] << ": " << BloodBank::bloodGroup[choice] << endl;
    if (BloodBank::bloodGroup[choice] > 0)
    {
        BloodBank::bloodGroup[choice]--;
    }
    else
    {
        cout << "Compatible blood group not available." << endl;
        cout << "---------------------------------------" << endl;
    }
}
// Donor Class
class Donor
{
    char name[50];
    string sex;
    char dob[20]; // Date of Birth
    int bloodGroupIndex;
    int packets;

public:
    void save();
    void display();
};

// Blood Availability Checking Function
void Donor::save()
{
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter date of birth (DD/MM/YYYY): ";
    cin >> dob;
    cout << "Enter your sex: ";
    cin >> sex;
    cout << "Available Blood Groups: " << endl;
    cout << "0. A+" << endl;
    cout << "1. O+" << endl;
    cout << "2. B+" << endl;
    cout << "3. AB+" << endl;
    cout << "4. A-" << endl;
    cout << "5. O-" << endl;
    cout << "6. B-" << endl;
    cout << "7. AB-" << endl;
    cout << "\nEnter the type of blood group you are donating (0-7): ";
    cin >> bloodGroupIndex;

    cout << "How many packets of blood are you donating? ";
    cin >> packets;

    BloodBank::bloodGroup[bloodGroupIndex] += packets;

    char choice;
    cout << "Do you want your information to be displayed now (Y/N)? ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        display();
}
// Donor Data Display Function
void Donor::display()
{
    char bloodGroups[8][5] = {"A+", "O+", "B+", "AB+", "A-", "O-", "B-", "AB-"};
    cout << "Donor Information:" << endl;
    cout << "-------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Sex: " << sex << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodGroups[bloodGroupIndex] << endl;
    cout << "Packets of Blood: " << packets << endl;
    cout << "-------------------------------" << endl;
}
// Main Function
int main()
{
    int choice;
    Donor donors[100];
    Patient patients[50];
    int donorCount = 0;
    int patientCount = 0;

// MENU 
    while (true)
    {
        cout << "\n\n------------------------------------" << endl;
        cout << "BLOOD DONATION SYSTEM" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Donor" << endl;
        cout << "3. Patient" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            //Admin Page
        case 1:
        {
            char s[20] = "Vishnu";
            char str[20];
            cout << "Enter password: ";
            cin >> str;
            cout << "------------------------------------" << endl;
            if (strcmp(s, str) == 0)
            {
                cout << "Welcome Admin!!!" << endl;
                cout << "Blood Inventory:" << endl;
                cout << "A+ : " << BloodBank::bloodGroup[0] << endl;
                cout << "O+ : " << BloodBank::bloodGroup[1] << endl;
                cout << "B+ : " << BloodBank::bloodGroup[2] << endl;
                cout << "AB+ : " << BloodBank::bloodGroup[3] << endl;
                cout << "A- : " << BloodBank::bloodGroup[4] << endl;
                cout << "O- : " << BloodBank::bloodGroup[5] << endl;
                cout << "B- : " << BloodBank::bloodGroup[6] << endl;
                cout << "AB- : " << BloodBank::bloodGroup[7] << endl;
                cout << "------------------------------------" << endl;
            }
            else
            {
                cout << "Invalid password. Access denied." << endl;
            }
            break;
        }
// Donor Page
        case 2:
            cout << "Welcome Donor!!!" << endl;
            donors[donorCount++].save();
            break;
            // Patient Page
        case 3:
            cout << "Welcome Patient!!!" << endl;
            patients[patientCount++].save();
            break;

        case 4:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
