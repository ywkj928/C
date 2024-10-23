#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stPerson {
    char name[10]; // 이름
    int id; // 아이디(주민번호)
    int age; // 나이
} PERSON;

typedef struct stGrade {
    double eng; // 영어
    double kor; // 국어
    double math; // 수학
} GRADE;

typedef struct stStudent {
    PERSON person;
    GRADE grade;
} STUDENT;

typedef struct stCTC {
    char floor; // 층수
    int num; // 총인원
    int completion; // 수료연도
    STUDENT* pst; // 학생 목록
} CTC;

void registerStudent(CTC* ctc) {
    ctc->pst = realloc(ctc->pst, sizeof(STUDENT) * (ctc->num + 1));
    if (!ctc->pst) {

        return;
    }

    STUDENT* newStudent = &ctc->pst[ctc->num];

    printf("이름: ");
    scanf("%s", newStudent->person.name);
    printf("아이디(주민번호): ");
    scanf("%d", &newStudent->person.id);
    printf("나이: ");
    scanf("%d", &newStudent->person.age);
    printf("영어 성적: ");
    scanf("%lf", &newStudent->grade.eng);
    printf("국어 성적: ");
    scanf("%lf", &newStudent->grade.kor);
    printf("수학 성적: ");
    scanf("%lf", &newStudent->grade.math);

    ctc->num++;
}

void deleteStudent(CTC* ctc) {
    int id, i, found = 0;
    printf("삭제할 학생의 아이디(주민번호): ");
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
        printf("학생이 삭제되었습니다.\n");
    }
    else {
        printf("학생을 찾을 수 없습니다.\n");
    }
}

void modifyStudent(CTC* ctc) {
    int id, i, found = 0;
    printf("수정할 학생의 아이디(주민번호): ");
    scanf("%d", &id);

    for (i = 0; i < ctc->num; i++) {
        if (ctc->pst[i].person.id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("새 이름: ");
        scanf("%s", ctc->pst[i].person.name);
        printf("새 나이: ");
        scanf("%d", &ctc->pst[i].person.age);
        printf("새 영어 성적: ");
        scanf("%lf", &ctc->pst[i].grade.eng);
        printf("새 국어 성적: ");
        scanf("%lf", &ctc->pst[i].grade.kor);
        printf("새 수학 성적: ");
        scanf("%lf", &ctc->pst[i].grade.math);
        printf("학생 정보가 수정되었습니다.\n");
    }
    else {
        printf("학생을 찾을 수 없습니다.\n");
    }
}

void listStudents(CTC* ctc) {
    printf("학생 목록:\n");
    for (int i = 0; i < ctc->num; i++) {
        printf("이름: %s, 아이디: %d, 나이: %d, 영어: %.2lf, 국어: %.2lf, 수학: %.2lf\n",
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
        printf("\n1. 학생 등록\n2. 학생 삭제\n3. 학생 수정\n4. 학생 목록 보기\n5. 종료\n선택: ");
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
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다.\n");
        }
    } while (choice != 5);

    free(ctc.pst); // 메모리 해제
    return 0;
}
