void togglesticky(const Arg *arg)
{
    if (!selmon->sel)
        return;
    setsticky(selmon->sel, !selmon->sel->issticky);
    arrange(selmon);
}

void setsticky(Client *c, int sticky)
{

    if (sticky && !c->issticky)
    {
        XChangeProperty(dpy, c->win, netatom[NetWMState], XA_ATOM, 32,
                        PropModeReplace, (unsigned char *)&netatom[NetWMSticky], 1);
        c->issticky = 1;
    }
    else if (!sticky && c->issticky)
    {
        XChangeProperty(dpy, c->win, netatom[NetWMState], XA_ATOM, 32,
                        PropModeReplace, (unsigned char *)0, 0);
        c->issticky = 0;
        arrange(c->mon);
    }
}
