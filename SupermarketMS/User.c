#include "Super.h"

/********************************************�û����˵�********************************************/
void UserMenu()
{
        cls();
        printf("\n\n");
        printf("             �q�T�T�T�T�T�T�T�T�T�T���Tӭ�Tʹ�T�èT�T�T�T�T�T�T�T�T�r      \n");
        printf("             �t�r�q���������������������������������������������r�q�s \n");
        printf("             ���s�U����              ��ѡ�����            �����U�t�� \n");
        printf("             ���U����                                    �����U��� \n");
        printf("             ���U����             [1] �����Ʒ           �����U��� \n");
        printf("             ���U����                                    �����U��� \n");
        printf("             ���U����             [2] ������Ʒ           �����U��� \n");
        printf("             ���r�U����                                    �����U�q�� \n");
        printf("             �q�s�t���������������������������������������������s�t�r \n");
        printf("             �t�T�T�T�T�T�T�T�T�T�Tʹ�T�èT��T��T�T�T�T�T�T�T�T�T�s         \n");
        printf("\n");
}

/********************************************�û�������********************************************/
void UserWindows()
{
        char choose[100] = "";
        while (1)
        {
                UserMenu();  //�û����˵�

                scanf("%s", choose);
                if (!strcmp(choose, "1"))
                        UserBrowse();
                else if (!strcmp(choose, "2"))
                {
                        UserCart();  //���빺�ﳵ
                }
                else if (!strcmp(choose, close_passward))
                {
                        SaveAndExit();
                }

                else if (!strcmp(choose, password))
                        break;
        }
}
