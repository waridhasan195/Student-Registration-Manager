#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[100];
    char id[100];
    char program[100];
    char sec[3];
    char ph[100];
    struct node*next;
};struct node*head=NULL;
void regis(char*stn,char*si,char*sc,char*sph,char*sp);
void display();
void search(char*sit);
int main()
{
    int c;
    char stn[100],si[100],sc[3],sph[100],sp[100],sit[3],sitt[100],sect[100];

    do{
     printf("\n                           >>>>>>>>>MENU<<<<<<<<<<<<<<<<<\n");
    printf("                                 \n");
    printf("                             1.Register a student\n");
    printf("                             2.Show all students information\n");
    printf("                             3.Search a student\n");
    printf("                             4.Total students in a Section\n");\
    printf("                             5.Delete information\n");
    printf("                             pres 0 for exit\n");
    printf("Enter your choice\n");
    scanf("%d",&c);
    switch(c)
    {

        case 1:printf("Enter student name:\n");
        scanf(" %[^\n]",&stn);
        printf("Enter student ID:\n");
        scanf(" %[^\n]",&si);
        printf("Enter Department:\n");
        scanf(" %[^\n]",&sp);
        printf("Enter Section:\n");
        scanf(" %[^\n]",&sc);
        printf("Enter student phone number:\n");
        scanf(" %[^\n]",&sph);
        regis(stn,si,sc,sph,sp);

        printf(">>>>>>Sucessfully added<<<<<<<<<\n");
        break;

        case 2:printf(">>>>>>>All Students Information<<<<<<<<<\n");
        display();
        break;

        case 3:printf("Enter student ID:\n");
        scanf(" %[^\n]",&sit);
       printf("\n>>>>>>Search Result<<<<<<<\n");
       search(sit);
       break;

       case 4:printf("Enter section: \n");
       scanf(" %[^\n]",&sect);
       count(sect);
       break;

       case 5:printf("Enter ID: \n");
       scanf(" %[^\n]",&sitt);
       deleteinfo(sitt);
       printf(">>>>>>>>Delete Sucessfully<<<<<<<<<<<<\n");
       break;

    }
    }while(c!=0);
}
void regis(char*stn,char*si,char*sc,char*sph,char *sp)
{
    int i;
    struct node*temp1,*p;
    temp1=(struct node*)malloc(sizeof(struct node));
    strcpy(temp1->name,stn);
    strcpy(temp1->id,si);
    strcpy(temp1->sec,sc);
    strcpy(temp1->ph,sph);
    strcpy(temp1->program,sp);
    temp1->next=NULL;
    p=head;
    if(head==NULL){
        head=temp1;
    }else
    {
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp1;
    }
}
void display()
{
    struct node*temp=head;
    if(head==NULL){
        printf("List is empty\n");
    }else
    {
         int i=0;
        while(temp!=NULL){
            printf("\nNO: %d\tNAME: %s\tID: %s\tDEPARTMENT: %s\tSECTION: %s\tMOBILE: %s\t",i+1,temp->name,temp->id,temp->program,temp->sec,temp->ph);
            temp=temp->next;
            i++;
        }
        printf("\n");
    }
}
void search(char*sit)
{

    struct node*temp=head;
    while(temp!=NULL){
            if(strcmp(temp->id,sit)==0){
                   printf("Name: %s\n",temp->name);
                   printf("ID: %s\n",temp->id);
                   printf("Section: %s\n",temp->sec);
                   printf("Department: %s\n",temp->program);
                   printf("Mobile No: %s\n",temp->ph);
                   printf("\n");
                   return;

            }
            temp=temp->next;
    }


}
void count(char*sect)
{
    int count=0;
    struct node*temp=head;
    while(temp!=NULL){
        if(strcmp(temp->sec,sect)==0){
            count++;
        }
        temp=temp->next;
    }
    printf("Total student in '%s' section = %d\n",sect,count);

}
void deleteinfo(char*sitt)
{
    int i=0;
    struct node*temp1=head;
    while(temp1!=NULL){
            i++;
        if(strcmp(temp1->id,sitt)==0){
            delit(i);
            return i;
        }
        temp1=temp1->next;
    }

}
void delit(int i)
{
    struct node*temp1=head;
    if(i==1){
        head=temp1->next;
        free(temp1);
    }else
    {
        int j;
        for(j=1;j<i-1;j++){
            temp1=temp1->next;
        }struct node*temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
    }
}

