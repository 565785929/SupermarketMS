#include "Super.h"

/********************************************���沢�˳�********************************************/
void SaveAndExit()
{
        SaleSaveToFile();//����������Ϣ
        GoodsSaveToFile();//������Ʒ��Ϣ
        cls();
        printf("\n\n\n\n\n\n");

        printf("\n\t\t      �������������������������������������������� ");
        printf("\n\t\t      ���������������������������������������� ");
        printf("\n\t\t     ��������������������������� ");
        printf("\n\t\t       �л����л������ʹ�����á��� ");
        printf("\n\t\t       ��������������������������� ");
        printf("\n\t\t     ���������������������������������������� ");
        printf("\n\t\t        ���������������������������������������� ");
        printf("\n");
        Sleep(3000);
        exit(0);
}

/********************************************������Ʒ��Ϣ********************************************/
int GoodsSaveToFile()
{
        FILE *fp;
        if ((fp = fopen(GOODS_PATH, "wb+")) == NULL)
                return 0;

        struct Good *goods_pointer = GOOD;              //��λ������ͷ��
        while (goods_pointer->next != NULL)
        {
                goods_pointer = goods_pointer->next;
                fwrite(goods_pointer, sizeof(struct Good), 1, fp);//������浽�ļ�
        }
        fclose(fp);
        return 1;
}

/********************************************����������Ϣ********************************************/
int SaleSaveToFile()
{
        FILE *fp;
        if ((fp = fopen(SALE_PATH, "wb+")) == NULL)
                return 0;

        struct Sale *sale_pointer = SALE;       //��λ������ͷ��
        while (sale_pointer->next != NULL)
        {
                sale_pointer = sale_pointer->next;
                fwrite(sale_pointer, sizeof(struct Sale), 1, fp);//������浽�ļ�
        }
        fclose(fp);
        return 1;
}

/********************************************��ȡ��Ʒ��¼********************************************/
int GoodsReadFromFile()
{
        FILE *fp;

        if ((fp = fopen(GOODS_PATH, "rb+")) == NULL)
                return 0;

        int number, i;
        fseek(fp, 0, SEEK_END);                         //��λ���ļ�ĩβ
        number = ftell(fp) / sizeof(struct Good);       //����ܽ����
        fseek(fp, 0, SEEK_SET);                         //��λ���ļ��Ŀ�ʼ��


        struct Good *goods;
        for (i = 0; i < number; i++)
        {
                goods = (struct Good *)malloc(sizeof(struct Good));
                fread(goods, sizeof(struct Good), 1, fp);
                Add(goods);
        }
        fclose(fp);//�ر��ļ�
        return 1;
}

/********************************************��ȡ���ۼ�¼********************************************/
int SaleReadFromFile()
{
        FILE *fp;

        if ((fp = fopen(SALE_PATH, "rb+")) == NULL)
                return 0;

        int number, i;
        fseek(fp, 0, SEEK_END);                         //��λ���ļ�ĩβ
        number = ftell(fp) / sizeof(struct Sale);       //����ܽ����
        fseek(fp, 0, SEEK_SET);                         //��λ���ļ��Ŀ�ʼ��

        struct Sale *sale_pointer = SALE, *sale;
        for (i = 0; i < number; i++)
        {
                sale = (struct Sale *)malloc(sizeof(struct Sale));
                fread(sale, sizeof(struct Sale), 1, fp);
                sale->next = NULL;

                while (sale_pointer->next != NULL)      //��λ�������б�ĩβ
                        sale_pointer = sale_pointer->next;

                sale_pointer->next = sale;              //���뵽������
        }
        fclose(fp);  //�ر��ļ�
        return 1;
}

