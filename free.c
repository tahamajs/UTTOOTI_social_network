#include "headers.h"

//for free postes
void freePost(struct Post* head)
{
   Post* tmp;
   head=head->next;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

//for free users
void freeUser(struct User* head)
{
   User* tmp;
   head=head->next;
   
   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}