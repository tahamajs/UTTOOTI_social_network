#include "headers.h"
// #include "functions.h"


int main()
{
    User *head_user = creatUser(), *main_user, *temp_user;
    Post *head_post = creatPost();
    char *name;
    char *name1, *name2, *name3, *name_secend;
    FILE *usersFile ,*postFile;
    printf("Hello   ---   Wellcom to UTtooti \n");
    if (loadUsers(head_user) != 0)
    {
        printf("Users are in database now . \n");
    }else{
        printf("We dont find any last user .\n");
    }
    if (loadPost(head_post,head_user) != 0)
    {
        printf("post are in database now . \n");
    }else{
        printf("We dont find any last post .\n");
    }
    
    
    while (1)
    {
        printf("What do you want to do ? -> login or signup or exit ? \n");
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
        else if (strcmp(name1, "exit") == ZERO)
        {
            usersFile = fopen("UTtootiUser.txt","w");
            postFile = fopen("UTtootiPost.txt","w");
            saveUsersToFile(usersFile,head_user);
            savePostToFile(postFile,head_post);
            exit(0);
        }
        else
        {
            printf("Incorrect input !!!\n\n");
        }
        printf("-----------------------------------------------------------\n");
    }
}
