#include "Super.h"

/********************************************��Ʒ��Ϣ��ʾ********************************************/
void GoodShow(struct Good *goods)
{
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\n\t***************��Ʒ��Ϣ******************");
        SetConsoleTextAttribute(handle, GREEN);
        printf("\n\t��Ʒ���...%30d\n", goods->id);
        printf("\n\t-----------------------------------------");
        printf("\n\t��Ʒ����...%30s\n", goods->name);
        printf("\n\t-----------------------------------------");
        printf("\n\t��Ʒ����...%30d\n", goods->num);
        printf("\n\t-----------------------------------------");
        printf("\n\t���ۼ۸�...%30.2f\n", goods->pur_price);
        printf("\n\t-----------------------------------------");
        printf("\n\t��������...%30s\n", goods->date);
        printf("\n\t-----------------------------------------");
        printf("\n\t������...%32d\n", goods->period);
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\t-----------------------------------------\n\n");
        SetConsoleTextAttribute(handle, CYAN);
}

/*****************************************���ĳ����Ʒ***********************************************/
void ShowGood(struct Good *goods)
{

        printf("\n\n\t************************************************************************");
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\n\t���\t����\t����\t����\t����\t�ۼ�\t��������\t������ \n\n");
        SetConsoleTextAttribute(handle, GREEN);
        show;
        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\t************************************************************************");
}

/*****************************************���������Ʒ***********************************************/
void ShowGoods(struct Good *goods, char type)
{
        printf("\n\n\t************************************************************************");
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\n\t���\t����\t����\t����\t����\t�ۼ�\t��������\t������ \n\n");
        while (goods->next != NULL) {
                goods = goods->next;
                if(type == '0')
                {
                    if(goods->num < StockMin)                   //���Ԥ�� red
                                SetConsoleTextAttribute(handle, RED);
                    else
                                SetConsoleTextAttribute(handle, GREEN);
                        show;
                }

                else {
                        if(goods->kind == type)
                                show;
                }
        }
        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\t************************************************************************");
}
