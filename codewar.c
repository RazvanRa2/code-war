#include <stdio.h>
#include <stdlib.h>

/*algoritm flood fill*/
void floodFill(int i,int j,int zoneNr, int m, int n, int land[][405], int *baseArea)
{

    if(land[i][j]==1)
    {
        land[i][j]=zoneNr;/*se inlocuieste 1 cu indexul zonei la care apartine baza*/
        (*baseArea)++;/*se creste numarul de baze din reuniunea de baze*/
        /*se verifica pe cele patru directii, recursiv daca mai exista baze in reuniune
        atata timp cat nu se iese in afara matricei*/
        if (i!=0) floodFill(i-1,j,zoneNr,m,n,land, baseArea);
        if (i!=n-1) floodFill(i+1,j,zoneNr,m,n,land, baseArea);
        if (j!=0) floodFill(i,j-1,zoneNr,m,n,land, baseArea);
        if(j!=m-1) floodFill(i,j+1,zoneNr,m,n,land, baseArea);
    }

}
/*verifica datele de intrare de la task2*/
int minusOneChecker(int nr1, int nr2){

    if(nr1==-1 && nr2==-1)  return 0;
    return 1;

}
/*functia calculeaza 2 la puterea power*/
int notUsingPow(int power){

    int i, thisPower=1;
    for(i=0;i<power;i++)
        thisPower*=2;
    return thisPower;

}
int main()
{
    /*declararea variabilelor utilizate*/
    int b,m,n, cpyB=0, cnt=0, selected=0, pot=0, max=0, codedNr, tempX, tempY,baseArea=0,pzd,plm;
    int i, j, k, task3Counter, zoneIndex=2;
    int startX[160005], startY[160005], result[200005], bit[35];
    int land[405][405];
    /*task1*/
    scanf("%d %d %d",&b,&m,&n);
    scanf("%d", &codedNr);
    while(codedNr!=-1){ /*fiecare codedNr se prelucreaza pt a se obitne sirul cerut*/

        k=0; /*k memoreaza numarul de biti al lui codedNr*/
            if(codedNr==0) /*tratarea cazului special codedNr=0*/
            {
                if(cpyB==0) cpyB=b; /*cpyB memoreaza cati biti se selecteaza*/
                result[cnt]=0; /*se trece 0 in vectorul rezultat*/
                cpyB--;
                cnt++;

            }
            if(codedNr>0){ /*tratarea cazului general*/
            while(codedNr>0) /*se scrie codedNr in baza 2, de la coada la cap*/
            {
                bit[k]=codedNr%2;k++;
                codedNr/=2;
            }
            if(cpyB==0)	cpyB=b; /*resetarea lui cpyB, daca e cazul*/
            for(j=0;j<k;j++) /*trecerea bitilor semnificativi in rezultat*/
            {
                if(cpyB==0) /*daca s-au selectat deja cati biti trebuie, se sare la umratorul numar*/
                    break;
                result[cnt]=bit[k-j-1]; /*biti se trec de la coada la cap, asa fiind memorati*/
                cpyB--;
                cnt++;
            }
            }
        scanf("%d",&codedNr);
    }

    for(i=0;i<cnt;i++) /*tiparirea rezultatului pentru task1*/
        printf("%d ", result[i]);
    printf("\n");

    /*task2*/
    scanf("%d %d", &tempX, &tempY); /*tempX, tempY memoreaza fiecare pereche citita*/
    while(minusOneChecker(tempX,tempY)){ /*verifica daca sunt -1 in acelasi timp*/
        /*ajustarea tempX si tempY conform datelor din tema*/
        if(tempX<0) tempX=0;

        if(tempY-tempX>30) tempY=tempX+30;

        if(tempY>=cnt) tempY=cnt-1;

        if(tempY>=tempX && tempX<cnt && tempY>=0){
            pot=0; selected=0; /*pot=power of two; selected=numarul ce va fi construit din biti*/
            for(j=tempY;j>=tempX;j--){
                if(result[j]==1){ /*daca bitul e 1, se ridica 2 la puterea pot si se aduna*/
                    selected+=notUsingPow(pot);
                    pot++; /*se mareste putera pentru considerarea urmatorului bit*/
                }
            else pot++; /*daca bitul e 0, doar se mareste puterea*/
            }
            if(selected>m*n)    selected=selected%(m*n); /*ajustarea numarului pentru a incapea*/
            printf("%d ",selected); /*se tiparesc numerele cerute*/
            land[selected/n][selected%n]=1; /*se populeaza cu baze matricea*/

        }
        scanf("%d %d", &tempX,&tempY);
    }
    for(pzd=0;pzd<n;pzd++){
        for(plm=0;plm<n;plm++)
            printf("%d \t", land[pzd][plm]);
        printf("\n");
        }

    printf("\n");
    /*task3*/
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(land[i][j]==1){
                baseArea=0;/*se initializeaza marimea unei reuniuni de baze*/
                floodFill(i,j,zoneIndex,m,n,land, &baseArea);
                zoneIndex++;/*zoneIndex acorda un numar de ordine fiecarei reuniuni de baze*/
                /*zoneIndex incepe de la 2 ca sa nu se "confunde" cu 1 care arata doar existenta unei baze*/
                if(max==baseArea){ /*daca se gaseste o reuniune de dimensiune maxima*/
                    startX[task3Counter]=i; /*se memoreaza datele cerute despre aceasta*/
                    startY[task3Counter]=j;
                    task3Counter++;
                    }
                if(max<baseArea){ /*daca se gaseste o reuniune mai mare ca cea maxima*/
                    max=baseArea; /*se reseteaza datele*/
                    task3Counter=0;
                    startX[task3Counter]=i;
                    startY[task3Counter]=j;
                    task3Counter++;
                }
            }
    /*tiparirea datelor cerute la task3*/
    for(i=0;i<task3Counter;i++)
         printf("%d %d %d\n", startX[i], startY[i], max);

    return 0;
}
