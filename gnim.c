#include <stdio.h>
typedef int bool;
#define true 1;
#define false 0;

void Rules();
void StartGame();
void CheckPacks(int A, int B , int C);
bool isItBalance(int A, int B , int C);
int SetPack(int Pack, int val);
int findMax(int a,int b,int c);
int SumOfTwo(int a, int b, int c);
void PrintPacks(int a, int b, int c);

int main(){
    int choice;
    printf("Hello. \n Welcome to our Game 'gnim' the please enter: \n 1. for rulse \n 2. to start the game.");
    scanf("%d", &choice);
   
    switch(choice){
        case 1: Rules(); break;
        case 2: StartGame(); break;
        default : {
            while(choice != 1 || choice != 2){
            printf("enter 1 or 2 \n");
            scanf("%d", &choice);
            }
        }
    }

    return 0;
}

void Rules(){
    /*
    The Game rules Goes HERE
    */
    printf("The Game name is Gnim , Its a game about picking up a Pack and decrese its amount in every step \n , You play vs. the computer , in every step each player can set a new value to the package , \n  the game kippes going until some one have only one untit at the same of all packages. \n Summery : \n");
    printf("1. The game start by Flip Coin (random start) \n 2. Select pack \n 3. set new Value to the pack, its should be at the most as how much its containts. \n 4.if player left with only one unit , he lost. \n");
    main();
    return;
}

void StartGame(){

    //Welcome .. //
    int A, B, C;
    printf(" ----- Gnim ----- ");
    printf("NOTE* : that you can insert only positive , full number (aka Integer) \n");
    printf("The packs are A B C \n first we will insert the amount of each pack. \n Pack A: \n ");
    scanf("%d", &A);
    printf("Pack B: \n");
    scanf("%d", &B);
    printf("Pack C: \n");
    scanf("%d", &C);

    //Detrminate all negative inserts. // 
    if(A<0 || B<0 || C<0){
        printf("some of your packs was negative number , you like to play in your rules? \n no problem.. \n but there is one think , Im the one who make that game and rules \n so I changed your number to positive. \n");
        if(A<0) A*= -1;
        else if(B<0) B*= -1;
        else C*= -1;
    }

    PrintPacks(A,B,C);
    //"Cazion Effect" - lets make the "honest" feeling. // 
    int coin;
    bool isitbalanced;
    //CheckPacks(A,B,C);
    printf("let's make it fair and flip a coin to choice who will start the game... \n Head or Tails.. \n 1.Head \n 2.Tails. \n");
    scanf("%d", &coin);
    isitbalanced = isItBalance(A,B,C);
    
    
    //Game Starting Here. // 
    
    
    if(isitbalanced){
        printf("You Start! .. Lucky \n");
        bool startGame = true;
        while(startGame){
            int inGamePack =99;
            int decVal = -1 ;
            int tmpSumOfPacks;
            int compTurntmp1;
            while((inGamePack != 1 || inGamePack != 2 || inGamePack !=3 ) && (decVal >0)){
            printf("\n Choose Pack: \n 1.A \n 2.B \n 3.C \n");
            scanf("%d" , &inGamePack);
            printf("Decrese: \n");
            scanf("%d" , &decVal);
            }
            PrintPacks(A,B,C);

            switch(inGamePack){
                case 1 : A = SetPack(A, decVal); break;
                case 2 : B = SetPack(B, decVal); break;
                case 3 : C = SetPack(C, decVal); break; // at the end try to improve by adding default.
            }

            tmpSumOfPacks = SumOfTwo(A,B,C);
            if(tmpSumOfPacks == 0 || tmpSumOfPacks == 1 || tmpSumOfPacks == 2){
                 startGame = false;

            }
            else{
                compTurntmp1 = findMax(A,B,C);
                if(tmpSumOfPacks <= compTurntmp1){
                    if(compTurntmp1 == A) A = tmpSumOfPacks;
                    else if(compTurntmp1 ==B ) B = tmpSumOfPacks;
                    else C = tmpSumOfPacks;
                    PrintPacks(A,B,C);
                }
                else{
                    if(compTurntmp1 == A) A = -(A-tmpSumOfPacks);
                    else if(compTurntmp1 == B) B = -(B-tmpSumOfPacks);
                    else C = -(C-tmpSumOfPacks);
                    PrintPacks(A,B,C);
                }
            }
            tmpSumOfPacks = SumOfTwo(A,B,C);
            PrintPacks(A,B,C);
            if(tmpSumOfPacks == 0 || tmpSumOfPacks == 1 || tmpSumOfPacks == 2) startGame = false;
        }
    } 
    else {// else.. the packs is not balanced, comp start. // 
        printf("Its look like im starting ! \n");
        bool startGame2 = true;
        int tmpMax2;
        int tmpSum2Packs2;

        while(startGame2){
            tmpMax2 = findMax(A,B,C);
            tmpSum2Packs2 = SumOfTwo(A,B,C);
            if(tmpSum2Packs2 == 0 || tmpSum2Packs2 == 1 || tmpSum2Packs2 == 2){
                 startGame2 = false;
            }
            else{// comp move.
                if(tmpSum2Packs2<= tmpMax2){ // set the max to sum of two packs. /// BElow 10:38 st.
                    if(tmpMax2 == A)A=tmpSum2Packs2;
                    else if(tmpMax2 == B)B=tmpSum2Packs2; 
                    else C= tmpSum2Packs2; 
                    
                }else{
                    if(tmpMax2 == A) A = -(A-tmpSum2Packs2); 
                    else if(tmpMax2 == B) B = -(B-tmpSum2Packs2); 
                    else C = -(C-tmpSum2Packs2); 
                 
                }
            //    PrintPacks(A,B,C); //10:34 st.
            }
            tmpSum2Packs2 = SumOfTwo(A,B,C);
            if(tmpSum2Packs2 == 0 || tmpSum2Packs2 == 1 || tmpSum2Packs2 == 2) startGame2 = false;
            PrintPacks(A,B,C);
            //now the user turn//
            int inGamePack2 =4;
            int decVal2 =-1;
            while((inGamePack2 != 1 || inGamePack2 != 2 || inGamePack2 !=3 ) && (decVal2>0)){
            printf("\n Choose Pack: \n 1.A \n 2.B \n 3.C \n");
            scanf("%d" , &inGamePack2);
            printf("Decrese: \n");
            scanf("%d" , &decVal2);
            }

            switch(inGamePack2){
                case 1 : A = SetPack(A, decVal2); break;
                case 2 : B = SetPack(B, decVal2); break;
                case 3 : C = SetPack(C, decVal2); break; // at the end try to improve by adding default.
            }
            PrintPacks(A,B,C);

            tmpSum2Packs2 = SumOfTwo(A,B,C);
            if(tmpSum2Packs2 == 0 || tmpSum2Packs2 == 1 || tmpSum2Packs2 == 2) startGame2 = false;
        }

    }
    int AfterWhileCases = SumOfTwo(A,B,C); // After the "While" in each Situation : Balanced / UnBalance calculate the sum of two smallest packs in the game .
    switch(AfterWhileCases){
        case 1: {
            PrintPacks(A,B,C);
            printf("I set the %d , to 0 and you left with the 1. - YOU LOSE. -GAME OVER-" , findMax(A,B,C));
            break;
        }
        case 2: {
            PrintPacks(A,B,C);
            printf("I set the %d , to 1\n you can set any pack to 0 , but I will set another to Zero too \n and you left with the 1. - YOU LOSE. -GAME OVER-\n" , findMax(A,B,C));
            break;
        }
        case 0 :{
            PrintPacks(A,B,C);
            printf("I set the %d , to 1 and you left with the 1. - YOU LOSE. -GAME OVER-" , findMax(A,B,C));
            break;
        }

    }
    return;
}

void CheckPacks(int A, int B , int C){
    printf("\n pack A: %d \n pack B: %d \n pack C: %d \n", A,B,C);
    return;
}

bool isItBalance(int A, int B , int C){
    int a= A;
    int b= B;
    int c = C;
    bool flag = false;
    if( (  (a+b) == c  )  ||(  (a+c) == b  ) ||  (  (b+c) == a)  ){
        flag=true; 
    } 
    else flag = false;
   
    
    return flag;
}

int SetPack(int Pack, int val){
    if(val >= Pack) Pack = 0;
    else Pack -= val;
    return Pack;
}

int findMax(int a,int b,int c){
    int max;
    if(a>b && a>c )max=a;
    else if (b>a && b>c) max =b;
    else max =c;
    return max;
}

int SumOfTwo(int a, int b, int c){
    int tmpMax;
    int sum =a+b+c;
    tmpMax = findMax(a,b,c);
    sum -= tmpMax;
    return sum;
}

void PrintPacks(int a, int b, int c){
    printf("\n Pack A: %d \n Pack B: %d \n Pack C: %d \n ", a,b,c);
    return;
}




