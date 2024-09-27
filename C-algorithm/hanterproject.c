#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 30

typedef struct Account {
    char password[MAX_LEN];
    char account[MAX_LEN];
    int balance;
} Account;

typedef enum Function {
    LOGIN = 1, RETRIEVE_BALANCE, DEPOSIT, WITHDRAW, TRANSFER, REGISTER, DELETE, END
} Function;

Account currentAccount;
int accountNum;

void login(Account *accounts, int *islogin) {
    //TODO
    char password[MAX_LEN];
    char account[MAX_LEN];

    printf("계좌번호를 입력해주세요: ");
    scanf("%s", account);
    printf("비밀번호를 입력해주세요: ");
    scanf("%s", password);

    for(int i=0; i<accountNum; i++){
        if(strcmp(accounts[i].account, account)==0 && strcmp(accounts[i].password,password) ==0){
            *islogin = 1;
            currentAccount = accounts[i];
            printf("로그인되었습니다.\n");
            return;
        }
    }
}

void retrieveBalance() {
    printf("현재 잔액은 %d원입니다. \n", currentAccount.balance);
}

void deposit() {
    int howmuch;
    printf("입금할 금액을 입력하세요: ");
    scanf("%d",&howmuch);

    currentAccount.balance += howmuch;
    printf("%d원을 입금했습니다. 현재 잔액은 %d원입니다.", howmuch, currentAccount.balance);

}

void withdraw() {
    int howmuch;
    printf("출금할 금액을 입력하세요: ");
    scanf("%d",&howmuch);

    if(howmuch>currentAccount.balance){
        printf("잔액이 부족합니다. 현재 잔액은 %d입니다.",currentAccount.balance);
    }
    else {
        currentAccount.balance -= howmuch;
        printf("%d이 출금되었습니다. 현재 잔액은 %d입니다.", howmuch, currentAccount.balance);
    }
}


void transfer(Account *accounts) {
    //TODO
    char goalAccount[MAX_LEN];
    int howmuch;

    printf("이체할 계좌 번호를 입력해주세요: ");
    scanf("%s",goalAccount);


    int goalIndex = 0;
    for(int i=0; i<accountNum; i++){
        if(strcmp(accounts[i].account,goalAccount)==0){
        goalIndex = i;
        break;
        }
    }

    if(howmuch<=0){
        printf("가능한 금액을 입력해주세요. \n");
        return;
    }

    if(howmuch > currentAccount.balance){
        printf("잔액이 부족합니다. 현재 잔액은 %d원입니다. ", currentAccount.balance);
    }
    else{
        currentAccount.balance -= howmuch;
        accounts[goalIndex].balance += howmuch;
        printf("%d원이 계좌(%s)로 이체되었습니다. 현재 잔액은 %d원입니다.",howmuch, goalAccount,currentAccount.balance);
    }
}

void registerAccount(Account *accounts, int index) {
    //TODO
    char account[MAX_LEN];
    char password[MAX_LEN];

    printf("새롭게 등록할 계좌 번호를 입력해주세요: ");
    scanf("%s", accounts[index].account);

    for(int i=0; i< index; i++){
        if(strcmp(accounts[i].account,account)==0){
            printf("이미 등록되어 있는 계좌입니다. \n");
            return;
        }
    }

    printf("비밀번호를 입력해주세요: ");
    scanf("%s", accounts[index].password);

    printf("잔액: ");
    scanf("%d",&accounts[index].balance);

    printf("계좌가 등록되었습니다.");


}

void deleteAccount(Account *accounts) {
    //TODO

    char account[MAX_LEN];
    char password[MAX_LEN];

    printf("삭제할 계좌번호를 입력하세요: ");
    scanf("%s", account);

    for(int i=0; i<accountNum; i++){
        if(strcmp(accounts[i].account,account)==0){
            printf("비밀번호를 입력하세요: ");
            scanf("%s",password);
        

        if(strcmp(accounts[i].password,password)==0){
            for(int j = i; j<accountNum -1; j++){
                accounts[j] = accounts[j+1];
            }
            printf("계좌가 삭제되었습니다.\n");
        }
        else{
            printf("잘못된 비밀번호를 입력했습니다. 다시 시도하세요. \n");
        }
        return;
    }
}
    printf("현재 등록된 계좌 중 일치하는 계좌 정보가 없습니다. \n");
}


int main() {
    printf("==========[Bank System]==========\n\n");
    printf("등록할 계좌 수를 입력해주세요: ");
    scanf("%d", &accountNum);
    Account *accounts = (Account *)malloc(accountNum * sizeof(Account));
    printf("총 %d개의 계좌를 등록할 수 있습니다\n\n", accountNum);

    for (int i = 0; i < accountNum; i++) {
        printf("계좌번호 입력: ");
        scanf("%s", (accounts[i].account));
        printf("비밀번호 입력: ");
        scanf("%s", (accounts[i].password));
        printf("잔액 입력: ");
        scanf("%d", &(accounts[i].balance));
        printf("\n");
    }

    Function function;
    int islogin = 0;
    for (int repeat = 1; repeat != 0;) {
        printf("==========[Main Menu]==========\n");
        printf("현재 계좌: %s\n", currentAccount.account);
        printf("1. 로그인(계좌 변경)\n");
        printf("2. 잔액 조회\n");
        printf("3. 입금\n");
        printf("4. 출금\n");
        printf("5. 이체\n");
        printf("6. 계좌 등록\n");
        printf("7. 계좌 삭제\n");
        printf("8. 종료\n");
        printf("원하는 기능을 입력해주세요: ");
        scanf("%d", &function);

        switch (function) {
            case LOGIN:
                login(accounts,&islogin);
                break;
                
            case RETRIEVE_BALANCE:
                if(islogin){
                    retrieveBalance();
                }
                else{
                    printf("로그인 후 시도해주세요\n");
                }
                break;
            case DEPOSIT:
                if (islogin) {
                    deposit();
                } 
                else {
                    printf("로그인 후 시도해주시기 바랍니다\n");
                }
                break;
            case WITHDRAW:
               if (islogin) {
                    withdraw();
                } 
                else {
                    printf("로그인 후 시도해주시기 바랍니다\n");
                } 
                break;
            case TRANSFER:
                if (islogin) {
                    transfer(accounts);
                } 
                else {
                    printf("로그인 후 시도해주시기 바랍니다\n");
                }
                break;
            case REGISTER:
                accountNum++;
                accounts = (Account *)realloc(accounts, accountNum * sizeof(Account));
                registerAccount(accounts, accountNum - 1);
                break;
            case DELETE:
                  deleteAccount(accounts);
                accountNum--;
                accounts = (Account *)realloc(accounts, accountNum * sizeof(Account));
                break;
            case END:
                 printf("ATM을 종료합니다\n");
                repeat = 0;
                break;

            default:
                printf("올바른 기능을 선택해주세요\n");
                break;
        }
        printf("\n");
    }

    free(accounts);
    return 0;
}




