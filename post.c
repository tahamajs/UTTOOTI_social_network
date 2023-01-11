#include "headers.h"

//for create new node of linklist in posts
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

//for get all post number
int getAllPostLength(Post* head_post){
    Post *temp=head_post->next;
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

//it returns number of post that user have
int getPostLength(User *user){
    Post *temp=user->User_First_Post;
    if (temp == NULL)
    {
        return 0;
    }else{
        int i=0;
        while (temp!=NULL  )
        {
            if (temp->User_ID==user->User_id)
            {
                i++;
            }
            temp=temp->next;
            
        }
        return i;
        
    }
    
}

