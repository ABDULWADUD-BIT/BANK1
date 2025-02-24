#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reg();
void tran();
int call = 1;
struct bank_user {
    char my_name[100];
    char fa_name[100];
    char ma_name[100];
    long long int id;
    long long int pass;
    long long int blance;

};

struct add_money{
    char my_name[100];
    long long int id;
    long long int money;

};


void reg(){
 int account_create,sign_up,x;
    printf("account create enter 1: ");
    scanf("%d", &account_create);
    printf("account sign up 2: ");
    scanf("%d", &sign_up);
    getchar();

    if (account_create == 1) {
        struct bank_user s1;
        printf("Enter name: ");
        fgets(s1.my_name, sizeof(s1.my_name), stdin);//scanf use on console
        printf("FATHER NAME: ");
        fgets(s1.fa_name, sizeof(s1.fa_name), stdin);
        printf("MOTHER NAME : ");
        fgets(s1.ma_name, sizeof(s1.ma_name), stdin);
        printf("Enter ID: ");
        scanf("%lld", &s1.id);
        printf("Enter PASSWRD: ");
        scanf("%lld", &s1.pass);
        printf("CHECK BLANCE :");
        scanf("%lld",&s1.blance);
        printf("Name: %s", s1.my_name);
        printf("FATHER Name: %s", s1.fa_name);
        printf("MOTHER Name: %s", s1.ma_name);
        printf("ID: %lld\n", s1.id);
        printf("password: %lld\n", s1.pass);
        printf("BLANCE : %lld\n",s1.blance);
        FILE *ptr = fopen("jibon.txt", "a+");
        fprintf(ptr,"%s %s %s %lld %lld %lld\n\n",s1.my_name, s1.fa_name, s1.ma_name, s1.id, s1.pass,s1.blance);//write in file

        fclose(ptr);

    }
     else if (sign_up == 2) {
        char name[100];
        long long int password;
        struct bank_user s1;

        printf("Enter your name: ");
        scanf("%s",name);

        printf("Enter your password: ");
        scanf("%lld", &password);

        FILE *ptr = fopen("jibon.txt", "r+");

        while (fscanf(ptr, "%s %s %s %lld %lld %lld",
                      s1.my_name, s1.fa_name, s1.ma_name, &s1.id, &s1.pass,&s1.blance) != EOF) {

            if ((strcmp(s1.my_name, name) == 0) && (s1.pass == password)) {
                printf("Name: %s\n", s1.my_name);
                printf("Father's Name: %s\n", s1.fa_name);
                printf("Mother's Name: %s\n", s1.ma_name);
                printf("ID: %lld\n", s1.id);
                printf("Password: %lld\n", s1.pass);
                printf("BLANCE : %lld\n",s1.blance);

            }

        }


        fclose(ptr);
    }
        tran();
        call++;
}
void tran(){
if(call == 1){
    struct bank_user s1;
    char name[100];
    int n;
    long long int id,x;
    printf("add money enter 3 or send money enter 4 :\n"); // impotant line
    scanf("%d",&n);
    if(n == 3){
        printf("Enter your name: ");
        scanf("%s",name);
        printf("Enter your  id: ");
        scanf("%lld", &id);
        getchar();
         FILE *ptr = fopen("jibon.txt", "a+");
           while (fscanf(ptr, "%s %s %s %lld %lld %lld",
                      s1.my_name, s1.fa_name, s1.ma_name, &s1.id, &s1.pass,&s1.blance) != EOF) {

            if ((strcmp(s1.my_name, name) == 0) && (s1.id == id)) {
                    FILE *npp = fopen("moron.txt", "a+");
                     FILE *ptr = fopen("jibon.txt", "a+");
                    struct add_money p1;
                    p1.my_name[100] = name[100];
                    p1.id =  s1.id;
                    p1.money = s1.blance;
                    printf("MONEY ADD :");
                    scanf("%lld",&x);
                    p1.money = p1.money + x;
                    s1.blance = p1.money;
                    printf("account money: %lld\n",p1.money);
                    fprintf(npp,"%s   %lld    %lld\n\n",p1.my_name,p1.id,p1.money);
                    fprintf(ptr,"%s   %lld    %lld\n\n",s1.my_name,s1.id,s1.blance);
                    fclose(npp);
            }


            }

    }
    else if(n==4){
         printf("Enter your name: ");
        scanf("%s",name);
        printf("Enter your  id: ");
        scanf("%lld", &id);
        getchar();
        FILE *ptr = fopen("jibon.txt", "a+");
           while (fscanf(ptr, "%s %s %s %lld %lld",
                      s1.my_name, s1.fa_name, s1.ma_name, &s1.id, &s1.pass) != EOF) {

            if ((strcmp(s1.my_name, name) == 0) && (s1.id == id)) {
                    FILE *npp = fopen("moron.txt", "a+");
                    struct add_money p1;
                    struct add_money p2;
                    p1.id =  s1.id;
                    scanf("%lld",&p2.id);
                    printf("MONEY transfer :");
                    scanf("%lld\n",&x);
                    p1.money = p1.money - x;
                    p2.money = p2.money + x;
                    printf("account money: %lld\n",p1.money);
                    printf("account money: %lld\n",p2.money);
                    fprintf(npp,"%lld    %lld\n\n",p1.id,p1.money+x);
                    fprintf(npp,"%lld    %lld\n\n",p2.id,p2.money-x);
                    fclose(npp);
            }
    }
    }

}
else{
    exit(0);
}


}
//void send_money(){
//
//     struct add_money p1;
//     struct add_money p2;
//     long long int x,y,z;
//     scanf("%lld %lld %lld",&x,&y,&z);
//      p1.id = x;
//      p1.money = p1.money - x;
//      p2.id = y;
//      p2.money = p2.money + x;
//
//}


int main() {
    reg();
    tran();



    return 0;
}


