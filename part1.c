#include <stdio.h>
#include <string.h>
void create_account(char *filename,long long int b[]);
void create_password(char *filename,char a[][101]);
int main(){
    printf("��ӭʹ��ѧ���ɼ�����ϵͳ.\n");
    printf("��ϵͳʹ�����ֻ��˵����������Ӧ��������֣����س���ȷ����\n");
    printf("----------ѧ������ϵͳ----------\n");
    printf("1.ѧ���˺�ע��     2.ϵͳ�û���¼\n");
    printf("3.����or�޸�����   4.�˺Ų�ѯ     \n");
    printf("5.�鿴ʹ��˵��     6.�˳�ϵͳ\n");
    int index=0;
    long long int stu_idnum[100]={0},stu_phonenum[100]={0};
    char password[100][101];
    scanf("%d",&index);
    switch(index)
    {
        case 1:
        printf("------ע���˺�------\n");
        printf("���������ĵ绰���룺");
        char temp1[]="stu_phonenum.txt";
        create_account(temp1,stu_phonenum);
        printf("\n");
        printf("����������ѧ�ţ�");
        char temp2[]="stu_idnum.txt";
        create_account(temp2,stu_idnum);
        printf("\n");
        printf("�������������루Ϊ��ȷ������İ�ȫ�ԣ���������8λ����");
        char temp3[]="password.txt";
        create_password(temp3,password);
        printf("�˺Ŵ����ɹ������μ������˺������롣");
        break;
        case 6:
        return 0;
        break;
    }
    return 0;
}
void create_password(char *filename,char a[][101]){
    int cnt=0,i=0;
    int change=0;
    char pass[101];
    FILE *file,*tempfile;
    char *tempfilename="temp.txt";
    file = fopen (filename,"r");
    while(fscanf(file,"%100s",pass)!=EOF)
    {strcpy(a[cnt++],pass);}
    for(i=0;i<100;i++){
        if(strlen(a[i])==1){
            change=i;
            break;
        }
    }
    char new[101];
    scanf("%100s",new);
    strcpy(a[change],new);
    tempfile=fopen(tempfilename,"w");
    for(i=0;i<100;i++)
    {fprintf(tempfile,"%s\n",a[i]);}
    fclose(tempfile);
    fclose(file);
    remove(filename);
    rename(tempfilename,filename);
}
void create_account(char *filename,long long int b[]){
    long long int number;
    int cnt=0,i=0;
    FILE *file,*tempfile;
    char *tempfilename="temp.txt";
    int change=0;
    file = fopen (filename,"r");
    while (fscanf(file,"%lld",&number)!=EOF)
    {b[cnt++] = number;}
    fclose(file);
    for(i=0;i<100;i++){
        if(b[i]==0){
            change=i;
            break;
        }
    }    
    long long int new=0;
    scanf("%lld",&new);
    b[change]=new;
    tempfile=fopen(tempfilename,"w");
    for(i=0;i<100;i++)
    {fprintf(tempfile,"%lld\n",b[i]);}
    fclose(file);
    fclose(tempfile);
    remove(filename);
    rename(tempfilename,filename);
}