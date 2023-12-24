#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

struct Player{
    char name[11];
    int level;
    int life;
};

struct keyData{
	int keyX;
	int keyY;
};

struct starData{
	int starX;
	int starY;
};

int x, y, tempx, tempy;
char map[100][100], mapSave[100][100];
char tips[100];
int level = 0, first = 0, truFirst = 0, treshold = 0, gameover = 0, yippe = 0, kcount = 0, box, maxKey;
int i, j, k, l;
int sequence1 = 0, sequence2 = 0, sequence3 = 0;
struct keyData key[100];
struct starData star[100];
struct Player players[12];
struct Player tempos;
FILE *fp;

void collect(){
	for(i = 0; i < maxKey; ++i){
		if(x == key[i].keyX && y == key[i].keyY){
			key[i].keyX = -1; key[i].keyY = -1;
			treshold++;
		}else{
			map[key[i].keyX][key[i].keyY] = '$';
		}
	}
	
	for(i = 0; i < 1; ++i){
		if(x == star[i].starX && y == star[i].starY){
			star[i].starX = -1; star[i].starY = -1;
			yippe++;
		}else{
			map[star[i].starX][star[i].starY] = '*';
		}
	}
	
	if(treshold == maxKey){
		treshold = 0;
		first = 0;
		sequence1 = 0;
		sequence2 = 0;
		sequence3 = 0;
		truFirst = 0;
		kcount = 0;
		level++;
		
		system("cls");
			
		if(level != 9){
			puts("======================================");
			puts("                                      ");
			printf("       |=== On To Level %d ===|           \n",level);
			puts("                                      ");
			puts("======================================");
		}else{
			puts("======================================");
			puts("                                      ");
			puts("       |=== FREEEEDOOOOM!!!! ===|     ");
			puts("                                      ");
			puts("======================================");
			puts("                                      ");
			puts("       CONGRATULATION!!!!!!!!!!!!     ");
			puts("       YOU HAVE ESCAPED LAMAZE!!!     ");
			puts("                                      ");
			puts("======================================");
		}
	}
}

void draw(){
	int p = 0;
	for(p = 0; p < box; ++p){
		fscanf(fp,"%[^\n]\n", mapSave[p]);
	}
}

void creator(){
	
	switch(level){
		case 0: 
			
			//Starting Game
			if(!first){
			treshold = 0;
			first = 1;
			
			tempx = 7; tempy = 7;
			x = tempx; y = tempy;
			
			//Map Limit
			if(!truFirst){
				box = 15;
				draw();
				strcpy(tips,"I am X, whats is this place.... [Move: AWSD] Hmmm i see a shine.. [Keys: $]");
				truFirst = 1;
			}
			
			//Keys Placement
			key[0].keyX = 12; key[0].keyY = 7;
			key[1].keyX = 2; key[1].keyY = 7;
			maxKey = 2;
			
			//No Star :(
			star[0].starX = -2; star[0].starY = -2;
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
			}
			
			collect();
        break;
        
        case 1: 
        	
        	//Starting Game
        	if(!first){
        	treshold = 0;
        	first = 1;
        	strcpy(tips,"Oh another obstacle");
        	system("cls");
			
			tempx = 3; tempy = 2;
			x = tempx; y = tempy;
			
			//Map Limit
			box = 7;
			draw();
			
			//Keys Placement
			key[0].keyX = 3; key[0].keyY = 26;
			maxKey = 1;
			
			//Super Star!
			star[0].starX = 5; star[0].starY = 12;
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
			}
			
			collect();
        break;
        
        case 2: 
        
        	//Starting Game
        	if(!first){
        	treshold = 0;
        	first = 1;
        	strcpy(tips,"This is..Getting harder....");
        	system("cls");
			
			tempx = 7; tempy = 7;
			x = tempx; y = tempy;
			
			//Map Limit
			box = 11;
			draw();
			
			//Keys Placement
			key[0].keyX = 2; key[0].keyY = 2;
			key[1].keyX = 2; key[1].keyY = 14;
			key[2].keyX = 2; key[2].keyY = 21;
			maxKey = 3;
			
			//Super Star!
			star[0].starX = 8; star[0].starY = 12;
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
			}
			
			collect();
        break;
        
        case 3: 
        
        //Starting Game
        if(!first){
        	treshold = 0;
        	first = 1;
        	system("cls");
	
			tempx = 7; tempy = 7;
			x = tempx; y = tempy;
			strcpy(tips,"I feel somethings up in here... [Are Sure That This Is Your True Adventures? Press L To Give Up!]");
			
			//Map Limit
			if(!truFirst){
				box = 13;
				draw();
				truFirst = 1;
			}
			
			//No Star :( (Only After Sequence)
			star[0].starX = -1; star[0].starY = -1;
			
			//Keys Placement
			key[0].keyX = 1; key[0].keyY = 7;
			key[1].keyX = 11; key[1].keyY = 7;
			maxKey = 2;
			}
			
			//TRAPS
			if(treshold == 1 && !sequence1){
				sequence1 = 1;
				//Super Star!
				star[0].starX = 6; star[0].starY = 7;
				strcpy(tips,"OH DEAR Spike! I must be careful..");
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
				
					if(sequence1 == 1){
					for(j = 0; j < 5; ++j){
						map[5][5+j] = '^';
						map[7][5+j] = '^';
					}
					
					for(j = 0; j < 3; ++j){
						map[8][1+j] = '^';
						map[8][11+j] = '^';
					}
				}
			}
			
			collect();
        break;
        	
        case 4: 
        
        //Starting Game
        if(!first){
        	treshold = 0;
        	first = 1;
        	system("cls");
	
			tempx = 6; tempy = 7;
			x = tempx; y = tempy;
			strcpy(tips,"WHAT! WHO ARE YOU!");
			
			//Map Limit
			if(!truFirst){
				box = 13;
				draw();
				truFirst = 1;
			}
			
			//No Star :( (Only After Sequence)
			star[0].starX = -1; star[0].starY = -1;
			
			//Keys Placement
			key[0].keyX = 10; key[0].keyY = 7;
			key[1].keyX = 2; key[1].keyY = 7;
			key[2].keyX = 6; key[2].keyY = 13;
			key[3].keyX = -1; key[3].keyY = -1;
			key[4].keyX = -1; key[4].keyY = -1;
			maxKey = 5;
			}
			
			if(treshold == 2 && !sequence1){
				sequence1 = 1;
				
				tempx = 6; tempy = 15;
				x = tempx; y = tempy;
				
				key[2].keyX = 10; key[2].keyY = 12;
				key[3].keyX = 2; key[3].keyY = 12;
				key[4].keyX = 6; key[4].keyY = 6;
				strcpy(tips,"huh???");
			}
			
			if(treshold == 4 && !sequence2){
				sequence1 = 0;
				sequence2 = 1;
				
				tempx = 10; tempy = 8;
				x = tempx; y = tempy;
				
				key[4].keyX = 2; key[4].keyY = 8;
				star[0].starX = 2; star[0].starY = 5;
				
				strcpy(tips,"Hmph!");
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
				
				if(sequence1 == 1){
					map[6][14] = '#';
					map[6][5] = 'Y';
					
					for(j = 0; j < 6; ++j){
						map[8][11+j] = '^';
						map[4][11+j] = '^';
						map[3+j][18] = '^';
					}
					
					map[9][18] = '^';
					map[2][14] = '^';
					map[10][14] = '^';
				}
				
				if(sequence2 == 1){
					map[6][14] = 'Y';
					map[6][5] = '#';
					
					for(j = 0; j < 6; ++j){
						map[8][4+j] = '^';
						map[3+j][2] = '^';
					}
					
					for(j = 0; j < 4; ++j){
						map[2+j][6] = '^';
						map[2+j][3] = '^';
					}
					
					map[3][5] = '^';
					map[7][7] = '^';
					map[3][8] = '^';
				}
			}
			
			collect();
        break;
        
        case 5: 
        
        	//Starting Game
        	if(!first){
        	treshold = 0;
        	first = 1;
        	strcpy(tips,"That was wierd... as if i saw myself....");
        	system("cls");
			
			tempx = 7; tempy = 4;
			x = tempx; y = tempy;
			
			if(!truFirst){
				box = 9;
				draw();
				truFirst = 1;
			}
			
			//Keys Placement
			key[0].keyX = 1; key[0].keyY = 6;
			key[1].keyX = 4; key[1].keyY = 24;
			key[2].keyX = 3; key[2].keyY = 34;
			maxKey = 3;
			
			star[0].starX = -1; star[0].starY = -1;
			}
			
			if(treshold == 2 && !sequence1){
				sequence1 = 1;
				k = 0;
				kcount = 1;
				strcpy(tips,"Ive heard.. IS THAT A LAZER?!?!? [Press space to dodge! Example: ~~X~~ is better to press that!]");
				
				star[0].starX = 6; star[0].starY = 11;
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
				
				if(sequence1 == 1){
					map[1][20] = '|';
					map[2][20] = '|';
					map[6][9] = '-';
					map[6][10] = '-';
					map[6][12] = '-';
				
					switch (k){
						case 0:
						case 1:
							for(j = 0; j < 15; ++j){
								map[1][21+j] = '!';
								map[2][21+j] = '!';
							}
						break;
						
						case 2:
						case 3:
							for(j = 0; j < 15; ++j){
								map[1][21+j] = '~';
								map[2][21+j] = '~';
							}
						break;
						
						default:
							k = 0;
						break;
					}
				}
			}
			
			collect();
        break;
        
        case 6: 
        
        	//Starting Game
        	if(!first){
        	treshold = 0;
        	first = 1;
        	kcount = 1;
        	strcpy(tips,"What is.. this lair...");
        	system("cls");
			
			tempx = 5; tempy = 7;
			x = tempx; y = tempy;
			
			if(!truFirst){
				box = 14;
				draw();
				truFirst = 1;
			}
			
			//Keys Placement
			key[0].keyX = 3; key[0].keyY = 25;
			key[1].keyX = 1; key[1].keyY = 23;
			key[2].keyX = 1; key[2].keyY = 27;
			maxKey = 3;
			
			//Super Star!
			star[0].starX = -1; star[0].starY = -1;
			}
			
			if(treshold == 1 && !sequence1){
				sequence1 = 1;
				k = 0;
				strcpy(tips,"Oh dear!");
				key[1].keyX = 3; key[1].keyY = 7;
				key[2].keyX = 5; key[2].keyY = 7;
			}
			
			if(treshold == 2 && !sequence2){
				sequence2 = 1;
				
				star[0].starX = 7; star[0].starY = 25;
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
				
				if(sequence1 == 0){
					switch (k){
						case 0:
						case 1:
							for(j = 0; j < 28; ++j){
							map[12][6+j] = '!';
							}
						break;
							
						case 2:
						case 3:
							for(j = 0; j < 28; ++j){
								map[12][6+j] = '~';
							}
							break;
							
						default:
							k = 0;
						break;
					}
				}
				
				if(sequence1 == 1){
					map[2][7] = '-';
					switch (k){
						case 0:
							for(j = 0; j < 17; ++j){
								map[4][17+j] = '!';
								map[5][17+j] = '!';
								map[6][17+j] = '!';
								map[8][17+j] = '~';
								map[9][17+j] = '~';
								map[10][17+j] = '~';
							}
						break;
						
						case 1:
							for(j = 0; j < 17; ++j){
								map[4][17+j] = '~';
								map[5][17+j] = '~';
								map[6][17+j] = '~';
							}
						break;
						case 2:
							for(j = 0; j < 17; ++j){
								map[4][17+j] = '~';
								map[5][17+j] = '~';
								map[6][17+j] = '~';
								map[8][17+j] = '!';
								map[9][17+j] = '!';
								map[10][17+j] = '!';
							}
						break;
						
						case 3:
							for(j = 0; j < 17; ++j){
								map[8][17+j] = '~';
								map[9][17+j] = '~';
								map[10][17+j] = '~';
							}
						break;
						
						default:
							k = 0;
						break;
					}
				}
			}
			
			collect();
        break;
        
        case 7: 
        
        	//Starting Game
        	if(!first){
        	treshold = 0;
        	first = 1;
        	kcount = 1;
        	strcpy(tips,"I need to get out of this mess....patiently....");
        	system("cls");
			
			tempx = 1; tempy = 4;
			x = tempx; y = tempy;
			
			if(!truFirst){
				box = 16;
				draw();
				truFirst = 1;
			}
		
			//Keys Placement
			key[0].keyX = 14; key[0].keyY = 4;
			key[1].keyX = 7; key[1].keyY = 1;
			maxKey = 2;
			
			//Super Star!
			star[0].starX = -1; star[0].starY = -1;
			}
			
			if(treshold == 1 && !sequence1){
				sequence1 = 1;
				strcpy(tips,"I need to get home.... focus...");
				star[0].starX = 1; star[0].starY = 4;
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
				
				switch (k){
					case 0:
					case 1:
						for(j = 0; j < 26; ++j){
							map[5][5+j] = '~';
							map[6][5+j] = '~';
							map[9][5+j] = '~';
							map[10][5+j] = '~';
						}
						
						if(sequence1 == 1 && k == 1){
							for(j = 0; j < 29; ++j){
								map[7][3+j] = '!';
								map[8][3+j] = '!';
							}
						}
					break;
					
					case 2:
						for(j = 0; j < 24; ++j){
							map[1][7+j] = '!';
							map[2][7+j] = '!';
							map[13][7+j] = '!';
							map[14][7+j] = '!';
						}
						
						for(j = 0; j < 26; ++j){
							map[5][5+j] = '~';
							map[6][5+j] = '~';
							map[9][5+j] = '~';
							map[10][5+j] = '~';
						}
						
						if(sequence1 == 1){
							for(j = 0; j < 29; ++j){
								map[7][3+j] = '~';
								map[8][3+j] = '~';
							}
						}
					break;
					
					case 3:	
					case 4:
						for(j = 0; j < 24; ++j){
							map[1][7+j] = '~';
							map[2][7+j] = '~';
							map[13][7+j] = '~';
							map[14][7+j] = '~';
						}
						
						if(sequence1 == 1 && k == 3){
							for(j = 0; j < 29; ++j){
								map[7][3+j] = '~';
								map[8][3+j] = '~';
							}
						}
					break;
					
					case 5:
						for(j = 0; j < 26; ++j){
							map[5][5+j] = '!';
							map[6][5+j] = '!';
							map[9][5+j] = '!';
							map[10][5+j] = '!';
						}
						
						for(j = 0; j < 24; ++j){
							map[1][7+j] = '~';
							map[2][7+j] = '~';
							map[13][7+j] = '~';
							map[14][7+j] = '~';
						}
					break;
							
					default:
						k = 0;
					break;
				}
			}
			
			collect();
        break;
        
        case 8: 
        
        	//Starting Game
        	if(!first){
        	treshold = 0;
        	first = 1;
        	kcount = 1;
        	strcpy(tips,". . . You.... WHY you trapped me HERE!");
        	system("cls");
			
			tempx = 19; tempy = 11;
			x = tempx; y = tempy;
			
			if(!truFirst){
				box = 24;
				draw();
				truFirst = 1;
			}
			
			//Keys Placement
			key[0].keyX = 4; key[0].keyY = 11;
			key[1].keyX = -1; key[1].keyY = -1;
			key[2].keyX = -1; key[2].keyY = -1;
			key[3].keyX = -1; key[3].keyY = -1;
			key[4].keyX = -1; key[3].keyY = -1;
			maxKey = 5;
			
			//Super Star!
			star[0].starX = -1; star[0].starY = -1;
			}
			
			if(treshold == 1 && sequence1 == 0){
				sequence1 = 1;
				k = 0;
				strcpy(tips,"I will stand till i die!");
				key[1].keyX = 22; key[1].keyY = 11;
			}
			
			if(treshold == 2 && sequence1 == 1){
				sequence1 = 2;
				k = 0;
				strcpy(tips,"I dont get it...... why you pick me than anybody else?");
				key[2].keyX = 4; key[2].keyY = 11;
			}
			
			if(treshold == 3 && sequence1 == 2){
				sequence1 = 3;
				k = 0;
				strcpy(tips,"ITS TIME TO END THIS!");
				key[3].keyX = 22; key[3].keyY = 11;
			}
			
			if(treshold == 4 && sequence1 == 3){
				sequence1 = 4;
				k = 0;
				kcount = 0;
				strcpy(tips,".... Im... free...");
				key[4].keyX = 1; key[4].keyY = 21;
				star[0].starX = 1; star[0].starY = 1;
			}
			
			//Draw
			for(i = 0; i < box; ++i){
				strcpy(map[i], mapSave[i]);
				
				if(sequence1 == 0){
					for(j = 0; j < 19; ++j){
						map[7][2+j] = '^';
						map[8][2+j] = '^';
						map[10][2+j] = '^';
						map[11][2+j] = '^';
						map[13][2+j] = '^';
						map[14][2+j] = '^';
						map[16][2+j] = '^';
						map[17][2+j] = '^';
					}
					
					for(j = 0; j < 4; ++j){
						map[7][13+j] = '-';
						map[8][13+j] = '-';
						map[10][3+j] = '-';
						map[11][3+j] = '-';
						map[13][7+j] = '-';
						map[14][7+j] = '-';
						map[16][9+j] = '-';
						map[17][9+j] = '-';
					}
				}
				
				if(sequence1 == 1 || sequence1 == 2){
					for(j = 0; j < 19; ++j){
						map[6][2+j] = '^';
						map[7][2+j] = '^';
						map[9][2+j] = '^';
						map[10][2+j] = '^';
						map[12][2+j] = '^';
						map[13][2+j] = '^';
						map[15][2+j] = '^';
						map[16][2+j] = '^';
						map[18][2+j] = '^';
						map[19][2+j] = '^';
					}
					
					for(j = 0; j < 2; ++j){
						map[6][3+j] = '-';
						map[7][4+j] = '-';
						map[9][13+j] = '-';
						map[10][14+j] = '-';
						map[12][2+j] = '-';
						map[13][3+j] = '-';
						map[15][15+j] = '-';
						map[16][16+j] = '-';
						map[18][3+j] = '-';
						map[19][4+j] = '-';
					}
				}
				
				if(sequence1 == 3){
					for(j = 0; j < 19; ++j){
						map[7][2+j] = '^';
						map[8][2+j] = '^';
						map[9][2+j] = '^';
						map[11][2+j] = '^';
						map[12][2+j] = '^';
						map[13][2+j] = '^';
						map[15][2+j] = '^';
						map[16][2+j] = '^';
						map[17][2+j] = '^';
					}
					
					for(j = 0; j < 2; ++j){
						map[7][2+j] = '-';
						map[8][3+j] = '-';
						map[9][4+j] = '-';
						map[11][16+j] = '-';
						map[12][17+j] = '-';
						map[13][18+j] = '-';
						map[15][2+j] = '-';
						map[16][3+j] = '-';
						map[17][4+j] = '-';
					}
				}
				
				if(sequence1 == 4){
					for(j = 0; j < 19; ++j){
						map[1][2+j] = '-';
						map[2][2+j] = '-';
						map[3][2+j] = '-';
						map[4][2+j] = '-';
					}
					map[7][11] = 'Y';
					map[7][12] = '@';
					map[7][10] = '@';
					map[6][11] = '@';
					map[8][11] = '@';
					
					map[7][15] = '#';map[7][18] = '#';map[7][3] = '#';
					map[6][3] = '#';map[6][9] = '#';
					map[8][7] = '#';map[8][10] = '#';
					map[5][6] = '#';map[5][10] = '#';map[5][15] = '#';
					map[4][4] = '#';map[4][8] = '#';map[4][3] = '#';
				}
				
				if(sequence1 != 4){
					switch (k){
						case 0:	
							for(j = 0; j < 19; ++j){
								map[5][2+j] = '!';
								map[6][2+j] = '!';
							}
						break;
						
						case 17:
							if(sequence1 == 0 || sequence1 == 2){
								k = 0;
							}
						break;
						
						case 18 ... 25:
						break;
						
						default:
							for(j = 0; j < 19; ++j){
								map[5+k-1][2+j] = '=';
								map[6+k-1][2+j] = '=';
							}
						break;
					}
				}
				
				if(sequence1 == 1 || sequence1 == 3){
					switch (k){
						case 0 ... 8:	
						break;
						
						case 9:	
							for(j = 0; j < 19; ++j){
								map[5][2+j] = '!';
								map[6][2+j] = '!';
							}
						break;
		
						case 26:
							k = 0;
						break;
						
						default:
							for(j = 0; j < 19; ++j){
								map[5+k-10][2+j] = '=';
								map[6+k-10][2+j] = '=';
							}
						break;
					}
				}
				
				if(sequence1 == 2){
					switch (k){
						case 10:
							if(x <= 21 && x >= 6){
								l = x;
							}else{
								l = 10;
							}
							
							map[l][21] = '=';
							map[l][22] = 'O';
							map[l-1][21] = '=';
							map[l-1][22] = 'O';
							for(j = 0; j < 19; ++j){
								map[l][2+j] = '!';
								map[l-1][2+j] = '!';
							}
						break;
						
						case 11:
						case 12:
							map[l][21] = '=';
							map[l][22] = 'O';
							map[l-1][21] = '=';
							map[l-1][22] = 'O';
							for(j = 0; j < 19; ++j){
								map[l][2+j] = '~';
								map[l-1][2+j] = '~';
							}
						break;
						
						default:
							if(x <= 21 && x >= 6){
								l = x;
							}else{
								l = 10;
							}
							map[l][21] = '=';
							map[l][22] = 'O';
							map[l-1][21] = '=';
							map[l-1][22] = 'O';
						break;
					}
				}
				
				if(sequence1 == 3){
					switch (k){
						case 18:
							if(x <= 20 && x >= 5){
								l = x;
							}else{
								l = 10;
							}
							map[l][21] = '=';
							map[l][22] = 'O';
							map[l+1][21] = '=';
							map[l+1][22] = 'O';
							for(j = 0; j < 19; ++j){
								map[l][2+j] = '!';
								map[l+1][2+j] = '!';
							}
						break;
						
						case 19:
						case 20:
							map[l][21] = '=';
							map[l][22] = 'O';
							map[l+1][21] = '=';
							map[l+1][22] = 'O';
							for(j = 0; j < 19; ++j){
								map[l][2+j] = '~';
								map[l+1][2+j] = '~';
							}
						break;
						
						default:
							if(x <= 20 && x >= 5){
								l = x;
							}else{
								l = 10;
							}
							map[l][21] = '=';
							map[l][22] = 'O';
							map[l+1][21] = '=';
							map[l+1][22] = 'O';
						break;
					}
				}
			}
			
			collect();
        break;
        
        default: 
        	gameover = 1; 
        break;
	}

}

void input() 
{ 
	
    switch (getch()) { 
    case 'a': 
		tempy--;
    break; 
    case 's': 
    	tempx++;
    break; 
    case 'd': 
        tempy++;
    break; 
    case 'w': 
        tempx--;
    break; 
    case 'l': 
        gameover = 1;
        system("cls");
    break;
    case '0': 
		treshold = maxKey;
    break; 
    default: 
    break; 
    }
    
    if(kcount){
    	k++;
	}

    if(yippe == -1){
    	gameover = 1;
	}
    
    if(map[tempx][tempy] == '#'){
    	tempx = x;
		tempy = y;
	}else{
		x = tempx;
    	y = tempy;
	}
	
	if(map[x][y] == '^' || map[x][y] == '~' || map[x][y] == '=' || map[x][y] == 'O'){
		yippe -= 1;
		first = 0;
		sequence1 = 0;
		sequence2 = 0;
		sequence3 = 0;
		kcount = 0;
		system("cls");
	    puts("======================================");
		puts("               OUCH!                  ");
		puts("======================================");
		Sleep(300);
	}
    system("cls");
} 


int main(void){
	int neva = 0;
	while(!neva){
	char menu = '0';
	fp = fopen("map.txt", "r");
		puts("======================================");
		puts("     _         __  __                 ");
		puts("    | |   __ _|  \\/  |__ _ ______    ");
		puts("    | |__/ _` | |\\/| / _` |_ / -_)   ");
		puts("    |____\\__,_|_|  |_\\__,_/__\\___| ");
		puts("                               v.Final");
		puts("======================================");
		puts("         Press A To Start             ");
		puts("       Press Z For LeaderBoard        ");
		puts("           Press X To Exit            ");
		puts("======================================");
		scanf("%c", &menu);
		
		switch(menu){
		case 'x':
			neva = 1;
		break;
			
		case 'z':
			system("cls");
			printf("\nLeaderboard:\n");
			printf("-1 Mean They Lose All Their Life\n");
			printf("======================================\n");
			printf("Name\t\tLevel\t\tLife\n");
			printf("======================================\n");
			
			for(i = 0; i < 10; i++) {
				printf("%s\t\t%d\t\t%d\n", players[i].name, players[i].level, players[i].life);
			}
			
			scanf("%d", &tempos.life);
			tempos.life = 0;
		break;	
		
		case 'a':
			system("cls");
			while (!gameover) { 
				
				creator();
		        
		        map[x][y] = 'X';
		        
				if(level == 8){
					switch(sequence1){
						case 0:
							puts("Its none of your business... Xreefen");
						break;
						
						case 1:
							puts("I doubt about it");
						break;
						
						case 2:
							puts("Its all about science... You have been picked to be..... a star");
						break;
						
						case 3:
							puts("SYSTEM: !!SYSTEM OVERLOAD!!");
							puts("Initiate full assult");
						break;
						
						case 4:
							puts("!!BOOOM!!");
							puts("AUgh!......");
						break;
					}
					
				}
					
				for(i = 0; i < box; ++i){
					printf("%s\n",map[i]);
				}
				
				printf("Coordinates: %d %d\n", x, y);
				printf("Life: %d\n", yippe);
				printf("%s\n", tips);	
				
				input();
		    }
		    system("cls");
	    break;
	    
	    default:
	    break;
		}
		system("cls");
		if(gameover == 1){
			players[11].level = level;
			players[11].life = yippe;
		   	fclose(fp);
		   	first = 0;
			treshold = 0;
			sequence1 = 0;
			sequence2 = 0;
			sequence3 = 0;
			truFirst = 0;
			yippe = 0;
			level = 0;
			gameover = 0;
			kcount = 0;
			puts("");
			puts("");
			puts("");
		    puts("======================================");
			puts("             GAME OVER!               ");
			puts("======================================");
			puts("");
			puts("");
			puts("");
			printf("!!Max 10 char, and no space!!\n");
			printf("Player Name: ");
			scanf("%s", players[11].name);getchar();
			
			for(i = 0; i < 12 - 1; i++) {
        		for(j = 0; j < 12 - i - 1; j++) {
            		if (players[j].level < players[j + 1].level) {
                		tempos = players[j];
                		players[j] = players[j + 1];
                		players[j + 1] = tempos;
           			}
        		}
    		}
    		system("cls");
		}
		Sleep(1000);
	}
	
    puts("======================================");
	puts("   Thank You for Playing Our Game.    ");
	puts("          Shane, Rama, Nisa           ");
	puts("            Created 2023              ");
	puts("======================================");

	return 0;
}
