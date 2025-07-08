#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_POSTS 10
#define MAX_TITLE_LEN 64
#define MAX_AUTHOR_LEN 32
#define MAX_CONTENT_LEN 256

const char *sampleTitles[] = {
    "안녕하세요, 첫 게시글입니다",
    "오늘 날씨 어때요?",
    "C언어 팁 공유합니다",
    "프로젝트 아이디어 토론",
    "버그 수정 완료 보고",
    "새로운 기능 제안",
    "일정 공유드립니다",
    "팀 미팅 공지",
    "자료구조 공부 자료",
    "자유 주제 토론장"
};

const char *sampleAuthors[] = {
    "kim", "lee", "park", "choi", "jung",
    "kang", "cho", "yoon", "shin", "jang"
};

const char *sampleContents[] = {
    "이것은 더미 콘텐츠입니다. 테스트용으로 사용하세요.",
    "C언어로 간단한 더미 데이터를 생성해봤습니다.",
    "프로젝트 진행 상황 공유 바랍니다.",
    "이슈 트래커에 올릴 글입니다.",
    "테스트 중입니다. 실제 서비스가 아닙니다.",
    "샘플 내용이 반복될 수 있습니다.",
    "랜덤하게 생성된 글입니다.",
    "사용자 인터페이스 테스트용 글입니다.",
    "DB 삽입 전 더미 데이터입니다.",
    "마지막 더미 게시글입니다."
};

int main(void) {
    srand((unsigned)time(NULL));

    printf("[\n");
    for (int i = 0; i < NUM_POSTS; i++) {
        int t = rand() % (sizeof(sampleTitles) / sizeof(sampleTitles[0]));
        int a = rand() % (sizeof(sampleAuthors) / sizeof(sampleAuthors[0]));
        int c = rand() % (sizeof(sampleContents) / sizeof(sampleContents[0]));
        time_t now = time(NULL) - rand() % (60*60*24*30); // 과거 한 달 이내 랜덤

        struct tm *tm_info = localtime(&now);
        char timestr[20];
        strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", tm_info);

        printf("  {\n");
        printf("    \"id\": %d,\n", i + 1);
        printf("    \"title\": \"%s\",\n", sampleTitles[t]);
        printf("    \"author\": \"%s\",\n", sampleAuthors[a]);
        printf("    \"content\": \"%s\",\n", sampleContents[c]);
        printf("    \"created_at\": \"%s\"\n", timestr);
        printf("  }%s\n", (i == NUM_POSTS - 1) ? "" : ",");
    }
    printf("]\n");

    return 0;
}
