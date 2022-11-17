#include <stdbool.h>
#include <stdio.h>

struct homework
{
    char* book_name;
    int page_number;
};


struct subject
{
    char name[20];
    int difficulty;
    float hours;
    struct homework hw;
};

struct student
{
    char name[20];
    int group;
    char city[20];
    _Bool (*study)(struct subject *sbj_ptr);
    
    enum { C, CPP, Java , CSharp, Python } favourite_language;
    char flexible_array_member[];
} s, *p;

_Bool study(struct subject *sbj_ptr) {
    sbj_ptr->hours += sbj_ptr->difficulty/60.0;
    return true;
}

void print_homework(const struct homework *hw) {
    printf("Book: %s \nPage: %d", hw->book_name, hw->page_number);
}

void print_subject(const struct subject *s) {
    printf("Name: %s \nDifficulty: %d \nHours: %f\n", s->name, s->difficulty, s->hours);
    printf("Homework: {\n");
    print_homework(&(s->hw));
    printf("\n}\n");
}

int main(int argc, char const *argv[])
{
    struct student st = {"Смирнов П.В.", 104, "Калуга"};
    // struct student st = {.city = "Moscow", .group = ""};
    struct student *st_p = &st;

    st.name;
    st_p->name;
    // (*st_p).name;

    st.study = study;
    st.favourite_language = 0;

    struct homework hw = {"WorkBook", 45};
    struct subject sbj = {"Algorithms", 7, 0, hw};
    struct subject *sbj_ptr = &sbj; 

    (&sbj)->hw.book_name;
    sbj_ptr->hw.book_name;

    st.study(&sbj);

    print_subject(&sbj);

    return 0;
}
