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

void login(User *main_user, User *head_user, Post *head_post);
void signup(char *name2, char *name3, User *head_user);
char *get_str();
int likePost(Post *post, User *user);
int *createList(int *list);
char *bradcast1(char *name);
char *bradcast2(char *name);
char *bradcast3(char *name);
char *secend_part_str(char *name);
User *creatUser();
void addUser(User *head, char *name, char *password);
User *searchUser(User *head, char *name);
User *deleteUser(User *head, char *name);
Post *creatPost();
void deletePost(Post *head, int id, User *user);
Post *searchPost(Post *head, int id, User *user);
void addPost(Post *head, char *postText, User *);
void showPosts(User *user);
void doLike(char *name2, char *name3, User *head_user, Post *head_post, User *main_user);
void doDelete(char *name2, Post *head_post, User *main_user);
void doInfo(User *main_user);
void doNewPost(char *name2, char *name_secend, User *main_user, Post *head_post);
void doFindUser(char *name2, User *head_user);
void setLike(User *user);
int getAllPostLength(Post *head_post);
int getAllUserLength(User *head_user);
int getPostLength(User *head);
int saveUsersToFile(FILE *file,User *head_user);
int savePostToFile(FILE *file,Post *head_post);
char* mallocSTRUresName(FILE* file);
char* mallocSTRUresPass(FILE* file);
int loadUsers(User *Head_user);
char* mallocSTRName(FILE* file);
int loadPost(Post *Head_post ,User* Head_user);
User *searchUserByID(User *head, int user_id);
