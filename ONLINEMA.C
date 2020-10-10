#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
char filename[50]="filename.txt",sins[10];
int lyang;
void admin();
void add();
void bagdel();
void dlt();
void move(int dltline);
int del1(char item[]);
void update();
unsigned int toint(char qty[]);
void display();
void tostr(unsigned int n);
struct id
{
 char uname[30];
 struct id *link;
};
struct uid
{
 char uname[30];
 char pwd[30];
 struct uid *link;
}*front=NULL;
struct node
{
 char item[20];
 char model[20];
 char qty[10];
 char price[10];
 char color[20];
 char ram[20];
 char strg[20];
 char display[20];
 char camera[20];
 char androidvrsn[20];
 char warrenty[20];
 struct node *link;
}*first=NULL;
struct buy
{
 char item[20],model[20];
 int qty;
 unsigned long int price,tp;
 struct buy *link;
}*head=NULL;
unsigned int toint(char qty[])
{
 int i,d;
 unsigned int num=0;
 for(i=0;qty[i]!='\0';i++)
 {
  d=qty[i]-'0';
  num=d+(num*10);
 }
 return num;
}
void tostr(unsigned int n)
{
 int i,len=0;
 unsigned int d=n;
 for(i=0;d!=0;i++)
 {
  len++;
  d=d/10;
 }
 for(i=0;i<len;i++)
 {
  d=n%10;
  sins[len-(i+1)]=d+'0';
  n=n/10;
 }
 sins[len]='\0';
}
void del2()
{
 int choose,i=1;
 FILE *r1;
 struct node *pre=NULL,*temp=first;
 printf("\nEnter the item no. you want to delete(S.N):");
 scanf("%d",&choose);
 while(temp!=NULL)
 {
  if(i==choose)
  {
   printf("\n%s %s deleted successfully.\n",temp->item,temp->model);
   getch();
   break;
  }
  pre=temp;
  temp=temp->link;
  i++;
 }
 if(temp==NULL)
 {
  printf("\nITEM NOT FOUND.\n");
 }
 else if(first->link==temp->link)
 {
  first=first->link;
  free(temp);
 }
 else
 {
  pre->link=temp->link;
  free(temp);
 }
 r1=fopen("filename.txt","w");
 temp=first;
 while(temp!=NULL)
 {
  if(temp!=first)
  {
   fprintf(r1,"\n");
  }
  fprintf(r1,"%s",temp->item);
  fprintf(r1,"\t%s",temp->model);
  fprintf(r1,"\t%s",temp->qty);
  fprintf(r1,"\t%s",temp->price);
  fprintf(r1,"\t%s",temp->color);
  fprintf(r1,"\t%s",temp->ram);
  fprintf(r1,"\t%s",temp->strg);
  fprintf(r1,"\t%s",temp->display);
  fprintf(r1,"\t%s",temp->camera);
  fprintf(r1,"\t%s",temp->androidvrsn);
  fprintf(r1,"\t%s",temp->warrenty);
  temp=temp->link;
 }
 fclose(r1);
 lyang=0;
 display();
}
void update1()
{
 char ch;
 int choose,k,i=1;
 FILE *r1;
 struct node *temp=first;
 printf("\nEnter the item no. you want to update(S.N):");
 scanf("%d",&choose);
 while(temp!=NULL)
 {
  if(i==choose)
  {
   break;
  }
  temp=temp->link;
  i++;
 }
 if(temp==NULL)
 {
  printf("\nITEM NOT FOUND.\n");
 }
 else
 {
  beg:
  printf("\nEnter the new stock quantity\n: ");
  scanf("%s",temp->qty);
  for(k=0;k<strlen(temp->qty);k++)
  {
   ch=temp->qty[k];
   if(ch<'0' || ch>'9')
   {
    printf("\nINVALID QUANTITY\n");
    goto beg;
   }
  }
  geb:
  printf("\nEnter the new price of mobile\n: Rs");
  scanf("%s",temp->price);
  for(k=0;k<strlen(temp->price);k++)
  {
   ch=temp->price[k];
   if(ch<'0' || ch>'9')
   {
    printf("\nINVALID PRICE\n");
    goto geb;
   }
  }
 }
 r1=fopen("filename.txt","w");
 temp=first;
 while(temp!=NULL)
 {
  if(temp!=first)
  {
   fprintf(r1,"\n");
  }
  fprintf(r1,"%s",temp->item);
  fprintf(r1,"\t%s",temp->model);
  fprintf(r1,"\t%s",temp->qty);
  fprintf(r1,"\t%s",temp->price);
  fprintf(r1,"\t%s",temp->color);
  fprintf(r1,"\t%s",temp->ram);
  fprintf(r1,"\t%s",temp->strg);
  fprintf(r1,"\t%s",temp->display);
  fprintf(r1,"\t%s",temp->camera);
  fprintf(r1,"\t%s",temp->androidvrsn);
  fprintf(r1,"\t%s",temp->warrenty);
  temp=temp->link;
 }
 fclose(r1);
 lyang=0;
 display();
}
void display()
{
 int i=0;
 char sent[512];
 FILE *fptr;
 struct node s[10];
 fptr=fopen("filename.txt","r");
 system("cls");
 printf("\nThe items are as follows:\n");
 printf("\n============================================================================");
 printf("\nSN. NAME\tMODEL      QUANTITY    PRICE\t\tCOLOR    \tRAM\n");
 printf("\n============================================================================");
 while(!feof(fptr))
 {
  fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
  printf("\n%d   %-10s\t%-10s %+4spcs    Rs%s\t\t%-8s   %+4sGB",i+1,s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram);
  i++;
 }
 printf("\n\t\t\t\t****\n");
 fclose(fptr);
 getch();
 if(lyang==0)
 {
  admin();
 }
 else if(lyang==1)
 {
  del2();
 }
 else if(lyang==2)
 {
  update1();
 }
 getch();
}
void add()
{
 struct node s[10];
 int i,n,k,len,flag=0;
 char sent[512],name[30],ch,trash[15];
 FILE *fptr,*fptr1,*fptr2;
 //t:
  system("cls");
  printf("\n------------******PLEASE AVOID USING SPACE BY USING UNDERSCORE*****-----------");
  printf("\nEnter the number of items you want to add: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   printf("\n\t\t\tENTER THE DETAILS OF PRODUCT NO.%d\n",i+1);
   p:
   printf("\nEnter the mobile name(BRAND): ");
   scanf("%s",s[i].item);
   len=0;
   ch=s[i].item[len];
   do
   {
    if(isalpha(ch)==0)
    {
     printf("\nINVALID NAME\n");
     goto p;
    }
    len++;
    ch=s[i].item[len];
   }
   while(ch!='\0');
   fptr2=fopen("brand.txt","r");
   while(!feof(fptr2))
   {
    fscanf(fptr2,"%s",name);
    if(stricmp(name,s[i].item)==0)
    {
     flag++;
     break;
    }
   }
   fclose(fptr2);
   if(flag==0)
   {
    printf("\nPLEASE ENTER A VALID MOBILE BRAND NAME\n");
    goto p;
   }
   fptr1=fopen(filename,"r");
   printf("\nEnter its model name\n: ");
   scanf("%s",s[i].model);
   while(!feof(fptr1))
   {
    fscanf(fptr1,"%s %s",trash,name);
    if(stricmp(name,s[i].model)==0 && stricmp(trash,s[i].item)==0)
    {
     printf("\nTHIS ITEM ALREADY EXISTS\n");
     goto p;
    }
   }
   q:
   printf("\nEnter the stock quantity\n: ");
   scanf("%s",s[i].qty);
   for(k=0;k<strlen(s[i].qty);k++)
   {
    ch=s[i].qty[k];
    if(ch<'0' || ch>'9')
    {
     printf("\nINVALID QUANTITY\n");
     goto q;
    }
   }
   r:
   printf("\nEnter the price of mobile\n: Rs");
   scanf("%s",s[i].price);
   for(k=0;k<strlen(s[i].price);k++)
   {
    ch=s[i].price[k];
    if(ch<'0' || ch>'9')
    {
     printf("\nINVALID PRICE\n");
     goto r;
    }
   }
   s:
   printf("\nEnter the color of mobile: ");
   scanf("%s",s[i].color);
   len=0;
   flag=0;
   ch=s[i].color[len];
   do
   {
    if(isalpha(ch)==0)
    {
     printf("\nINVALID COLOR\n");
     goto s;
    }
    len++;
    ch=s[i].color[len];
   }
   while(ch!='\0');
   fptr2=fopen("color.txt","r");
   while(!feof(fptr2))
   {
    fscanf(fptr2,"%s %s",name,trash);
    if(strcmp(strlwr(name),strlwr(s[i].color))==0)
    {
     flag++;
     break;
    }
   }
   fclose(fptr2);
   if(flag==0)
   {
    printf("\nPLEASE ENTER A VALID COLOR NAME\n");
    goto s;
   }
   if(trash=="n")
   {
    printf("\nNOT AVAILABLE IN THIS COLOR\n");
    goto s;
   }
   u:
   printf("\nEnter the RAM size & storage( in GB )\n: ");
   scanf("%s",s[i].ram);
   for(k=0;k<strlen(s[i].ram);k++)
   {
    ch=s[i].ram[k];
    if(ch<'0' || ch>'9')
    {
     printf("\nINVALID RAM SIZE\n");
     goto u;
    }
   }
   printf("\n:");
   scanf("%s",s[i].strg);
   for(k=0;k<strlen(s[i].strg);k++)
   {
    ch=s[i].strg[k];
    if(ch<'0' || ch>'9')
    {
     printf("\nINVALID STRORAGE\n");
     goto u;
    }
   }
   printf("\nDisplay( eg: 1280x720 || 1920x1080 ) \n: ");
   scanf("%s",s[i].display);
   printf("\nCamera( Front+Back in MP )\n eg: 5+12\n: ");
   scanf("%s",s[i].camera);
   printf("\nSpecify it's android version\n: ");
   scanf("%s",s[i].androidvrsn);
   printf("\nWarrenty period( If any )\n: ");
   scanf("%s",s[i].warrenty);
   printf("\nItem %d added successfully.\n",i+1);
  }
  fclose(fptr1);
  fptr1=fopen(filename,"a+");
  for(i=0;i<n;i++)
  {
    fprintf(fptr1,"\n%s",s[i].item);
    fprintf(fptr1,"\t%s",s[i].model);
    fprintf(fptr1,"\t%s",s[i].qty);
    fprintf(fptr1,"\t%s",s[i].price);
    fprintf(fptr1,"\t%s",s[i].color);
    fprintf(fptr1,"\t%s",s[i].ram);
    fprintf(fptr1,"\t%s",s[i].strg);
    fprintf(fptr1,"\t%s",s[i].display);
    fprintf(fptr1,"\t%s",s[i].camera);
    fprintf(fptr1,"\t%s",s[i].androidvrsn);
    fprintf(fptr1,"\t%s",s[i].warrenty);
  }
 fclose(fptr1);
 system("cls");
 display();
}
void admin()
{
 int choice;
 char filenam[20];
 struct node *p,*temp;
 FILE *r1;
 clrscr();
 while(1)
 {
  printf("\n1-add 2-delete 3-update 4-display 5-logout\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
     add();
     break;
   case 2:
     first=NULL;
     r1=fopen("filename.txt","r+");
     while(!feof(r1))
     {
      p=(struct node*)malloc(sizeof(struct node));
      fscanf(r1,"%s %s %s %s %s %s %s %s %s %s %s",p->item,p->model,p->qty,p->price,p->color,p->ram,p->strg,p->display,p->camera,p->androidvrsn,p->warrenty);
      p->link=NULL;
      if(first==NULL)
      {
       first=p;
      }
      else
      {
       temp=first;
       while(temp->link!=NULL)
       {
	temp=temp->link;
       }
       temp->link=p;
      }
     }
     fclose(r1);
     lyang=1;
     display();
     del2();
     break;
   case 3:
     system("cls");
     first=NULL;
     r1=fopen("filename.txt","r+");
     while(!feof(r1))
     {
      p=(struct node*)malloc(sizeof(struct node));
      fscanf(r1,"%s %s %s %s %s %s %s %s %s %s %s",p->item,p->model,p->qty,p->price,p->color,p->ram,p->strg,p->display,p->camera,p->androidvrsn,p->warrenty);
      p->link=NULL;
      if(first==NULL)
      {
       first=p;
      }
      else
      {
       temp=first;
       while(temp->link!=NULL)
       {
	temp=temp->link;
       }
       temp->link=p;
      }
     }
     fclose(r1);
     lyang=2;
     display();
     update1();
     break;
   case 4:
     lyang=0;
     display();
     break;
   case 5:
     exit(0);
  }
 }
}


void addbuy(char it[],char mod[],int x,char pri[])
{
 struct buy  *p;
 p=(struct buy*)malloc(sizeof(struct buy));
 strcpy(p->item,it);
 strcpy(p->model,mod);
 p->qty=x;
 p->price=toint(pri);
 p->tp=(x*p->price);
 p->link=NULL;
 if(head==NULL)
 {
  head=p;
 }
 else
 {
  p->link=head;
  head=p;
 }
 printf("\n%s %s succecssfully added to bag.\n",p->item,p->model);
}
void bag()
{

 int i=1,choice,j,d,len;
 unsigned int num;
 unsigned long long int total=0;
 FILE *r1;
 struct buy *temp=head;
 struct node *p,*t;
 if(head==NULL)
 {
  printf("\nNO ITEMS ADDED TO CART.\n");
  getch();
 }
 else
 {
  printf("\n\t\t\t***BAG***\n");
  printf("\nSN. ITEM\tMODEL\tQUANTITY\t  PRICE\t   TOTAL PRICE\n");
  while(temp!=NULL)
  {
   printf("\n%d.  %-8s   %-8s  %5dpcs\t Rs%-9llu    Rs%-9llu\n",i,temp->item,temp->model,temp->qty,temp->price,temp->tp);
   total=total+temp->tp;
   temp=temp->link;
   i++;
  }
  printf("\nYour total amount is Rs%llu.\n",total);
  printf("\n1-delete\t2-purchase\t3-Go back\n");
  scanf("%d",&choice);
  if(choice==1)
  {
   bagdel();
   system("cls");
   bag();
  }
  else if(choice==2)
  {
   printf("\nTHANK YOU FOR PURCHASING ON OMM.\n");
   r1=fopen("filename.txt","r");
   first=NULL;
   while(!feof(r1))
   {
    p=(struct node*)malloc(sizeof(struct node));
    fscanf(r1,"%s %s %s %s %s %s %s %s %s %s %s",p->item,p->model,p->qty,p->price,p->color,p->ram,p->strg,p->display,p->camera,p->androidvrsn,p->warrenty);
    p->link=NULL;
    if(first==NULL)
    {
     first=p;
    }
    else
    {
     t=first;
     while(t->link!=NULL)
     t=t->link;
     t->link=p;
    }
   }
   fclose(r1);
   temp=head;
   while(temp!=NULL)
   {
    t=first;
    while(t!=NULL)
    {
     if(stricmp(temp->item,t->item)==0 && stricmp(temp->model,t->model)==0)
     {
      num=toint(t->qty)-temp->qty;
      tostr(num);
      strcpy(t->qty,sins);
      break;
     }
     t=t->link;
    }
    temp=temp->link;
   }
   r1=fopen("filename.txt","w");
   t=first;
   while(t!=NULL)
   {
    if(t!=first)
    {
     fprintf(r1,"\n");
    }
    fprintf(r1,"%s",t->item);
    fprintf(r1,"\t%s",t->model);
    fprintf(r1,"\t%s",t->qty);
    fprintf(r1,"\t%s",t->price);
    fprintf(r1,"\t%s",t->color);
    fprintf(r1,"\t%s",t->ram);
    fprintf(r1,"\t%s",t->strg);
    fprintf(r1,"\t%s",t->display);
    fprintf(r1,"\t%s",t->camera);
    fprintf(r1,"\t%s",t->androidvrsn);
    fprintf(r1,"\t%s",t->warrenty);
    t=t->link;
   }
   fclose(r1);
   head=NULL;
   first=NULL;
   getch();
  }
  else if(choice==3)
  {
   goto be;
  }
  else
  {
   printf("\nINVALID ENTRY.\n");
  }
 }
 be:
}
void bagdel()
{
 int choose,i=1;
 char it[10],mod[20];
 struct buy *temp=head,*pre=NULL;
 printf("\nEnter the item number you want to delete(S.N):");
 scanf("%d",&choose);
 while(temp!=NULL)
 {
  if(i==choose)
  {
   strcpy(it,temp->item);
   strcpy(mod,temp->model);
   break;
  }
  pre=temp;
  temp=temp->link;
  i++;
 }
 if(temp==NULL)
 {
  printf("\nINVALID ENTRY.\n");
  getch();
 }
 else if(head->link==temp->link)
 {
  head=head->link;
  free(temp);
  system("cls");
  printf("\n%s %s deleted successfully.\n",it,mod);
  getch();
 }
 else
 {
  pre->link=temp->link;
  free(temp);
  system("cls");
  printf("\n%s %s deleted successfully.\n",it,mod);
  getch();
 }
}
void products()
{
 FILE *f1,*f2,*f3;
 struct node s[30],v;
 int brand,i=0,nl=0,select,add;
 char sent[512],ch,ll[100];
 clrscr();

 while(1)
 {
  system("cls");
  printf("\nWhich brand do you want to check?\n");
  printf("\n1.SAMSUNG\t\t2.NOKIA\t\t3.ONEPLUS\t\t4.REALME\n5.HUAWEI\t\t6.OPPO\t\t7.VIVO\t\t\t8.ASUS\n9.XIAOMI\t\t10.MICROMAX\t\t\t100.GOTO BAG\n");
  printf("\nEnter 0 to go back\n");
  scanf("%d",&brand);
  switch(brand)
  {
   case 1:
     loop:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***SAMSUNG***\n");
     f1=fopen("filename.txt","r+");
     if(f1==NULL)
     {
      printf("\nERROR OPENING FILE.\n");
     }
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"samsung")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
       system("cls");
       printf("\n\t\t\t***SAMSUNG***\n");
       printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     if(f1==NULL)
     {
      printf("\nERROR OPENING FILE.\n");
     }
     a2:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     strcpy(s[i].model,ll);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a2;
     }
     else if(select==0)
     {
      goto exec;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     //while(fgets(sent,512,f1)!=NULL)
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"samsung")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s\n",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back;
       }
       i++;
      }
     }
     back:
     fclose(f1);
     goto loop;
     exec:
     break;
   case 2:
     loop1:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***NOKIA***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"nokia")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a3:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a3;
     }
     else if(select==0)
     {
      goto exec1;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"nokia")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back1;
       }
       i++;
      }
     }
     back1:
     fclose(f1);
     goto loop1;
     exec1:
     break;
   case 3:
     loop2:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***ONEPLUS***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"oneplus")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a4:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a4;
     }
     else if(select==0)
     {
      goto exec2;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"oneplus")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back2;
       }
       i++;
      }
     }
     back2:
     fclose(f1);
     goto loop2;
     exec2:
     break;
   case 4:
     loop3:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***REALME***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"realme")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a5:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a5;
     }
     else if(select==0)
     {
      goto exec3;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"realme")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back3;
       }
       i++;
      }
     }
     back3:
     fclose(f1);
     goto loop3;
     exec3:
     break;
   case 5:
     loop4:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***HUAWEI***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"huawei")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a6:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a6;
     }
     else if(select==0)
     {
      goto exec4;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"huawei")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back4;
       }
       i++;
      }
     }
     back4:
     fclose(f1);
     goto loop4;
     exec4:
     break;
   case 6:
     loop5:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***OPPO***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"oppo")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a7:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a7;
     }
     else if(select==0)
     {
      goto exec5;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"oppo")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back5;
       }
       i++;
      }
     }
     back5:
     fclose(f1);
     goto loop5;
     exec5:
     break;
   case 7:
     loop6:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***VIVO***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"vivo")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a8:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a8;
     }
     else if(select==0)
     {
      goto exec6;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"vivo")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back6;
       }
       i++;
      }
     }
     back6:
     fclose(f1);
     goto loop6;
     exec6:
     break;
   case 8:
     loop7:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***ASUS***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"asus")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a9:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a9;
     }
     else if(select==0)
     {
      goto exec7;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"asus")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back7;
       }
       i++;
      }
     }
     back7:
     fclose(f1);
     goto loop7;
     exec7:
     break;
   case 9:
     loop8:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***XIAOMI***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"xiaomi")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a10:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a10;
     }
     else if(select==0)
     {
      goto exec8;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"xiaomi")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back8;
       }
       i++;
      }
     }
     back8:
     fclose(f1);
     goto loop8;
     exec8:
     break;
   case 10:
     loop9:
     nl=0;
     i=0;
     system("cls");
     printf("\n\t\t\t***MICROMAX***\n");
     f1=fopen("filename.txt","r");
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"micromax")==0)
      {
       if(nl==4)
       {
	printf("\n");
	nl=0;
       }
       printf("%d.%s\t\t",i+1,s[i].model);
       nl++;
       i++;
      }
     }
     if(i==0)
     {
      system("cls");
      printf("\n\t\t\t***NOKIA***\n");
      printf("\nSTOCK NOT AVAILABLE\n");
     }
     printf("\n");
     fclose(f1);
     f1=fopen("filename.txt","r");
     a11:
     printf("\nSelect to explore details:");
     printf("\nEnter 0 to go back\n");
     scanf("%d",&select);
     if(select>i)
     {
      printf("\nINVALID ENTRY\n");
      goto a11;
     }
     else if(select==0)
     {
      goto exec9;
     }
     system("cls");
     i=0;
     while(!feof(f1))
     {
      fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s",s[i].item,s[i].model,s[i].qty,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
      if(stricmp(s[i].item,"micromax")==0)
      {
       if(i+1==select)
       {
	printf("\nBRAND:%s\t\t\tMODEL:%s\nPRICE:%s\t\t\tCOLOR:%s\nRAM:%s\t\t\t\tSTORAGE:%s\nDISPLAY:%s\t\t\tCAMERA:%s\nANDROID VERSION:%s\t\tWARRENTY:%s",s[i].item,s[i].model,s[i].price,s[i].color,s[i].ram,s[i].strg,s[i].display,s[i].camera,s[i].androidvrsn,s[i].warrenty);
	printf("\nDo you want to buy %s %s?\nIf yes enter y/Y ...",s[i].item,s[i].model);
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
	 printf("\nEnter the no. of products:");
	 scanf("%d",&add);
	 printf("\ITEM ADDED SUCCESSFULLY TO YOUR BAG\n");
	 addbuy(s[i].item,s[i].model,add,s[i].price);
	}
	printf("\nPress Enter To Go Back..");
	getch();
	goto back9;
       }
       i++;
      }
     }
     back9:
     fclose(f1);
     goto loop9;
     exec9:
     break;
   case 0:
     goto last;
   case 100:
     bag();
     getch();
     break;
   default:
     printf("\nINVALID ENTRY\n");
     getch();
     break;
  }
 }
last:
}
void comment()
{
 int choose;
 char sent[512],ch;
 FILE *f1;
 while(1)
 {
  system("cls");
  printf("\n1.SAMSUNG\t\t2.NOKIA\t\t3.ONEPLUS\t\t4.REALME\n5.HUAWEI\t\t6.OPPO\t\t7.VIVO\t\t\t8.ASUS\n9.XIAOMI\t\t10.MICROMAX\t\t0-GO BACK\n");
  scanf("%d",&choose);
  switch(choose)
  {
   case 1:
     system("cls");
     printf("\t\t\t\t***SAMSUNG***\n");
     f1=fopen("samsung.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("samsung.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 2:
     system("cls");
     printf("\t\t\t\t***NOKIA***\n");
     f1=fopen("nokia.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("nokia.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 3:
     system("cls");
     printf("\t\t\t\t***ONEPLUS***\n");
     f1=fopen("oneplus.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("oneplus.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 4:
     system("cls");
     printf("\t\t\t\t***REALME***\n");
     f1=fopen("realme.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("realme.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 5:
     system("cls");
     printf("\t\t\t\t***HUAWEI***\n");
     f1=fopen("huawei.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("huawei.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 6:
     system("cls");
     printf("\t\t\t\t***OPPO***\n");
     f1=fopen("oppo.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("oppo.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 7:
     system("cls");
     printf("\t\t\t\t***VIVO***\n");
     f1=fopen("vivo.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("vivo.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 8:
     system("cls");
     printf("\t\t\t\t***ASUS***\n");
     f1=fopen("asus.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("asus.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 9:
     system("cls");
     printf("\t\t\t\t***XIAOMI***\n");
     f1=fopen("xiaomi.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("xiaomi.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 10:
     system("cls");
     printf("\t\t\t\t***MICROMAX***\n");
     f1=fopen("micromax.txt","r");
     while(!feof(f1))
     {
      fgets(sent,512,f1);
      if(stricmp(sent,"\n")!=0)
      printf("%s",sent);
     }
     fclose(f1);
     f1=fopen("micromax.txt","a+");
     printf("\n\nMention the model name:\n");
     gets(sent);
     if(stricmp(sent,"\0")!=0)
     fprintf(f1,"\n%s",sent);
     fclose(f1);
     break;
   case 0:
     goto ge;
   default:
     printf("\nInvalid entry\n");
     getch();
     break;
  }
 }
 ge:
}
void editu(char name[],char pd[])
{
 char ch;
 int choose,k,len;
 struct uid *temp=front,u;
 FILE *r1;
 while(temp!=NULL)
 {
  if(stricmp(temp->uname,name)==0 && stricmp(temp->pwd,pd)==0)
  {
   break;
  }
  temp=temp->link;
 }
 if(temp==NULL)
 {
  printf("\nITEM NOT FOUND.\n");
 }
 else
 {
  system("cls");
  bg:
  printf("\nEnter the new user name\n: ");
  scanf("%s",temp->uname);
  for(len=0;len<strlen(temp->uname);len++)
  {
   ch=temp->uname[len];
   if(isalpha(ch)==0)
   {
    printf("\nINVALID NAME\n");
    goto bg;
   }
  }
  r1=fopen("user.txt","r");
  while(!feof(r1))
  {
   fscanf(r1,"%s %s",u.uname,u.pwd);
   if(stricmp(u.uname,temp->uname)==0)
   {
    printf("\nTHIS USERNAME ALREADY EXISTS");
    goto bg;
   }
  }
  fclose(r1);
  printf("\nENTER your new 4 DIGIT PASSWORD : ");
  for(len=0;len<4;len++)
  {
   ch=getch();
   temp->pwd[len]=ch;
   ch='*';
   printf("*",ch);
  }
  temp->pwd[len]='\0';
 }
}
void customeru()
{
 system("cls");
 printf("\n\t\t\t\t***CUSTOMER CARE***\n");
 printf("\n\tFAQs:\n");
 printf("\n1.How to find other brands?\n");
 printf("\n->We are very sorry for your inconvenience, we will provide search option as \nsoon as possible.\n");
 printf("\n2.How to remove products from my bag?\n");
 printf("\n->Goto bag, choose delete option, then enter the item no. you want to remove.\n");
 printf("\n3.Where is my invoice?\n");
 printf("\n->Invoice will be directly sent to your mobile number through MMS.\n");
 printf("\n4.How to see my orders?\n");
 printf("\n->Order option will be provided as soon as possible.\n");
 printf("\n\n\n***If there are any other queries please contact on our toll-free number:*** \n\t\t\t\t\***9814416809***\n");
}
void user(char name[],char pd[])
{
 int choose,len;
 char uname[20],pwd[20],ch;
 struct uid *p,*temp;
 FILE *r1;
 clrscr();
 while(1)
 {
  printf("\n1.EDIT PROFILE\t\t2.PRODUCTS\t\t3.BAG\n4.COMMENTS\t\t5.CUSTOMER CARE\t\t6.LOG OUT\n");
  scanf("%d",&choose);
  switch(choose)
  {
   case 1:
     get:
     system("cls");
     printf("\nEDIT PROFILE\n");
     printf("\nEnter your user id:");
     scanf("%s",uname);
     if(stricmp(name,uname)==0)
     {
      printf("\nENTER your 4 DIGIT PASSWORD : ");
      for(len=0;len<4;len++)
      {
       ch=getch();
       pwd[len]=ch;
       ch='*';
       printf("*",ch);
      }
      pwd[len]='\0';
      if(stricmp(pwd,pd)==0)
      {
       front=NULL;
       r1=fopen("user.txt","r+");
       while(!feof(r1))
       {
	p=(struct uid*)malloc(sizeof(struct uid));
	fscanf(r1,"%s %s",p->uname,p->pwd);
	p->link=NULL;
	if(front==NULL)
	{
	 front=p;
	}
	else
	{
	 temp=front;
	 while(temp->link!=NULL)
	 {
	  temp=temp->link;
	 }
	 temp->link=p;
	}
       }
       fclose(r1);
       editu(uname,pwd);
       r1=fopen("user.txt","w");
       temp=front;
       while(temp!=NULL)
       {
	if(temp!=front)
	{
	 fprintf(r1,"\n");
	}
	fprintf(r1,"%s",temp->uname);
	fprintf(r1,"\t%s",temp->pwd);
	temp=temp->link;
       }
       fclose(r1);
      }
     }
     else
     {
      printf("\nWrong user name.\n");
      getch();
      goto get;
     }
     break;
   case 2:
     system("cls");
     products();
     system("cls");
     break;
   case 3:
     system("cls");
     printf("\nBAG\n");
     bag();
     getch();
     break;
   case 4:
     system("cls");
     printf("\nCOMMENTS\n");
     comment();
     getch();
     break;
   case 5:
     system("cls");
     printf("\nCUSTOMER CARE\n");
     customeru();
     getch();
     system("cls");
     break;
   case 6:
     system("cls");
     goto a1;
   default:
     system("cls");
     printf("\nINVALID ENTRY\n");
     getch();
     break;
  }
 }
 a1:
}
void main()
{
 struct id *u,*p;
 int choice,choice1,flag=0,len;
 char uname[30],pwd[30],luname[30],lpwd[30],sent[70],ch,ch1;
 FILE *fptr,*fptr1;
 clrscr();
 u=(struct id*)malloc(sizeof(struct id));
 p=(struct id*)malloc(sizeof(struct id));
 u->link=p;
 p->link=NULL;
 printf("-----------------WELCOME TO ONLINE MARKET FOR MOBILE-------------------");
 printf("\n\n\n\nDo you want to login/register?");
 printf("\n\t\t1-LOGIN\t\t2-REGISTER\n");
 scanf("%d",&choice);
 if(choice==1)
 {
  printf("\nDo you have admin or user id?\n");
  printf("\t\t\t\t1-admin\t\t\t\t2-user\n");
  scanf("%d",&choice1);
  if(choice1==1)
  {
   b:
   fptr=fopen("admin.txt","r+");
   if(fptr==NULL)
   {
    printf("\nFAILED TO LOGIN/SERVER DOWN\n");
    goto b;
   }
   else
   {
    printf("\nUSERNAME : ");
    scanf("%s",luname);
    while(!feof(fptr))
    {
     fscanf(fptr,"%s %s",&u->uname,&p->uname);

     if(strcmp(u->uname,luname)==0)
     {
      flag++;
      break;
     }
    }
    if(flag==0)
    {
     printf("\nUSERNAME not found!\n");
    }
    else
    {
     c:
     printf("\nPASSWORD :");
     for(len=0;len<4;len++)
     {
      ch=getch();
      lpwd[len]=ch;
      ch='*';
      printf("*",ch);
     }
     lpwd[len]='\0';
     if(strcmp(p->uname,lpwd)==0)
     {
      printf("\nYOU ARE LOGGED IN AS ADMIN.");
      flag++;
      admin();
     }
     else if(flag==1)
     {
      printf("\nINCORRECT PASSWORD");
      printf("\nDo you want to enter password again?(y/n)");
      ch=getch();
      if(ch=='y'||ch=='Y')
      {
       goto c;
      }
      else
      {
       exit(0);
      }
     }
    }
   }
   fclose(fptr);
  }
  else if(choice1==2)
  {
   d:
   fptr=fopen("user.txt","r+");
   if(fptr==NULL)
   {
    printf("\nFAILED TO LOGIN/SERVER DOWN\n");
    goto d;
   }
   else
   {
    printf("\nUSERNAME : ");
    scanf("%s",luname);
    while(!feof(fptr))
    {
     fscanf(fptr,"%s %s",&u->uname,&p->uname);
     if(strcmp(u->uname,luname)==0)
     {
      flag++;
      break;
     }
    }
    if(flag==0)
    {
     printf("\nUSERNAME not found!\n");
    }
    else
    {
     e:
     printf("\nPASSWORD :");
     for(len=0;len<4;len++)
     {
      ch=getch();
      lpwd[len]=ch;
      ch='*';
      printf("*",ch);
     }
     lpwd[len]='\0';
     if(strcmp(p->uname,lpwd)==0)
     {
      printf("\nYOU ARE LOGGED IN AS USER.");
      flag++;
      user(luname,lpwd);
     }
     else if(flag==1)
     {
      printf("\nINCORRECT PASSWORD");
      printf("\nDo you want to enter password again?(y/n)");
      ch=getch();
      if(ch=='y'||ch=='Y')
      {
       goto e;
      }
      else
      {
       exit(0);
      }
     }
    }
   }
   fclose(fptr);
  }
 }
 else if(choice==2)
 {
  printf("\nDo you want to register as admin/user?");
  printf("\n\t\t\t1-admin\t\t\t2-user\n");
  scanf("%d",&choice1);
  if(choice1==1)
  {
   f:
   fptr=fopen("admin.txt","a+");
   if(fptr==NULL)
   {
    printf("/nPLEASE GET PROPER INTERNET CONNECTION./n");
    goto f;
   }
   else
   {
    g:
    printf("\nENTER USERNAME : ");
    scanf("%s",&uname);
    for(len=0;len<strlen(uname);len++)
    {
     ch1=uname[len];
     if(isalpha(ch1)==0)
     {
      printf("\nINVALID NAME\n");
      goto g;
     }
    }
    fptr1=fopen("admin.txt","r");
    while(!feof(fptr1))
    {
     fscanf(fptr1,"%s %s",&u->uname,&p->uname);
     if(stricmp(u->uname,uname)==0)
     {
      printf("\nTHIS USERNAME ALREADY EXISTS");
      goto g;
     }
    }
    fclose(fptr1);
    printf("\nENTER 4 DIGIT PASSWORD : ");
    for(len=0;len<4;len++)
    {
     ch=getch();
     pwd[len]=ch;
     ch='*';
     printf("*",ch);
    }
    pwd[len]='\0';
    fprintf(fptr,"\n%-10s %-15s",uname,pwd);
    printf("\nSUCCESSFULLY REGISTERED AS ADMIN!\n");
   }
   fclose(fptr);
   goto b;
  }
  else if(choice1==2)
  {
   h:
   fptr=fopen("user.txt","a+");
   if(fptr==NULL)
   {
    printf("/nPLEASE GET PROPER INTERNET CONNECTION./n");
    goto h;
   }
   else
   {
    i:
    printf("\nENTER USERNAME : ");
    scanf("%s",&uname);
    for(len=0;len<strlen(uname);len++)
    {
     ch1=uname[len];
     if(isalpha(ch1)==0)
     {
      printf("\nINVALID NAME\n");
      goto i;
     }
    }
    fptr1=fopen("user.txt","r");
    while(!feof(fptr1))
    {
     fscanf(fptr1,"%s %s",&u->uname,&p->uname);
     if(stricmp(u->uname,uname)==0)
     {
      printf("\nTHIS USERNAME ALREADY EXISTS");
      goto i;
     }
    }
    fclose(fptr1);
    printf("\nENTER 4 DIGIT PASSWORD : ");
    for(len=0;len<4;len++)
    {
     ch=getch();
     pwd[len]=ch;
     ch='*';
     printf("*",ch);
    }
    pwd[len]='\0';
    fprintf(fptr,"\n%-10s %-15s",uname,pwd);
    printf("\nSUCCESSFULLY REGISTERED AS USER!\n");
   }
   fclose(fptr);
   goto d;
  }
 }
 getch();
}