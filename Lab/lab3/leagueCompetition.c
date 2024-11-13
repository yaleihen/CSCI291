/* 
 * code for Question 3, League Team Application
 * 
 * throughout the code, "char" arrays are initialized
 * with +1 the intended amount of elements to store 
 * the "NULL" character, this is purely for syntax reasons
 * */

///*** Headers ***///

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

///*** Constants ***///

// we assume this is a soccer league

#define SQUAD_SIZE 11
#define NUM_CLUBS 6

///*** Structures ***///

// individual players name, kit number, birthdate, age and club position
typedef struct {
    char playerName[25];
    int kitNumber;
    char club[15 + 1];
    struct {
        int playerBDay;
        int playerBMonth;
        int playerBYear;
    } playerAge;
    char playerPosition[20 + 1];
} player_t;

// clubs name, amount of enrolled players and details about each one
typedef struct {
    char clubName[20 + 1];
    player_t clubPlayers[SQUAD_SIZE];
    int activeSize;
} club_t;

// variable to compare against NUM_CLUBS
int clubCount = 0;
// initalize an array "clubs" of type struct club_t with NUM_CLUBS elements
club_t clubs[NUM_CLUBS];

///*** Function Prototypes ***///

void display_menu();              // display menu
void enroll_club();               // enroll a new club
void add_player();                // add player to a club
void display_club_statistics();   // display statistics for each club
void search_update();             // search and update player details
void clear_input_buffer();        // clear input buffer

/* throughout the program, the input buffer is cleared after each scanf.
 * fgets is used to read strings with a whitespace as input from stdin.
 * since fgets stops when a newline '\n' character is read, the input
 * buffer is cleared after any input to clear any lingering '\n' which
 * could accidentally end fgets prematurely, before any input is read */

///*** Main Function ***///

int main(void) {
    int menuChoice;

    while (1) { // menu embedded within inf. loop
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &menuChoice);

        clear_input_buffer();

        switch (menuChoice) {
            case 1:
                enroll_club();
                break;
            case 2:
                add_player();
                break;
            case 3:
                display_club_statistics();
                break;
            case 4:
                search_update();
                break;
            case 0:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}

// displays league team application menu
void display_menu() {
    printf("\n###--- League Team Application ---###\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Display Club Statistics\n");
    printf("4. Search and Update Player\n");
    printf("0. Exit\n");
}

// allows to enroll a new club
void enroll_club() {
    
    club_t newClub; // each new club variable is of type "club_t"
    if (clubCount >= NUM_CLUBS) {
        printf("Cannot enroll more clubs, no spots available.\n");
        return;
    }

    // fgets to read stdin with whitespaces and assign input to "clubName" of "clubs" 
    printf("\nEnter the name of the FC: ");
    fgets(newClub.clubName, 20, stdin);

    /* strlen returns length of the passed string up, size_t is an 
     * integer data type that guarantees containing the size of
     * the string. in the following lines, strlen is used to
     * check if the last character in the string read by fgets
     * is a newline and replaces it with a null character. */

    size_t len = strlen(newClub.clubName);
    if (len > 0 && newClub.clubName[len - 1] == '\n') {
        newClub.clubName[len - 1] = '\0';
    }

    // cycles through currently enrolled clubs for duplicate names
    for (int i = 0; i < clubCount; i++) {
        if (strcmp(clubs[i].clubName, newClub.clubName) == 0) {
            printf("\nThis club has already been enrolled.\n");
            return;
        }
    }

    // if not a duplicate name, the newClub name is copied to "clubs" with strcpy
    strcpy(clubs[clubCount].clubName, newClub.clubName);
    clubs[clubCount].activeSize = 0; // the player count of the newly enrolled club is 0
    printf("\nClub '%s' has been enrolled successfully.\n", clubs[clubCount].clubName);
    clubCount++; // when "enroll_club()" is called again, the next element of "clubs" is used
}

// adds a player to an existing club
void add_player() {
    if (clubCount == 0) {
        printf("No clubs available. Please enroll a club first.\n");
        return;
    }

    int clubIndex; // variable to index selected club by user
    printf("\nAvailable clubs:-\n");
    for (int i = 0; i < clubCount; i++) {
        printf("%d. %s\n", i + 1, clubs[i].clubName);
    }
    printf("\nEnter club number to enroll player: ");
    scanf("%d", &clubIndex);
    clear_input_buffer();

    clubIndex -= 1; // adjust for zero (first element) indexing

    if (clubIndex < 0 || clubIndex >= clubCount) {
        printf("\nInvalid club selection.\n");
        return;
    }

    if (clubs[clubIndex].activeSize >= SQUAD_SIZE) {
        printf("\nClub's squad is full.\n");
        return;
    }

    player_t newPlayer; // each player variable is of type "player_t"
    printf("Enter player name: ");
    fgets(newPlayer.playerName, 25, stdin);
    
    /* the following is an alternative method of appending
     * a null character at the end of an fgets input.
     * strcspn calculates the length of the string before
     * the first occurrence of "\n". */
 
    newPlayer.playerName[strcspn(newPlayer.playerName, "\n")] = '\0';
    printf("Enter kit number (1-99): ");
    scanf("%d", &newPlayer.kitNumber);

    clear_input_buffer();
 
    /* cycles through every players' name and kit number for duplicates */
    for (int i = 0; i < clubs[clubIndex].activeSize; i++) {
        if (clubs[clubIndex].clubPlayers[i].kitNumber == newPlayer.kitNumber) {
            printf("\nKit number already in use. Please choose a unique kit number.\n");
            return;
        }
        if (clubs[clubIndex].clubPlayers[i].playerName == newPlayer.playerName) {
            printf("\nDuplicate name.\n");
            return;
        }
    }

    printf("Enter position: ");
    fgets(newPlayer.playerPosition, 20, stdin);
    newPlayer.playerPosition[strcspn(newPlayer.playerPosition, "\n")] = '\0';

    printf("Enter birth date (day month year): ");
    scanf("%d %d %d", &newPlayer.playerAge.playerBDay, 
                      &newPlayer.playerAge.playerBMonth, 
                      &newPlayer.playerAge.playerBYear);

    clear_input_buffer();

    clubs[clubIndex].clubPlayers[clubs[clubIndex].activeSize++] = newPlayer;
    printf("\nPlayer '%s' has been added to %s.\n", newPlayer.playerName, clubs[clubIndex].clubName);
}

// displays statistics for each club
void display_club_statistics() {
    for (int i = 0; i < clubCount; i++) {
        printf("\nClub: %s\n", clubs[i].clubName);
        printf("Total Players: %d\n", clubs[i].activeSize);

        for (int j = 0; j < clubs[i].activeSize; j++) {
            player_t player = clubs[i].clubPlayers[j];
            printf("Player %d:\n", j + 1);
            printf("  Name: %s\n", player.playerName);
            printf("  Kit Number: %d\n", player.kitNumber);
            printf("  Position: %s\n", player.playerPosition);
            printf("  Birth Date: %02d-%02d-%04d\n",
                   player.playerAge.playerBDay,
                   player.playerAge.playerBMonth,
                   player.playerAge.playerBYear);
        }
    }
}

// allows to search and update player details
void search_update() {
    char playerName[25 + 1]; // temp char array for player search
    bool found = false; // boolean value changing based on player being found or not

    printf("\nEnter the name of the player to search: ");
    fgets(playerName, 25, stdin);
    playerName[strcspn(playerName, "\n")] = '\0';

    // cycles through all clubs
    for (int i = 0; i < clubCount; i++) {
        // cycles through players of each club
        for (int j = 0; j < clubs[i].activeSize; j++) {
            // access the player's data directly
            if (strcasecmp(clubs[i].clubPlayers[j].playerName, playerName) == 0) {
                found = true;
                printf("\nPlayer found in club '%s'\n", clubs[i].clubName);

                printf("Enter new kit number: ");
                scanf("%d", &clubs[i].clubPlayers[j].kitNumber);
                clear_input_buffer();

                printf("Enter new position: ");
                fgets(clubs[i].clubPlayers[j].playerPosition, 20, stdin);
                clubs[i].clubPlayers[j].playerPosition[strcspn(clubs[i].clubPlayers[j].playerPosition, "\n")] = '\0';

                printf("\nPlayer details updated successfully.\n");
                return;
            }
        }
    }

    if (!found) {
        printf("\nPlayer not found.\n");
    }
}

// clears any remaining characters in the input buffer after scanf
void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
