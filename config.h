/* See LICENSE file for copyright and license details. */

/* defaults */
#define TERMINAL "st"
#define TERMCLASS "St"


/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const int user_bh            = 0;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char font[]            = "Fira Code Nerd Font bold 10";
static const char dmenufont[]       = "monospace:size=10";
static const char col_black[]       = "#1d2021";
static const char col_black1[]      = "#3c3836";
static const char col_gray[]        = "#928374";
static const char col_red[]         = "#fb4934";
static const char col_green[]       = "#b8bb26";
static const char col_yellow[]      = "#fabd2f";
static const char col_blue[]        = "#83a598";
static const char col_purple[]      = "#d3869b";
static const char col_aqua[]        = "#8ec07c";
static const char col_orange[]      = "#fe8019";
static const char col_white[]       = "#ebdbb2";
static const char col_white1[]      = "#a89984";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray,  col_black, col_black1},
	[SchemeSel]  = { col_black, col_white, col_orange},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                    instance    title       tags mask       isfloating  monitor */
	{ NULL,                     NULL,       NULL,       0,              False,      -1 },
	{ "Anydesk",                NULL,       NULL,       1 << 7,         False,      -1 },
	{ "Bitwarden",              NULL,       NULL,       1 << 8,         False,      -1 },
	{ "Connman-gtk",            NULL,       NULL,       1 << 8,         False,      -1 },
	{ "Emacs",                  NULL,       NULL,       1 << 3,         False,      -1 },
	{ "Ferdi",                  NULL,       NULL,       1 << 2,         False,      -1 },
	{ "firefox",                NULL,       NULL,       1 << 5,         False,      -1 },
	{ "Mailspring",             NULL,       NULL,       1 << 6,         False,      -1 },
	{ "Pcmanfm",                NULL,       NULL,       1 << 3,         False,      -1 },
	{ "qutebrowser",            NULL,       NULL,       1 << 1,         False,      -1 },
	{ TERMCLASS,                NULL,       NULL,       0,              False,      -1 },
	{ TERMCLASS,                NULL,       "lf",       1 << 4,         False,      -1 },
	{ TERMCLASS,                NULL,       "nvim",     1 << 3,         False,      -1 },
    { TERMCLASS,                NULL,       "qalc",     0,              True,       -1 },
	{ "TelegramDesktop",        NULL,       NULL,       1 << 2,         False,      -1 },
	{ "Transmission-remote-gtk",NULL,       NULL,       1 << 7,         False,      -1 },
	{ "Vivaldi-stable",         NULL,       NULL,       1 << 5,         False,      -1 },
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run_history_i", "-c", "-l", "20", "-bw", "3", "-p", "run", NULL};
static const char *termcmd[]  = { TERMINAL , NULL };

#include "focusurgent.c"
static Key keys[] = {
	/* modifier                     key                 function        argument */
	{ MODKEY|ShiftMask,             XK_d,               spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,          spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,               togglebar,      {0} },
	{ MODKEY,                       XK_j,               focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,               focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_numbersign,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_exclam,          incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,               setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,               setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,          zoom,           {0} },
	{ MODKEY,                       XK_Tab,             view,           {0} },
	{ MODKEY,                       XK_apostrophe,      killclient,     {0} },
	{ MODKEY,                       XK_ampersand,       setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_bracketleft,     setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_braceleft,       setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,           setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,           togglefloating, {0} },
	{ MODKEY,                       XK_i,               view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_i,               tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_v,               focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_w,               focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_v,               tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_w,               tagmon,         {.i = +1 } },
    { MODKEY,                       XK_g,               focusurgent,    {0} },
	{ MODKEY|ShiftMask,             XK_q,               quit,           {0} },
	{ MODKEY|ControlMask,           XK_q,               quit,           {1} }, 
	TAGKEYS(                        XK_u,                       0)
	TAGKEYS(                        XK_e,                       1)
	TAGKEYS(                        XK_o,                       2)
	TAGKEYS(                        XK_a,                       3)
	TAGKEYS(                        XK_p,                       4)
	TAGKEYS(                        XK_period,                  5)
	TAGKEYS(                        XK_comma,                   6)
	TAGKEYS(                        XK_semicolon,               7)
	TAGKEYS(                        XK_y,                       8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
