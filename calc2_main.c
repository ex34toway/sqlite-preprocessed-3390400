
#include "calc2.c"

int main()
{
    void* pParser = ParseAlloc(malloc);

    struct Token t0 = { 40, 0 };
    struct Token t1 = { 2, 0 };

    /* First input:
    ** 40 - 2
    */
    Parse(pParser, NUM, t0);
    Parse(pParser, MINUS, t0);
    Parse(pParser, NUM, t1);
    Parse(pParser, 0, t0);

    /* Second input:
    ** 40 + 2
    */
    Parse(pParser, NUM, t0);
    Parse(pParser, PLUS, t0);
    Parse(pParser, NUM, t1);
    Parse(pParser, 0, t0);

    /* Third input:
    ** 40 * 2 + 2 / 2
    */
    Parse(pParser, NUM, t0);
    Parse(pParser, TIMES, t0);
    Parse(pParser, NUM, t1);
    Parse(pParser, PLUS, t0);
    Parse(pParser, NUM, t1);
    Parse(pParser, DIVIDE, t0);
    Parse(pParser, NUM, t1);
    Parse(pParser, 0, t0);

    ParseFree(pParser, free);

    return 0;
}