#include<stdio.h>
#include<stdbool.h>
int a[9][9] = { {3,0,6,5,0,8,4,0,0},
		{5,2,0,0,0,0,0,0,0},
		{0,8,7,0,0,0,0,3,1},
		{0,0,3,0,1,0,0,8,0},
		{9,0,0,8,6,3,0,0,5},
		{0,5,0,0,9,0,6,0,0},
		{1,3,0,0,0,0,2,5,0},
		{0,0,0,0,0,0,0,7,4},
		{0,0,5,2,0,6,3,0,0}};
int row[9]={1,2,3,4,5,6,7,8,9};
int col[9]={1,2,3,4,5,6,7,8,9};
int square[9]={1,2,3,4,5,6,7,8,9};
void resetmax();
void printmatx();
void initialize();
void preinit();
void solve();
void checkrow();
void checkcol();
void checksquare();
int mergecheck();


void resetmatx()
{
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			a[i][j]=0;
}


void solve()
{
	int solved=true;
	int i,j,itr=0;
	while(1)
	{
	solved=true;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[i][j]==0)
			{
				solved=false;
				//check the rows
				checkrow(i,j);
				checkcol(i,j);
				checksquare(i,j);
				a[i][j]=mergecheck();
			}
		}
	}
	printmatx();
	//sleep(1);
	printf("iterations=%d",itr++);
	if(solved==true)
		return;
	}
}

void checkrow(int i, int j)
{
	int k;
	for(k=0;k<9;k++)
		{
		row[k]=k+1;
		}
	for(k=0;k<9;k++)
	{
//	row[k]=k+1;
		if(a[i][k])
			row[a[i][k]-1]=0;
	}
	printf("\nrow possibility for %d %d\n",i,j);
	for(k=0;k<9;k++)
	{
		if(row[k])
			printf("%d",row[k]);
	}
	printf("\n");
	
}


void checkcol(int i, int j)
{
	int k;
	for(k=0;k<9;k++)
		{
		col[k]=k+1;
		}
	for(k=0;k<9;k++)
	{
		if(a[k][j])
			col[a[k][j]-1]=0;
	}
	printf("\ncol possibility for %d %d\n",i,j);
	for(k=0;k<9;k++)
	{
		if(col[k])
			printf("%d",col[k]);
	}
	printf("\n");
}


void checksquare(int i, int j)
{
	int k,x,y;
	for(k=0;k<9;k++)
		{
		square[k]=k+1;
		}
	for(x=((i/3)*3);x<(((i/3)*3)+3);x++)
	{
		for(y=((j/3)*3);y<(((j/3)*3)+3);y++)
		{
			if(a[x][y])
				square[a[x][y]-1]=0;
		}
	}
	printf("\nsquare possibility for %d %d\n",i,j);
	for(k=0;k<9;k++)
	{
		if(square[k])
			printf("%d",square[k]);
	}
	printf("\n");
	
}

int mergecheck()
{
	int k,ret,sol=0;
	for(k=0;k<9;k++)
	{
		if(row[k] && col[k] && square[k])
		{
			ret=row[k];
			sol++;
			printf("merge possibility = %d\n", ret);
		}
	}
	if(sol==1)
		return ret;
	else
		return 0;
}
	
void checkcol();
void checksquare();
int mergecheck();

void printmatx()
{
	int i,j;
	for(i=0;i<9;i++)
		{
		if(i%3==0)
			printf("\n========================================\n");
		else
			printf("\n----------------------------------------\n");
		printf("|");
		for(j=0;j<9;j++)
			{
			if(j%3==0)
				printf("|");
			printf(" %d |",a[i][j]);
			}
			
		}
	printf("\n========================================\n");
}


void initialize()
{
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			printf("\na[%d][%d]= ",i,j);
			scanf("%d",&a[i][j]);
		}
}






void preinit()
{
a[0][0]= 0; a[0][1]= 2; a[0][2]= 0; a[0][3]= 1;a[0][4]= 7;a[0][5]= 8;a[0][6]= 0;a[0][7]= 3;a[0][8]= 0;
a[1][0]= 0; a[1][1]= 4; a[1][2]= 0; a[1][3]= 3;a[1][4]= 0;a[1][5]= 2;a[1][6]= 0;a[1][7]= 9;a[1][8]= 0;
a[2][0]= 1; a[2][1]= 0; a[2][2]= 0; a[2][3]= 0;a[2][4]= 0;a[2][5]= 0;a[2][6]= 0;a[2][7]= 0;a[2][8]= 6;
a[3][0]= 0; a[3][1]= 0; a[3][2]= 8; a[3][3]= 6;a[3][4]= 0;a[3][5]= 3;a[3][6]= 5;a[3][7]= 0;a[3][8]= 0;
a[4][0]= 3; a[4][1]= 0; a[4][2]= 0; a[4][3]= 0;a[4][4]= 0;a[4][5]= 0;a[4][6]= 0;a[4][7]= 0;a[4][8]= 4;
a[5][0]= 0; a[5][1]= 0; a[5][2]= 6; a[5][3]= 7;a[5][4]= 0;a[5][5]= 9;a[5][6]= 2;a[5][7]= 0;a[5][8]= 0;
a[6][0]= 9; a[6][1]= 0; a[6][2]= 0; a[6][3]= 0;a[6][4]= 0;a[6][5]= 0;a[6][6]= 0;a[6][7]= 0;a[6][8]= 2;
a[7][0]= 0; a[7][1]= 8; a[7][2]= 0; a[7][3]= 9;a[7][4]= 0;a[7][5]= 1;a[7][6]= 0;a[7][7]= 6;a[7][8]= 0;
a[8][0]= 0; a[8][1]= 1; a[8][2]= 0; a[8][3]= 4;a[8][4]= 3;a[8][5]= 6;a[8][6]= 0;a[8][7]= 5;a[8][8]= 0;
}

void main()
{
//	resetmatx();
//	printmatx();
//	initialize();
//	preinit();
	printmatx();
	solve();
	printmatx();
}
