#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_TEAMS 5
#define SQUAD_SIZE 11

// Define structs for player and team
typedef struct {
    char name[25];
    int kit_number;
    char club[30];
    struct {
        int day;
        int month;
        int year;
    } age;
    char position[15];
} player_t;

typedef struct {
    char name[20];
    player_t players[SQUAD_SIZE];
    int active_size;
} team_t;

// Function prototypes
void display_menu();
void enroll_club(team_t teams[], int *num_teams);
void add_player(team_t teams[], int num_teams);
void display_club_statistics(const team_t teams[], int num_teams);
bool is_kit_number_unique(const team_t *team, int kit_number);
bool is_name_unique(const team_t *team, const char *name);

int main() {
    team_t teams[NUM_TEAMS];
    int num_teams = 0;
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enroll_club(teams, &num_teams);
                break;
            case 2:
                add_player(teams, num_teams);
                break;
            case 3:
                display_club_statistics(teams, num_teams);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to display the main menu
void display_menu() {
    printf("\n---- League Team Application Menu ----\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Display Club Statistics\n");
    printf("0. Exit\n");
}

// Function to enroll a new club
void enroll_club(team_t teams[], int *num_teams) {
    if (*num_teams >= NUM_TEAMS) {
        printf("Maximum number of teams reached.\n");
        return;
    }

    printf("Enter the name of the new club: ");
    scanf(" %[^\n]", teams[*num_teams].name);
    teams[*num_teams].active_size = 0;
    (*num_teams)++;

    printf("Club '%s' has been enrolled successfully.\n", teams[*num_teams - 1].name);
}

// Function to add a player to a club
void add_player(team_t teams[], int num_teams) {
    if (num_teams == 0) {
        printf("No clubs available. Please enroll a club first.\n");
        return;
    }

    int club_index;
    printf("Select a club to add a player:\n");
    for (int i = 0; i < num_teams; i++) {
        printf("%d. %s\n", i + 1, teams[i].name);
    }
    printf("Enter club number: ");
    scanf("%d", &club_index);
    club_index--;

    if (club_index < 0 || club_index >= num_teams) {
        printf("Invalid club selection.\n");
        return;
    }

    if (teams[club_index].active_size >= SQUAD_SIZE) {
        printf("Squad size for %s is full.\n", teams[club_index].name);
        return;
    }

    player_t new_player;
    printf("Enter player name: ");
    scanf(" %[^\n]", new_player.name);

    printf("Enter kit number (1-99): ");
    scanf("%d", &new_player.kit_number);
    if (!is_kit_number_unique(&teams[club_index], new_player.kit_number)) {
        printf("Kit number already in use. Please choose a unique kit number.\n");
        return;
    }

    printf("Enter position: ");
    scanf(" %[^\n]", new_player.position);

    printf("Enter birth date (day month year): ");
    scanf("%d %d %d", &new_player.age.day, &new_player.age.month, &new_player.age.year);

    new_player.club[0] = '\0';
    strcpy(new_player.club, teams[club_index].name);
    teams[club_index].players[teams[club_index].active_size++] = new_player;

    printf("Player '%s' has been added to %s successfully.\n", new_player.name, teams[club_index].name);
}

// Function to check if a kit number is unique in a team
bool is_kit_number_unique(const team_t *team, int kit_number) {
    for (int i = 0; i < team->active_size; i++) {
        if (team->players[i].kit_number == kit_number) {
            return false;
        }
    }
    return true;
}

// Function to display club statistics
void display_club_statistics(const team_t teams[], int num_teams) {
    for (int i = 0; i < num_teams; i++) {
        printf("\nClub: %s\n", teams[i].name);
        printf("Total Players: %d\n", teams[i].active_size);

        for (int j = 0; j < teams[i].active_size; j++) {
            printf("Player %d:\n", j + 1);
            printf("  Name: %s\n", teams[i].players[j].name);
            printf("  Kit Number: %d\n", teams[i].players[j].kit_number);
            printf("  Position: %s\n", teams[i].players[j].position);
            printf("  Birth Date: %02d-%02d-%04d\n",
                   teams[i].players[j].age.day,
                   teams[i].players[j].age.month,
                   teams[i].players[j].age.year);
        }
    }
}

