#include "game.h"

int judge = 1;

FILE* fp = NULL;
char buff[255];

void zhuce() {
    char temp[20], txt[20], cha;

    printf("�û�ע��\n");
    printf("�û���:");
    scanf("%s", u.user);
    fp = fopen(u.user, "r");
    /*�ж��û����Ƿ��ظ�*/
    if (fp != NULL){
            printf("\n���û����Ѵ���");
        fclose(fp);
        printf("\n����ע��?(Y/N)");
        scanf("%s", &cha);
        if (cha == 'Y')
            return zhuce();
        else
            return denglu();
    }
    /*ȷ���������������Ƿ�һ��*/
    do {
        printf("\n����:");
        scanf("%s", u.mima);
        printf("\nȷ������:");
        scanf("%s", temp);
        if (strcmp(u.mima, temp) != 0)
            printf("\n�������벻һ��,����������");
    } while (strcmp(u.mima, temp) != 0);
    /*�û�����������д���ĵ������û���Ϣ*/
    fp = fopen(u.user, "w");
    if (fp == NULL) {
        printf("\nע��ʧ��\n");
        exit(0);
    }
    else {
        system("cls");
        printf("\nע��ɹ�");
        write();               //�û���Ϣд�뺯�������¸���
        judge = 0;
        denglu();             //������ת����½ģ��
    }
}

void write() {
    if (fwrite(&u, sizeof(user), 1, fp) != 1) {
        printf("\nд���ļ�����");
        exit(0);                     //д��������˳�����
    }
}

void denglu() {
    char z[20], c[20], temp[20];      //�����������飬��ż���������û���������
    printf("\n�û���¼");
    printf("\n�û���:");
    scanf("%s", z);
    /*�ж��û����Ƿ����*/
    fp = fopen(z, "r+");
    temp[0] = '0';
    if (fp == NULL) {
        printf("\n�û�������,��ע��");
        printf("\n1.ע��   2.���µ�½");
        scanf("%s", &temp);
        if (temp[0] == '1') {
            system("cls");
            zhuce();
        }
        else
            denglu();
    }
    /*��֤�����Ƿ���ȷ*/
    do {
        if (judge == 1) fread(&u, sizeof(user), 1, fp); //��ȡ�û���������
        printf("����:");
        scanf("%s", c);
        if (strcmp(u.mima, c) != 0) {                     //�Ա����������Ͷ�ȡ������
            printf("\n�������(1.�˳� 2.��������)");
            scanf("%s", &temp);
            printf("\n");
            if (temp[0] == '1') {
                fclose(fp);                           //�ر��ļ���ֹ�������
                zhuce();
            }
        }
    } while (temp[0] == '2');

}
 