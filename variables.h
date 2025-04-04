#include <unistd.h>
#include <stdbool.h>
#include <signal.h>


#define SIG_MOTVALIDE SIGUSR1
#define SIG_MOTINVALIDE SIGUSR2
#define SIG_PERTEVIE SIGCHLD
#define SIG_ATONTOUR SIGPWR
#define SIG_PSEUDOVALIDE SIGCONT
#define SIG_PSEUDOINVALIDE SIGRTMIN+1
#define SIG_LISTEJOUEURS SIGTSTP
#define SIG_FINPARTIE SIGRTMIN+2
#define SIG_GAGNE SIGRTMIN+3

#define FICHIER "./dictionnaire.txt"

/* Corps des messages qui transitent, utilisé par le joueur et le jeu */
typedef struct corps {
    pid_t pid; 
    char msg[256];
    int type;
} t_corps;

typedef struct {
    long type;
    t_corps corps;
} t_message;

typedef struct {
    pid_t pid;
    bool vivant;
    char pseudo[50];
    bool tour;
} t_joueur;

