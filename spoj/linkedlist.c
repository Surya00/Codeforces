#include<stdio.h>

struct node {
	int data;
	struct node *add;
};

  insertionattheend(int data,struct node* head, struct node* temp, int no){
  	struct node* newnode;
  	newnode = (struct node*)malloc(sizeof(struct node));
  	newnode->data= data;
  	newnode->add= NULL;
  	if( no== 0){
  		head = newnode;
        temp = newnode;
  	}else{
  		temp->add= newnode;
  		temp= newnode;
  	}
  }

   insertionatthebegining( int data, struct node* head){
   	  struct node* newnode;
   	  newnode= ( struct node*)malloc(sizeof(struct node));
   	   newnode->data= data;
   	   newnode->add= head;
   	   head= newnode;
   }

   printlist(struct node* head){
   	  while(head!= NULL){
   	  	cout<<head->data<<endl;
   	  	head= head->add;
   	  }
   }

   deleteelement( struct node* head, int data){
   	 struct node* temp;
   	 struct node* temp2;
   	  while( head->data!= data){
   	  	temp= head;
   	  	temp2= head->add;
   	  	head= head->add;
   	  }
   	   temp->add= temp2->add;
   }

     sortlist(struct node* head){
        struct node* temp;
        struct node* temp2;
        temp= temp2= head;
        int c;
        while( temp!= NULL){

        	while( temp2->add!= NULL){
               if(temp2->add->data< temp2->data){
                 c= temp2->add->data;
                 temp2->add->data= temp2->data;
                 temp2->data= c;

               }
               temp2= temp2->add;
        	}
        	 temp= temp->add;

        }
     }

        search(struct node* head, data){
        	while(head!= NULL){
        		if(head->data== data){
        			f=1;
        			break;
        		}	
        	}

        	if(f){
        		return true;
        	}
              return false;
        }

        reverselist( struct node* head){
        	struct node* temp;
        	struct node* temp2;
                temp= head;

                head= head->add;
                temp->add= NULL;
        	while(head!= NULL){
                temp2= head->add;
                head->add= temp;
                temp= head;
                head= temp2;
        	}
        }

  int main(int argc, char const *argv[])
  {
  	 int a,b,c,n,m;
  	 struct node* head;
  	 cout<<" Enter the no of node";
  	 cin>>t;
     cout<<"Enter the choice 1 for insertion at the end and 2 for insertion at the begining";
     cin>>n;
     if(n==1){
     cout<<"Enter the node data";
     struct node* temp;
     	while(t--){
     		cin>>m;
     		insertionattheend(m,head,temp,0);
     	}
     }
     else{
     	cout<<"Enter the node data";
        struct node* temp;
     	while(t--){
     		cin>>m;
     		insertionatthebegining(m,head);
     	}

     }
       struct node* temp;
       temp= head;
        printlist(temp);
         temp= head;
        reverselist(temp);
        temp= head;
        printlist(temp);
  	return 0;

  }