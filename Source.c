#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stPerson {
    char name[10]; // �̸�
    int id; // ���̵�(�ֹι�ȣ)
    int age; // ����
} PERSON;

typedef struct stGrade {
    double eng; // ����
    double kor; // ����
    double math; // ����
} GRADE;

typedef struct stStudent {
    PERSON person;
    GRADE grade;
} STUDENT;

typedef struct stCTC {
    char floor; // ����
    int num; // ���ο�
    int completion; // ���Ῥ��
    STUDENT* pst; // �л� ���
} CTC;

void registerStudent(CTC* ctc) {
    ctc->pst = realloc(ctc->pst, sizeof(STUDENT) * (ctc->num + 1));
    if (!ctc->pst) {

        return;
    }

    STUDENT* newStudent = &ctc->pst[ctc->num];

    printf("�̸�: ");
    scanf("%s", newStudent->person.name);
    printf("���̵�(�ֹι�ȣ): ");
    scanf("%d", &newStudent->person.id);
    printf("����: ");
    scanf("%d", &newStudent->person.age);
    printf("���� ����: ");
    scanf("%lf", &newStudent->grade.eng);
    printf("���� ����: ");
    scanf("%lf", &newStudent->grade.kor);
    printf("���� ����: ");
    scanf("%lf", &newStudent->grade.math);

    ctc->num++;
}

void deleteStudent(CTC* ctc) {
    int id, i, found = 0;
    printf("������ �л��� ���̵�(�ֹι�ȣ): ");
    scanf("%d", &id);

    for (i = 0; i < ctc->num; i++) {
        if (ctc->pst[i].person.id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < ctc->num - 1; j++) {
            ctc->pst[j] = ctc->pst[j + 1];
        }
        ctc->num--;
        ctc->pst = realloc(ctc->pst, sizeof(STUDENT) * ctc->num);
        printf("�л��� �����Ǿ����ϴ�.\n");
    }
    else {
        printf("�л��� ã�� �� �����ϴ�.\n");
    }
}

void modifyStudent(CTC* ctc) {
    int id, i, found = 0;
    printf("������ �л��� ���̵�(�ֹι�ȣ): ");
    scanf("%d", &id);

    for (i = 0; i < ctc->num; i++) {
        if (ctc->pst[i].person.id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("�� �̸�: ");
        scanf("%s", ctc->pst[i].person.name);
        printf("�� ����: ");
        scanf("%d", &ctc->pst[i].person.age);
        printf("�� ���� ����: ");
        scanf("%lf", &ctc->pst[i].grade.eng);
        printf("�� ���� ����: ");
        scanf("%lf", &ctc->pst[i].grade.kor);
        printf("�� ���� ����: ");
        scanf("%lf", &ctc->pst[i].grade.math);
        printf("�л� ������ �����Ǿ����ϴ�.\n");
    }
    else {
        printf("�л��� ã�� �� �����ϴ�.\n");
    }
}

void listStudents(CTC* ctc) {
    printf("�л� ���:\n");
    for (int i = 0; i < ctc->num; i++) {
        printf("�̸�: %s, ���̵�: %d, ����: %d, ����: %.2lf, ����: %.2lf, ����: %.2lf\n",
            ctc->pst[i].person.name,
            ctc->pst[i].person.id,
            ctc->pst[i].person.age,
            ctc->pst[i].grade.eng,
            ctc->pst[i].grade.kor,
            ctc->pst[i].grade.math);
    }
}

int main(void) {
    CTC ctc = { 0 };
    ctc.pst = NULL;

    int choice;
    do {
        printf("\n1. �л� ���\n2. �л� ����\n3. �л� ����\n4. �л� ��� ����\n5. ����\n����: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            registerStudent(&ctc);
            break;
        case 2:
            deleteStudent(&ctc);
            break;
        case 3:
            modifyStudent(&ctc);
            break;
        case 4:
            listStudents(&ctc);
            break;
        case 5:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
        }
    } while (choice != 5);

    free(ctc.pst); // �޸� ����
    return 0;
}
