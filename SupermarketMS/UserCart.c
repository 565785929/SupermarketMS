#include "Super.h"

/***********************************************���ﳵ**********************************************/
void UserCart()
{
        if (!IsHaveGood())
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t��Ǹ���̵���Ʒ��ȫ���꣬��������æµ������.");
                sleep(2);
                SetConsoleTextAttribute(handle, CYAN);
                return ;
        }

        cls();
        SetConsoleTextAttribute(handle, YELLOW);
        printf("\n\n\n\t��������ѡ�����棬���Ե�.");
        sleep(2);

        struct Sale *shopping_cart; //���ﳵ
        shopping_cart = (struct Sale *)malloc(sizeof(struct Sale));
        shopping_cart->next = NULL;   //��ʼ�����ﳵ�б�

        int i;
        struct Good *goods, *address[ShoppingCart_Max]; //address�����Ʒ��ַ ָ������  goods����ָ��

        for (i=0; i < ShoppingCart_Max; i++)
        {
                goods = GoodsFind();
                //������Ʒ
                SetConsoleTextAttribute(handle, YELLOW);
                if (goods == NULL)
                {
                        printf("\n\n\n\t\t��Ǹ��û������Ҫ����Ʒ��");
                        sleep(2);
                        continue;
                }
                else if (goods == GOOD)  //��ѡ����Ʒʱѡ��  ��������
                {
                        cls();
                        if (shopping_cart->next == NULL)
                        {
                                printf("\n\n\n\n\t\t���������ﳵ�տյģ����������ι��");
                                printf("\n\n\n\t����ϵͳ���ڹرգ����Ե�");
                                free(shopping_cart);  //���ٹ��ﳵ
                                sleep(4);
                                SetConsoleTextAttribute(handle, CYAN);
                                break;
                        }
                        else
                        {
                                printf("\n\n\n\t��ȡ���˱���ѡ�����Ƿ�ǰ��֧����");
                                printf("\n\n\t��Y��ǰ��֧�� �����������������");
                                char choose1;
                                choose1 = getch();
                                if (choose1 == 'Y' || choose1 == 'y')
                                {
                                        UserPay(shopping_cart, address); //����
                                        SetConsoleTextAttribute(handle, CYAN);
                                        break;
                                }
                                else
                                {
                                        printf("\n\n\n\n\t\t����ϵͳ���ڹرգ����Ե�");
                                        free(shopping_cart); //���ٹ��ﳵ
                                        sleep(4);
                                        SetConsoleTextAttribute(handle, CYAN);
                                        break;
                                }
                        }
                }


                cls();
                GoodShow(goods);                        //��ʾ��Ʒ��Ϣ
                SetConsoleTextAttribute(handle, YELLOW);
                struct Sale *cart_pointer = shopping_cart;
                int judge = 1;                          //�ж��Ƿ��ظ�����

                while (cart_pointer->next != NULL)      //�������ﳵ ���ҹ��ﳵ�Ƿ��Ѵ��ڸ���Ʒ
                {
                        cart_pointer = cart_pointer->next;
                        judge = strcmp(cart_pointer->name, goods->name);
                        if (judge == 0)
                        {
                                printf("\t�����ﳵ����%d������Ʒ��,��Ҫ�������򣬽��Զ�Ϊ���ϲ�����\n", cart_pointer->num);
                                break;
                        }
                }


                struct Sale *sale;                      //ָ������۽��в���
                sale = (struct Sale *)malloc(sizeof(struct Sale));
                printf("\n\n������Ҫ�����������(���� [0] ������ѡ��)\t");
                SetConsoleTextAttribute(handle, CYAN);
                scanf("%d", &sale->num);
                SetConsoleTextAttribute(handle, YELLOW);
                if (sale->num == 0)                     //����Ϊ0
                        continue;


                if (judge == 0)                         //׼���ϲ���ͬ��Ʒ
                        sale->num = (cart_pointer->num) + (sale->num);


                if ((sale->num) > (goods->num))         //�ж� (�ϲ���) �Ƿ񳬹������Ʒ����
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\n\t��������ʾ���ܱ�Ǹ������Ʒ��������̫�𱬣�Ŀǰֻʣ��%d���ˡ�", goods->num);
                        printf("\n\n\t\t��A������������%d��  ��B������ѡ��  �����������������\n", goods->num);
                        char choose;
                        ff();
                        choose = getch();

                        if (choose == 'A' || choose == 'a')
                        {
                                sale->num = goods->num;
                                printf("\n\n\n\t��лл��������֧�֣���");
                        }
                        else if (choose == 'B' || choose == 'b')
                                continue;
                        else
                                break;
                }


                if (judge == 0) //���ﳵ������Ʒʱ���ϲ���Ʒ
                {
                        cart_pointer->num = sale->num;
                        printf("\n\n\t�����ڹ��ﳵ���ڸ���Ʒ,���Զ�Ϊ���ϲ�����\n\n\n");
                }
                else //���ﳵ��������Ʒʱ����ӵ����ﳵ
                {
                        address[i] = goods;                     // ��¼��Ʒ��ַ
                        strcpy(sale->name, goods->name);        // ��¼��Ʒ����
                        sale->id = goods->id;                   // ��¼��Ʒ����
                        sale->pur_price = goods->pur_price;     // ��¼��Ʒ����
                        sale->sell_price = goods->sell_price;   // ��¼��Ʒ�ۼ�
                        sale->next = NULL;

                        while (cart_pointer->next != NULL)
                                cart_pointer = cart_pointer->next;
                        cart_pointer->next = sale;              // ��ӵ������г���

                        printf("\n\n\t�ѳɹ������Ʒ�����ﳵ��");
                }


                if (i == (ShoppingCart_Max - 1)) //���ﳵ��ʱ����
                {
                        system("cls");
                        printf("\n\n\n\n\t\t���ﳵ�Ѵﵽ������������Զ�Ϊ������֧�����棡");
                        Sleep(2000);
                        UserPay(shopping_cart, address); //����
                        break;
                }

                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\n\t\t��1��:ǰ��֧�� ��2��:������� ��3��:��������\n");
                char choice;
                choice = getch();
                if (choice == '1')
                {
                        UserPay(shopping_cart, address); //����
                        SetConsoleTextAttribute(handle, CYAN);
                        break;
                }
                else if (choice == '3')
                {
                        free(shopping_cart);
                        cls();
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\n\n\t\t�����˳�����ϵͳ�����Ե�...");
                        sleep(2);
                        SetConsoleTextAttribute(handle, CYAN);
                        break;
                }

        }
        SetConsoleTextAttribute(handle, CYAN);
}
