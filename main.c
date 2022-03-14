#include "header.h"

int main(int argc, char **argv)
{

    int Sflag = 0;
    int tflag = 0;
    // int fflag = 0;
    int eflag = 0;
    char *svalue = NULL;
    long int srvalue = 0;
    char *fvalue = "\0";
    char *tvalue = NULL;
    int index;
    int c;
    char *trvalue = NULL;
    strcpy(pathgetter, " ");
    ui=0;
    opterr = 0;

    while ((c = getopt(argc, argv, "Ss:f:t:e:E:")) != -1)
    {
        switch (c)
        {
        case 'S':
            Sflag = 1;
            break;
        case 's':
            svalue = optarg;
            srvalue = atoi(svalue);
            break;
        case 'f':
            // fflag = 1;
            fvalue = optarg;
            break;
        case 't':
            tflag = 1;
            tvalue = optarg;
            break;
        case 'e':
            eflag = 1;
            inputForEeflag(optarg, pathcopy);
            break;
        case 'E':
            eflag = 1;
            inputForEeflag(optarg, pathcopy);
            break;
        case '?':
            if (optopt == 'c')
            {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            }
            else if (isprint(optopt))
            {
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            }
            else
            {
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            }
            return 1;
        default:
            abort();
        }
    }

    if (tflag == 1)
    {
        if (strcmp(tvalue, "f") == 0)
        {
            trvalue = "regular file";
        }
        else if (strcmp(tvalue, "d") == 0)
        {
            trvalue = "directory";
        }
        else
        {
            printf("Please give the value for t flag either f or d");
            exit(-1);
        }
    }
    
    void (*readingDir_ptr)(char *, int, long int, char *, int, char *, int) = &readingDir;
    
    if (argc < 2)
    {
        (*readingDir_ptr)(".", Sflag, srvalue, fvalue, tflag, trvalue, eflag);
    }
    else
    {
        if (optind >= argc)
        {
            (*readingDir_ptr)(".", Sflag, srvalue, fvalue, tflag, trvalue, eflag);
        }
        else
        {
            for (index = optind; index < argc; index++)
            {
                (*readingDir_ptr)(argv[index], Sflag, srvalue, fvalue, tflag, trvalue, eflag);
            }
        }
    }

    void (*inputForEeflag_ptr)(char *, char **)= &inputForEeflag;
   
    if (eflag == 1)
    {
        if (strcmp(pathgetter," ")!=0)
        {
            (*inputForEeflag_ptr)(pathgetter,pathcopy);
    
            int forking = fork();
            if (forking == 0)
            {
                int resulting = execvp(pathcopy[0], pathcopy);
                if (resulting == -1)
                {
                    printf("error");
                }
            }
            else if (forking > 0)
            {
            wait(NULL);
            }
        }
        else
        {
            printf("Please give the valid inputs\n");
        }
        
        
    }
    
    

    return 0;
}