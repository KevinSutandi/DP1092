#define MAJOR_LENGTH 6
#define MAX_NAME 20

struct student {
    // 5555555...
    int  id;
    // 'Emmet', just the first name.
    char name[MAX_NAME];
    // SENGAH, COMP1A, etc.
    char program[MAJOR_LENGTH];
};

