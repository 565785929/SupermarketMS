#include "Super.h"

/********************************************����Ա���˵�********************************************/
void AdminMenu()
{
        cls();
        printf("\n\n");
        printf("             �q�T�T�T�T�T�T�T�T�T�T���Tӭ�Tʹ�T�èT�T�T�T�T�T�T�T�T�r      \n");
        printf("             �t�r�q���������������������������������������������r�q�s \n");
        printf("             ���s�U����                                      ���U�t�� \n");
        printf("             ���U����           С�ͳ��й���ϵͳ           ���U��� \n");
        printf("             ���U����                                      ���U��� \n");
        printf("             ���U����  [1]      ��  �¹���Ʒ���  ��       ���U��� \n");
        printf("             ���U����  [2]      ��  ��Ʒ��Ϣ����  ��       ���U��� \n");
        printf("             ���U����  [3]      ��  ��Ʒ��Ϣ����  ��       ���U��� \n");
        printf("             ���U����  [4]      ��  ��Ʒ��Ϣɾ��  ��       ���U��� \n");
        printf("             ���U����  [5]      ��  ��Ʒ��Ϣ���  ��       ���U���\n");
        printf("             ���U����  [6]      ��  ��Ʒ���۹���  ��       ���U��� \n");
        printf("             ���U����  [7]      ��  �����û�����  ��       ���U��� \n");
        printf("             ���U����  [0]      ��  �����˳�����  ��       ���U��� \n");
        printf("             ���U����                                      ���U��� \n");
        printf("             ���U����                                      ���U��� \n");
        printf("             �q�s�t���������������������������������������������s�t�r \n");
        printf("             �t�T�T�T�T�T�T�T�T�T�Tʹ�T�èT��T��T�T�T�T�T�T�T�T�T�s         \n");
        printf("\n\n\t\tPress key to continue your choice ....");
}

/********************************************����Ա������********************************************/
void AdminWindows()
{
        int flag = 1;                           //�ж��Ƿ�����û�����ı�־
        char choose;
        while (flag)
        {
                AdminMenu();
                choose = getch();
                cls();

                switch (choose) {

                        case '1':
                                GoodsAdd();             //�¹���Ʒ���
                                break;

                        case '2':
                                GoodsControl("Detail"); //��Ʒ��Ϣ����
                                break;

                        case '3':
                                GoodsControl("Change"); //��Ʒ��Ϣ����
                                break;

                        case '4':
                                GoodsControl("Delete"); //��Ʒ��Ϣɾ��
                                break;

                        case '5':
                                GoodsBrowse();          //��Ʒ��Ϣ���
                                break;

                        case '6':
                                SaleManage();           //��Ʒ���۹���
                                break;

                        case '7':
                                cls();
                                flag = 0;               //flag ��Ϊ0��׼�������û�����
                                printf("\n\n\n\t���������û����棬���Ե�");
                                sleep(3);
                                break;                  //�����û�����

                        case '0':
                                SaveAndExit();          //���沢�˳�
                                exit(0);
                }
                ff();
        }
}
