#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
#include <time.h> 

int mat[ 20 ][ 20 ], count = 0, choice = 0;
int min, sec;
char level[10][15] = {" ","Easy","Medium","Hard","Very Hard","Customized"};

void result ()              /* Display Result screen */
{
	system("cls");
	int i , j;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	
	for(i = 0 ; i <= 10; i++)
	{
		printf("\t\t\t\t\t\t\t\t");
		if(i !=0 && i !=10)
		{
			printf("*");
		}
		for(j = 0; j < 5; j++)
		{
			if(i == 2)
			{
				printf("\t\t\t\t\t!!! You Solved The Puzzle !!!\t\t\t\t     ")	;
				break;
			}
			else if(i == 5)
			{
				printf("           Time Taken  : %02d Min %02d Sec\t\t\t             Moves Taken : %02d\t\t    ",min,sec,count);
				if(count < 100)
				{
					printf(" ");
				}
				break;
			}
			else if(i == 0 || i == 10)
			{
				if(j == 0)
				{
					printf(" ");
				}
				printf("* * * * * * * * * * ");
			}
			else
			{
				printf("                    ");
			}
		}
		printf("*\n");
	}
}

int check(int n)          /* Checking for correctness of Puzzle */
{
	int val = 1 ,i ,j;
	for(i = 0;i < n; i++)
	{
		for(j = 0; j < n && val < n*n; j++)
		{
			if(mat[i][j] == val++)
			{
				continue;
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}

void instruction()        /*Display Instructions*/
{
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t*********************   PUZZLE GAME   *******************");	
	printf("\n\n\t\t\t\tINSTRUCTIONS : ");
	printf("\n\n\t\t\t\t\t\t1. The game board has blocks with numbers in it. Also there is a single 'Empty space' that can be used for moving the blocks");
	printf("\n\n\t\t\t\t\t\t2. The objective of the game is to order the numbers using the 'Empty space' for temporary movement");
	printf("\n\n\t\t\t\t\t\t3. Move blocks in a row by pressing Arrow Keys on them. A block can be moved only if it is in the same row or column as the 'Empty space' ");
	printf("\n\n\t\t\t\t\t\t\tKey Functions : ");
	printf("\n\n\t\t\t\t\t\t\t\t\t*  UP ARROW KEY    (%c) - Move Upward and fill the empty space",24);
	printf("\n\n\t\t\t\t\t\t\t\t\t*  DOWN ARROW KEY  (%c) - Move Downward and fill the empty space",25);	
	printf("\n\n\t\t\t\t\t\t\t\t\t*  LEFT ARROW KEY  (%c) - Move Leftward and fill the empty space",'<');
	printf("\n\n\t\t\t\t\t\t\t\t\t*  RIGHT ARROW KEY (%c) - Move Rightward and fill the empty space",'>');
	printf("\n\n\t\t\t\t\t\t\t\t\t\tPress 1 to Start the Game and Press 2 to End the Game (At any time) ");
}
void print_matrix(int n)            /*  Print matrix  */
{
	int i , j;
	printf("\n\n");
	printf("                                                                                    *********************   PUZZLE GAME   *******************");
	printf("\n\n\n");
	printf("\n\n                                                                               Level : %s                                             Moves : %d \n\n\n",level[choice],count);
	printf("                                                                                     ");
	
	for(i = 0; i < n; i++)
	{
		printf("  ____ ___");
	}
	
	printf("\n\n");
	for(i = 0; i < n; i++)
	{
		printf("                                                                                     ");
		printf(" |    ");
		for(j = 0; j < n; j++)
		{
			if(mat[ i ][ j ] == 0)
			{
				printf("     |    ");
			}
			else if(mat[ i ][ j ] > 9)
			{
				printf("%d   |    ", mat[ i ][ j ]);
			}
			else
			{
				printf("%d    |    ", mat[ i ][ j ]);
			}
		}

		printf("\n");
		printf("                                                                                     ");
		
		for(j = 0; j <= n; j++)
		{
			printf(" |        ");
		}
		
		printf("\n");
		printf("                                                                                     ");
		
		for(j = 0; j < n; j++)
		{
			printf("  ____ ___");
		}
		
		printf("\n\n");
	}
}

void move(char ch, int n)                    /* Move blocks */
{
	int i , j;
	for(i = 0;i < n;i++)
	{
		int flag = 0;
		for(j = 0;j < n; j++)
		{
			if(mat[ i ][ j ]==0)
			{
				int row = i,col = j;
				count++;
				if(ch == 'r' && j-1 >= 0)
					col-=1;
				else if(ch=='l' && j+1 <= n-1)
					col+=1;
				else if(ch=='d' &&i-1 >= 0)
					row-=1;
				else if(ch=='u' &&i+1 <= n-1)
					row+=1;
				else 
					count--;
			
				int temp = mat[ i ][ j ];   /* swap */
				mat[ i ][ j ] = mat[ row ][ col ];
				mat[ row ][ col ] = temp;
				flag = 1;
				break;	
			}
		}
		if(flag)
			break;
	}
}

void make_puzzle(int n)      /* Shuffle process*/
{
	int pos_i = 0 , pos_j = 0, flag = 0 , i, j;
	for(i = 0;i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(mat[ i ][ j ] == 0)
			{
				pos_i = i;
				pos_j = j;
				flag = 1 ;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	
	for(i = pos_i ; i < n-1;i++)
		mat[i][pos_j] = mat[i+1][pos_j];
		
	for(j = pos_j; j<n-1; j++)
		mat[ n-1 ][ j ] = mat[ n-1 ][ j+1 ];
		
	mat[ n-1 ][ n-1 ]=0;
}

int main()
{
	printf("\n\n\t\t\t\t\t\t****************************************************  WELCOME TO PUZZLE GAME  ****************************************************");
	printf("\n\n\n\n\t\t\t\t\t\tChoose the level : ");
	printf("\n\n\t\t\t\t\t\t\t\t\t1.Easy          (3 X 3)");
	printf("\n\n\t\t\t\t\t\t\t\t\t2.Medium        (4 X 4)");
	printf("\n\n\t\t\t\t\t\t\t\t\t3.Hard          (5 X 5)");
	printf("\n\n\t\t\t\t\t\t\t\t\t4.Very Hard     (3 X 3)");
	printf("\n\n\t\t\t\t\t\t\t\t\t5.Customize     (N X N)\n\n");
	int n,i,j,k;
	scanf("%d", &choice);
	n = choice+2;
	if(choice ==  5)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\tEnter size of the Box : ");
		scanf("%d", &n);
	}
	int shuffle = 0 , key;
	char ways[ 4 ] = {'u','d','l','r'};
	int row = n-1, col = n-1;
	instruction();
	int choice1;
	scanf("%d", &choice1);
	if(choice1 == 2)
		exit(0);
	
	for( i = 0, k =1 ; i < n; i++)
	{
		for( j = 0; j < n; j++)
		{
			mat[ i ][ j ] = k++;
		}
	}
	mat[row][col]=0;
	srand(time(0));

	while(shuffle<30)
	{
		shuffle = rand()%100;
	}
	
	for( i = 0; i < shuffle; i++)
	{
		move(ways[rand()%4],n);
	}
		
	make_puzzle(n);
	count = 0;
	system("cls");
	print_matrix(n);
	time_t seconds;
	seconds = time(NULL);
	
	while(1)
	{
		getch();
		key = getch();
		if(key == 72)
		{
			system("cls");
			move('u',n);
			print_matrix(n);
		}
		else if(key == 80)
		{
			system("cls");
			move('d',n);
			print_matrix(n);
		}
		else if(key == 75)
		{
			system("cls");
			move('l',n);
			print_matrix(n);
		}
		else if(key == 77)
		{
			system("cls");
			move('r',n);
			print_matrix(n);
		}
		else if(key == 50)
		{
			exit(0);
		}
		else
		{
			system("cls");
			print_matrix(n);
		}
				
		if(check(n)==1){
			seconds -=time(NULL);
			seconds*=-1;
			min = seconds/60;
			sec = seconds %60;
			result();
			break;
		}
	}
}
	
