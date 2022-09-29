/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Hack Bold Nerd Font Complete Mono:size=10"};
//static const char *fonts[]          = { "monospace:size=10", "fontawesome:size=15" };
static const char dmenufont[]       = "Hack Bold Nerd Font Complete Mono:size=10";

/* background color */
static const char col_gray1[]		= "#000000";
/* inactive border color */
static const char col_gray2[]		= "#000000";
/* font color */
static const char col_gray3[]		= "#ffffff";
/* current tag and current window font color */
static const char col_gray4[]		= "#00ffff";
/* top bar second color (blue) and active window border color */
static const char col_cyan[]		= "#0e1420";

/* Statusbar right text */
static const char sb_rt[]	= "#ffffff";
/* Statusbar right background */
static const char sb_rb[]	= "#0e1420";
/* Tagbar left selected text */
static const char tb_lst[]	= "#00ffff";
/* Tagbar left selected background */
static const char tb_lsb[]	= "#0e1420";
/* Tagbar left unselected text */
static const char tb_lust[]	= "#ffffff";
/* Tagbar left unselected background */
static const char tb_lusb[]	= "#0e1420";
/* infobar middle  selected text */
static const char ib_mst[]	= "#ffffff";
/* infobar middle  selected background */
static const char ib_msb[]	= "#0e1420";
/* infobar middle  unselected text */
static const char ib_must[]	= "#ffffff";
/* infobar middle  unselected background */
static const char ib_musb[]	= "#0e1420";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },

	/* Statusbar right {text,background,not used but cannot be empty} */
	[SchemeStatus]  = { sb_rt, sb_rb,  "#000000"  },
	/* Tagbar left selected {text,background,not used but cannot be empty} */
	[SchemeTagsSel]  = { tb_lst, tb_lsb,  "#000000"  },
	/* Tagbar left unselected {text,background,not used but cannot be empty} */
	[SchemeTagsNorm]  = { tb_lust, tb_lusb,  "#000000"  },
	/* infobar middle  selected {text,background,not used but cannot be empty} */
	[SchemeInfoSel]  = { ib_mst, ib_msb,  "#000000"  },
	/* infobar middle  unselected {text,background,not used but cannot be empty} */
	[SchemeInfoNorm]  = { ib_must, ib_musb,  "#000000"  }, 
};

/* tagging */
static const char *tags[] = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]", "[9]" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class	instance	title	tags mask	isfloating	monitor */
	{ "Gimp",		NULL,		NULL,	0,		0,		-1 },
	{ "Telegram",		NULL,		NULL,	1 << 8,		0,		-1 },
	{ "Firefox", 		NULL, 		NULL, 	1, 		0, 		-1 },
	{ "Tor Browser", 	NULL, 		NULL, 	2, 		0, 		-1 },
	{ "XVkbd",		NULL, 		NULL, 	0, 		1, 		-1 }
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "",      spiral },
	{ "",      NULL },    /* no layout function means floating behavior */
	//{ "[M]",      monocle },
	//{ "[]=",      tile },    /* first entry is default */
 	//{ "[\\]",      dwindle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define SUPER Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ SUPER,             		KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
<<<<<<< HEAD
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]		= { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]		= { "st", NULL };

/* 
 * i replace this command by easy why sxhkd
 * static const char *nnncmd[]		= {  "st","nnn","-H", NULL };
 * static const char *telecmd[]		= { "telegram-desktop", NULL };
 */

/*
 * use "apules" with firefox because firefox need "pules audio" to detect the input audio 
 *
 * static const char *browsercmd[] 	= { "apulse", "firefox", NULL };
 */


/* im too lazy to write these to sxhkd so i will keep it :P */
static const char *print_screen[] 	= { "/bin/sh", "-c", "maim --format=png | xclip -selection clipboard -t image/png\
	&&  xclip -selection clipboard -t image/png -o > /home/muhammed/Screenshot/clipboard_$(ls /home/muhammed/Screenshot | wc -l).png", NULL };
//static const char *print_active_window[] = { "/bin/sh", "-c", "flameshot gui -p /home/muhammed/Screenshot", NULL };
static const char *print_select_window[] = { "flameshot", "gui","-c","-p", "/home/muhammed/Screenshot", NULL };
static const char *print_active_window[] = { "/bin/sh", "-c", "maim --format=png -u -s | xclip -selection clipboard -t image/png\
	&&  xclip -selection clipboard -t image/png -o > /home/muhammed/Screenshot/clipboard_$(ls /home/muhammed/Screenshot | wc -l).png", NULL };

/*
 * all these commands replaced with sxhkd now 
 * install sxhkd then input $ man sxhkd 
 * or uncommant these command (and keybindings)
 *
 * static const char *alsamixercmd[] 	= { "st", "alsamixer", NULL };
 * static const char *mpv_youtube[] 	= { "/bin/sh", "-c", "mpv $(xsel -o -b)", NULL };
 * static const char *brightness_inc[]	= {  "xbacklight", "-inc", "10", NULL };
 * static const char *brightness_dec[]	= { "xbacklight", "-dec", "10", NULL };
 */ 
static const char *volume_inc[]		= { "amixer", "-q", "sset", "Master", "2dB+", NULL };
static const char *volume_dec[]		= { "amixer", "-q", "sset", "Master", "2dB-", NULL };
static const char *volume_mute[]	= { "amixer", "-q", "sset", "Master", "toggle", NULL };

static const char *xvkbd[]	= { "/bin/sh","-c"," pkill xvkbd || xvkbd &\
	play /home/muhammed/.local/custom/notification_sound", NULL };
//static const char *date_notfi[]	= { "/bin/sh","-c","pkill herbe || herbe \"$(date)\"", NULL };
static const char *date_notfi[]	= { "/bin/sh","-c","pkill herbe || herbe \"$(date)\" &\ 
	play /home/muhammed/.local/custom/notification_sound", NULL };
/* static const char *gimpcmd[]		= { "gimp", NULL };
 * static const char *grapcolor[]		= { "/bin/sh", "-c", "grabc | xclip -selection clipboard", NULL };
 * static const char *vscode[]		= { "code-oss", NULL };
 */


/*
 * by me: you can use
 * static const char *mpv_youtube[] 	= { "/bin/sh", "-c", "mpv $(xclip  -o  -selection clipboard)", NULL };
 */
=======
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
>>>>>>> refs/remotes/origin/master

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	//{ MODKEY,                     XK_g,      spawn,          {.v = grapcolor } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	//{ MODKEY,          	 	XK_n,	   spawn,          {.v = nnncmd } },
	//{ SUPER,          	 	XK_t,	   spawn,          {.v = telecmd } },
	//{ SUPER,          	 	XK_g,	   spawn,          {.v = gimpcmd } },
	//{ SUPER,          	 	XK_b,	   spawn,          {.v = browsercmd } },
	//{ SUPER,          	 	XK_v,	   spawn,          {.v = alsamixercmd } },
	//{ SUPER,          	 	XK_p,	   spawn,          {.v = mpv_youtube } },
	//{ SUPER,		        XK_Home,   spawn,          {.v = brightness_inc } },
	//{ SUPER,		        XK_End,    spawn,          {.v = brightness_dec } },
	//{ SUPER,		        XK_e,      spawn,          {.v = vscode } },
	//{ 0,			        XK_Menu,   spawn,          {.v = termcmd } },
	{ 0,			        0x1008ff13,spawn,          {.v = volume_inc } },
	{ 0,			        0x1008ff11,spawn,          {.v = volume_dec } },
	{ 0,			        0x1008ff12,spawn,          {.v = volume_mute } },
	{ 0,			        XK_Print,  spawn,          {.v = print_select_window } },
	{ ShiftMask,		        XK_Print,  spawn,          {.v = print_screen } },
	{ MODKEY,		        XK_Print,  spawn,          {.v = print_active_window } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	//{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	//{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	//{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Left,   rotatetags,     {.i = -1 } },
	{ MODKEY,                       XK_Right,  rotatetags,     {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[1]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = xvkbd } },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = date_notfi } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
