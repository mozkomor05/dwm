void saveSession(void)
{
    FILE *fw = fopen(sessionfile, "w");
    for (Client *c = selmon->clients; c != NULL; c = c->next)
    { // get all the clients with their tags and write them to the file
        fprintf(fw, "%lu %u\n", c->win, c->tags);
    }
    fclose(fw);
}

void restoreSession(void)
{
    // restore session
    FILE *fr = fopen(sessionfile, "r");
    if (!fr)
        return;

    char *str = malloc(23 * sizeof(char)); // allocate enough space for excepted input from text file
    while (fscanf(fr, "%[^\n] ", str) != EOF)
    { // read file till the end
        long unsigned int winId;
        unsigned int tagsForWin;
        int check = sscanf(str, "%lu %u", &winId, &tagsForWin); // get data
        if (check != 2)                                         // break loop if data wasn't read correctly
            break;

        for (Client *c = selmon->clients; c; c = c->next)
        { // add tags to every window by winId
            if (c->win == winId)
            {
                c->tags = tagsForWin;
                break;
            }
        }
    }

    for (Client *c = selmon->clients; c; c = c->next)
    { // refocus on windows
        focus(c);
        restack(c->mon);
    }

    for (Monitor *m = selmon; m; m = m->next) // rearrange all monitors
        arrange(m);

    free(str);
    fclose(fr);

    // delete a file
    remove(sessionfile);
}