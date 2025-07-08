#ifndef DUMMY_POSTS_H
#define DUMMY_POSTS_H

#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_DUMMY_POSTS 10
#define MAX_TITLE_LEN    64
#define MAX_AUTHOR_LEN   32
#define MAX_CONTENT_LEN 256

// 더미 게시글 구조체 정의
typedef struct {
    int    id;
    char   title[MAX_TITLE_LEN];
    char   author[MAX_AUTHOR_LEN];
    char   content[MAX_CONTENT_LEN];
    char   created_at[20];  // "YYYY-MM-DD HH:MM:SS"
} DummyPost;

// 내부 샘플 데이터
static const char *SAMPLE_TITLES[NUM_DUMMY_POSTS] = {
    "첫 게시글 환영합니다",
    "새 기능 제안",
    "버그 신고 게시판",
    "공지사항 확인",
    "사용자 리뷰 남기기",
    "Q&A 코너",
    "프로젝트 진행 상황",
    "자유 토론장",
    "이벤트 안내",
    "운영 정책 변경"
};

static const char *SAMPLE_AUTHORS[] = {
    "kim", "lee", "park", "choi", "jung",
    "kang", "cho", "yoon", "shin",  "jang"
};

static const char *SAMPLE_CONTENTS[] = {
    "이것은 더미 콘텐츠입니다. 실제 게시글처럼 보이기 위해 생성되었습니다.",
    "새로운 기능에 대한 아이디어를 공유해주세요.",
    "버그를 발견하셨다면 이곳에 상세히 남겨주세요.",
    "중요 공지사항이 있을 때 사용합니다.",
    "서비스 이용 후기를 작성해주세요.",
    "질문과 답변을 주고받을 수 있습니다.",
    "프로젝트의 최신 진행 상황을 업데이트합니다.",
    "자유롭게 주제를 선택해 토론해보세요.",
    "곧 있을 이벤트 일정을 안내합니다.",
    "정책 변경 사항을 확인하세요."
};

// count 만큼의 더미 데이터를 posts 배열에 채워줍니다.
static inline void fill_dummy_posts(DummyPost posts[], int count) {
    if (count > NUM_DUMMY_POSTS) count = NUM_DUMMY_POSTS;
    srand((unsigned)time(NULL));
    for (int i = 0; i < count; i++) {
        int t = rand() % NUM_DUMMY_POSTS;
        int a = rand() % (sizeof(SAMPLE_AUTHORS)/sizeof(SAMPLE_AUTHORS[0]));
        int c = rand() % (sizeof(SAMPLE_CONTENTS)/sizeof(SAMPLE_CONTENTS[0]));
        
        posts[i].id = i + 1;
        strncpy(posts[i].title, SAMPLE_TITLES[t], MAX_TITLE_LEN - 1);
        strncpy(posts[i].author, SAMPLE_AUTHORS[a], MAX_AUTHOR_LEN - 1);
        strncpy(posts[i].content, SAMPLE_CONTENTS[c], MAX_CONTENT_LEN - 1);
        
        time_t now = time(NULL) - rand() % (60*60*24*301);
        struct tm tm_info;
        localtime_r(&now, &tm_info);
        strftime(posts[i].created_at, sizeof(posts[i].created_at), "%Y-%m-%d %H:%M:%S", &tm_info);
    }
}

#endif // DUMMY_POSTS_H
