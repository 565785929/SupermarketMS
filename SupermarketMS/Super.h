#ifndef SUPER_H_INCLUDED
#define SUPER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define password "123" //����Ա���� �100λ
#define close_passward  "000000" //�û��رճ�������
#define show printf("\t%d\t%s\t%c\t%d\t%.2f\t%.2f\t  %s \t\t  %d\n", goods->id, goods->name, goods->kind, goods->num, goods->pur_price, goods->sell_price, goods->date, goods->period)
#define ShoppingCart_Max 10
#define StockMin 20
#define FILENAME "file.txt"
#define GOODS_PATH "Goods.dat"
#define SALE_PATH "Sale.dat"

//��Ʒ��Ϣ
struct Good
{
        int id;                 //��Ʒ���
        char name[20];          //��Ʒ����
        char kind;              //��Ʒ����
        int num;                //��Ʒ����
        float pur_price;        //�����۸�
        float sell_price;       //���ۼ۸�
        char date[128];         //��������
        int period;             //������
        struct Good *next;
}*GOOD;

//������Ϣ
struct Sale
{
        int id;                 //��Ʒ���
        char name[20];          //��Ʒ����
        float pur_price;        //�����۸�
        float sell_price;       //���ۼ۸�
        int num;                //��������
        char buyer[20];         //�˿�����
        char time[128];         //����ʱ��
        struct Sale *next;
}*SALE;

void ff();                                                      //��ջ�����
void show_file();                                               //��ʾ��ӭ����
void sleep(int num);                                            //��Ϣ����
void Init();                                                    //��ʼ���ļ�
void AdminWindows();                                            //����Ա����
void UserMenu();                                                //����Ա�˵�
void UserWindows();                                             //�û�����
void AdminMenu();                                               //����Ա�˵�
void UserBrowse();                                              //�û����

void ShowTip();                                                 //��ʾ
void cls();                                                     //��������
void ShowGood(struct Good *goods);                              //��ʾ������Ʒ
void ShowGoods(struct Good *goods, char type);                  //��ʾ������Ʒ
void GoodShow(struct Good *goods);                              //�û�չʾһ����Ʒ
int IsHaveGood();                                               //�Ƿ��л���

void GoodsAdd();                                                //�������
void GoodsControl(char control[]);                              //ɾ�Ĳ���ƺ���
void Change(struct Good *goods);                                //����
void Add(struct Good *goods);                                   //���
void Delete(struct Good *goods);                                //ɾ��
void GoodsBrowse();                                             //�������

struct Good *GoodsFind();                                       //���һ���
struct Good *GoodsIdFind(int good_id);                          //ͨ��ID��
struct Good *GoodsNameFind(char goods_name[]);                  //ͨ�����ֲ�
void UserPay(struct Sale *shopping_cart, struct Good *address[]);//�û�֧��
void UserCart();                                                //���ﳵ
void SaleManage();                                              //�˵�����

void SaveAndExit();                                             //�����˳�
int GoodsSaveToFile();                                          //���ﱣ��
int GoodsReadFromFile();                                        //�����ȡ
int SaleSaveToFile();                                           //�˵�����
int SaleReadFromFile();                                         //�˵���ȡ
void InventoryEarlyWarning();                                   //���Ԥ��
void goodscopy(struct Good *s1, struct Good *s2);               //�ṹ�忽��

enum ConsoleTextColor{  RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
                        GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
                        BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
                        YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
                        PURPLE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
                        CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
                        WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
                        BLACK = 0};
HANDLE handle;
#endif // SUPER_H_INCLUDED
