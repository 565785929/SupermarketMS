#include "Super.h"

/**********************************************�Ƿ��п��********************************************/
int IsHaveGood()
{
        if (GOOD->next == NULL)
                return 0;
        return 1;
}

/********************************************�¹���Ʒ���********************************************/
void GoodsAdd()
{
        while (1)
        {
                cls();
                struct Good *goods, *exist;                             // *exist �ж��Ƿ��Ѵ��ڸ���Ʒ
                char choose;

                ShowTip();

                printf("\n\n��������Ʒ��Ϣ��");

                goods = (struct Good *)malloc(sizeof(struct Good));

                printf("\n\n��Ʒ���:");
                scanf("%d", &goods->id);
                exist = GoodsIdFind(goods->id);                         //������Ƿ��ظ�
                if (exist != NULL)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t����Ʒ��Ϣ�Ѵ��ڣ���ѡ�������\n\t [1] ��������\t [2] ǰ���༭");
                        SetConsoleTextAttribute(handle, CYAN);
                        choose = getch();
                        if (choose == '2')
                                Change(exist);                          //����
                        free(goods);
                        continue;
                }

                printf("��Ʒ����:");
                scanf("%s", goods->name);
                exist = GoodsNameFind(goods->name);                     //��������Ƿ��ظ�
                if (exist != NULL)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t����Ʒ��Ϣ�Ѵ��ڣ���ѡ�������\n\t [1] ��������\t [2] ǰ���༭");
                        SetConsoleTextAttribute(handle, CYAN);
                        choose = getch();
                        if (choose == '2')
                                Change(exist);                          //���Ĳ���
                        free(goods);
                        continue;
                }

                ff();  //��ջ�����
                printf("��Ʒ����:");
                scanf("%c", &goods->kind);
                goods->kind = tolower(goods->kind);

                printf("��Ʒ����:");
                scanf("%d", &goods->num);
                while(goods->num<=0)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t���������д������������룺");
                        SetConsoleTextAttribute(handle, CYAN);
                        scanf("%d", &goods->num);
                }

                printf("�����۸�:");
                scanf("%f", &goods->pur_price);
                while(goods->pur_price<=0)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t��������д������������룺");
                        SetConsoleTextAttribute(handle, CYAN);
                        scanf("%f", &goods->pur_price);
                }

                printf("���ۼ۸�:");
                scanf("%f", &goods->sell_price);
                while(goods->sell_price<=0)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t�����ۼ��д������������룺");
                        SetConsoleTextAttribute(handle, CYAN);
                        scanf("%f", &goods->sell_price);
                }

                printf("��������:");
                scanf("%s", goods->date);
                printf("������:");
                scanf("%d", &goods->period);

                cls();
                ShowGood(goods);
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\tȷ��¼�����Ʒ��Ϣ��\t(��[ Y ]ȷ��)\n");
                ff();
                choose = getch();
                if (choose == 'Y' || choose == 'y')
                {
                        Add(goods);
                }
                ff();

                printf("\n\n\t�Ƿ����¼����Ʒ��Ϣ��\t(��[ Y ]ȷ��)\n");
                choose = getch();
                if (choose != 'Y' && choose != 'y')
                {
                        cls();
                        printf("\n\n\n\n\t���ڽ�����Ʒ��Ϣ¼�룬��������������");
                        sleep(3);
                        SetConsoleTextAttribute(handle, CYAN);
                        break;
                }

        }
}

/********************************************��Ʒ��Ϣ����ѡ��********************************************/
struct Good *GoodsFind()
{
        if (!IsHaveGood())
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t\t��Ǹ��Ŀǰ�̵�û����Ʒ��Ϣ");
                sleep(3);
                SetConsoleTextAttribute(handle, CYAN);
                return GOOD;
        }
        while (1)
        {
                struct Good *goods;
                char choose;
                cls();
                SetConsoleTextAttribute(handle, CYAN);
                printf("\n\n\n");
                printf("            |                                                     |\n");
                printf("           -+-----------------------------------------------------+-\n");
                printf("            |                 [A] ������Ʒ���idѡ��              |\n");
                printf("            |                 [B] ������Ʒ����nameѡ��            |\n");
                printf("            |                 [*] ��������                        |\n");
                printf("            |-----------------------------------------------------|\n");
                printf("            |                   ****��ѡ�����****                |\n");
                printf("           -+-----------------------------------------------------+-\n");
                printf("            |                                                     |\n");
                ff();

                choose = getch();
                choose = tolower(choose);
                SetConsoleTextAttribute(handle, YELLOW);
                switch (choose){
                        case 'a':
                                printf("\n\t��������Ʒ��ţ�");
                                int goods_number;
                                SetConsoleTextAttribute(handle, CYAN);
                                scanf("%d", &goods_number);
                                goods = GoodsIdFind(goods_number);
                                break;
                        case 'b':
                                printf("\n\t��������Ʒ���ƣ�");
                                ff();
                                char goods_name[20];//����������
                                SetConsoleTextAttribute(handle, CYAN);
                                scanf("%s", goods_name);
                                goods = GoodsNameFind(goods_name);
                                break;
                        default:
                                goods = GOOD; break;
                }
                return goods;
        }
}

/********************************************����id����good********************************************/
struct Good *GoodsIdFind(int good_id)
{
        struct Good *goods = GOOD;
        while (goods->next != NULL)
        {
                goods = goods->next;
                if (goods->id == good_id)
                        return goods;
        }
        return NULL;
}

/********************************************�������Ʋ���********************************************/
struct Good *GoodsNameFind(char goods_name[])
{
        struct Good *goods = GOOD;
        while (goods->next != NULL)
        {
                goods = goods->next;
                if (!strcmp(goods->name, goods_name))
                        return goods;
        }
        return NULL;
}

/********************************************���Ĳ��� ********************************************/
void Change(struct Good *goods)
{
        int flag = 0;
        char choose;
        struct Good *good_temp;
        good_temp = (struct Good *)malloc(sizeof(struct Good));
        goodscopy(goods, good_temp);
        while (1)
        {
                cls();
                ShowGood(goods);
                ShowTip();
                printf("           -+-----------------------------------------------------------------+-\n");
                printf("            |  [1]��Ʒ���\t[2]��Ʒ����\t[3]��Ʒ����\t[4]��Ʒ����   |\n");
                printf("            |  [5]�����۸�\t[6]���ۼ۸�\t[7]��������\t[8]������     |\n");
                printf("            |                   [0]ȡ���޸�\t[*]�����˳�                   |\n");
                printf("            |-----------------------------------------------------------------|\n");
                printf("            |                         ****��ѡ�����****                      |\n");
                printf("           -+-----------------------------------------------------------------+-\n");

                choose = getch();
                switch (choose) {
                        case '1':
                        {
                                int temp;
                                printf("\n\t��������Ʒ���:");
                                scanf("%d", &temp);
                                if(!GoodsIdFind(temp))
                                        goods->id = temp;
                                else
                                {
                                        printf("\n\t����ظ����޸�ʧ��.");
                                        sleep(2);
                                }

                                break;
                        }
                        case '2':
                        {
                                char temp[20];
                                printf("\n\t��������Ʒ����:");
                                scanf("%s", temp);
                                if(!GoodsNameFind(temp))
                                        strcpy(goods->name, temp);
                                else
                                {
                                        printf("\n\t�����ظ����޸�ʧ��.");
                                        sleep(2);
                                }

                                break;
                        }
                        case '3':
                        {
                                printf("\n\t��������Ʒ����:");
                                scanf("%c", &goods->kind);
                                break;
                        }
                        case '4':
                        {
                                printf("\n\t��������Ʒ����:");
                                scanf("%d", &goods->num);
                                break;
                        }
                        case '5':
                        {
                                printf("\n\t����������۸�:");
                                scanf("%f", &goods->pur_price);
                                break;
                        }
                        case '6':
                        {
                                printf("\n\t��������ۼ۸�:");
                                scanf("%f", &goods->sell_price);
                                break;
                        }
                        case '7':
                        {
                                printf("\n\t��������������:");
                                scanf("%s", goods->date);
                                break;
                        }
                        case '8':
                        {
                                printf("\n\t�����뱣����:");
                                scanf("%d", &goods->period);
                                break;
                        }
                        case '0':
                        {
                                goodscopy(good_temp, goods);
                                printf("\n\n\t����ȡ�������Ե�");
                                sleep(3);
                                flag = 1;
                                break;
                        }
                        default:
                        {
                                printf("\n\n\t���ڱ��棬���Ե�");
                                if (goods->num == 0)
                                        Delete(goods);                                 //�������Ϊ0����Ʒ��¼
                                sleep(3);
                                flag = 1;
                                break;
                        }
                } // switch
                if (flag)
                        break;
        }
        free(good_temp);
}

/********************************************�����������********************************************/
void Add(struct Good *goods)
{
        struct Good *goods_pointer = GOOD;
        while (goods_pointer->next != NULL)
                goods_pointer = goods_pointer->next;    //��λ����Ʒ�б�ĩβ

        goods->next = goods_pointer->next;              //��ӽڵ�
        goods_pointer->next = goods;
}

/********************************************ɾ����������********************************************/
void Delete(struct Good *goods)
{
        struct Good *goods_pointer = GOOD;

        while (goods_pointer->next != goods)            //�ҵ��ڵ�ǰһ��λ��
                goods_pointer = goods_pointer->next;

        goods_pointer->next = goods->next;              //ɾ���ڵ�
        free(goods);                                    //�ͷſռ�

}

/********************************************  ���Ԥ��  ********************************************/
void InventoryEarlyWarning()
{
        char message[1000]="", str[100];
        int f=0;
        struct Good *goods = GOOD;
        while(goods->next != NULL)
        {
                goods = goods->next;
                if(goods->num <= StockMin)
                {
                        sprintf(str, "���:%d   ��Ʒ��:%s  ����Ʒ���� %d �� \n", goods->id, goods->name, goods->num);
                        strcat(message, str);
                        f=1;
                }
        }
        if(f)       //û��ʱ�Ͳ�����
        {
                strcat(message, "��ץ������!!!");
                MessageBox(NULL,message,"���Ԥ��",MB_OK);
        }
}

