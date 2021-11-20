/* Key binding functions */
static void defaultgaps(const Arg *arg);
static void incrgaps(const Arg *arg);
/* static void incrigaps(const Arg *arg); */
/* static void incrogaps(const Arg *arg); */
/* static void incrohgaps(const Arg *arg); */
/* static void incrovgaps(const Arg *arg); */
/* static void incrihgaps(const Arg *arg); */
/* static void incrivgaps(const Arg *arg); */
static void togglegaps(const Arg *arg);

/* Layouts */
static void bstack(Monitor *m);
static void centeredmaster(Monitor *m);
static void centeredfloatingmaster(Monitor *m);
	static void deck(Monitor *m);
static void dwindle(Monitor *m);
static void fibonacci(Monitor *m, int s);
static void spiral(Monitor *m);
static void tile(Monitor *);

/* Internals */
static void getgaps(Monitor *m, int *oh, int *ov, int *ih, int *iv, unsigned int *nc);
static void setgaps(int oh, int ov, int ih, int iv);