#include <stdio.h>
#include <stdlib.h>

void show_ui(int arr[3][3]);
int end_game(int arr[3][3]);


void green(void)
{
	printf("\x1b[92m");
}

void red(void)
{
  printf("\x1b[31m");
}

void reset_color(void)
{
	printf("\033[0m");
}



int main(void)
{
	int arr[3][3];
	int k = 1;
	int choice;
	int win1 = 0, win2 = 0;
	int n = 5;
	
	
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) { 
			arr[i][j] = k;
			k++;
		}
	}
	
	show_ui(arr);
	printf("Player 1: X\t\tPlayer 2: O\n");
	
	
	while(1) {
		
		
		
		printf("Choose any number\n");
		
		printf("Player 1: ");
		scanf("%d", &choice);
		
		for(int i = 0; i < 3; ++i) 
			for(int j = 0; j < 3; ++j)
				if(arr[i][j] == choice) 
					arr[i][j] = 1000;
		
		show_ui(arr);
		
		win1 = end_game(arr);
		if(win1 != 0) {
			break;
		}
			
		
		printf("Choose any number\n");
		
		printf("Player 2: ");
		scanf("%d", &choice);
		
		for(int i = 0; i < 3; ++i) 
			for(int j = 0; j < 3; ++j)
				if(arr[i][j] == choice) 
					arr[i][j] = 2000;
			
		show_ui(arr);
		
		win2 = end_game(arr);
		if(win2 != 0) {
			break;
		}
		
		
	}	
	
	if(win1 == 2 || win2 == 2) {
			printf("Match draw!!!\n");
		} else if(win1 == 1) {
			printf("Player 1 wins\n");
		} else if(win2 == 1)
			printf("Player 2 wins\n");
		
		
	return 0;	
}

void show_ui(int arr[3][3])
{
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(arr[i][j] == 1000) {
				red();
				printf("%c%10s", 'X', " ");
				reset_color();
			}
			else if(arr[i][j] == 2000) {
				green();	
				printf("%c%10s", 'O', " ");
				reset_color();
			}
			else	
				printf("%d%10s", arr[i][j], " ");
		}
		puts("\n\n\n");
	}
}
		

/*
 * @return int   1 = win
 *               2 = draw
 *               0 = continue
 */
int  end_game(int arr[3][3])
{
	if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
		return 1;
	else if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
		return 1;
	else if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
		return 1;
	else if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
		return 1;
	else if(arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])
		return 1;
	else if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
		return 1;
	else if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
		return 1;
	else if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
		return 1;
	else if(arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1])
		return 1;
	
	// checking game is  draw or not
	for(int i = 0; i < 3; ++i) 
		for(int j = 0; j < 3; ++j) 
			if(arr[i][j] != 1000 && arr[i][j] != 2000) 
				return 0;
	return 2;
}
	


