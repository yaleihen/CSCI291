#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SQUAD_SIZE 11
#define NUM_CLUBS 6

typedef struct {
    char playerName[25];
    int kitNumber;
    char club[15];
    struct {
        int playerBDay;
        int playerBMonth;
        int playerBYear;
    } playerAge;
    char playerPosition[20];
} player_t;

typedef struct {
    char clubName[20];
    player_t clubPlayers[SQUAD_SIZE + 1];
    int activeSize;
} club_t;

club_t clubs[NUM_CLUBS];
int clubCount = 0;
int len;

///*** Function Prototypes ***///

void display_menu(); // display menu
void enroll_club(); // enrolling a club
void add_player(); // adding player to a club
void clear_input(); // clear input buffer

int main(void){
    int menuChoice;
    while(1){
        display_menu();
        scanf("%d", &menuChoice);

        clear_input();

        switch(menuChoice){
            case 1:
                enroll_club();
                break;
            case 2:
                add_player();
                break;
            case 3:
                // display_club_stats();
                break;
            case 0:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}

// displays league team application menu
void display_menu(){
    printf("\n###--- League Team Application ---###\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Display Club Statistics\n");
    printf("0. Exit\n\n");
    printf("Select your menu: ");
}

// allows to enroll a new club
void enroll_club(){
    if (clubCount >= NUM_CLUBS) {
        printf("\nCannot enroll more teams, no spots available.\n");
        return;
    }
    
    printf("\nEnter the name of the FC: ");
    fgets(clubs[clubCount].clubName, 20, stdin);
    
    // remove the newline character stored by fgets
    size_t len = strlen(clubs[clubCount].clubName);
    if (len > 0 && clubs[clubCount].clubName[len - 1] == '\n') {
        clubs[clubCount].clubName[len - 1] = '\0';
    }
    printf("Club '%s' has been enrolled successfully.\n", clubs[clubCount].clubName);
    clubCount++;
}

void add_player(){
    if (clubCount == 0){
        printf("No club available.\n");
        return;
    }

    int clubIndex;
    for (int i = 0; i < clubCount; i++){
        printf("\n%d. %s\n", i + 1, clubs[i].clubName);
    }
    printf("Select a club to add player: ");
    scanf("%d", &clubIndex);
    clubIndex--;
    
    if (clubIndex < 0 || clubIndex >= clubCount){
        printf("Invalid club number.\n");
        return;
    }

    if (clubs[clubIndex].activeSize >= SQUAD_SIZE){
        printf("Club '%s' is full.\n", clubs[clubIndex].clubName);
        return;
    }

    player_t newPlayer;
    printf("Enter player name: ");
    scanf(" %[^\n]", newPlayer.playerName);

    printf("Enter player's kit number (1-99): ");
    scanf("%d", &newPlayer.kitNumber);
    
    printf("Enter player's club position: ");
    scanf(" %[^\n]", newPlayer.playerPosition);

    printf("Enter player's birthdate (day month year): ");
    scanf("%d %d %d", 
        &newPlayer.playerAge.playerBDay,
        &newPlayer.playerAge.playerBMonth,
        &newPlayer.playerAge.playerBYear);

    newPlayer.club[0] = '\0';
    strcpy(newPlayer.club, clubs[clubIndex].clubName);
    clubs[clubIndex].clubPlayers[clubs[clubIndex].activeSize++] = newPlayer;

    printf("'%s' has been added to '%s'.\n", newPlayer.playerName, clubs[clubIndex].clubName); 
}

void clear_input(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);  // Discards all characters up to the newline
}
