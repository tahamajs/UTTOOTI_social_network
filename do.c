#include "headers.h"

// use this function for like posts
void doLike(char *name2, char *name3, User *head_user, Post *head_post, User *main_user)
{
    int flag;
    User *temp_user;
    Post *temp_post;
    if (name2 != NULL && name3 != NULL)
    {
        temp_user = searchUser(head_user, name2);
        if (temp_user != NULL)
        {

            temp_post = searchPost(head_post, atoi(name3), temp_user);

            if (temp_post != NULL)
            {
                flag = likePost(temp_post, main_user);
                if (flag == ONE)
                {
                    printf("You liked successfully \n\n");
                }
                else
                {
                    printf("You liked this user before !!!\n\n");
                }
            }
            else
            {
                printf("Post not found\n\n");
            }
        }
        else
        {
            printf("User not found\n\n");
        }
    }
    else
    {
        printf("Incorrect input !!!\n\n");
    }
}

// use this function for delete post
void doDelete(char *name2, Post *head_post, User *main_user)
{
    Post *temp_post;

    if (name2 != NULL)
    {
        temp_post = searchPost(head_post, atoi(name2), main_user);
        if (temp_post != NULL)
        {
            deletePost(head_post, temp_post->Post_ID, main_user);
            printf("You deleted successfully \n\n");
            setLike(main_user);
        }
        else
        {
            printf("Post not found \n\n");
        }
    }
    else
    {
        printf("Incorrect input !!!\n\n");
    }
}

// use this function for show information of user
void doInfo(User *main_user)
{
    printf("\n");
    printf("UserName:%s\n", main_user->User_Name);
    printf("UserPassword : %s\n", main_user->User_Password);
    showPosts(main_user);
}

// use this function for finde user from users
void doFindUser(char *name2, User *head_user)
{
    User *temp_user;
    if (name2 != NULL)
    {
        temp_user = searchUser(head_user, name2);
        if (temp_user != NULL)
        {
            printf("\nUserName:%s\n\n", temp_user->User_Name);
            showPosts(temp_user);
        }
        else
        {
            printf("User not found !!\n\n");
        }
    }
    else
    {
        printf("Incorrect input !!!\n\n");
    }
}

// use this function for new post
void doNewPost(char *name2, char *name_secend, User *main_user, Post *head_post)
{
    if (name2 != NULL)
    {

        addPost(head_post, name_secend, main_user);
        printf("You posted successfully. \n\n");
    }
    else
    {
        printf("Incorrect input !!! \n\n");
    }
}
