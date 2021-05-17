#include "manager.h"

void saveTable(Table p[], int count){
    FILE *fp = fopen("Table.txt", "wt"); 

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
    int i = 0; // i -> �о���� �迭�� ������ ǥ���� ����
    FILE *fp = fopen("Table.txt", "rt"); //�ؽ�Ʈ�� read ���� ��Ʈ���� ������ ���� ����ü

    if (fp == NULL)
    {
        printf(" \n ���� ���� \n \n");
        return 0;
    }

    for (; i < MAX_TABLE_NUMBER; i++)
    {
        if (feof(fp))
            break;

    fscanf(fp, "%d %d", &p[i].guestNumber, &p[i].tableSum);
    }

    fclose(fp);
    printf("=> �ε� ����! \n");
    i--;

    return i;

}

void searchTable(Table p[], int count){
    int scn = 0, num = 0; //  num -> �˻��� �����͸� �����ϱ� ���� ����, scn -> ã�� �������� ������ �����ϱ����� ����
    int search = 0;
    
    printf("�˻��� ������ �����ϼ���. \n");
    printf("1.�ο��� \n");
    printf("2.�ֹ� ���� \n");
    scanf("%d" , &num);

    switch (num)
    {
    case 1:
        printf("�˻��� �ο�����? ");
        scanf("%d", &search);
        break;
    case 2:
        printf("�˻��� ������? ");
        scanf("%d", &search);
        break;
    
    }   
    
    printTableFormat();

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
