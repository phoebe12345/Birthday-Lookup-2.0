// Name: Phoebe (Xu) Han 
// student ID: 301558325
// course: CMPT 125 D100
// Computing ID:301558325

#include "a4_birthdayBST.hpp"
#include "a4_birthdaylib.hpp"

// #include <iostream>
using namespace std;






//============================================================================================================================
BirthdayBST::BirthdayBST(){
   root=NULL;
}
BirthdayBST::~BirthdayBST(){


}
//============================================================================================================================


BirthdayBSTreeNode* BirthdayBST::newNode(Birthday* value){
  // BirthdayBSTreeNode* BirthdayBST::newNode(Birthday* value){
   BirthdayBSTreeNode* aNode = new BirthdayBSTreeNode;
   aNode->left=NULL;
   aNode->right = NULL;
   aNode->value = value;
   return aNode;
}
//============================================================================================================================


BirthdayBSTreeNode* BirthdayBST::insertNode_rec(BirthdayBSTreeNode* node, Birthday* value){
   if(node == NULL){
       return newNode(value);
   }
   if(node->value->month>value->month){
       node->left = insertNode_rec(node->left,value);


   }
   else if(node->value->month<value->month){
       node->right = insertNode_rec(node->right,value);
   }
   else{
       if(node->value->day > value->day){
           node->left = insertNode_rec(node->left,value);
       }
       else if(node->value->day < value->day){
           node->right = insertNode_rec(node->right,value);
       }
       else{
           node->right = insertNode_rec(node->right,value);
       }
   }
   return node;
}
//============================================================================================================================


void BirthdayBST::insertNode(Birthday* value){
   root = insertNode_rec(root,value);
}


//============================================================================================================================


BirthdayBSTreeNode* BirthdayBST::minSuccessor(BirthdayBSTreeNode*node){
   BirthdayBSTreeNode*minNode= node;


   while(minNode!=NULL&&minNode->left!=NULL){
       minNode = minNode->left;
   }
   return minNode;
}






//============================================================================================================================


BirthdayBSTreeNode* BirthdayBST::removeNode_rec(BirthdayBSTreeNode* node, Birthday* value){
   if(node == NULL)return node;


   if(node->value>value){
       node->left = removeNode_rec(node->left,value);


   }
   else if(node->value<value){
       node->right = removeNode_rec(node->right,value);


   }


   else{
       if(node-> left == NULL && node->right == NULL){
           free(node);
           return NULL;
       }
       else if(node->right == NULL){
           BirthdayBSTreeNode* leftChild = node->left;
           free(node);
           return leftChild;
       }
       else if(node->left == NULL){
           BirthdayBSTreeNode*rightChild = node->right;
           free(node);
           return rightChild;
       }else{
           //node has 2 kids
           BirthdayBSTreeNode*minRightNode = minSuccessor(node->right);
           node->value = minRightNode->value;
           node->right = removeNode_rec(node->right,minRightNode->value);


       }
   }
   return node;
 
}








//============================================================================================================================


void BirthdayBST::inOrderPrint_rec(BirthdayBSTreeNode* node, ostream& os){
   if(node != NULL){
       inOrderPrint_rec(node->left,os);
       os<<node->value->year<<"-"<<node->value->month<<"-";
       os<<node->value->day<<endl;
       os<<node->value->name<<endl;
       os<<node->value->knownFor<<endl;
       os<<"========================================"<<endl;
       inOrderPrint_rec(node->right,os);
   }
}
//============================================================================================================================


void BirthdayBST::inOrderPrint(ostream& os){
   inOrderPrint_rec(root,os);


}




//============================================================================================================================


void BirthdayBST::printAllNodeWithMatchingMD_rec(BirthdayBSTreeNode* node, ostream& os,short month, short day){
   if(node == NULL){
       return;
   }
   else if(node->value->month == month && node->value->day == day){
       os<<"Birthday found: "<<endl;
       os<<node->value->year<<"-"<<node->value->month <<"-"<<node->value->day<<endl;
       os<<node->value->name<<endl;
       os<<node->value->knownFor<<endl;
       os<<"----------------------------------------"<<endl;
   }
   printAllNodeWithMatchingMD_rec(node->left,os,month,day);
   printAllNodeWithMatchingMD_rec(node->right,os,month,day);


}


//============================================================================================================================




void BirthdayBST::printAllNodeWithMatchingMD(short month, short day, ostream& os){
   return printAllNodeWithMatchingMD_rec(root,os,month,day);
}


//============================================================================================================================
BirthdayBSTreeNode* BirthdayBST::findNodeByMD_rec(BirthdayBSTreeNode*node,short month, short day){
   if(node == NULL){
       return NULL;
   }
   if(node->value->month == month && node->value->day == day){
       return node;
   }
   else if(node->value->month > month ||(node->value->month == month && node->value->day >day)){
       return findNodeByMD_rec(node->left,month,day);
   }
   else{
       return findNodeByMD_rec(node->right,month,day);
   }
}


//============================================================================================================================


Birthday* BirthdayBST::findNodeByMD(short month, short day) {
       BirthdayBSTreeNode* nodefound = findNodeByMD_rec(root, month, day);
       if (nodefound == NULL) {
           return NULL;
       }
       return nodefound->value;
   }
//============================================================================================================================
BirthdayBSTreeNode* BirthdayBST::findNodeByYMDN_rec(BirthdayBSTreeNode* node,short year, short month, short day,string name){
   if(node == NULL){
       return NULL;
   }
   else{
       if(node->value->year == year && node->value->month == month &&node->value->day == day && node->value->name==name){
           return node;
       }
       else if(node->value->month >month ||(node->value->month == month && node->value->day >day)){
           return findNodeByYMDN_rec(node->left,year,month,day,name);
       }
       else{
           return findNodeByYMDN_rec(node->right,year,month,day,name);
       }
   }
}
Birthday* BirthdayBST::findNodeByYMDN(short year, short month, short day,string name){
   BirthdayBSTreeNode* found = findNodeByYMDN_rec(root,year,month,day,name);
   if(found == NULL){
       return NULL;
   }
   return found->value;
}


























