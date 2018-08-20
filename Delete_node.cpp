/*
Delete nodes having greater value on right
Given a singly linked list, remove all the nodes which have a greater value on right side.

Input:
You have to complete the method which takes 1 argument: the head of the  linked list  .You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the linked list in which all nodes which have a greater value on right side are removed.

Constraints:
1<=T<=50
1<=size of linked list <=100
1<=element of linked list <=1000

Example:

Input:
3
8
12 15 10 11 5 6 2 3
6
10 20 30 40 50 60
6
60 50 40 30 20 10

Output:

15 11 6 3
60
60 50 40 30 20 10

*/


//---------------------------Solution--------------------------------------------------
Node *Delete(Node *head){
  if(!head->next)
    return head;
  
  Node *temp = Delete(head->next);
  if(temp->data>head->data)
    return temp;
  else
    head->next=temp;
   return head;
}
    


