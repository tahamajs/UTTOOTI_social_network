#include "headers.h"
//for add new user
void addUser(User *head, char *name, char *password)
{
    User *temp, *p;

    if (head->next == NULL)
    {
        temp = creatUser();
        temp->next = NULL;
        temp->User_First_Post = NULL;
        temp->User_id = ONE;
        temp->User_Name = name;
        temp->User_Password = password;
        head->next = temp;
    }
    else
    {
        int i = ONE;
        temp = head->next;

        while (temp->next != NULL)
        {
            temp = temp->next;
            i++;
        } // we are in last node
        i++;
        p = creatUser();
        p->next = NULL;
        p->User_First_Post = NULL;
        p->User_id = i;
        p->User_Name = name;
        p->User_Password = password;
        temp->next = p;
    }
}

User *creatUser()
{
    User *temp;
    temp = (User *)malloc(sizeof(User));
    temp->User_id = NO_VALUE;
    temp->User_Name = NULL;
    temp->next = NULL;
    temp->User_Password = NULL;
    temp->User_First_Post = NULL;
    return temp;
}

/* this function is for search in linklist  if it not found return null*/
User *searchUser(User *head, char *name)
{
    User *temp;
    if (head->next == NULL)
    {
        return NULL;
    }
    else
    {
        temp = head->next;
        while (temp != NULL)
        {
            if (strcmp(name, temp->User_Name) == ZERO)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

/* this function is for delete user with name it return head becaus maybe it change head */
User *deleteUser(User *head, char *name)
{
    User *temp, *prev = NULL;
    if (head == NULL)
    {
        return head;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            // if (strcmp(name, temp->Name) == ZERO)
            {
                if (prev == NULL)
                {
                    head = head->next;
                    free(temp);
                }
                else
                {
                    prev->next = temp->next;
                    free(temp);
                }
                return head;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

int getAllUserLength(User * head_user){
    User *temp=head_user->next;
    if (temp == NULL)
    {
        return 0;
    }else{
        int i=0;
        while (temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        return i;
        
    }
}

User *searchUserByID(User *head, int user_id)
{
    User *temp;
    if (head->next == NULL)
    {
        return NULL;
    }
    else
    {
        temp = head->next;
        while (temp != NULL)
        {
            if (temp->User_id==user_id)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}
