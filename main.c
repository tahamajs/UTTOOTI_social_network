#include <stdio.h>
#include <string.h>
#include "functions.h"
#define ZERO 0
#define NO_VALUE -1
#define ONE 1

int main()
{
    User *head_user = creatUser(), *main_user, *temp_user;
    Post *head_post = creatPost();
    char *name;
    char *name1, *name2, *name3, *name_secend;
    printf("Hello   ---   Wellcom to UTtooti \n");
    while (1)
    {
        printf("What do you want to do ? -> login or signup ? \n");
        name = get_str();
        name1 = bradcast1(name);
        name2 = bradcast2(name);
        name3 = bradcast3(name);
        if (strcmp(name1, "login") == ZERO)
        {
            if (name2 != NULL && name3 != NULL)
            {
                main_user = searchUser(head_user, name2);

                if (main_user != NULL && strcmp(name3, main_user->User_Password) == ZERO)
                {
                    printf("You successfully login. \n\n");
                    printf("-----------------------------------------------------------\n");
                    login(main_user, head_user, head_post);
                }
                else
                {
                    printf("Incorrect urename or password !! \n\n");
                }
            }
            else
            {
                printf("Incorrect input !!! \n\n");
            }

            /* for signup user */
        }
        else if (strcmp(name1, "signup") == ZERO)
        {
            if (name2 != NULL && name3 != NULL)
            {
                signup(name2, name3, head_user);
            }
            else
            {
                printf("Incorrect input !!!\n\n");
            }
        }
        else
        {
            printf("Incorrect input !!!\n\n");
        }
        printf("-----------------------------------------------------------\n");
    }
}
