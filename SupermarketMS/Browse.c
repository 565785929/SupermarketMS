#include "Super.h"


/********************************************��Ʒ��Ϣ���********************************************/
void GoodsBrowse()
{
        cls();
        if (!IsHaveGood())
        {
                printf("\n\n\t\t��Ǹ��Ŀǰ�̵�û����Ʒ��Ϣ");
                sleep(3);
        }
        else
        {
                printf("\n\n\n\t\t��ѡ�������ʽ��\n\n\t [1] ȫ�����\t  [2] ���������\n\n");
                char choose;
                ff();
                while (1)
                {
                        choose = getch();
                        if (choose == '1')
                        {
                                cls();
                                ShowGoods(GOOD, '0');                           //0����ȫ������
                                break;
                        }
                        else if (choose == '2')
                        {
                                cls();
                                ShowTip();
                                SetConsoleTextAttribute(handle, YELLOW);
                                printf("\n\n\n��ѡ��Ҫ�������Ʒ���ͣ�");
                                SetConsoleTextAttribute(handle, CYAN);
                                char type;
                                type = tolower(getch());
                                cls();
                                ShowGoods(GOOD, type);                          //�鿴type���͵���Ʒ
                                break;
                        }
                }
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\n\t�����������...");
                SetConsoleTextAttribute(handle, CYAN);
                getch();
        }
}

/***********************************************�û����********************************************/
void UserBrowse()
{
        if (!IsHaveGood())
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t��Ǹ���̵���Ʒ��ȫ�����꣬�ɰ��ĵ�������æµ������.");
                sleep(2);
                SetConsoleTextAttribute(handle, CYAN);
        }
        else
        {
                cls();
                struct Good *goods_pointer = GOOD;
                while (goods_pointer->next != NULL)
                {
                        goods_pointer = goods_pointer->next;
                        GoodShow(goods_pointer);
                }
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\t�Ƿ�����Ʒ������ [Y] ȷ�ϣ�");
                SetConsoleTextAttribute(handle, CYAN);
                ff();
                char flag;
                flag = getch();
                if (flag == 'Y' || flag == 'y')
                {
                        UserCart();             //���빺�ﳵ
                }
        }
}
