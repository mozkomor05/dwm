static char c000000[]                    = "#bc7ad9"; // placeholder value

static char normfgcolor[]                = "#cdd6f4";
static char normbgcolor[]                = "#1e1e2e";
static char normbordercolor[]            = "#45475a";
static char normfloatcolor[]             = "#1e1e2e";

static char selfgcolor[]                 = "#ffffff";
static char selbgcolor[]                 = "#89b4fa";
static char selbordercolor[]             = "#89b4fa";
static char selfloatcolor[]              = "#89b4fa";

static char titlenormfgcolor[]           = "#cdd6f4";
static char titlenormbgcolor[]           = "#1e1e2e";
static char titlenormbordercolor[]       = "#45475a";
static char titlenormfloatcolor[]        = "#1e1e2e";

static char titleselfgcolor[]            = "#A6E3A1";
static char titleselbgcolor[]            = "#1e1e2e";
static char titleselbordercolor[]        = "#1e1e2e";
static char titleselfloatcolor[]         = "#89b4fa";

static char tagsnormfgcolor[]            = "#cdd6f4";
static char tagsnormbgcolor[]            = "#1e1e2e";
static char tagsnormbordercolor[]        = "#45475a";
static char tagsnormfloatcolor[]         = "#1e1e2e";

static char tagsselfgcolor[]             = "#89dceb";
static char tagsselbgcolor[]             = "#45475a";
static char tagsselbordercolor[]         = "#89dceb";
static char tagsselfloatcolor[]          = "#89dceb";

static char hidnormfgcolor[]             = "#F38BA8";
static char hidselfgcolor[]              = "#89dceb";
static char hidnormbgcolor[]             = "#1e1e2e";
static char hidselbgcolor[]              = "#1e1e2e";

static char urgfgcolor[]                 = "#cdd6f4";
static char urgbgcolor[]                 = "#1e1e2e";
static char urgbordercolor[]             = "#74c7ec";
static char urgfloatcolor[]              = "#1e1e2e";

static char *statuscolors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { "#f38ba8",        normbgcolor,			normbordercolor,      normfloatcolor },
	[SchemeSel]          = { "#fab387",        normbordercolor,		selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { "#74c7ec",        normbgcolor,  		titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { "#89b4fa",        normbordercolor,		titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { "#f9e2af",        normbgcolor,			tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { "#cba6f7",        normbordercolor,		tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { "#94e2d5",        normbgcolor,			c000000,              c000000 },
	[SchemeHidSel]       = { "#a6e3a1",        normbordercolor,		c000000,              c000000 },
	[SchemeUrg]          = { "#89dceb",        normbgcolor,			urgbordercolor,       urgfloatcolor },
};