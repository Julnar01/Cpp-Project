#include<iostream>
#include<string>
#include<vector>
#include<iomanip> //for output formatting as a table
//#include <sstream> // used to strip the name of a certain line
#include <unistd.h> //for the sleep function

using namespace std;

//Class declarations
//class Module;
class Lecturer;
class Rooms;
class Student;
class Classes;
class Timetable;

//Globals
vector <string> availLec; //a vector to store lecturers with yes
vector <string> accountingLecturers;
vector <string> computingLecturers;
vector <string> crimLecturers;
vector <string> archLecturers;
vector <string> journLecturers;
vector <string> artLecturers;
//for the formatting:
string group, clss, loc, lec;
unsigned first, last;

// ===============  The modules class ==================================
class Module {
    // MEMBERS:
    public:
    vector <string> listOfModules={"Accounting", "Computer Science", "Architecture", "Criminology", "Journalism", "Art"}; //to be accessed by classes class.
    int numModules = listOfModules.size();
    int numClasses; //number of classes per module

    // METHODS:
    void addModule(string& newmod){
        listOfModules.push_back(newmod);
        cout<<"Module was added successfully...\n";
    }
    void showModules(){
       int i;
        cout<<"Available modules are: \n";
        for (i=0; i<listOfModules.size(); i++){
            cout<<"\t- "<<listOfModules.at(i)<<endl;
        }
    }
}modObject;


// The lecturer class
class Lecturer: public Module {
    public:

    vector <string> lecturers = {"David Croft Computer Science","Diana Hintea Accounting", "Simon Billings Architecture", "Matthew England Criminology", "Susanne Horn Journalism", "Brian Journalism","Edward Computer Science", "Smith Accounting"};
    vector <string> lecAvail = {"yes","yes", "yes", "yes", "yes", "no", "no", "no"};


//:ecturer's class methods
void addLecturer(string& lec){
    lecturers.push_back(lec);
    cout<<"Lecturer was added successfully...\n";
}
void showAllLecturers(){ //show all lecturers
    cout<<"Available lecturers are: \n";
    for (int i=0; i<lecturers.size(); i++){
        cout<<"\t- "<<lecturers.at(i)<<endl;
    }
}
void storeAvailableLecturers(){ // To filter out only available lecturers.
    for(int i=0;i<lecturers.size();i++){
        if(lecAvail.at(i)=="yes"){
            availLec.push_back(lecturers.at(i));
        }
    }
}
//To distibute lecturers to designated vectors based on modules they teach
void sortLecturersByModule(){
  for (int i=0; i<availLec.size();i++){
    //for(int j=0;j<availLec.size();j++){
        if(availLec.at(i).find("Accounting")!=string::npos){ accountingLecturers.push_back(availLec.at(i));}
        else if(availLec.at(i).find("Computer Science")!=string::npos){computingLecturers.push_back(availLec.at(i));}
        else if(availLec.at(i).find("Criminology")!=string::npos){crimLecturers.push_back(availLec.at(i));}
        else if(availLec.at(i).find("Architecture")!=string::npos){archLecturers.push_back(availLec.at(i));}
        else if(availLec.at(i).find("Journalism")!=string::npos){journLecturers.push_back(availLec.at(i));}
        else if(availLec.at(i).find("Art")!=string::npos){artLecturers.push_back(availLec.at(i));}
        else {cout<<"Either you have no available lecturers, or the lecturers have no module assigned to their names\n";}

    }
  }

}lecObject; // End of lecturer class.

// Classes class
class Classes: public Module{
public:
vector <string> listOfClasses;
vector <char> firstLetterMod;
vector <char> classType = {'L', 'R'}; // L: Lab, R: Room
string Word;
//int numClasses = 30/modObject.listOfModules.size(); //to keep num of classes around 30 all the time

//methods
void createClasses(){ //creating max of 30 classes ALWAYS
if(!listOfClasses.empty()){
    listOfClasses.clear();
}
for (int i=0; i<modObject.listOfModules.size();i++){
    Word = modObject.listOfModules.at(i); // skip
    //firstLetterMod.push_back(Word[0]); //This contains 1st letter of each mod // skip
    for(int j=0; j<(30/modObject.listOfModules.size());j++){
        listOfClasses.push_back(Word+"-"+to_string(rand()%5));

        }
    }
    cout<<"For the 30 periods in the timetable,  "<<listOfClasses.size()<<" classes have been created\n";
}

void showClasses(){
    cout<<"Currently you have the following classes:\n";
    for (int i=0; i<listOfClasses.size();i++){
        cout<<listOfClasses.at(i)<<" ,";
    }
}
}classObj;

// Student class
class Student: public Classes{
public:
int numStudents; //number of students to be entered when calling the create TT function
int numGroups; //number of students/ number of classes
vector <string> studentGroups; //holds created groups

//Methods
void createGroups(){
    //check if classes have been created first:
    if (classObj.listOfClasses.size()==0){ //no classes?
    cout<<"It looks like no classes have been created! \n";

    cout<<"Creating classes...\n";sleep(2);
    classObj.createClasses();
    }

    cout<<"How many students would you like to timetable?\n";
    cin>>numStudents;
    cout<<"Creating groups...\n";sleep(2);
    cout<<"You will have "<<numStudents/classObj.listOfClasses.size()<<" students per group.\n"; //students/classes
    numGroups = classObj.listOfClasses.size(); //number of groups = number of classes
    //Make less groups (i.e. 10), requires nest loop below ##################################
    for (int i=0; i<numGroups;i++){
        studentGroups.push_back("- Group:"+to_string(i)+" \t Class: "+classObj.listOfClasses.at(i)+"-"+classObj.classType.at(rand()%2));
        //Line above: combines a group with a class and a postfix (L or R)
    }
}

void showGroups(){
    cout<<"The student groups are:\n";
    for (int j=0;j<studentGroups.size();j++){
        cout<<studentGroups.at(j)<<" , ";
    }
    cout<<endl;
}
}studentObj;

class Rooms{ //Can inherit other classes.
public:
vector <string> rooms{"ASG-31,L","EC1-01,L", "EC2-01,R","ECG-01,L", "EC2-02,R", "EC2-14,R", "EC2-14,L"}; //initially 6 rooms (L:Lab, R: Room)

string newRoom;

void showRooms(){
    cout<<"Currently available rooms:\n";
   for (int i=0; i<rooms.size();i++){
    cout<<"\t- "<<rooms.at(i)<<" ,";
   }
}

void addRoom(string& newr){

    rooms.push_back(newr);
    cout<<"New room has been added successfully!\n";
    showRooms();
}

}roomsObj;

class Timetable: public Rooms, Lecturer, Student{ //inherting all to use their info
public:
vector <string> days={"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY"};
vector <string> periods = {"P1", "P2", "P3", "P4", "P5", "P6"}; //assumption: periods are 6
int classesTimetabled=0; // a counter to display how many classes have been timetabled.



    // check whether they relate or not (all math? all Lab, etc...)
    vector <string> GCR; //to store group-class-room combo
    vector <string> GCRL; //to store all.

void assignRoomstoGroups(){
    //the created groups (group-class-type should be now assigned to a room based on the last letter)
    int i,j;
    for(i=0;i<studentObj.studentGroups.size();i++){
        for(j=0;j<roomsObj.rooms.size();j++){
        if (studentObj.studentGroups.at(i).back()==roomsObj.rooms.at(j).back())
        {
            GCR.push_back(studentObj.studentGroups.at(i)+" \t Location: "+roomsObj.rooms.at(j));
            break;
        }
    }
    }
}

//----------------- assign lecturers ------------
void assignLecturers(){
    // IMPORTANT: before assigning lecturers, they must be sorted based on availability and modules they teach
    storeAvailableLecturers();
    sortLecturersByModule();

    int i,j;
    for(i=0;i<GCR.size();i++){
        if (GCR.at(i).find("Accounting")!=string::npos && !accountingLecturers.empty()) {
            for(j=0;j<accountingLecturers.size();j++){
               //remove the tailing suffix of the lecturer's name before appending:
                    string lecName =  accountingLecturers.at(rand()%accountingLecturers.size());
                    string substring = "Accounting";
                    size_t ind = lecName.find(substring);
                    if(ind !=string::npos){
                    lecName.erase(ind,substring.length());}
               GCRL.push_back(GCR.at(i)+" \t Lecturer:"+lecName);
               classesTimetabled++;
               break;

              }
        }
        else if (GCR.at(i).find("Computer Science")!=string::npos && !computingLecturers.empty()) {
            for(j=0;j<computingLecturers.size();j++){
                    //remove the tailing suffix of the lecturer's name before appending:
                    string lecName =  computingLecturers.at(rand()%computingLecturers.size());
                    string substring = "Computer Science";
                    size_t ind = lecName.find(substring);
                    if(ind !=string::npos){
                    lecName.erase(ind,substring.length());}
               GCRL.push_back(GCR.at(i)+" \t Lecturer: "+lecName);
               classesTimetabled++;
               break;
               //}

              }
               }

        else if (GCR.at(i).find("Criminology")!=string::npos && !crimLecturers.empty()) {
            for(j=0;j<crimLecturers.size();j++){
               //remove the tailing suffix of the lecturer's name before appending:
                    string lecName =  crimLecturers.at(rand()%crimLecturers.size());
                    string substring = "Criminology";
                    size_t ind = lecName.find(substring);
                    if(ind !=string::npos){
                    lecName.erase(ind,substring.length());}
               GCRL.push_back(GCR.at(i)+" \t Lecturer:"+lecName);
               classesTimetabled++;
               break;
               //}

              } }


        else if (GCR.at(i).find("Architecture")!=string::npos && !archLecturers.empty()) {
            for(j=0;j<archLecturers.size();j++){
            //remove the tailing suffix of the lecturer's name before appending:
                    string lecName =  archLecturers.at(rand()%archLecturers.size());
                    string substring = "Architecture";
                    size_t ind = lecName.find(substring);
                    if(ind !=string::npos){
                    lecName.erase(ind,substring.length());}
               GCRL.push_back(GCR.at(i)+" \t Lecturer:"+lecName);
               classesTimetabled++;
               break;
               //}

              } }


        else if (GCR.at(i).find("Journalism")!=string::npos && !journLecturers.empty()) {
            for(j=0;j<journLecturers.size();j++){
                //remove the tailing suffix of the lecturer's name before appending:
                    string lecName =  journLecturers.at(rand()%journLecturers.size());
                    string substring = "Journalism";
                    size_t ind = lecName.find(substring);
                    if(ind !=string::npos){
                    lecName.erase(ind,substring.length());}
               GCRL.push_back(GCR.at(i)+" \t Lecturer:"+lecName);
               classesTimetabled++;
               break;
               //}

               }}


        else if (GCR.at(i).find("Art")!=string::npos && !artLecturers.empty()) {
            for(j=0;j<artLecturers.size();j++){
                //remove the tailing suffix of the lecturer's name before appending:
                    string lecName =  artLecturers.at(rand()%artLecturers.size());
                    string substring = "Art";
                    size_t ind = lecName.find(substring);
                    if(ind !=string::npos){
                    lecName.erase(ind,substring.length());}
               GCRL.push_back(GCR.at(i)+" \t Lecturer:"+lecName);
               classesTimetabled++;
               break;
               //}

             } }
    }

 //Move availLec from global to inside Lecturer class
cout<<"Number of classes have been timetabled is: "<<classesTimetabled<<endl;
}
// ----------------end assign lecturers ----------

void createTT(){
    int numDays = 5;
    int numPeriods = 6;
    //If this function was called directly without running pre-requisite functions (create classes, etc..)
    // run them here.
    //check first:
    if (classObj.listOfClasses.empty()){
        cout<<"Creating classes...\n";
    }
    classObj.createClasses();
        if(studentObj.studentGroups.empty()){ studentObj.createGroups();}
sleep(2);

    assignRoomstoGroups();
    cout<<"Allocating classrooms...\n";sleep(2);
    cout<<"Assigning lecturers...\n";sleep(2);
    assignLecturers();
    system("cls");

    cout<<"Generating a timetable... please wait!";sleep(1);system("cls");
    cout<<"Generating a timetable... please wait.!";sleep(1);system("cls");
    cout<<"Generating a timetable... please wait..!";sleep(1);system("cls");
    cout<<"Generating a timetable... please wait...!";sleep(1);system("cls");
    cout<<"Generating a timetable... please wait....!";sleep(1);system("cls");

    cout<<"\n-------------------------------------------------------------------------------------------------------------------";

     cout<<"\n-------------------- The Timetable has been generated - Choose to show it (12)-------------------------------------";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------";



}

void showTT(){
    int numDays = 5;
    int numPeriods = 6;
    for (int i=0; i<numDays;i++){
        cout<<"\n\t\t\t\t\t\t\t"<<days.at(i);
        for(int j=0;j<numPeriods;j++){
            cout<<"\n"<<periods.at(j)<<": \t\t"<<GCRL.at(rand()%GCRL.size())<<setw(10);

        } cout<<"\n-------------------------------------------------------------------------------------------------------------------";
    }
    cout<<"\n";
}
}ttObj;
