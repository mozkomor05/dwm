/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 5;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 5;  /* vert inner gap between windows */
static const unsigned int gappoh         = 5;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 5;  /* vert outer gap between windows and screen edge */
static const unsigned int smartgaps      = 0;   /* 1 means no outer gap when there is only one window */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const char sessionfile[]          = "/tmp/dwm-session";
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 24;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 5;  /* vertical padding of bar */
static const int sidepad                 = 5;  /* horizontal padding of bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_BOTTOM_BAR_SLIM;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
//static const char *fonts[]               = { "JetBrainsMono Nerd Font:size=10:style=bold:antialias=true:autohint=true" };
static const char *fonts[]          = { 
	"JetBrainsMono Nerd Font:size=10:antialias=true:autohint=true", 
	"Noto Color Emoji:size=10:antialias=true:autohint=true"  
};

// theme
#include "themes/catppuccin-macho.h"

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype 	= WTYPE "DIALOG",	.isfloating = 1)
	RULE(.wintype	= WTYPE "UTILITY",	.isfloating = 1)
	RULE(.wintype	= WTYPE "TOOLBAR",	.isfloating = 1)
	RULE(.wintype	= WTYPE "SPLASH",	.isfloating = 1)
	RULE(.class		= "Alacritty",		.iscentered = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_pwrl_status,       draw_pwrl_status,       click_pwrl_status,       "powerline_status" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,          draw_wintitle,          click_wintitle,          "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 0;    /* 1 means respect decoration hints */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",	  tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	  bstack },		/* Master on top, slaves on bottom */

	{ "[@]",	  spiral },		/* Fibonacci spiral */
	{ "[\\]",	  dwindle },		/* Decreasing in size right and leftward */

	{ "[D]",	  deck },			/* Master on left, slaves in monocle-like mode on right */
	{ "[M]",      monocle },		/* All windows on top of eachother */

	{ "|M|",	  centeredmaster },		/* Master in middle, slaves on sides */
	{ ">M>",	  centeredfloatingmaster },	/* Same but master floats */
	{ "HHH",      grid },

	{ "><>",	  NULL },			/* no layout function means floating behavior */
	{ NULL,		  NULL },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *prtscrcmd[] = { "flameshot", "gui", NULL};
static const char *termcmd[] = { "alacritty", NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {

	/* modifier                     key            function                argument */

	{ MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_s,          swapfocus,              {.i = -1 } },
	{ MODKEY,                       XK_a,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_z,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_Left,       setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_Right,      setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Up,         setcfact,               {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_Down,       setcfact,               {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,          setcfact,               {0} },
	{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod1Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,		   togglegaps,             {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,		   defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY,						XK_q,		   killclient,			   {0} },

	{ MODKEY,						XK_t,		   setlayout,	           {.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,				XK_t,		   setlayout,			   {.v = &layouts[1]} }, /* bstack */
	{ MODKEY,						XK_y,		   setlayout,	 		   {.v = &layouts[2]} }, /* spiral */
	{ MODKEY|ShiftMask,				XK_y,		   setlayout,	 		   {.v = &layouts[3]} }, /* dwindle */
	{ MODKEY,						XK_u,	       setlayout,	 		   {.v = &layouts[4]} }, /* deck */
	{ MODKEY|ShiftMask,				XK_u,		   setlayout,	 		   {.v = &layouts[5]} }, /* monocle */
	{ MODKEY,						XK_i,		   setlayout,	 		   {.v = &layouts[6]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,				XK_i,		   setlayout,	 		   {.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY,						XK_g,		   setlayout,	 		   {.v = &layouts[8]} }, /* grid */
	{ MODKEY|ShiftMask,				XK_g,		   setlayout,			   {.v = &layouts[9]} }, /* floating */

	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_f,          togglefullscreen,       {0} },
	{ MODKEY|ShiftMask,				XK_f,		   fullscreen,			   {0} },
	{ MODKEY,                       XK_0,		   view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,		   tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period,     tagmon,                 {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     cyclelayout,            {.i = +1 } },
	TAGKEYS(                        XK_1,									0)
	TAGKEYS(                        XK_2,	                     			1)
	TAGKEYS(                        XK_3,   		                   		2)
	TAGKEYS(                        XK_4,                   	  			3)
	TAGKEYS(                        XK_5,                 				    4)
	TAGKEYS(                        XK_6,              			    		5)
	TAGKEYS(                        XK_7,                			    	6)
	TAGKEYS(                        XK_8,              			    		7)
	TAGKEYS(                        XK_9,              			    		8)

	// restart
	{ MODKEY|ShiftMask,             XK_BackSpace,	quit,                   {1} },

	/* Custom commands */
	{ MODKEY,                       XK_d,          spawn,                  SHCMD("~/.config/rofi/launchers/launcher/launcher.sh")}, /* rofi launcher */
	{ MODKEY,			            XK_v,          spawn,                  SHCMD("~/.config/rofi/launchers/greenclip/launcher.sh")}, /* rofi clipboard */

	{ 0, 							XK_Print, 				  spawn, 		   {.v = prtscrcmd } },
	{ 0,							XF86XK_AudioMute,		  spawn,		   SHCMD("pamixer -t; kill -36 $(pidof dwmblocks)") },
	{ 0, 							XF86XK_AudioRaiseVolume,  spawn,		   SHCMD("pamixer --allow-boost -i 3; kill -36 $(pidof dwmblocks)") },
	{ 0, 							XF86XK_AudioLowerVolume,  spawn,		   SHCMD("pamixer --allow-boost -d 3; kill -36 $(pidof dwmblocks)") },
	{ 0, 							XF86XK_AudioPrev,		  spawn,		   SHCMD("playerctl previous") },
	{ 0, 							XF86XK_AudioNext,		  spawn,		   SHCMD("playerctl next") },
	{ 0, 							XF86XK_AudioPause,		  spawn,		   SHCMD("playerctl pause") },
	{ 0, 							XF86XK_AudioPlay,		  spawn,		   SHCMD("playerctl play-pause") },
	{ 0, 							XF86XK_AudioStop,		  spawn,		   SHCMD("playerctl stop") },
	{ 0, 							XF86XK_AudioMicMute,	  spawn,		   SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0,							XF86XK_Sleep,			  spawn,		   SHCMD("systemctl suspend") },
	{ 0, 							XF86XK_MonBrightnessUp,	  spawn,		   SHCMD("xbacklight -inc 15") },
	{ 0, 							XF86XK_MonBrightnessDown, spawn,		   SHCMD("xbacklight -dec 15") },
	{ Mod1Mask,						XK_Shift_L,				  spawn,		   SHCMD("xkb-switch -n; kill -37 $(pidof dwmblocks)") },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },

	{ ClkStatusText,        0,              	 Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              	 Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              	 Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              	 Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              	 Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      	 Button1,        sigdwmblocks,   {.i = 6} },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,			0,					 Button4,		 shiftview,		 {.i = -1} },
	{ ClkTagBar,			0,					 Button5,		 shiftview,		 {.i = 1} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};
