/* See LICENSE file for copyright and license details. */

/* defaults */
#define TERMINAL "wezterm"
#define TERMCLASS "org.wezfurlong.wezterm"

/* appearance */
static const unsigned int borderpx = 3; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int systraypinning =
    0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayonleft =
    0; /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails, display systray on the first monitor, False:
          display systray on the last monitor*/
static const int showsystray = 1; /* 0 means no systray */
static const int showbar = 1;     /* 0 means no bar */
static const int topbar = 0;      /* 0 means bottom bar */
static const int user_bh = 0; /* 0 means that dwm will calculate bar height, >=
                                 1 means dwm will user_bh as bar height */
static const char font[] = "Fira Code Nerd Font bold 10";
static const char dmenufont[] = "monospace:size=10";

//                                    // GRUVBOX    //  MATERIAL
static const char col_black[] = "#1E1E2E";  // "#202020";
static const char col_black1[] = "#11111b"; // "#2E2C2B";
static const char col_gray[] = "#6C7086";   // "#928374";
static const char col_red[] = "#fb4934";    // "#ea6962";
static const char col_green[] = "#b8bb26";  // "#a9b665";
static const char col_yellow[] = "#fabd2f"; // "#d8a657";
static const char col_blue[] = "#83a598";   // "#7daea3";
static const char col_purple[] = "#d3869b"; // "#d3869b";
static const char col_aqua[] = "#8ec07c";   // "#89b482";
static const char col_orange[] = "#fab387"; // "#e78a4e";
static const char col_white[] = "#cdd6f4";  // "#D4BE98";
static const char col_white1[] = "#d5c4a1"; // "#a89984";

/* TOKYONIGHT MOON */
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray, col_black, col_black1},
    [SchemeSel] = {col_black, col_white, col_orange},
    // [SchemeNorm] = { "#828bb8", "#222346", "#394b70"},
    // [SchemeSel]  = { "#222346", "#c8d3f5", "#82aaff"},
};

static const XPoint stickyicon[] = {
    {0, 0}, {4, 0}, {4, 8},
    {2, 6}, {0, 8}, {0, 0}}; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb = {
    4, 8}; /* defines the bottom right corner of the polygon's bounding box
              (speeds up scaling) */

/* tagging */
static const char *tags[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */

    /* Tag Specificity:
     *  1 << 0  terminal
     *  1 << 1  browser
     *  1 << 2  editor
     *  1 << 3  tools
     *  1 << 4  misc
     *  1 << 5  todo | notes
     *  1 << 6  browser secondary
     *  1 << 7  social
     *  1 << 8  media
     *  1 << 9  extra
     */

    /* class                instance  title      tags mask  isfloating isfakefullscreen  monitor */
    {NULL, NULL, NULL, 0, 0, 1, -1},
    {"Beeper", NULL, NULL, 1 << 7, 0, 1, -1},
    /* {"Bitwarden", NULL, NULL, 1 << 8, 0, 1, -1}, */
    {"Brave-browser", NULL, NULL, 1 << 6, 0, 1, -1},
    {"Code", NULL, NULL, 1 << 2, 0, 1, -1},
    {"discord", NULL, NULL, 1 << 7, 0, 1, -1},
    {"Emacs", NULL, NULL, 1 << 2, 0, 1, -1},
    /* {"firefox", NULL, NULL, 1 << 1, 0, 1, -1}, */
    /* {"firefox", NULL, "Picture-in-Picture", 0, 1, 0, -1}, */
    {"firefoxdeveloperedition", NULL, NULL, 1 << 1, 0, 1, -1},
    {"firefoxdeveloperedition", NULL, "Picture-in-Picture", 0, 1, 0, -1},
    {"firefoxdeveloperedition-dev", NULL, NULL, 1 << 3, 0, 1, -1},
    /* {"FreeTube", NULL, NULL, 1 << 3, 0, 1, -1}, */
    {"Gimp", NULL, NULL, 1 << 4, 0, 1, -1},
    {"KotatogramDesktop", NULL, NULL, 1 << 7, 0, 1, -1},
    /* {"KeePassXC", NULL, NULL, 0, 1, 1, -1}, */
    {"Morgen", NULL, NULL, 1 << 5, 0, 1, -1},
    {"mpv", NULL, NULL, 1 << 8, 0, 0, -1},
    {"neovim", NULL, NULL, 1 << 2, 0, 1, -1},
    {"Notion", NULL, NULL, 1 << 5, 0, 1, -1},
    {"notion-calendar-electron", NULL, NULL, 1 << 5, 0, 1, -1},
    /* {"photoshop.exe", NULL, NULL, 1 << 4, 0, 1, -1}, */
    /* {"pomotroid", NULL, NULL, 1 << 7, 1, 1, -1}, */
    {"Qalculate-gtk", NULL, NULL, 0, 1, 1, -1},
    {"QML Timer", NULL, NULL, 0, 1, 1, -1},
    /* {"qutebrowser", NULL, NULL, 1 << 1, 0, 1, -1}, */
    {"Ripcord", NULL, "Emoji", 0, 1, 1, -1},
    /* {"Slack", NULL, NULL, 1 << 6, 0, 1, -1}, */
    {"Spotify", "spotify", NULL, 1 << 8, 0, 1, -1},
    {"Stremio", NULL, NULL, 0, 0, 0, -1},
    {"ticktick", NULL, NULL, 1 << 6, 0, 1, -1},
    /* {"thunderbird-beta", NULL, NULL, 1 << 5, 0, 1, -1}, */
    {"todoist-nativefier-409272", NULL, NULL, 1 << 6, 0, 1 - 1},
    {"Todoist", NULL, NULL, 1 << 5, 0, 1 - 1},
    {"VSCodium", NULL, NULL, 1 << 2, 0, 1, -1},
    {TERMCLASS, NULL, NULL, 0, 0, 1, -1},
    {TERMCLASS, NULL, "qalc", 0, 1, 1, -1},
};

/* layout(s) */
static const float mfact = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    0; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},
#define STACKKEYS(MOD, ACTION)                                                 \
  {MOD, XK_j, ACTION##stack, {.i = INC(+1)}},                                  \
      {MOD, XK_k, ACTION##stack, {.i = INC(-1)}},                              \
      {MOD, XK_dollar, ACTION##stack, {.i = PREVSEL}},
/* { MOD, XK_q,     ACTION##stack, {.i = 0 } }, \ */
/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
/* { MOD, XK_x,     ACTION##stack, {.i = -1 } },  */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run_history_i", "-c", "-l", "20", "-bw", "3", "-p", "run", NULL};
static const char *termcmd[] = {TERMINAL, NULL};

#include "focusurgent.c"
static Key keys[] = {
    /* modifier                     key                 function argument */
    /* {MODKEY, XK_d, spawn, {.v = dmenucmd}}, */
    /* {MODKEY, XK_Return, spawn, {.v = termcmd}}, */
    /* {MODKEY, XK_s, spawn, {.v = termcmd}}, */
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_numbersign, incnmaster, {.i = +1}},
    {MODKEY, XK_exclam, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_apostrophe, killclient, {0}},
    {MODKEY, XK_ampersand, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_bracketleft, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_braceleft, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_minus, togglesticky, {0}},
    /* {MODKEY, XK_i, view, {.ui = ~0}}, */
    /* {MODKEY | ShiftMask, XK_i, tag, {.ui = ~0}}, */
    {MODKEY, XK_v, focusmon, {.i = -1}},
    {MODKEY, XK_w, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_v, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_w, tagmon, {.i = +1}},
    {MODKEY, XK_g, focusurgent, {0}},
    {MODKEY | Mod1Mask | ControlMask, XK_q, quit, {1}}, // reload dwm
    {MODKEY | Mod1Mask | ControlMask | ShiftMask, XK_BackSpace, quit, {0}},
    STACKKEYS(MODKEY, focus) STACKKEYS(MODKEY | ShiftMask, push)
        TAGKEYS(XK_u, 0) TAGKEYS(XK_e, 1) TAGKEYS(XK_o, 2) TAGKEYS(XK_a, 3)
            TAGKEYS(XK_i, 4) TAGKEYS(XK_p, 5) TAGKEYS(XK_period, 6)
                TAGKEYS(XK_comma, 7) TAGKEYS(XK_semicolon, 8) TAGKEYS(XK_y, 9)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
