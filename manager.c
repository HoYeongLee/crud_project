#include "manager.h"


void saveTable(Table p[], int count){
    FILE *fp = fopen("Table.txt", "wt"); ///write ���� ��Ʈ���� ������ ���� ����ü 

    for (int i = 0; i < count; i++)
    {
        if (p[i].guestNumber == -1)
            continue;
            fprintf(fp, "%d %d \n", p[i].guestNumber, p[i].tableSum);
    }

    if (fp == NULL)
        printf("���� ���忡 �����߽��ϴ�! \n");

    else
    {
        fclose(fp);
        printf("=>�����! \n");
    }
}



int loadTable(Table *p){

    int i = 0; 
    FILE *fp = fopen("Table.txt", "rt");

    if (fp == NULL)
    {
        printf(" \n ���� ���� \n \n");
        return 0;
    }

    for (; i < 100; i++)
    {
        if (feof(fp))
            break;

    fprintf(fp, "%d %d", &p[i].guestNumber, &p[i].tableSum);
    
   
    }
    i--;
    fclose(fp);
    printf("=> �ε� ����! \n");

    return i;

}

void searchTable(Table p[], int count){
    int scn = 0, num = 0; //  num -> �˻��� �����͸� �����ϱ� ���� ����, scn -> ã�� �������� ������ �����ϱ����� ����
    char search[20];// search -> ã������ �����͸� �����ϱ����� ���ڿ� ����
    
    printf("�˻��� ������ �����ϼ���. \n");
    printf("1.�ο��� \n");
    printf("2.�̿�ݾ� \n");
    
    scanf("%d" , &num);

    switch (num)
    {
    case 1:
        printf("�˻��� �ο�����? ");
        scanf("%d", search);
        break;
    case 2:
        printf("�˻��� �̿�ݾ���? ");
        scanf("%d", search);
        break;
  
   
    

    for (int i = 0; i < count; i++)
    {

        if (p[i].guestNumber == -1)
            continue;

        switch (num)
            {
            case 1:
                if (p[i].guestNumber == search)
                {
                    printf("%d ", i + 1);
                    readTable(p[i]);
                    scn++;
                }
                break;
            case 2:
                if (p[i].tableSum == search)
                {
                    printf("%d ", i + 1);
                    readTable(p[i]);
                    scn++;
                }
                break;  
            }

    }
    if (scn == 0)
        printf(" => �˻��� ������ ����! \n");

    printf("\n");
    getchar();
}