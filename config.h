/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating = 1;       /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {"monospace:size=10","NotoColorEmoji:pixelsize=10:antialias=true:autohint=true"};
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
/* static char selbordercolor[]        = "#00ffff"; // cyan */
static char selbordercolor[]        = "#ffffff"; // white
/* static char selbordercolor[]        = "#5cf9cf"; // white */
/* static char selbordercolor[]        = "#iff0000"; // red */
static char selbgcolor[]            = "#004763";
static const char *colors[][3]      = {
		/*               fg         bg         border   */
		[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
		[SchemeSel]  = { selfgcolor, selbgcolor,  selbordercolor  },
};
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class			instance title  tags mask	isfloating	isterminal	noswallow 	monitor */
	{ "st-256color",		NULL,	NULL,	0,       	0,		1,		0,		-1 },
	{ NULL,				"lf",	NULL,	0,       	0,		1,		0,		-1 },
	{ NULL,				NULL,	"lf",	0,       	0,		1,		0,		-1 },
	{ "lf",				NULL,	NULL,	0,       	0,		1,		0,		-1 },
	{ "qBittorrent",		NULL,	NULL,	1 << 8,       	0,		0,		0,		-1 },
	{ "resolve",			NULL,	NULL,	1 << 1,       	0,		0,		0,		-1 },
	{ "discord",			NULL,	NULL,	1 << 1,       	0,		0,		0,		-1 },
	{ NULL,           NULL,	"LINE",	1 << 1,       	0,		0,		0,		-1 },
	{ NULL,           "LINE",	NULL,	1 << 1,       	0,		0,		0,		-1 },
	{ "LINE",           NULL,	NULL,	1 << 1,       	0,		0,		0,		-1 },
	{ "Gwe",			NULL,	NULL,	1 << 7,       	0,		0,		0,		-1 },
	{ "Nvidia-settings",		NULL,	NULL,	1 << 6,       	0,		0,		0,		-1 },
	{ "nvidia-settings",		NULL,	NULL,	1 << 6,       	0,		0,		0,		-1 },
	{ "Microsoft Teams - Preview",	NULL,	NULL,	1 << 7,       	0,		0,		0,		-1 },
	{ "jamesdsp",			NULL,	NULL,	1 << 7,       	0,		0,		0,		-1 },
	{ "teams-for-linux",		NULL,	NULL,	1 << 7,       	0,		0,		0,		-1 },
	{ "obs",			NULL,	NULL,	1 << 1,       	0,		0,		0,		-1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	/* { "><>",      NULL },    /1* no layout function means floating behavior *1/ */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALT Mod1Mask
#define TAGKEYS(KEY,TAG) \ 
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ ALT,			                    KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/usr/bin/zsh", "-c", cmd, NULL } }
#define MAIL "gmail-desktop"
#define VEDITOR "dav"
#define BROWSER "chromium"
#define TORRENT "qbittorrent" 
#define SCREENSHOT "sc"
/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", selbgcolor, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,             		      XK_Return, spawn,          {.v = termcmd } },
	/* { MODKEY,                       XK_f,      togglebar,      {0} }, */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	/* { MODKEY,                    XK_equal,  togglebar,      {0} }, */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_f,      togglefullscr,  {0}},
	/* { MODKEY,                    XK_i,      incnmaster,     {.i = +1 } }, */
	/* { MODKEY,                    XK_d,      incnmaster,     {.i = -1 } }, */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                   		XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {.v = &layouts[0]} },
	/* { MODK                       XK_f,      setlayout,      {.v = &layouts[1]} }, */
	/* { MODKEY,                    XK_equal,  setlayout,      {.v = &layouts[2]} }, */
	/* { MODKEY,                    XK_space,  setlayout,      {0} }, */
	/* { MODKEY|ShiftM,             XK_space,  togglefloating, {0} }, */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ ALT,             		          XK_0,      tag,            {.ui = ~0 } },
	/* { MODKEY,                    XK_comma,  focusmon,       {.i = -1 } }, */
	/* { MODKEY,                    XK_period, focusmon,       {.i = +1 } }, */
	/* { MODKEY|ShiftMask,          XK_comma,  tagmon,         {.i = -1 } }, */
	/* { MODKEY|ShiftMask           XK_period, tagmon,         {.i = +1 } }, */
	/* { ALT,             		      XK_equal,  quit,            {0} }, */ 
	{ MODKEY,			                  XK_w,		    spawn,	       {.v = (const char*[]){ BROWSER, NULL } } },
	{ MODKEY,			                  XK_m,		    spawn,	       {.v = (const char*[]){ MAIL, NULL } } },
	/* { MODKEY,			              XK_d,		    spawn,	       {.v = (const char*[]){ VEDITOR, NULL } } }, */
	{ MODKEY,			                  XK_t,		    spawn,	       {.v = (const char*[]){ TORRENT, NULL } } },
	{ ALT,                       	  XK_s,  		  spawn,	       {.v = (const char*[]){ SCREENSHOT, NULL } } },
	{ MODKEY,			                  XK_minus,	  spawn,	       SHCMD("pamixer -d 1")},
	{ ALT,				                  XK_minus,	  spawn,	       SHCMD("pamixer -d 2")},
	{ MODKEY,			                  XK_equal,	  spawn,	       SHCMD("pamixer -i 1")},
	{ ALT,				                  XK_equal,	  spawn,	       SHCMD("pamixer -i 2")},
	{ ALT,				                  XK_m,		    spawn,	       SHCMD("pamixer -t")},
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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
