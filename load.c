#include "headers.h"

//this function is for load users from file 
int loadUsers(User *Head_user){
    FILE *file = fopen("UTtootiUser.txt","r");
    int number , posts;
    if (file==NULL || number==0)
    {
        return 0 ;
    }
    fscanf(file,"%d",&number);
    
    fscanf(file,"\n");

    for (int i = 0; i < number; i++)
    {
        char * name1=mallocSTRUresName(file);
        char * name2=mallocSTRUresName(file);
        addUser(Head_user,name1,name2);
        fscanf(file," ");
        fscanf(file,"%d",&posts);
        fscanf(file,"\n");
    }
    return 1;

}

//this function is for load posts from file 
int loadPost(Post *Head_post ,User* Head_user){
    FILE *file = fopen("UTtootiPost.txt","r");
    Post *tempPost;
    User *tempUser;
    int number ,userID,likes ,tempUserID;
    
    if (file==NULL || number==0)
    {
        return 0 ;
    }
    fscanf(file,"%d",&number);
    fscanf(file,"\n");
    for (int i = 0; i < number; i++)
    {
        fscanf(file,"%d",&userID);
        fscanf(file," ");
        fscanf(file,"%d",&likes);
        fscanf(file," ");
        char * name1=mallocSTRName(file);
        addPost(Head_post,name1,searchUserByID(Head_user,userID));
        fscanf(file,"\n");
    }
    return 1;
    
    

}
