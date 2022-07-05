#include<iostream>
#include "timetable.h"

using namespace std;

//global variables to hold data while the program is running


int main(){
while(true){
int choice;
cout<<"\n\n\n";

system("pause");
cout<<"\n===================================================================================\n";

cout<<"\n================================== MAIN MENU ======================================\n";

cout<<"\n===================================================================================\n\n";
cout<<"*********** Lecturers Section ***********\n";
cout<<"1. Add a lecturer \n";
cout<<"2. Show lecturers \n\n";

cout<<"*********** Modules Section **************\n";
cout<<"3. Add a Module \n";
cout<<"4. Show Modules \n\n";

cout<<"*********** Classes Section **************\n";
cout<<"5. Create classes \n";
cout<<"6. Show classes\n\n";

cout<<"*********** Students Section *************\n";
cout<<"7. Create student groups \n";
cout<<"8. Show groups\n\n";

cout<<"*********** Rooms Section ****************\n";
cout<<"9. Show available rooms \n";
cout<<"10. Add a new room\n\n";

cout<<"*********** Timetable Section ***********\n";
cout<<"11. Generate a Timetable (Auto Generation) \n";
cout<<"12. Show Timetable\n\n";

cout<<"*********** To Exit ***********\n";
cout<<"99. Exit\n\n";

cout<<"\n===================================================================================\n\n";
cout<<"Please make your choice by entering any number from the above: ";

cin>>choice;

switch (choice)
{
case 1:
    {
        string newLecturer;
        cout<<"Please enter the name of the lecturer:\n";
        cin.ignore();
        getline(cin,newLecturer);
        lecObject.addLecturer(newLecturer);
    }
    break;
case 2:
    {
        lecObject.showAllLecturers();
    }
    break;
case 3:
    {
        string newModule;
        cout<<"Please enter the name of the module:\n";
        cin.ignore();
        getline(cin, newModule);
        modObject.addModule(newModule);
    }
    break;
case 4:
    {
        modObject.showModules();
    }
    break;
case 5:
    {
        classObj.createClasses();
    }
    break;
case 6:
    {
        classObj.showClasses();
    }
    break;
case 7:
    {
        studentObj.createGroups();
    }
    break;
case 8:
    {
        studentObj.showGroups();
    }
    break;
case 9:
    {
        roomsObj.showRooms();
    }
    break;
case 10:
    {
        string newRoom;
        cout<<"Please enter a new room number and add ,X at the end\n";
        cout<<"Where X can be L (Lab), or R (Room):";
        cin.ignore();
        getline(cin,newRoom);
        roomsObj.addRoom(newRoom);
    }
    break;
case 11:
    {
        ttObj.createTT();
    }
    break;
case 12:
    {
        ttObj.showTT();
    }
    break;
case 99:
    {
        exit(0);
    }
    break;

default:
    break;
}
}
return 0;
}
