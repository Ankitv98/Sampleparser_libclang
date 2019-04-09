struct _gsoc {
char orgname[128];
int year;
};
typedef struct _gsoc GSoC;
char fetch(GSoC *lua);
int getyear(GSoC *lua);
