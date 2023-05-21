#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct fullname                    ///////// //FINISHED PROJECT//////
{
    string firstname;
    string lastname;
};

struct account
{
    string username;
    string password;
};

struct patient
{
    fullname patientName;
    account patientAccount;
    int age;
    char gender;
    int diseasesHistory[20] = { 0 };
}patients[30];

struct doctor
{
    fullname doctorName;
    account doctorAccount;
    int diseasesAdded[40] = { 0 };
}doctors[30];

struct disease
{
    string title;
    int id = 0;
    string generalInfo;
    string symptoms[20]; //array of strings
    int numberOfPatients = 0;
    int firstSymptomIndex = 0;
    int lastSymptomIndex = 0;
    int numberOfSymptoms = 0;
}diseases[30];
int userIndexPatient;
int userIndexDoctor;
int menu();
void readPatients();
void readDoctors();
void readDiseases();
void readFromFile();
bool loginPatients(int& userIndexPatient);
bool loginDoctors(int& userIndexDoctor);
void registerPatients();
void registerDoctors();
void patientmenu();
void displayDiagnosis();
void displaySymptoms();
void viewHistory();
void clearHistory();
void DoctorMenu();
void addDisease();
void removeDisease();
void DisplayDisease();
void addSymptom();
void viewPatient();
void removeSymptom();
int main()
{
    readFromFile();
    int option;
    char ans = 'y';
    int accountType;
    bool verified = false;
    while (true)
    {
        option = menu();
        switch (option)
        {
        case 1:
            cout << "Are you a doctor or a patient\n1-patient\n2-doctor\n";
            cin >> accountType;
            if (accountType == 1)
                registerPatients();
            else if (accountType == 2)
                registerDoctors();
            else
                cout << "Invalid number,please enter 1 or 2\n";
            continue;
        case 2:
            cout << "Are you a doctor or a patient\n1-patient\n2-doctor\n";
            cin >> accountType;
            if (accountType == 1)
            {
                verified = loginPatients(userIndexPatient);
            }
            else if (accountType == 2)
            {
                verified = loginDoctors(userIndexDoctor);
            }
            else
                cout << "Invalid number,please enter 1 or 2\n";
            if (!verified)
                continue;
            if (accountType == 1)
                patientmenu();
            if (accountType == 2)
                DoctorMenu();
            break;
        case 3:
            cout << "thank you, goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid number,please enter number from 1 to 3\n";
            continue;
        }
    }
}
int menu()
{
    int option;
    cout << "\t \t \t \t \t Welcome to self diagnosis system\n";
    cout << "1-register" << endl << "2-log in" << endl << "3-exit" << endl;
    cin >> option;
    return option;
}
void readPatients()
{
    int count = 0;
    fstream input;
    input.open("patients.txt");
    while (input.good())
    {
        input >> patients[count].patientName.firstname;
        input >> patients[count].patientName.lastname;
        input >> patients[count].patientAccount.username;
        input >> patients[count].patientAccount.password;
        input >> patients[count].age;
        input >> patients[count].gender;
        count++;
    }
    input.close();
    //intialize disease history for patients
      //patient 1
    patients[0].diseasesHistory[0] = 25;
    patients[0].diseasesHistory[1] = 30;
    patients[0].diseasesHistory[2] = 23;
    //patient 2
    patients[1].diseasesHistory[0] = 45;
    patients[1].diseasesHistory[1] = 25;
    patients[1].diseasesHistory[2] = 11;
    patients[1].diseasesHistory[3] = 30;
    //patient 3
    patients[2].diseasesHistory[0] = 45;
    patients[2].diseasesHistory[1] = 23;
    patients[2].diseasesHistory[2] = 30;
    //patient 4
    patients[3].diseasesHistory[0] = 11;
    patients[3].diseasesHistory[1] = 57;
}
void readDoctors()
{
    int count = 0;
    fstream input;
    input.open("doctors.txt");
    while (input.good())
    {
        input >> doctors[count].doctorName.firstname;
        input >> doctors[count].doctorName.lastname;
        input >> doctors[count].doctorAccount.username;
        input >> doctors[count].doctorAccount.password;
        count++;
    }
    input.close();
}
void readDiseases()
{
    int count = 0;
    string idString;
    int id;
    string numberOfRevs;
    int numberOfCycles;
    fstream input;
    int temp = 0;
    int temp2 = 0;
    input.open("diseases1.txt");
    while (input.good())
    {
        getline(input, diseases[count].title);
        getline(input, idString);
        id = stoi(idString);
        diseases[count].id = id;
        getline(input, diseases[count].generalInfo);
        getline(input, numberOfRevs);
        numberOfCycles = stoi(numberOfRevs);
        for (int i = 0; i < numberOfCycles; i++)
            getline(input, diseases[count].symptoms[i]);
        //save number of symptoms for each disease
        diseases[count].numberOfSymptoms = numberOfCycles;
        //save last symptom index for each disease
        temp += numberOfCycles;
        diseases[count].lastSymptomIndex = temp;
        //save first index symptom for each disease
        temp2 = diseases[count].lastSymptomIndex - diseases[count].numberOfSymptoms;
        diseases[count].firstSymptomIndex = temp2 + 1;
        //cout << diseases[count].firstSymptomIndex << endl;
        //cout << diseases[count].lastSymptomIndex << endl;
        //cout << endl;
        count++;
    }
    input.close();
}
void readFromFile()
{
    readPatients();
    readDoctors();
    readDiseases();
}
bool loginPatients(int& userIndexPatient)
{
    system("CLS");
    char ans;
    int i = 0;
    string username, password;
    do
    {
        cout << "LONIN as a patient\n";
        cout << "enter your username\n";
        cin >> username;
        cout << "enter your password\n";
        cin >> password;
        while (!patients[i].patientName.firstname.empty()) //to check that we ran over all the users
        {
            if (username == patients[i].patientAccount.username && password == patients[i].patientAccount.password)
            {
                userIndexPatient = i;
                return true;
            }
            i++;
        }
        i = 0;
        cout << "Wrong username or password. Do you want to try again?(Y\N)" << endl;
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return false;
}
bool loginDoctors(int& userIndexDoctor)
{
    system("CLS");
    char ans;
    int i = 0;
    string username, password;
    do
    {
        cout << "LOGIN as a doctor\n";
        cout << "enter your username\n";
        cin >> username;
        cout << "enter your password\n";
        cin >> password;
        while (!doctors[i].doctorName.firstname.empty()) //to check that we ran over all the users
        {
            if (username == doctors[i].doctorAccount.username && password == doctors[i].doctorAccount.password)
            {
                userIndexDoctor = i;
                return true;
            }
            i++;
        }
        i = 0;
        cout << "Wrong username or password. Do you want to try again(Y/N)?\n";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return false;
}
void registerPatients()
{
    int i = 0;
    while (!patients[i].patientName.firstname.empty())
        i++;
    cout << "Enter your full name\n";
    cin >> patients[i].patientName.firstname >> patients[i].patientName.lastname;
    cout << "Enter username\n";
    cin >> patients[i].patientAccount.username;
    cout << "Enter password\n";
    cin >> patients[i].patientAccount.password;
    cout << "Enter your age\n";
    cin >> patients[i].age;
    cout << "Enter your gender(m/f)\n";
    cin >> patients[i].gender;
    cout << "patient account created successfully,thank you\n";
}
void registerDoctors()
{
    int i = 0;
    while (!doctors[i].doctorName.firstname.empty())
        i++;
    cout << "Enter your full name\n";
    cin >> doctors[i].doctorName.firstname >> doctors[i].doctorName.lastname;
    cout << "Enter username\n";
    cin >> doctors[i].doctorAccount.username;
    cout << "Enter password\n";
    cin >> doctors[i].doctorAccount.password;
    cout << "doctor account created successfully, thank you\n";
}
void patientmenu()
{
    system("CLS");
    int ans;
    while (true)
    {
        cout << "\t \t \t \t \t Welcome to patient menu\n";
        cout << "1-find your disease" << endl << "2-display symptoms for a certain disease" << endl
            << "3-view diagnosis history" << endl << "4-clear diagnosis history" << endl << "5-log out" << endl;
        cin >> ans;
        if (ans == 1)
        {
            displayDiagnosis();
            cout << "operation completed, thank you!" << endl;
            cout << " \t \t \t***********************\n";
        }
        else if (ans == 2)
        {
            displaySymptoms();
            cout << "operation completed, thank you!" << endl;
            cout << " \t \t \t***********************\n";
        }
        else if (ans == 3)
        {
            viewHistory();
            cout << "operation completed, thank you!" << endl;
            cout << " \t \t \t***********************\n";
        }
        else if (ans == 4)
        {
            clearHistory();
            cout << "operation completed, thank you!" << endl;
            cout << " \t \t \t***********************\n";
        }
        else if (ans == 5)
            break;
        else
            cout << "Invalid number,please enter number from 1 to 5\n";
        continue;
    }
}
void displayDiagnosis()
{
    system("CLS");
    int symptoms[50];
    int i = 0;
    int count = 1;
    cout << "please select your symptoms, then click 0 to submit" << endl;
    while (!diseases[i].title.empty()) //to display all symptoms
    {
        int j = 0;
        while (!diseases[i].symptoms[j].empty())
        {
            cout << count << "-" << diseases[i].symptoms[j] << endl;
            count++;
            j++;
        }
        i++;
    }
    fstream myfile;
    string line;
    myfile.open("other.txt", ios::in);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << count << "-" << line << endl;
            count++;
        }
    }
    myfile.close();

    int  ans=-1 ;
    int x = 0;
    while (ans != 0) //to take symptoms from user and save them in an array
    {
        cin >> ans;
        symptoms[x] = ans;
        x++;
    }
    float diseaseCounter[10] = { 0 }; //array contain counter for each disease
// example:when user select fever, common cold counter increases by 1
//explains condition : first<=symptom<=last

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; diseases[j].id != 0; j++)
        {
            if (symptoms[i] >= diseases[j].firstSymptomIndex && symptoms[i] <= diseases[j].lastSymptomIndex)
                diseaseCounter[j]++;
        }
    }
    float percent[10] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        percent[i] = (diseaseCounter[i] / float(diseases[i].numberOfSymptoms)) * 100;

    }
    system("CLS");
    float max = percent[0];
    int number;
    for (int index = 0; index < 10; index++)
    {
        if (max <= percent[index])
        {
            max = percent[index];
            number = index;
        }
    }
    if (max >= 60.0)
    {
        cout << "you are diagnosed with " << "---" << diseases[number].title << "---" << endl;
        cout << diseases[number].generalInfo << endl;
        cout << "percentage = " << max << "%" << endl;
        cout << "get well soon!" << endl;
        int counter = 0;
        while (patients[userIndexPatient].diseasesHistory[counter] > 0)
        {
            counter++;
        }
        patients[userIndexPatient].diseasesHistory[counter] = diseases[number].id;
    }
    else if (max < 60.0 && max != 0)
    {
        cout << "No exact disease founded related diseases\n";
        cout << "the closest disease with those symptoms is " << "---" << diseases[number].title << "---" << endl;
        cout << "percentage = " << max << "%" << endl;
        cout << " get well soon!" << endl;
    }
    else
        cout << "Sorry, 0% match found" << endl;

}
void displaySymptoms()
{
    system("CLS");
    int i = 0, j = 0;
    char anss = 'y';
    do
    {
        cout << "please select a disease to view it's symptoms \n";
        while (!diseases[i].title.empty())
        {
            cout << i + 1 << "-" << diseases[i].title << endl;
            i++;
        }
        int disease;
        cin >> disease;
        if (disease > i || disease <= 0)
        {
            cout << "invalid choice please try again" << endl;
            continue;
        }
        cout << "The symptoms for this disease are : \n";
        while (!diseases[disease - 1].symptoms[j].empty())
        {
            cout << diseases[disease - 1].symptoms[j] << endl;
            j++;
        }
        i = 0;
        j = 0;
        cout << "do you want to show symptoms for another disease? (Y/N) \n";
        cin >> anss;
    } while (anss == 'y' || anss == 'Y');

}
void viewHistory()
{
    bool flag = false;
    int i;
    int j;
    system("CLS");
    cout << "your diagnosis history is" << endl;
    for (i = 0; patients[userIndexPatient].diseasesHistory[i] != 0; i++)
    {
        for (j = 0; diseases[j].id != 0; j++)
        {
            if (patients[userIndexPatient].diseasesHistory[i] == diseases[j].id)
            {
                cout << diseases[j].title << endl;
                flag = true;
            }
        }
    }
    if (!flag)
        cout << "empty \n";
}

void clearHistory()
{
    system("CLS");
    int i = 0;
    while (patients[userIndexPatient].diseasesHistory[i] != 0)
    {
        patients[userIndexPatient].diseasesHistory[i] = 0;
        i++;
    }
    cout << "your disease history is cleared successfully" << endl;
}
void DoctorMenu()
{
    system("CLS");
    int doc_option;
    while (true)
    {
        cout << " \t \t \t \t \t Welcome to doctor menu\n";
        cout << "1-add disease\n";
        cout << "2-remove disease\n";
        cout << "3-add symptom to an existing disease\n";
        cout << "4-remove  symptom to an existing disease\n";
        cout << "5-display all diseases\n";
        cout << "6-view patient with a certain disease\n";
        cout << "7-log out\n";
        cin >> doc_option;
        if (doc_option == 1)
        {
            addDisease();
            cout << "operation completed, thank you!" << endl;
            cout << "\t \t \t***********************\n";
        }
        else if (doc_option == 2)
        {
            removeDisease();
            cout << "operation completed, thank you!" << endl;
            cout << "\t \t \t***********************\n";
        }
        else if (doc_option == 3)
        {
            addSymptom();
            cout << "operation completed, thank you!" << endl;
            cout << "\t \t \t ***********************\n";
        }
        else if (doc_option == 4)
        {
            removeSymptom();
            cout << "operation completed, thank you!" << endl;
            cout << "\t \t \t ***********************\n";
        }
        else if (doc_option == 5)
        {
            DisplayDisease();
            cout << "operation completed, thank you!" << endl;
            cout << "\t \t \t ***********************\n";
        }
        else if (doc_option == 6)
        {
            viewPatient();
            cout << "operation completed, thank you!" << endl;
            cout << "\t \t \t ***********************\n";
        }
        else if (doc_option == 7)
            break;
        else
            cout << "Invalid number,please enter number from 1 to 7 \n";
        continue;
    }
}
void addDisease()
{
    system("CLS");
    int lastSymptom =0;
    int i = 0, c = 0, numberOfSymptoms, ID;
    char ans;
    bool match = false;
    while (!diseases[i].title.empty())
    {
        lastSymptom = diseases[i].lastSymptomIndex;
        i++;
    }
    cin.ignore();
    cout << "enter disease name\n";
    getline(cin, diseases[i].title);
    cout << "enter disease id\n";
    cin >> ID;
    bool flag = false;
    for (int k = 0; diseases[k].id != 0; k++)
    {
        if (ID == diseases[k].id)
        {
            cout << "unavailable ID\n";
            cout << "Enter ID\n";
            cin >> ID;
            k = 0;
            flag = true;
            continue;
        }
    }
    if (!flag)
    {
        diseases[i].id = ID;
    }

    cin.ignore();
    cout << "enter disease general info \n";
    getline(cin, diseases[i].generalInfo);
    cout << "enter number of symptoms\n";
    //save number of symptoms - first index - last index in struct
    cin >> diseases[i].numberOfSymptoms;
    diseases[i].firstSymptomIndex = lastSymptom + 1;
    diseases[i].lastSymptomIndex = diseases[i].firstSymptomIndex + diseases[i].numberOfSymptoms - 1;
    cin.ignore();
    cout << "enter disease symptoms\n";
    for (int index = 0; index < diseases[i].numberOfSymptoms; index++)
        getline(cin, diseases[i].symptoms[index]);
    int k = 0;
    while (doctors[userIndexDoctor].diseasesAdded[k] != 0)
        k++;
    doctors[userIndexDoctor].diseasesAdded[k] = diseases[i].id;

}
void removeDisease()
{
    system("CLS");
    int i = 0, noOfdisease, docCounter = 0;
    bool access = false;
    char ans = 'y', noAccessAns;
    do
    {
        cout << "enter the number of disease you want to remove:\n";
        while (!diseases[i].title.empty())
        {
            cout << i + 1 << "-" << diseases[i].title << endl;
            i++;
        }
        i = 0;

        cin >> noOfdisease;
        noOfdisease--;
        while (doctors[userIndexDoctor].diseasesAdded[docCounter] > 0)
        {
            if (doctors[userIndexDoctor].diseasesAdded[docCounter] == diseases[noOfdisease].id)
            {
                access = true;
                break;
            }
            docCounter++;
        }
        docCounter = 0;
        if (!access)
        {
            cout << "You don't have access to edit this disease\n";
            cout << "do you want to try again(Y/N)?\n";
            cin >> noAccessAns;
            if (noAccessAns == 'y' || noAccessAns == 'Y')
                continue;
            else
                break;
        }
        for (int k = noOfdisease; !diseases[i].title.empty(); k++)
        {
            diseases[k] = diseases[k + 1];
            i++;
        }
        cout << "Disease removed successfully\n";
        for (int k = 0; !diseases[k].title.empty(); k++)
            cout << k + 1 << "-" << diseases[k].title << endl;
        i = 0;
        access = false;
        cout << "Do you want to remove another disease(Y/N)?\n";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

}

void addSymptom()
{
    system("CLS");
    int diseaseID = 0, numberOfdisease = 0, numberOfSymptoms = 0, i = 0, j = 0, docCounter = 0;
    char Ans = 'y', noAccessAns;
    bool access = false;
    int k = 0;
    do
    {
        cout << "enter the number of the disease\n";
        while (!diseases[i].title.empty())
        {
            cout << i + 1 << "-" << diseases[i].title;
            cout << endl;
            i++;
        }
        cin >> numberOfdisease;
        numberOfdisease--;
        while (doctors[userIndexDoctor].diseasesAdded[docCounter] > 0)
        {
            if (doctors[userIndexDoctor].diseasesAdded[docCounter] == diseases[numberOfdisease].id)
            {
                access = true;
                break;
            }
            docCounter++;
        }
        docCounter = 0;
        if (!access)
        {
            cout << "You don't have access to edit this disease\n";
            cout << "do you want to try again(Y/N)?\n";
            cin >> noAccessAns;
            if (noAccessAns == 'y' || noAccessAns == 'Y')
                continue;
            else
                break;
        }
        cout << "symptoms:" << endl;
        for (j; !diseases[numberOfdisease].symptoms[j].empty(); j++)
            cout << j + 1 << "-" << diseases[numberOfdisease].symptoms[j] << endl;
        cout << "****************************************\n";
        cin.ignore();
        if (diseases[numberOfdisease].symptoms[j].empty())
        {
            cout << "add symptom:\n";
            getline(cin, diseases[numberOfdisease].symptoms[j]);
            diseases[numberOfdisease].numberOfSymptoms++;
            diseases[numberOfdisease].lastSymptomIndex++;
        }
        j = 0;
        for (j; !diseases[numberOfdisease].symptoms[j].empty(); j++)
            cout << j + 1 << "-" << diseases[numberOfdisease].symptoms[j] << endl;
        cout << "Do you want to add another symptom ? (Y/N)\n";
        j = 0;
        i = 0;
        access = false;
        cin >> Ans;
    } while (Ans == 'y' || Ans == 'Y');
}
void removeSymptom()
{
    system("CLS");
    int i = 0, numOfDisease, j = 0, removeSymptoms, docCounter = 0;
    char answer = 'y', noAccessAns;
    bool access = false;
    do
    {
        cout << "enter the number of the disease :\n";
        while (!diseases[i].title.empty())
        {
            cout << i + 1 << "-" << diseases[i].title << endl;
            i++;
        }
        i = 0;
        cin >> numOfDisease;
        numOfDisease--;
        while (doctors[userIndexDoctor].diseasesAdded[docCounter] > 0)
        {
            if (doctors[userIndexDoctor].diseasesAdded[docCounter] == diseases[numOfDisease].id)
            {
                access = true;
                break;
            }
            docCounter++;
        }
        docCounter = 0;
        if (!access)
        {
            cout << "You don't have access to edit this disease\n";
            cout << "do you want to try again(Y/N)?\n";
            cin >> noAccessAns;
            if (noAccessAns == 'y' || noAccessAns == 'Y')
                continue;
            else
                break;
        }
        cout << "enter the number of symptom you want to remove:\n";
        while (!diseases[numOfDisease].symptoms[j].empty())
        {
            cout << j + 1 << "-" << diseases[numOfDisease].symptoms[j] << endl;
            j++;
        }
        cout << "*****************************************\n";
        j = 0;
        cin >> removeSymptoms;
        removeSymptoms--;
        if (diseases[numOfDisease].symptoms[removeSymptoms].empty())
            cout << "No symptoms left to remove\n";
        diseases[numOfDisease].numberOfSymptoms--;
        diseases[numOfDisease].lastSymptomIndex--;
        for (int k = removeSymptoms; !diseases[numOfDisease].symptoms[k].empty(); k++)
            diseases[numOfDisease].symptoms[k] = diseases[numOfDisease].symptoms[k + 1];

        for (int index = 0; !diseases[numOfDisease].symptoms[index].empty(); index++)
            cout << index + 1 << "-" << diseases[numOfDisease].symptoms[index] << endl;
        cout << "Do you want to remove another symptom(Y/N)?\n";
        access = false;
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
}
void DisplayDisease()
{
    system("CLS");
    int i = 0, j = 0;
    do
    {
        cout << i + 1 << "-" << diseases[i].title << endl;
        cout << "id:" << diseases[i].id << endl;
        cout << "general info:" << diseases[i].generalInfo << endl;
        cout << "symptoms:" << endl;
        do
        {
            cout << j + 1 << "-" << diseases[i].symptoms[j] << endl;
            j++;
        } while (!diseases[i].symptoms[j].empty());
        cout << "\t \t \t***********************" << endl;
        j = 0;
        i++;
    } while (!diseases[i].title.empty());
}
void viewPatient()
{
    system("CLS");
    int i = 0, j = 0, diseaseID;
    bool flag = false;
    cout << "enter the id of disease:\n";
    while (!diseases[i].title.empty())
    {
        cout << diseases[i].title << endl;
        cout << diseases[i].id << endl;
        i++;
    }
    cin >> diseaseID;
    while (!patients[j].patientName.firstname.empty())
    {
        for (int k = 0; patients[j].diseasesHistory[k] != 0; k++)
        {
            if (patients[j].diseasesHistory[k] == diseaseID)
            {
                cout << "patient name :" << patients[j].patientName.firstname << " " << patients[j].patientName.lastname << endl;
                flag = true;
            }
        }
        j++;
    }
    if (!flag)
        cout << "NO patient with this disease\n";
}