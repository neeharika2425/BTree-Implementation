#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ht=0;
struct node
{
	int no_ele;
	int p_num;
	struct node *pts[5];
	char str[4][16];
	struct node *pred;
};
typedef struct node node;
node  *root;
int fd,fd1;
int *cnt;
int flag=1;
char ***store;
char ***store1;
int mod_n;
char * getnext(char tuple[15],int type,node *root,int ht)
{
//printf("plzzz\n");

int tuple1,q;
int f;
char temp[3];
if(strcmp(tuple,"\0")!=0)
{
//printf("plzzz\n");
        if(type==1)
	   f =     ins_check(root,ht,tuple);
      else if(type==0)
{
tuple1=0;
for(q=0;q<15;q=q+4)
{
temp[0]=tuple[q];
temp[1]=tuple[q+1];
temp[2]=tuple[q+2];
tuple1=tuple1+atoi(temp);
}
	   f =     hash(tuple,tuple1);
//printf("casee%d\n",f);
}
}
else

return "NULL";
if(f==-1)
return "NULL";
else
return tuple;





}
int hash(char *tuple,int tuple1)
{
int i,j,hash_val=0,g;
char temp[3];
int no;
hash_val=tuple1%mod_n;
if(flag==0)
{
for(i=0;i<10000;i++)
{
if(strcmp(store[i][hash_val],tuple)==0)
return -1;
}
}
//printf("enter%d\n",mod_n);
if(flag==1){
//printf("eeeeeeeey");
//printf("kkkkk%d%d\n",tuple1,mod_n);
cnt=malloc(mod_n*sizeof(int));
for(i=0;i<mod_n;i++)
cnt[i]=0;
store = (char ***) malloc(10000*sizeof(char*));
	for(i=0;i<10000;i++)
	{
		store[i]= (char **) malloc (mod_n*sizeof(char*));
		for(j=0;j<mod_n;j++)
		{
			store[i][j]=(char * ) malloc (sizeof(char)*15);
		}
	}
for(i=0;i<10000;i++)
{
for(j=0;j<mod_n;j++)
{
strcpy(store[i][j],"\0");
}
}

flag=0;
}
//printf("kkkkk%d%d\n",tuple1,mod_n);
//printf("***********%s\n",store[1][1]);
//printf("oo%dooo\n",cnt[hash_val]);
if(cnt[hash_val]>=10000)
{
//printf("entered");
flag=1;
//char store1[2][mod_n][15];
store1 = (char ***) malloc(10000*sizeof(char*));
	for(i=0;i<10000;i++)
	{
		store1[i]= (char **) malloc (mod_n*sizeof(char*));
		for(j=0;j<mod_n;j++)
		{
			store1[i][j]=(char * ) malloc (sizeof(char)*15);
		}
	}
for(i=0;i<10000;i++)
{
for(j=0;j<mod_n;j++)
{
strcpy(store1[i][j],"\0");
}
}
for(i=0;i<10000;i++)
{
for(j=0;j<mod_n;j++)
{
strcpy(store1[i][j],store[i][j]);
//printf("%sjj\n",store1[i][j]);
}
}
//printf("casee\n");
free(store);
free(cnt);
int mod_n1=mod_n;
mod_n=mod_n*2;
for(i=0;i<10000;i++)
{
for(j=0;j<mod_n1;j++)
{
if(strcmp(store1[i][j],"\0")!=0)
{
no=0;
for(g=0;g<15;g=g+4)
{
temp[0]=store1[i][j][g];
temp[1]=store1[i][j][g+1];
temp[2]=store1[i][j][g+2];
no=no+atoi(temp);
}
int g=hash(store1[i][j],no);
if(g==-1)
return -1;
}
}
}
free(store1);
g=hash(tuple,tuple1);
if(g==-1)
return -1;
//hash(mod_n+30,tuple,tuple1);
}
else
{
//printf("enterelse\n");
strcpy(store[cnt[hash_val]][hash_val],tuple);
//printf("%s\n",store[cnt[hash_val]][hash_val]);
cnt[hash_val]=cnt[hash_val]+1;
}
}
closefile(char *in_file)
{
close(fd);
close(fd1);
}
void openfile(char *in_file)
{
	if((fd = open(in_file, O_RDONLY))==-1)
		write(2, "Error3\n", 7);
fd1=open("out", O_CREAT | O_RDWR | O_TRUNC, 0777);
}
void print(node *root,int ht)
 {
 int i;
 if(ht==0)
 {
 for(i=0;i<root->no_ele;i++)
 printf("hey %s\n",root->str[i]);
 }
 else
 {
 for(i=0;i<root->no_ele+1;i++)
 {
 print(root->pts[i],ht-1);
 }
 }
}

void print1(node *root,int ht)
{
    int i,k;
     if(ht==0)
     {
   //  for(i=0;i<root->no_ele;i++)
     //printf("hey %s\n",root->str[i]);
     }
    
     else
     {
     for(i=0;i<root->no_ele;i++)
     {
     //for(k=0;k<ht;k++)
     //printf("#");
     //printf("hiii %s\n",root->str[i]);
     }
    
     for(i=0;i<root->no_ele+1;i++)
     {
    
     print1(root->pts[i],ht-1);
     }


}










}

int ptr=-1;
void print2(node* temp)
{
int i=0;
int ptri=0;
node* stck[1000];
for(i=0;i<temp->no_ele;i++)
{
//printf("%s ",temp->str[i]);
}
ptr++;
if(temp->pts[ptr]!=NULL)
print2(temp->pts[ptr]);
else
{
ptr=-1;
return;
}
}
node * div_sort(node * noo,char * tuple,int tem_ht,node * np)
{
	int p=0,i;
	for(i=0;i<noo->no_ele;i++)
	{
		if(strcmp(noo->str[i],tuple)>0)
		{
			p=i;
			break;
		}

	}
      if(i==noo->no_ele)
{
           p=i;  
//printf("ttt%dttt",p);
	strcpy(noo->str[p],tuple);
//	if(tem_ht!=0)
		noo->pts[p+1]=np;
noo->no_ele++;
return noo;
}
             
    //    printf("%sup",tuple);
	for(i=noo->no_ele;i>=p+1;i--)
	{
         
		strcpy(noo->str[i],noo->str[i-1]);
//		if(tem_ht!=0)
			noo->pts[i+1]=noo->pts[i];
}
	strcpy(noo->str[p],tuple);
//	if(tem_ht!=0)
		noo->pts[p+1]=np;
noo->no_ele++;

return noo; 


}
void split(node *poi,char *tuple,int tem_ht)
{
	int i;
	if(tem_ht==0)
	{
		if(poi->pred == NULL)
		{
			node *temp1,*temp2; 
			temp1 = malloc(sizeof(node));
			temp1->pred=NULL;
			for(i=0;i<5;i++)
				temp1->pts[i]=NULL;
			temp1->no_ele=0;
			temp2 = malloc(sizeof(node));
			temp2->pred=NULL;
			for(i=0;i<5;i++)
				temp2->pts[i]=NULL;
			temp2->no_ele=0;
			temp2->no_ele++;
			poi->no_ele=2;
			strcpy(temp2->str[0],poi->str[2]);
			strcpy(temp1->str[0],poi->str[2]);
			strcpy(temp1->str[1],poi->str[3]);
			temp1->no_ele++;
			temp1->no_ele++;
			temp2->pred=NULL;
			temp2->pts[0]=poi;
			temp2->pts[1]=temp1;
			temp1->pred=temp2;
			poi->pred=temp2;
			//	poi->p_num=0;
//			temp1->p_num=1;
			root = temp2;
			ht++;
                       /* for(i=0;i<poi->no_ele;i++)
                       printf("%see\n",poi->str[i]);
             printf("\n");
                        for(i=0;i<temp2->no_ele;i++)
                       printf("%see\n",temp2->str[i]);
             printf("\n");
                        for(i=0;i<temp1->no_ele;i++)
                       printf("%see\n",temp1->str[i]);*/
		}
		else if(poi->pred !=NULL)
		{
			node *temp3; 
			temp3 = malloc(sizeof(node));
			temp3->pred=NULL;
			for(i=0;i<5;i++)
				temp3->pts[i]=NULL;
                        temp3->no_ele=0;
			poi->no_ele=2;
		//	strcpy(poi->pred->str[poi->pred->no_ele],poi->str[2]);
			strcpy(temp3->str[0],poi->str[2]);
			strcpy(temp3->str[1],poi->str[3]);
			temp3->no_ele++;
			temp3->no_ele++;
			temp3->pred=poi->pred;
			//     temp3->p_num=
//			poi->pred->no_ele++;
//printf("qqqq%dqqqqqqqqq",poi->pred->no_ele);
			poi->pred=div_sort(poi->pred,poi->str[2],tem_ht,temp3);
		//	poi->pred->pts[poi->pred->no_ele]=temp3;
//printf("qqqq%dqqqqqqqqq",poi->pred->no_ele);
			if(poi->pred->no_ele == 4)
				split(poi->pred,tuple,tem_ht+1);
                                         
                       /* for(i=0;i<poi->no_ele;i++)
                       printf("%see\n",poi->str[i]);
             printf("\n");
                        for(i=0;i<poi->pred->no_ele;i++)
                       printf("%see\n",poi->pred->str[i]);
             printf("\n");
                        for(i=0;i<temp3->no_ele;i++)
                       printf("%see\n",temp3->str[i]);
*/
		}

	}
	if(tem_ht!=0)
	{
		if(poi->pred == NULL)
		{
			node *temp1,*temp2; 
			temp1 = malloc(sizeof(node));
			temp1->pred=NULL;
			for(i=0;i<5;i++)
				temp1->pts[i]=NULL;
			temp1->no_ele=0;
			temp2 = malloc(sizeof(node));
			temp2->pred=NULL;
			for(i=0;i<5;i++)
				temp2->pts[i]=NULL;
			temp2->no_ele=0;
			poi->no_ele=2;
			strcpy(temp2->str[0],poi->str[2]);
			temp2->no_ele++;
			strcpy(temp1->str[0],poi->str[3]);
			temp1->no_ele++;
			temp2->pred=NULL;
			poi->pred=temp2;
			temp1->pred=temp2;
			//	poi->p_num=0;
			//	temp1->p_num=1;
			temp1->pts[0]=poi->pts[3];
			temp1->pts[1]=poi->pts[4];
			temp2->pts[0]=poi;
			temp2->pts[1]=temp1;
                        temp1->pts[0]->pred=temp1;
                        temp1->pts[1]->pred=temp1;
			root = temp2;
			ht++;
                       /* for(i=0;i<poi->no_ele;i++)
                       printf("%see\n",poi->str[i]);
             printf("\n");
                        for(i=0;i<temp2->no_ele;i++)
                       printf("%see\n",temp2->str[i]);
             printf("\n");
                        for(i=0;i<temp1->no_ele;i++)
                       printf("%see\n",temp1->str[i]);
                        for(i=0;i<temp1->pts[0]->no_ele;i++)
                       printf("%see\n",temp1->pts[0]->str[i]);
             printf("\n");
                        for(i=0;i<temp1->no_ele;i++)
                       printf("%see\n",temp1->str[i]);
             printf("\n");
                        for(i=0;i<temp1->pts[1]->no_ele;i++)
                       printf("%see\n",temp1->pts[1]->str[i]);
*/
		}
		else if(poi->pred !=NULL)
		{
			node *temp3; 
			temp3 = malloc(sizeof(node));
			temp3->pred=NULL;
			for(i=0;i<5;i++)
				temp3->pts[i]=NULL;
			temp3->no_ele=0;
			poi->no_ele=2;
		//	strcpy(poi->pred->str[poi->pred->no_ele],poi->str[2]);
			strcpy(temp3->str[0],poi->str[3]);
			temp3->no_ele++;
			temp3->pred=poi->pred;
			//     temp3->p_num=
			temp3->pts[0]=poi->pts[3];
			temp3->pts[1]=poi->pts[4];
                    temp3->pts[0]->pred=temp3;
                    temp3->pts[1]->pred=temp3;
//			poi->pred->no_ele++;
			poi->pred=div_sort(poi->pred,poi->str[2],tem_ht,temp3);
	//		poi->pred->pts[poi->pred->no_ele]=temp3;
			if(poi->pred->no_ele == 4)
				split(poi->pred,tuple,tem_ht+1);
}
}




}

int ins_check(node *curr_poi,int tem_ht,char *tuple)
{
int ret;
//node *root1 = NULL;
//printf("%sll",tuple);
	int i,note,flag;
	if(tem_ht==0)
	{
		if(curr_poi==NULL)

		{

			curr_poi = malloc(sizeof(node));
			curr_poi->pred=NULL;
			for(i=0;i<5;i++)
				curr_poi->pts[i]=NULL;
			curr_poi->no_ele=1;
                           strcpy(curr_poi->str[0],tuple);
            root=curr_poi;
         //printf("%splzzzzzz\n",curr_poi->str[0]);
		}
          else if(curr_poi!=NULL)
{
		for(i=0;i<curr_poi->no_ele;i++)
		{
 if(strcmp(curr_poi->str[i],tuple)==0) return -1;
}

		if(curr_poi->no_ele <= 3)
		{

//         printf("%smm",tuple);
	          curr_poi=div_sort(curr_poi,tuple,tem_ht,NULL);
//			curr_poi->no_ele=curr_poi->no_ele+1;
//         printf("%dmm",curr_poi->no_ele);
                       // for(i=0;i<curr_poi->no_ele;i++)
                       //printf("%see\n",curr_poi->str[i]);
                       // printf("\n");
                    //    strcpy(curr_poi->str[curr_poi->no_ele],tuple);
            //            strcpy(curr_poi->str[0],tuple);

		}
		if(curr_poi->no_ele==4)
		{
        //               exit(0);
			split(curr_poi,tuple,tem_ht);

		}



	}
}

	else
	{
		flag=0;
//printf("%dkk",curr_poi->no_ele);
		for(i=0;i<curr_poi->no_ele;i++)
		{
			if(strcmp(curr_poi->str[i],tuple)>0)
			{
				note=i;
				flag=1;
				break;
			}
else  if(strcmp(curr_poi->str[i],tuple)==0)
{
//printf("oooo");
return -1;
}
}
if(i==curr_poi->no_ele)
{
note=i;
//printf("hiiii%dhiii",note);
}
//for(i=0;i<curr_poi->pts[note]->no_ele;i++)
//printf("%s rr",curr_poi->pts[note]->str[i]);

			ret  =	ins_check(curr_poi->pts[note],tem_ht-1,tuple);
if(ret==-1)
return -1;
			
}
}
int main(int argc ,char *argv[])
{
    int type;
    int no_buf;
     float size_buf;
char in_file[100];
type=atoi(argv[1]);
no_buf=atoi(argv[3]);
size_buf=atof(argv[2]);
strcpy(in_file,argv[4]);
float in_buf;
in_buf=size_buf*(no_buf-1);
int  no_rec=in_buf*1024*1024/15;
int done=size_buf*1024*1024/15;
printf("%d %d\n",no_rec,done);
openfile(in_file);
	int count=1,q,tuple1;
        char buf[2];
        char temp[3];
        char string[15];
	root=NULL;
  mod_n=200;
         int i,j,y,f;
char **storeb;
char **storeo;
         storeb = (char **) malloc(15*no_rec);
         storeo = (char **) malloc(15*done);
	for(i=0;i<no_rec;i++)
	{
		storeb[i]= (char *) malloc (15);
	} 
	for(i=0;i<done;i++)
	{
		storeo[i]= (char *) malloc (15);
	} 
int out_c=0;
	while(1)
	{
        if(count==0)
                break;


        for(i=0;i<no_rec;i++)
{
for(j=0;j<15;j++)
storeb[i][j]='\0';
}

        for(i=0;i<no_rec;i++)
{  
		count=read(fd,storeb[i],15);
		count=read(fd,buf,1);
}

        for(i=0;i<no_rec;i++)
{  
//if(count==0)
//out_c=done;
        // strcat(tuple,"\0");
//                printf("888%s888\n",store[i]);
          //      printf("888%s888\n",getnext(storeb[i],type,root,ht));
strcpy(string,getnext(storeb[i],type,root,ht));
 //            printf("888%s888\n",string);
strcpy(storeo[out_c],string);
out_c++;
if(out_c==done)
{
for(j=0;j<out_c;j++)
{
if(strcmp(storeo[j],"NULL")!=0)
{
//printf("ooo");
write(fd1,storeo[j],15);
write(fd1,"\n",1);
}
}
        for(y=0;y<done;y++)
{
for(j=0;j<15;j++)
storeo[y][j]='\0';
}


out_c=0;
}

//printf("\n");
}
}

	/*        ins_check(root,ht,"2");
		ins_check(root,ht,"1");
		ins_check(root,ht,"3");
		ins_check(root,ht,"4");
		ins_check(root,ht,"5");
		ins_check(root,ht,"6");
		ins_check(root,ht,"7");
		ins_check(root,ht,"8");
		ins_check(root,ht,"9");
		ins_check(root,ht,"98");
		ins_check(root,ht,"38");
		ins_check(root,ht,"48");
		ins_check(root,ht,"49");
		ins_check(root,ht,"44");
*/
/*		ins_check(root,ht,"1");
		ins_check(root,ht,"2");
		ins_check(root,ht,"7");
		ins_check(root,ht,"3");
		ins_check(root,ht,"4");
		ins_check(root,ht,"5");
		ins_check(root,ht,"8");
		ins_check(root,ht,"88");
		ins_check(root,ht,"98");
		ins_check(root,ht,"9");
		ins_check(root,ht,"91");
		ins_check(root,ht,"92");
		ins_check(root,ht,"93");
		ins_check(root,ht,"94");
		ins_check(root,ht,"13");
		ins_check(root,ht,"24");
		ins_check(root,ht,"27");
		ins_check(root,ht,"29");
		ins_check(root,ht,"38");
		ins_check(root,ht,"51");
		ins_check(root,ht,"43");
		ins_check(root,ht,"72");
		ins_check(root,ht,"73");
		ins_check(root,ht,"74");
		ins_check(root,ht,"81");
		ins_check(root,ht,"82");*/
/*		ins_check(root,ht,"11");
		ins_check(root,ht,"61");
		ins_check(root,ht,"31");
		ins_check(root,ht,"52");
		ins_check(root,ht,"64");
		ins_check(root,ht,"66");
		ins_check(root,ht,"75");
		ins_check(root,ht,"79");
		ins_check(root,ht,"82");
*/
//print(root,ht);
//print1(root,ht);
closefile(in_file);
}

