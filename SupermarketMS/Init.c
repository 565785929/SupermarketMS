#include "Super.h"


/*************************************��ȡ�ļ��ַ�������*********************************************/
void show_file() {
        FILE *p = fopen(FILENAME, "r");
        char c;
        int i=0;
        while(fscanf(p,"%c",&c) != EOF)
        {
                if(i == 0)
                        SetConsoleTextAttribute(handle, RED);
                else if(i == 1)
                        SetConsoleTextAttribute(handle, BLUE);
                else if(i == 2)
                        SetConsoleTextAttribute(handle, GREEN);
                else if(i == 3)
                        SetConsoleTextAttribute(handle, CYAN);
                else if(i == 4)
                        SetConsoleTextAttribute(handle, PURPLE);
                else if(i == 5)
                        SetConsoleTextAttribute(handle, YELLOW);
                //else if(i == 6)
                        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green | red | blue);
                else
                {
                        i=0;
                        SetConsoleTextAttribute(handle, RED);
                }
                printf("%c",c);
                i++;
        }
        fclose(p);
}


/********************************************��ʼ������********************************************/
void Init()
{
        handle = GetStdHandle(STD_OUTPUT_HANDLE);
        char color[10] = "color ";
        char srands[16] = "0123456789abcdef";
        int r, i;
        srand(time(0));
        system("title С�ͳ��й���ϵͳ");               //����cmd���ڱ���
        //system("mode con cols=100 lines=35");
        show_file();
        Sleep(2000);
        cls();

        printf("\n\n");
        printf("             �q�T�T�T�T�T�T�T�T�T�T���Tӭ�Tʹ�T�èT�T�T�T�T�T�T�T�T�r      \n");
        printf("             �t�r�q���������������������������������������������r�q�s \n");
        printf("             ���s�U����                                    �����U�t�� \n");
        printf("             ���U����           С�ͳ��й���ϵͳ         �����U��� \n");
        printf("             ���U����                                    �����U��� \n");
        printf("             ���U����                                    �����U��� \n");
        printf("             ���U����             ף��ʹ�����           �����U��� \n");
        printf("             ���r�U����                                    �����U�q�� \n");
        printf("             �q�s�t���������������������������������������������s�t�r \n");
        printf("             �t�T�T�T�T�T�T�T�T�T�Tʹ�T�èT��T��T�T�T�T�T�T�T�T�T�s         \n");
        printf("\n");

        SALE = (struct Sale *)malloc(sizeof(struct Sale));
        GOOD = (struct Good *)malloc(sizeof(struct Good));
        SALE->next = NULL;              //��ʼ���˵�
        GOOD->next = NULL;              //��ʼ������
        SaleReadFromFile();             //��ȡ���ۼ�¼
        GoodsReadFromFile();            //��ȡ��Ʒ��¼

        for(i=0; i<10; i++)             //��Ϲ�������ɫ
        {
                r = rand()%16;
                color[6] = srands[r];
                r = rand()%16;
                color[7] = srands[r];
                system(color);
                Sleep(100);
        }

        SetConsoleTextAttribute(handle, CYAN | 0);
}

