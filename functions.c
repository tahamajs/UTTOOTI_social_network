#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "functions.h"
#define ZERO 0
#define NO_VALUE -1
#define ONE 1

/* this function is dvide name to three names and return first part*/
char *bradcast1(char *name)
{
    char *name1;
    int len = strlen(name) + ONE;
    name1 = (char *)malloc(len * sizeof(char));
    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        name1[i] = name[i];
        i++;
    }
    name1[i] = '\0';
    if (strlen(name1) == ZERO)
    {
        return NULL;
    }
    else
    {
        name1 = (char *)realloc(name1, (strlen(name1) + ONE) * sizeof(char));
        return name1;
    }
}

/* this function is dvide name to three names and return secend part */
char *bradcast2(char *name)
{
    char *name2;
    int len = strlen(name) + ONE;
    name2 = (char *)malloc(len * sizeof(char));
    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    int j = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        name2[j] = name[i];
        i++;
        j++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    j = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
        j++;
    }
    if (strlen(name2) == ZERO)
    {
        return NULL;
    }
    else
    {
        name2 = (char *)realloc(name2, (strlen(name2) + ONE) * sizeof(char));
        return name2;
    }
}

/* this function is for return secend part of input */
char *secend_part_str(char *name)
{
    char *name2;
    int len = strlen(name) + ONE;
    name2 = (char *)malloc(len * sizeof(char));
    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    int j = ZERO;
    while (name[i] != '\0')
    {
        name2[j] = name[i];
        i++;
        j++;
    }
    if (strlen(name2) == ZERO)
    {
        return NULL;
    }
    else
    {
        name2 = (char *)realloc(name2, (strlen(name2) + ONE) * sizeof(char));
        return name2;
    }
}

/* this function is dvide name to three names and return therd part*/
char *bradcast3(char *name)
{
    char *name3;
    int len = strlen(name) + ONE;
    name3 = (char *)malloc(len * sizeof(char));
    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    int j = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
        j++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }
    j = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        name3[j] = name[i];
        i++;
        j++;
    }

    if (strlen(name3) == ZERO)
    {
        return NULL;
    }
    else
    {
        name3 = (char *)realloc(name3, (strlen(name3) + ONE) * sizeof(char));
        return name3;
    }
}

/* this function get pointer of string and put input of user to that string with malloc function and it return lenth of string*/
char *get_str()
{
    char *name;
    char c;
    int count = ZERO;
    name = (char *)malloc(sizeof(char));
    while ((c = getchar()) != '\n')
    {
        name[count] = (char)c;
        count++;
        name = (char *)realloc(name, (count + ONE) * sizeof(char));
    }
    return name;
}

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

/* creat new post */
Post *creatPost()
{
    Post *temp;
    temp = (Post *)malloc(sizeof(Post));
    temp->Users_Like = NULL;
    temp->next = NULL;
    temp->Post_ID = NO_VALUE; /* it start from ONE to ... */
    temp->Post_Text = NULL;
    temp->User_name = NULL;
    temp->User_ID = NO_VALUE;
    return temp;
}

/* this function is for delete post with postid as it define id it return head becaus maybe it change head */
// before delete post you shuld trust that we have that post by search
void deletePost(Post *head, int id, User *user)
{
    Post *temp, *prev = NULL, *p;
    temp = head->next;
    p = user->User_First_Post; // for have user first post
    if (head->next->Post_ID == id && head->next->User_ID == user->User_id)
    {
        temp = head->next;
        head->next = head->next->next;
        user->User_First_Post = head->next;
        free(temp);
    }
    else if (p->Post_ID == id)
    {
        while (temp->next != p)
        {
            temp = temp->next;
        }
        temp->next = p->next;
        user->User_First_Post = temp->next;
        free(p);
    }
    else
    {
        while (p->next->next != NULL && p->next->Post_ID != id)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
}

/* this function is for search in posts whit postid and return NULL if it dond finde anythink . if do not available it return null pointer */
Post *searchPost(Post *head, int id, User *user)
{
    Post *temp;
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {

            if ((temp->Post_ID) == id && temp->User_ID == user->User_id)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

/* this function add post to post with post text and user that it want to post*/
void addPost(Post *head, char *postText, User *user)
{
    Post *temp, *p;

    if (head->next == NULL)
    {
        temp = creatPost();
        temp->Like_Number = ZERO;
        temp->next = NULL;
        temp->Post_ID = ONE;
        temp->User_ID = user->User_id;
        temp->User_name = user->User_Name;
        temp->Users_Like = NULL;
        temp->Post_Text = postText;
        user->User_First_Post = temp;
        head->next = temp;
        setLike(user);
    }
    else
    {
        int i = ONE;
        temp = head->next;
        if (user->User_First_Post == NULL) // first post of new user
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            } // we are in last node
            p = creatPost();
            p->Like_Number = ZERO;
            p->next = NULL;
            p->Post_ID = ONE;
            p->User_ID = user->User_id;
            p->User_name = user->User_Name;
            p->Users_Like = NULL;
            p->Post_Text = postText;
            user->User_First_Post = p;
            temp->next = p;
            setLike(user);
        }
        else
        {
            temp = user->User_First_Post;

            while (temp->next != NULL && temp->next->User_ID == user->User_id) // post of each user must be Continuous by post_id
            {
                if ((temp->next)->User_ID == user->User_id)
                {

                    temp = temp->next;
                    i = temp->Post_ID;
                }

            } // we find last post of that user in temp
            // we shuld put p in middle of this posts linklist
            p = creatPost();
            p->Like_Number = ZERO;
            p->next = NULL;
            p->Post_ID = i + ONE;
            p->User_ID = user->User_id;
            p->User_name = user->User_Name;
            p->Post_Text = postText;
            p->Users_Like = NULL;

            if (temp->next != NULL) // last post of that user is not last post of list
            {
                p->next = temp->next;
                temp->next = p;
                setLike(user);
            }
            else
            { // last post of that user is last post of list
                temp->next = p;
                setLike(user);
            }
        }
    }
}

/*this function is for show post and print post to user*/
void showPosts(User *user)
{
    Post *temp;
    temp = user->User_First_Post;
    while (temp != NULL && temp->User_ID == user->User_id)
    {
        printf("\n");
        printf("Post : %s\n", temp->Post_Text);
        printf("Post id : %d\n", temp->Post_ID);
        printf("like : %d\n", temp->Like_Number);
        printf("\n");
        temp = temp->next;
    }
}

// this function return state of like
int likePost(Post *post, User *user)
{
    int *likes = post->Users_Like;
    if (likes == NULL)
    {
        likes = createList(likes);
        likes[ZERO] = user->User_id;
        post->Like_Number += ONE;
        post->Users_Like = likes;
        return ONE;
    }
    else
    {
        int i = ZERO;
        int flag = ZERO;
        while (likes[i] != NO_VALUE)
        {
            if (likes[i] == user->User_id)
            {
                return ZERO;
            }
            i++;
        }
        likes[i] = user->User_id;
        post->Like_Number += ONE;
        return ONE;
    }
}

// this function is for malloc of userlikes int pointer of array in each post
int *createList(int *list)
{
    list = (int *)malloc(30 * sizeof(int));
    for (int i = ZERO; i < 30; i++)
    {
        list[i] = NO_VALUE;
    }
    return list;
}

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
            printf("\nUserName:%s\n\n",temp_user->User_Name);
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

// for signup you use this function
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

// this function set likes like id    when you use this function post id updates
void setLike(User *user)
{
    Post *temp, *p;
    int i = ONE;
    p = user->User_First_Post;
    if (p != NULL)
    {
        while (p != NULL)
        {
            if (p->User_ID == user->User_id)
            {
                p->Post_ID = i;
                p = p->next;
                i++;
            }
            else
            {
                p = p->next;
            }
        }
    }
}