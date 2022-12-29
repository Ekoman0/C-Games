#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	
	MainMenu();
	return 0;
}
void MainMenu()
{
	int GameSelect;
	
	printf("Adam Vurmaca Oynamak icin = 1 \nSayi Tahmini Oynamak icin = 2\n-----------------------------\nHangi Oyunu Oynamak Istersiniz:");
	
	scanf("%d",&GameSelect);
	
	if(GameSelect == 1)
	{
		Game1();
	}
	else if(GameSelect == 2)
	{
		Game2();
	}
	else
	{
		printf("\n\nLutfen 1 ile 2 Arasinda Deger Girin\n\n");
		MainMenu();
	}
	return 0;
}

void Game1()
{
	printf("Oyun Basliyor!\n");	
	
	
	int EnemySpawn, ErrorRate,Shoot,i,allErrorRate,Score=0,FailedShoot=0,CloseSuccessfulShooting=0,SuccessfulShooting=0;
	
	
	for(  i = 1 ; i < 5 ; i++ )
	{

	
		
	EnemySpawn = 5; 
	
	printf(" enemyspawn:%d",EnemySpawn);
	
	printf("\n%d. Dusman [1-10] Konumlari Arasinda Belirdi!\nHangi Konuma Ates Edeceksin : ",i);	
	
	scanf("%d",&Shoot);
	
	
	if( Shoot > EnemySpawn )
	{
		ErrorRate =   Shoot - EnemySpawn;
	}
	else if	( Shoot <= EnemySpawn )
	{
		ErrorRate =     EnemySpawn - Shoot;
	}

	

	
	if(ErrorRate == 0 )
	{
		printf("\n%d. Atis Hata Oraniniz:%d",i,ErrorRate);	
		printf("\nBasarili Atis Gerceklestirdiniz 10 Puan Kazandiniz");	
		Score +=10;
		SuccessfulShooting +=1;
	}
	else if(ErrorRate > 0 && ErrorRate<=0.5)
	{
		printf("\n%d. Atis Hata Oraniniz:%d",i,ErrorRate);	
		printf("\nCok Yaklastiniz 5 Puan Kazandiniz");	
		allErrorRate +=ErrorRate;
		Score +=5;
		CloseSuccessfulShooting +=1;
	}
	else if(ErrorRate > 0.5)
	{
		printf("\n%d. Atis Hata Oraniniz:%d",i,ErrorRate);	
		printf("\nBasarisiz Atis Gerceklestirdiniz");	
		allErrorRate +=ErrorRate ;
		FailedShoot +=1;
	}
	}
		printf("\n\nOyun Bitti!");
		printf("\n\n10 Atistaki Toplam Hataniz : %d",allErrorRate);	 
		printf("\n10 Atistaki Toplam Puaniniz : %d",Score);	 
		printf("\nBasarili Atis Sayiniz : %d",SuccessfulShooting);	 
		printf("\nYakin Basarili Atis Sayiniz : %d",CloseSuccessfulShooting);	
		printf("\nBasarisiz Atis Sayiniz : %d \n\n",FailedShoot);	
		 MainMenu();
}


void Game2()
{

    int number,ones,tens,hundreds,info1,info10,info100;

   int k=1,j=110,i,array[3];

   srand(time(NULL));

   for(i=0;i<3;i++)
   {
       do{
       do
   {
       //array[i]=rand() %10;
       array[0] = 6;
       array[1] = 9;
       array[2] = 3;
       }while(array[0]==array[1] || array[1]==array[2] || array[0]==array[2]);

    }while(array[0]==0);
   }


 printf("\n\n3 basamakli bir sayi giriniz ");
do
{
	printf("\n\n%d. Tahmininizi giriniz: ",k);
  	scanf("%d",&number);
	j-=10;
	k++;
		

  	hundreds=number/100;
  	tens=(number/10)%10;
  	ones=number%10;




	if(array[0]==hundreds)
	{
    	printf("\n1");
   	 	info100=1;
	}


 	else if(array[2]==hundreds || array[1]==hundreds)
	{
   	 printf("\n9");
   	 info100=9;
	}
  	else if(array[0]!=hundreds && array[1]!=hundreds && array[2]!=hundreds)
	{
    	printf("\n0");
    	info100=0;
	}




	if(array[1]==tens)
	{
   	 printf("1");
    	info10=1;


	}

	else if(array[2]==tens || array[0]==tens)
	{
    printf("9");
    info10=9;

	}

	else if(array[0]!=tens && array[1]!=tens && array[2]!=tens)
	{
    printf("0");
    info10=0;
	}


	if(array[2]==ones)
	{
    printf("1");
    info1=1;
	}

	else if( array[0]==ones || array[1]==ones)
	{
   printf("9");
    info1=9;

	}
	else if(array[0]!=ones && array[1]!=ones && array[2]!=ones)
	{
    printf("0");
    info1=0;
	}




}
while(info100==0 || info100==9 || info10==0 || info10==9 || info1==0 || info1==9 );

printf("\n\n%d. Tahmininizde bildiniz.",k-1);
printf("\nPuaniniz:%d\n\n",j);
MainMenu();
}
