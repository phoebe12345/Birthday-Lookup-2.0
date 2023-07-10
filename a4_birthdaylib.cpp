// Name: Phoebe (Xu) Han 
// student ID: 301558325
// course: CMPT 125 D100
// Computing ID:301558325

#include "a4_birthdayBST.hpp"
#include "a4_birthdaylib.hpp"


Birthday* create_Birthday(short year,short month,short day,string name, string knownFor){
   Birthday* BirthdayA = new Birthday;
   BirthdayA ->year = year;
   BirthdayA->month = month;
   BirthdayA ->day = day;
   BirthdayA->name = name;
   BirthdayA->knownFor = knownFor;
   return BirthdayA;
  
}
void delete_Birthday(Birthday* person){
    if(person == NULL){
        return;
    }
   
    delete person;
}