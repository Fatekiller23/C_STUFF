

#define NUMBER '0' /* signal that a number was found */
#define NAME '1' /* signal that a function name was found */

int getop(char []);
void push(double);
double pop();
int getch(void);
void ungetch(int);
void debug(int d);

void duplicate(void);
void show(void);
void swap(void);
void clear(void);
void use_function(char []);