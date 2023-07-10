// Name: Phoebe (Xu) Han 
// student ID: 301558325
// course: CMPT 125 D100
// Computing ID:301558325

#include <iostream>
#include <fstream>
#include <cstdio>
#include "a4_birthdayBST.hpp"
#include "a4_birthdaylib.hpp"
// #include "a4_birthdayBST.cpp"


//banner function to make printing easier
void print_greet_banner(){
   std::cout<<"----------------------------------------"<<std::endl;
   std::cout<<"--------|Birthday Lookup System|--------"<<std::endl;
   std::cout<<"----------------------------------------"<<std::endl;
   std::cout<<"----------Name:Phoebe (Xu) Han----------"<<std::endl;
   std::cout<<"---------SFU Mail: xha91@sfu.ca---------"<<std::endl;
   std::cout<<"------------SFU ID:301558325------------"<<std::endl;
   std::cout<<"----------Computing ID: xha91-----------"<<std::endl;
   std::cout<<"----------------------------------------"<<std::endl;
}
//banner function to make printing easier


void print_option_menu(){
   std::cout<<"========================================"<<std::endl;
   std::cout<<"Press numbers 1-5 for the following options and then enter:"<<std::endl;
   std::cout<<"1) to load a birthday file"<<std::endl;
   std::cout<<"2) to list birthdays sorted by Month-Day"<<std::endl;
   std::cout<<"3) to look up a birthday"<<std::endl;
   std::cout<<"4) to add a birthday"<<std::endl;
   std::cout<<"5) to save a birthday file"<<std::endl;
   std::cout<<"6) to terminate the program"<<std::endl;
}


int main(){


   BirthdayBST myBST;
   //to use functions  




//    int cap = 16;
//    capacity initializing
//    Birthday* BirthdayA = new Birthday[cap];


//    short year, month, day;
   std::string name, knownFor;
  
 
   print_greet_banner();
   int option;
  


   //option variable to keep track of what option the user inputs
   while(option != 6){
       //while loop so it doenst just stop halfway through
       print_option_menu();
       std::cout<<"Please Enter Your Option: ";
       std::cin>>option;
       int checker;
       //used to check if the file is found
       int counter = 0;
       //count the number if input
  
       if(option == 1){
           cout << "Enter the name of the file to open: ";
           string filename;
           cin >> filename;
           cout<<endl;


           ifstream file;
           file.open(filename,ifstream::in);
           int year,month,day;
           // int counter = 0;
           string syear,smonth,sday;
           string name, knownFor,sep;


           if (!file.good()) {
               cout<<"========================================"<<endl;
               cout<< "Failed to open file"<< endl;
               cout<<"========================================"<<endl;
               checker = 0;
               //this should be in every option to avoid code dying if there is no file loaded
               //just copy and paste this into each option
              
              
           }
           else{
               myBST.~BirthdayBST();
               //some initializing stuff
               while(getline(file,syear,'-')){
                   getline(file,smonth,'-');
                   getline(file,sday);
                   getline(file,name);
                   getline(file,knownFor);
                   getline(file,sep);
                   //getting data


                   year = stoi(syear);
                   month = stoi(smonth);
                   day = stoi(sday);
                   //to convert into integers so program can use the data


                   Birthday* BirthdayA = create_Birthday(year,month,day,name,knownFor);
                   myBST.insertNode(BirthdayA);


                   counter++;
                   //counter to keep track of number of elements in a file


               }
               cout<<"----------------------------------------"<<endl;
               cout<<counter<<" enteries read."<<endl;
               cout<<"----------------------------------------\n"<<endl;
               checker = 1;
               //the checker checks if a file has been opened
               //if the file is not open then tell user to load file
               //0 mean file has not been lodad (returns error)
               //1 means file has been loaded
               //shows how many entries has read
           }
           file.close();
           //dont forget to close the file
           
  
       }
       else if(option == 2){
           //option 2 is to print out birthdays in month day form
           if(checker == 0){
               cout<<"========================================\n"<<endl;
               cout<<"No file found, plase select option 1 and load a file first\n"<<endl;
               //check if file has been loaded, if not then complain
   
           }
           else{
               cout<<"========================================"<<endl;
               myBST.inOrderPrint(cout);
               cout<<endl;
               //in order print is defined in another folder
               //i should start using \n instead of another cout line....
               //this option is suspiciously short
           }


       }
       else if(option == 3){
           //option 3 -> search birthday by month and day
           if(checker == 0){
               //check file loaded or not
               cout<<"========================================\n"<<endl;
               cout<<"No file found, plase select option 1 and load a file first\n"<<endl;
   
           }
           else{
               int month,day;
               //defining some int stuff for the entries
               //only need month and day
               cout<<"please enter a month below"<<endl;
               cout<<"Month: ";
               cin>>month;
               cout<<"please enter a day below"<<endl;
               cout<<"Day: ";
               cin>>day;
               cout<<endl;


               bool finder = myBST.findNodeByMD(month,day);
               //find node by md defined in another folder


               if(finder == 0){
                   cout<<"there was no birthday found on that day"<<endl;
                   //complain to user if nothing is found
               }
               else{
                   myBST.printAllNodeWithMatchingMD(month,day,cout);
                   cout<<"==========================================\n"<<endl;
                   //if something is broken go fix the bst folder


               }
           }


       }
       else if(option == 4){
           //adding birthday
           short newyear,newmonth,newday;
           //defining stuff to take in user input
           string newname, newknownFor;

           cout <<"Please enter a year below"<<endl;
           cout<<"Year: ";
           cin>>newyear;

           cout<<"Please enter a month below"<<endl;
           cout<<"Month: ";
           cin>>newmonth;

           cout<<"Please enter a day below"<<endl;
           cout<<"Day: ";
           cin>>newday;

           cout<<"What is this persons name"<<endl;
           cout<<"Name: ";
           cin>>newname;
           cout<<endl;

           cout<<"What is this person known for"<<endl;
           cout<<"known for: ";
           cin>>newknownFor;
           cout<<endl;

           cout<<"\nyou have entered "<<endl;
           cout<< newyear<< "-"<<newmonth<<"-"<<newday<<endl;
           //taking in user input
           Birthday* checkperson = myBST.findNodeByYMDN(newyear,newmonth,newday,newname);
           if(checkperson == NULL){
            Birthday* insertperson = create_Birthday(newyear,newmonth,newday,newname,newknownFor);
            myBST.insertNode(insertperson);
            cout<<"~person loaded~"<<endl;
           }
           else{
            cout<<"An entry with this birthday and name is already in the file"<<endl;
           }
        
           
        //    bool findertwo = myBST.findNodeByYMDN(newyear,newmonth,newday,newname);


        //    if(findertwo == 0){
        //        Birthday* insertperson = create_Birthday(newyear,newmonth,newday,newname,newknownFor);
        //        myBST.insertNode(insertperson);
        //        cout<<"~person added~"<<endl;
               
        //        //if the birthday was not found then add a node containing the birthday entered
        //    }
        //    else{
        //        cout<<"~There is already a Birthday on that day, No entry added~"<<endl;
        //        cout<<"==========================================\n"<<endl;
               


        //    }
           
           //take user imput -> use the ymdn function to search -> add node for newest entry
           //if birthday exists then do not add the entry.


       }
       else if(option == 5){
           //just putting stuff into another folder
           string filename;
           cout<<"please enter a file name (includeing extension) below"<<endl;
           cout<<"Enter File Name: ";
           cin>>filename;
           cout<<endl;
           ofstream fout(filename);


           myBST.inOrderPrint(fout);
       }
       else if(option == 6){
           cout<<"\nThank you for using the Famous Birthday Lookup System!"<<endl;
           cout<<"~~ Goodbye ~~"<<endl;
           exit(0);
           //thanks the user and says goodbye
          
       }
       else{
           cout<<"\nthat is not a valid option please select an option from 1-6"<<endl;
           break;
           //this is kind of like the 'default' case used in the last assignment
           //if the option is not valid make user choose a new option
       }
   }
  
  
   return 0;
   //must return something for int main()
}
