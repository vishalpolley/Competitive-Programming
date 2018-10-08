#include <iostream>
using namespace std;

int main()
{
    char c;
    bool chk=1;
    while(scanf("%c", &c)!=EOF)
    {
        if(c=='"')
        {
            if(chk)
                printf("``");
            else
                printf("''");
            chk=(!chk);
        }
        else
            printf("%c", c);
    }
    return 0;
}
