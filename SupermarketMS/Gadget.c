#include "Super.h"

/******************************************��ջ�����************************************************/
void ff()
{
        fflush(stdin);          //ʱ����Ҫ��һ��
}

/**********************************************����**************************************************/
void cls()
{
        system("cls");
        ff();                   //ʱ����Ҫ��һ��
}

/********************************************��ʾ��ʾ*************************************************/
void ShowTip()
{
        SetConsoleTextAttribute(handle, RED); //���õ�ǰ���Ϊ��ɫ
        printf("\n\n\t\t\t r:����Ʒ w:�Ļ���Ʒ s:ʳƷ d:���Ӳ�Ʒ\n\n");
        SetConsoleTextAttribute(handle,  CYAN);
}

/********************************************˯�ߺ���********************************************/
void sleep(int num)
{
        int i;
        for(i=0; i<num; i++)
        {
                Sleep(1000);
                printf(".");            //��װ�ڼ���
        }
}

/********************************************����������********************************************/
void goodscopy(struct Good *s1, struct Good *s2)
{
        s2->id  = s1->id;
        s2->num = s1->num;
        s2->kind= s1->kind;
        s2->period = s1->period;
        s2->pur_price  = s1->pur_price;
        s2->sell_price = s1->sell_price;
        strcpy(s2->name, s1->name);
        strcpy(s2->date, s1->date);
}
