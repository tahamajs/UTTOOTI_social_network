//this functions are for working with posts

Post *creatPost();
void deletePost(Post *head, int id, User *user);
Post *searchPost(Post *head, int id, User *user);
void addPost(Post *head, char *postText, User *);
void showPosts(User *user);
int likePost(Post *post, User *user);
int *createList(int *list);
void setLike(User *user);
int getAllPostLength(Post *head_post);
int getPostLength(User *head);