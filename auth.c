#include "headers.h"

// when user loged in this function culled     all other functions call in this function
void login(User *main_user, User *head_user, Post *head_post)
{
    char *name;
    char *name1, *name2, *name3, *name_secend;
    while (1)
    {
 
        printf("What do you want to do?   -> post  like  delete  info  finde_user  logout  ?\n ");
        name = get_str();
        name1 = bradcast1(name);
        name2 = bradcast2(name);
        name3 = bradcast3(name);
        name_secend = secend_part_str(name);

        /* for new post */
        if (strcmp(name1, "post") == ZERO)
        {
            doNewPost(name2, name_secend, main_user, head_post);
        }

        /* for like others post */
        else if (strcmp(name1, "like") == ZERO)
        {
            doLike(name2, name3, head_user, head_post, main_user);
        }

        /* for delete post with postid*/
        else if (strcmp(name1, "delete") == ZERO)
        {
            doDelete(name2, head_post, main_user);
        }

        /* for show information and print it */
        else if (strcmp(name1, "info") == ZERO)
        {
            doInfo(main_user);
        }

        /* for finding user in program */
        else if (strcmp(name1, "find_user") == ZERO)
        {
            doFindUser(name2, head_user);
        }

        /* for logout of account */
        else if (strcmp(name1, "logout") == ZERO)
        {
            printf("You loged out\n\n");
            break;
        }

        /* input other thinks */
        else
        {
            printf("Incorrect input !!!\n\n");
        }
        free(name1);
        free(name2);
        free(name3);
        free(name);
        printf("-----------------------------------------------------------\n");
    }
}

// for signup 
void signup(char *name2, char *name3, User *head_user)
{
    User *temp_user;
    temp_user = searchUser(head_user, name2);
    if (temp_user == NULL)
    {
        addUser(head_user, name2, name3);
        printf("You successfully signup\n\n");
    }
    else
    {
        printf("You signup later please login\n\n");
    }
}
