#include "Super.h"


/********************************************�����ɾ�Ĳ�********************************************/
void GoodsControl(char* control)
{
        struct Good *goods;
        goods = GoodsFind(); //�����Ƿ���ڸ���Ʒ

        if (goods == NULL)
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t��Ǹ�������ڸ���Ʒ��");
                sleep(2);
                SetConsoleTextAttribute(handle, CYAN);
        }
        else if (goods == GOOD)
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\n\t\t���ڷ��س������Ե�");
                sleep(3);
                SetConsoleTextAttribute(handle, CYAN);
        }
        else
        {
                if(!strcmp(control, "Detail"))
                {
                        cls();
                        ShowGood(goods);
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t�����������...");
                        getch();
                        SetConsoleTextAttribute(handle, CYAN);
                }
                else if(!strcmp(control, "Change"))
                {
                        Change(goods);
                }
                else if(!strcmp(control, "Delete"))
                {
                        cls();
                        ShowGood(goods);
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n���棺�Ƿ�ȷ��ɾ������(���롾Y��ȷ��)");

                        char choose;
                        ff();
                        choose = tolower(getch());
                        if (choose == 'y') //ɾ������
                                Delete(goods);
                        printf("\n\n\t�����ɹ���");
                        sleep(3);
                        SetConsoleTextAttribute(handle, CYAN);
                }
        }
}
