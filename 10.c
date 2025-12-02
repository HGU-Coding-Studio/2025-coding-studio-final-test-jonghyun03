#include <stdio.h>
int markBingo(int num, int b[]){
    int row_start, col_start; // 행, 열 번호
    int r_count=0, c_count=0;
    int i;
    int index = num - 1;
    row_start = (index / 5) * 5;
    col_start = index % 5;
    if (b[index]) {
        printf("중복!\n");
        return 0;
    }
    else {
        b[index] = 1;
        for (i = row_start; i < row_start + 5; i++) {
            if (b[i] == 1)
                r_count++;
        }


        for (i = col_start; i <= col_start + 20; i += 5) {
            if (b[i] == 1)
                c_count++;
        }


        if (r_count == 5 || c_count == 5) {
            return 1; // 빙고
        }
        else {
            return -1; // 마킹만 함
        }
    }
}
void printBingo(int b[]){
    int i,j;
    for(i=0;i<25;i+=5){
        printf("--------------------- \n|");
        for(j=i;j<i+5;j++)
            printf(" %d |",b[j]);
        printf("\n");
    }
    printf("---------------------");
}
int main() {
    int bingo[25]={0}; // 25 매트릭스
    int num; // 입력받은 숫자
    while(1){
        printf("Enter a number(1~25) > ");
        scanf("%d",&num);
        if(num>25||num<1){
            printf("EXIT!\n");
            break;
        }
        if(markBingo(num,bingo)==1) {
            printf("빙고!\n");
            break;
        }

    }
    printf("BINGO MATRIX\n");
    printBingo(bingo);
    return 0;
}