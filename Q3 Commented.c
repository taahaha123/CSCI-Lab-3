#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define SQUAD_SIZE 25
#define MAX_TEAMS 10

// Structure to store date
typedef struct {
    int day, month, year;
} date_t;

// Structure to store player information
typedef struct {
    char name[50];
    int kit_number;
    date_t birthdate;
    char position[30];
} player_t;

// Structure to store team information
typedef struct {
    char name[50];
    player_t players[SQUAD_SIZE];
    int activeSize;
} team_t;

team_t teams[MAX_TEAMS];
int num_teams = 0;

// Function prototypes
void display_menu();
void enroll_club();
void add_player();
void search_update();
void display_club_statistics();
void handle_error(const char *message);

int main() {
    display_menu();
    return 0;
}

// Function to display the menu
void display_menu() {
    int choice;
    while (true) {
        printf("\nMenu:\n");
        printf("1. Enroll Club\n");
        printf("2. Add Player\n");
        printf("3. Search and Update Player\n");
        printf("4. Display Club Statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enroll_club();
                break;
            case 2:
                add_player();
                break;
            case 3:
                search_update();
                break;
            case 4:
                display_club_statistics();
                break;
            case 5:
                printf("Exiting...\n");
                return;
            default:
                handle_error("Invalid choice. Please try again.");
        }
    }
}

// Function to enroll a new club
void enroll_club() {
    if (num_teams >= MAX_TEAMS) {
        handle_error("Maximum number of clubs enrolled.");
        return;
    }

    printf("Enter club name: ");
    scanf(" %[^\n]", teams[num_teams].name);
    teams[num_teams].activeSize = 0;
    num_teams++;
    printf("Club enrolled successfully.\n");
}

// Function to add a player to a team
void add_player() {
    if (num_teams == 0) {
        handle_error("No clubs enrolled yet. Please enroll a club first.");
        return;
    }

    printf("Select a club to add the player:\n");
    for (int i = 0; i < num_teams; i++) {
        printf("%d. %s\n", i + 1, teams[i].name);
    }

    int team_choice;
    printf("Enter club number: ");
    scanf("%d", &team_choice);
    if (team_choice < 1 || team_choice > num_teams) {
        handle_error("Invalid team selection.");
        return;
    }
    team_choice--;  // Adjust for 0-based indexing

    team_t *team = &teams[team_choice];

    if (team->activeSize >= SQUAD_SIZE) {
        handle_error("Team has reached maximum player capacity.");
        return;
    }

    player_t new_player;
    printf("Enter player name: ");
    scanf(" %[^\n]", new_player.name);

    for (int i = 0; i < team->activeSize; i++) {
        if (strcasecmp(team->players[i].name, new_player.name) == 0) {
            handle_error("Duplicate player name found.");
            return;
        }
    }

    printf("Enter kit number (1-99): ");
    scanf("%d", &new_player.kit_number);

    for (int i = 0; i < team->activeSize; i++) {
        if (team->players[i].kit_number == new_player.kit_number) {
            handle_error("Duplicate kit number found.");
            return;
        }
    }

    printf("Enter birthdate (DD MM YYYY): ");
    scanf("%d %d %d", &new_player.birthdate.day, &new_player.birthdate.month, &new_player.birthdate.year);

    printf("Enter position: ");
    scanf(" %[^\n]", new_player.position);

    team->players[team->activeSize++] = new_player;
    printf("Player added successfully.\n");
}

// Function to search for a player and update details
void search_update() {
    if (num_teams == 0) {
        handle_error("No clubs enrolled yet.");
        return;
    }

    char search_name[50];
    int search_kit;
    int option;
    bool found = false;

    printf("Search by: 1. Name  2. Kit Number\n");
    printf("Enter choice: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("Enter player name to search: ");
        scanf(" %[^\n]", search_name);

        for (int i = 0; i < num_teams && !found; i++) {
            for (int j = 0; j < teams[i].activeSize; j++) {
                if (strcasecmp(teams[i].players[j].name, search_name) == 0) {
                    found = true;
                    printf("Player found: %s (Kit: %d) in Team: %s\n", 
                        teams[i].players[j].name, teams[i].players[j].kit_number, teams[i].name);

                    printf("Enter new position: ");
                    scanf(" %[^\n]", teams[i].players[j].position);
                    printf("Position updated successfully.\n");
                    break;
                }
            }
        }
    } else if (option == 2) {
        printf("Enter kit number to search: ");
        scanf("%d", &search_kit);

        for (int i = 0; i < num_teams && !found; i++) {
            for (int j = 0; j < teams[i].activeSize; j++) {
                if (teams[i].players[j].kit_number == search_kit) {
                    found = true;
                    printf("Player found: %s (Kit: %d) in Team: %s\n", 
                        teams[i].players[j].name, teams[i].players[j].kit_number, teams[i].name);

                    printf("Enter new position: ");
                    scanf(" %[^\n]", teams[i].players[j].position);
                    printf("Position updated successfully.\n");
                    break;
                }
            }
        }
    } else {
        handle_error("Invalid search option.");
    }

    if (!found) {
        printf("Player not found.\n");
    }
}

// Function to display club statistics
void display_club_statistics() {
    if (num_teams == 0) {
        handle_error("No clubs enrolled yet.");
        return;
    }

    for (int i = 0; i < num_teams; i++) {
        printf("Club: %s\n", teams[i].name);
        printf("Number of players: %d\n", teams[i].activeSize);

        // Calculate and display the average age of players
        int total_age = 0;
        for (int j = 0; j < teams[i].activeSize; j++) {
            player_t player = teams[i].players[j];
            // Calculate age based on birthdate and current date
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            int age = tm.tm_year + 1900 - player.birthdate.year;
            if (tm.tm_mon + 1 < player.birthdate.month || (tm.tm_mon + 1 == player.birthdate.month && tm.tm_mday < player.birthdate.day)) {
                age--;
            }
            total_age += age;
        }

        double avg_age = teams[i].activeSize > 0 ? (double)total_age / teams[i].activeSize : 0;
        printf("Average age of players: %.2f\n", avg_age);

        // Display player details
        for (int j = 0; j < teams[i].activeSize; j++) {
            player_t player = teams[i].players[j];
            printf("Player %d: Name: %s, Kit Number: %d, Birthdate: %02d-%02d-%d, Position: %s\n",
                   j + 1, player.name, player.kit_number, player.birthdate.day, player.birthdate.month, player.birthdate.year, player.position);
        }
    }
}

// Function to handle errors and display appropriate messages
void handle_error(const char *message) {
    printf("Error: %s\n", message);
}
