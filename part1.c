#include <stdio.h>
#include <string.h>
void create_account(char *filename,long long int b[]){
    long long int number;
    int cnt=0,i=0;
    FILE *file,*tempfile;
    char *tempfilename="temp.txt";
    int changeline=0;
    file = fopen (filename,"r");
    while (fscanf(file,"%lld",&number)!=EOF)
    {b[cnt++] = number;}
    fclose(file);
    for(i=0;i<10;i++){
        if(b[i]==0){
            changeline=i+1;
            break;
        }
    }    
    long long int new=0;
    scanf("%lld",&new);
    file=fopen(filename, "r");
    tempfile = fopen(tempfilename, "w");
    int currentline=1;
    while (fscanf(file, "%lld", &number) != EOF){
        if(currentline==changeline)
        {fprintf(tempfile,"%lld\n",new);}
        else {fprintf(tempfile,"%lld\n",number);}
        currentline++;
    }
    fclose(file);
    fclose(tempfile);
    remove(filename);
    rename(tempfilename,filename);
}
int main(){
    printf("��ӭʹ��ѧ���ɼ�����ϵͳ.\n");
    printf("��ϵͳʹ�����ֻ��˵����������Ӧ��������֣����س���ȷ����\n");
    printf("----------ѧ������ϵͳ----------\n");
    printf("1.ѧ���˺�ע��     2.ϵͳ�û���¼\n");
    printf("3.����or�޸�����   4.�˺Ų�ѯ     \n");
    printf("5.�鿴ʹ��˵��     6.�˳�ϵͳ\n");
    int index=0;
    long long int stu_idnum[100]={0},stu_phonenum[100]={0};
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
        printf("�������������룺");
        break;
        case 6:
        return 0;
        break;
    }
    return 0;
}