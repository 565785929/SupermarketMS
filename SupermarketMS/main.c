#include "Super.h"

int main()
{
        Init();
        while (1)//��������
        {
                UserWindows(); //�û�Ա������
                InventoryEarlyWarning(); //���Ԥ��
                AdminWindows(); //����Ա������
        }
        return 0;
}
