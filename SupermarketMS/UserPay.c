#include "Super.h"

/************************************************����************************************************/
void UserPay(struct Sale *shopping_cart, struct Good *address[])
{
        cls();
        float money = 0;
        struct Sale *sale_pointer = shopping_cart;
        SetConsoleTextAttribute(handle, YELLOW);
        printf("\n\n��ȫ����ϵͳ�Ѵ򿪣�");
        printf("\n\n������ʼ����...\n...\n\n�������ͨ��...\n\n�������ɶ���...\n\n����������ɣ�");

        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\n\t*************************��������**************************");
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\n\t��Ʒ����\t��Ʒ����\t��������\t�����ܼ�\n");
        SetConsoleTextAttribute(handle, GREEN);
        while (sale_pointer->next != NULL)
        {
                sale_pointer = sale_pointer->next;
                printf("\n\t%s\t\t%.2f\t\t%d\t\t%.2f\t\t", sale_pointer->name,
                       sale_pointer->sell_price, sale_pointer->num, (sale_pointer->sell_price) * (sale_pointer->num));

                money += (sale_pointer->sell_price) * (sale_pointer->num);
        }
        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\t***********************************************************");
        SetConsoleTextAttribute(handle, YELLOW);
        printf("\n\t�ܹ����ѽ��Ϊ��%.2f", money);


        printf("\n\n\n\tȷ����ɽ��ף�\t����Y��ȷ��֧�� ���������ȡ��֧��\n\t");
        ff();
        time_t timer = time(NULL);              //�õ�����ʱ��
        char flag;
        flag = getch();
        if (flag == 'Y' || flag == 'y')
        {
                char name[20];
                printf("\n\n\t�������������֣�");
                SetConsoleTextAttribute(handle, CYAN);
                scanf("%s", name);
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\nϵͳ������ɽ��ף����Ե�...");

                int i;
                struct Good *goods_address;                                             //�����Ʒ��ַ
                sale_pointer = shopping_cart;
                for (i = 0; sale_pointer->next != NULL; i++)
                {
                        sale_pointer = sale_pointer->next;
                        strcpy(sale_pointer->buyer, name);                                      //��¼����������

                        strcpy(sale_pointer->time, ctime(&timer));                              //��¼����ʱ��
                        goods_address = address[i];
                        goods_address->num = (goods_address->num) - (sale_pointer->num);        //������Ʒ����
                        if (goods_address->num == 0)
                                Delete(goods_address);                                 //�������Ϊ0����Ʒ��¼
                }

                //������Ʒ���ۼ�¼
                sale_pointer = SALE;
                while (sale_pointer->next != NULL)  //��λ�������б�ĩβ
                        sale_pointer = sale_pointer->next;

                sale_pointer->next = shopping_cart->next;
                printf("\n\n\n\t������ɣ�лл�ݹˣ� O(��_��)O~\n\n");
                printf("\n\n\t����ϵͳ���ڹرգ����Ժ�");
                sleep(5);
                SetConsoleTextAttribute(handle, CYAN);
        }
}

/********************************************��Ʒ���۹���********************************************/
void SaleManage()
{
        cls();
        SetConsoleTextAttribute(handle, YELLOW);
        printf("\n\n\t\t\t\t��������鿴������ͳ��");
        ShowTip();
        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\t***************************************************************************");
        if (SALE->next == NULL)
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\nĿǰ�������ۼ�¼��");
                Sleep(2000);
                SetConsoleTextAttribute(handle, CYAN);
        }
        else
        {
                SetConsoleTextAttribute(handle, PURPLE);
                printf("\n\n\t���\t����\t����\t�ۼ�\t����\t����\t\tʱ��\n\n");
                SetConsoleTextAttribute(handle, GREEN);
                int number = 0;//��Ʒ����
                float profit = 0;//��Ʒ����
                struct Sale *sale_pointer = SALE;
                while (sale_pointer->next != NULL)
                {
                        sale_pointer = sale_pointer->next;
                        printf("\t %d\t %s\t %.2f\t %.2f\t %d\t %s\t %s\n", sale_pointer->id, sale_pointer->name,
                               sale_pointer->pur_price, sale_pointer->sell_price, sale_pointer->num, sale_pointer->buyer, sale_pointer->time);

                        profit = profit + ((sale_pointer->sell_price) - (sale_pointer->pur_price)) * (sale_pointer->num);
                        number = number + (sale_pointer->num);
                }
                SetConsoleTextAttribute(handle, CYAN);
                printf("\n\t***************************************************************************");
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t��������Ʒ%d����������Ϊ%.2f", number, profit);
                printf("\n\n\n\t�����������...");
                getch();
                SetConsoleTextAttribute(handle, CYAN);
        }
}

