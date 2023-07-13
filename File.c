#include "game.h"

int judge = 1;

FILE* fp = NULL;
char buff[255];

void zhuce() {
    char temp[20], txt[20], cha;

    printf("用户注册\n");
    printf("用户名:");
    scanf("%s", u.user);
    fp = fopen(u.user, "r");
    /*判断用户名是否重复*/
    if (fp != NULL){
            printf("\n该用户名已存在");
        fclose(fp);
        printf("\n继续注册?(Y/N)");
        scanf("%s", &cha);
        if (cha == 'Y')
            return zhuce();
        else
            return denglu();
    }
    /*确认两次密码输入是否一致*/
    do {
        printf("\n密码:");
        scanf("%s", u.mima);
        printf("\n确认密码:");
        scanf("%s", temp);
        if (strcmp(u.mima, temp) != 0)
            printf("\n两次密码不一致,请重新输入");
    } while (strcmp(u.mima, temp) != 0);
    /*用户名密码无误，写入文档储存用户信息*/
    fp = fopen(u.user, "w");
    if (fp == NULL) {
        printf("\n注册失败\n");
        exit(0);
    }
    else {
        system("cls");
        printf("\n注册成功");
        write();               //用户信息写入函数，底下给出
        judge = 0;
        denglu();             //这里跳转到登陆模块
    }
}

void write() {
    if (fwrite(&u, sizeof(user), 1, fp) != 1) {
        printf("\n写入文件错误");
        exit(0);                     //写入错误则退出程序
    }
}

void denglu() {
    char z[20], c[20], temp[20];      //定义两个数组，存放键盘输入的用户名和密码
    printf("\n用户登录");
    printf("\n用户名:");
    scanf("%s", z);
    /*判断用户名是否存在*/
    fp = fopen(z, "r+");
    temp[0] = '0';
    if (fp == NULL) {
        printf("\n用户不存在,请注册");
        printf("\n1.注册   2.重新登陆");
        scanf("%s", &temp);
        if (temp[0] == '1') {
            system("cls");
            zhuce();
        }
        else
            denglu();
    }
    /*验证密码是否正确*/
    do {
        if (judge == 1) fread(&u, sizeof(user), 1, fp); //读取用户名和密码
        printf("密码:");
        scanf("%s", c);
        if (strcmp(u.mima, c) != 0) {                     //对比输入的密码和读取的密码
            printf("\n密码错误(1.退出 2.重新输入)");
            scanf("%s", &temp);
            printf("\n");
            if (temp[0] == '1') {
                fclose(fp);                           //关闭文件防止错误操作
                zhuce();
            }
        }
    } while (temp[0] == '2');

}
 