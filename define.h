#define ZERO 0
#define NO_VALUE -1
#define ONE 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
/* two struct for User and Posts */
typedef struct Post
{
    // this are for users information
    int User_ID;
    char *User_name;
    int Post_ID;
    int Like_Number;
    char *Post_Text;
    struct Post *next;
    int *Users_Like; // array of int for users id that like this post
} Post;

typedef struct User
{
    int User_id; // when useer deleted can not use agane
    char *User_Name;
    char *User_Password;
    Post *User_First_Post; // for pointer for user first post that created
    struct User *next;

} User;
