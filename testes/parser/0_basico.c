int a;
func int f()
{
    int b;
    int k;
    b = 2;
    k = 3;
    return b;
}

main {
    char c;
    string s;
    c = 'a';
    a = 3;
    s = "olá mundo";

    a++;
    a--;

    a = a + a;
    a = 3 + a;
    a = a + 4;
    a = 5 + 2;

    a = a - a;
    a = a - 3;
    a = 4 - a;
    a = 5 - 2;

    a = a * a;
    a = a * 3;
    a = 4 * a;
    a = 5 * 2;

    a = a # a;
    a = a # 3;
    a = 4 # a;
    a = 5 # 2;

    a = a / a;
    a = a / 3;
    a = 4 / a;
    a = 5 / 2;

    a = a % a;
    a = a % 3;
    a = 3 % a;
    a = 3 % 2;

    f();
    a = f();
}
