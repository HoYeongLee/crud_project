#include <string.h>
#include <ctype.h>
#include "table.h"

int createTable(Table *p)
{
    while (1)
    {   
        char* token;
        int i = 0; 

        printf("�� �̿��� ���ڴ�? (�ִ� 10����� ����!)");
        scanf("%s", token);

        while (getchar() != '\n');

        while (isdigit(token[i])){
            i++;
        }

        if (i != strlen(token) || atoi(token) > 10 || atoi(token) <= 0)
        {  
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ֽʽÿ�. \n");
            continue;
        }

        p->guestNumber = atoi(token);
        
        printf("�� �̿� �ݾ���? ");
        scanf("%s", token);

        while (getchar() != '\n');
        
        i = 0;

        while (isdigit(token[i])){
            i++;
        }

        if (i != strlen(token) || atoi(token) <= 0)
        {
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ֽʽÿ�. \n");
            continue;
        }
        p->tableSum = atoi(token);

        break;
    }

    return 1;
}

void printTableFormat()
{
    printf("���̺��ȣ    �ο���   �� �̿� �ݾ�\n");
    printf("========================================================\n");
}

int readTable(Table p)
{
    printf("%7d �� %8d ��\n", p.guestNumber, p.tableSum);
}

void listTable(Table p[], int count)
{

    printTableFormat();

    for (int i = 0; i < count; i++)
    {
        if (p[i].guestNumber == -1)
            continue;
        printf("%d �� ���̺�", i + 1);
        readTable(p[i]);
    }
    printf("\n");
}

int selectTableNo(Table p[], int count)
{
    int no;
    listTable(p, count);
    printf("��ȣ�� (��� :0)? ");
    scanf("%d", &no);
    return no;
}

int updateTable(Table *p)
{
    while (1)
    {   
        char* token;
        int i = 0; 

        printf("�� �̿��� ���ڴ�? (�ִ� 10����� ����!)");
        scanf("%s", token);

        while (getchar() != '\n');

        while (isdigit(token[i])){
            i++;
        }

        if (i != strlen(token) || atoi(token) > 10 || atoi(token) <= 0)
        {  
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ֽʽÿ�. \n");
            continue;
        }

        p->guestNumber = atoi(token);
        
        printf("�� �̿� �ݾ���? ");
        scanf("%s", token);

        while (getchar() != '\n');
        
        i = 0;

        while (isdigit(token[i])){
            i++;
        }

        if (i != strlen(token) || atoi(token) <= 0)
        {
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ֽʽÿ�. \n");
            continue;
        }
        p->tableSum = atoi(token);

        break;
    }

    printf("==> ��������! \n");

    return 1;
}

int deleteTable(Table *p)
{
    p->guestNumber = -1;
    p->tableSum = -1;

    return 1;
}

int selectMenu()
{
    int menu;
    printf("*** ���̺� ���� �ý��� ***\n");
    printf("1. ���̺���ȸ\n");
    printf("2. ���̺��߰�\n");
    printf("3. ���̺����\n");
    printf("4. ���̺����\n");
    printf("5. ���̺�����\n");
    printf("6. ���̺� �ο��� �˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);

    return menu;
}
