#include <unistd.h>
#include <conio.h>

#include <stdio.h>

#include <locale.h>

int main() {

    int k;



    setlocale(LC_ALL,"chs");

    printf("如果你三秒钟之内什么也不输入，我就输出-1。\n");

    sleep(3);

    if(!_kbhit())

        printf("-1\n");

    else {

        printf("输入了");

        while (1) {

            if (_kbhit()) {

                k=_getch();

				printf("%c",k);
                
            } else break;

        }

        printf("\n");

    }

    return 0;

}
