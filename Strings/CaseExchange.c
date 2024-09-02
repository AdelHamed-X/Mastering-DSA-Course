#include <stdio.h>

void caseExchange(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
}

int main(void) {

    char s[] = "Adel";

    printf("%s\n", s);
    caseExchange(s);
    printf("%s\n", s);

    return 0;

}
