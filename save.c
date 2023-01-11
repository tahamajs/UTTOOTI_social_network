#include "headers.h"
//for save urers in file
int saveUsersToFile(FILE *file,User *head_user){
    User * utemp=head_user->next;
    int userLength = getAllUserLength(head_user);

    fprintf(file,"%d",userLength);
    fputs("\n",file);
    for (int i = 0; i < userLength; i++)
    {
        fprintf(file,"%s %s %d ",utemp->User_Name,utemp->User_Password,getPostLength(utemp));
        fputs("\n",file);
        utemp=utemp->next;
    }
    return 0;
}

//for save posts in file
int savePostToFile(FILE *file,Post *head_post){
    Post * temp=head_post->next;
    int postLength = getAllPostLength(head_post);
    fprintf(file,"%d",postLength);
    fputs("\n",file);
    for (int j = 0; j < postLength; j++)
    {
        fprintf(file,"%d %d %s",temp->User_ID,temp->Like_Number,temp->Post_Text);
        // if (temp->Like_Number!=0){
        //     fputs("\n",file);
        //     for (int i = 0; i < temp->Like_Number; i++)
        //     {
        //         fprintf(file,"%d",temp->Users_Like[i]);
                
        //         fputs(" ",file);
        //     }
        //     fprintf(file,"0");
        //     fputs("\n",file);
            
        // }else{
        //     fputs("\n",file);
        // }
        fputs("\n",file);
        temp=temp->next;
    }
    return 0;
}
