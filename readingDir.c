#include "header.h"

char *filetype(unsigned char type)
{
    char *str;
    switch (type)
    {
    case DT_BLK:
        str = "block device";
        break;
    case DT_CHR:
        str = "character device";
        break;
    case DT_DIR:
        str = "directory";
        break;
    case DT_FIFO:
        str = "named pipe (FIFO)";
        break;
    case DT_LNK:
        str = "symbolic link";
        break;
    case DT_REG:
        str = "regular file";
        break;
    case DT_SOCK:
        str = "UNIX domain socket";
        break;
    case DT_UNKNOWN:
        str = "unknown file type";
        break;
    default:
        str = "UNKNOWN";
    }
    return str;
}

size_t getFileSize(const char *filename, char *file)   
{
    struct stat st;
    char *path = (char *)malloc(10000 * sizeof(char));
    strcpy(path, file);
    strcat(path, "/");
    strcat(path, filename);
    if (stat(path, &st) == -1)
    {
        perror("stat");
        printf("%s", path);
        exit(EXIT_FAILURE);
    }
    return st.st_size;
}

void readingDir(char *kar, int Sflag, long int srvalue, char *fvalue, int tflag, char *trvalue, int eflag)
{
    struct dirent *dirent;
    DIR *parentDir;

    size_t (*getFileSize_ptr)(const char *, char *) = &getFileSize;

    parentDir = opendir(kar);
    if (parentDir == NULL)
    {
        printf("Error opening directory == '%s'\n", kar);
        exit(-1);
    }

    char *temp = malloc(10000);

    int count = 1;
    while ((dirent = readdir(parentDir)) != NULL)
    {
        if (strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0)
        {
            if (((*getFileSize_ptr)(dirent->d_name, kar) >= srvalue) || (strcmp(filetype(dirent->d_type), "directory") == 0))
            {
                if (tflag == 1)
                {
                    if (filetype(dirent->d_type) == trvalue)
                    {
                        if (Sflag == 1)
                        {
                            if (strstr(dirent->d_name, fvalue))
                            {
                                if (eflag == 1)
                                {
                                    if (strcmp(filetype(dirent->d_type), "directory") != 0)
                                    {
                                        strcpy(temp, kar);
                                        strcat(temp, "/");
                                        strcat(temp, dirent->d_name);
                                        strcat(pathgetter, temp);
                                        strcat(pathgetter, " ");
                                        printf("%s [%lu]\n", dirent->d_name, (*getFileSize_ptr)(dirent->d_name, kar));
                                    }
                                }
                                else
                                {
                                    printf("[%d] %s (%s)\t[%lu]\n", count, dirent->d_name, filetype(dirent->d_type), (*getFileSize_ptr)(dirent->d_name, kar));
                                }
                            }
                        }
                        else
                        {
                            if (strstr(dirent->d_name, fvalue))
                            {
                                if (eflag == 1)
                                {
                                    if (strcmp(filetype(dirent->d_type), "directory") != 0)
                                    {
                                        strcpy(temp, kar);
                                        strcat(temp, "/");
                                        strcat(temp, dirent->d_name);
                                        strcat(pathgetter, temp);
                                        strcat(pathgetter, " ");
                                    }
                                }
                                else
                                {
                                    printf("[%d] %s (%s)\n", count, dirent->d_name, filetype(dirent->d_type));
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (Sflag == 1)
                    {
                        if (strstr(dirent->d_name, fvalue))
                        {
                            if (eflag == 1)
                            {
                                if (strcmp(filetype(dirent->d_type), "directory") != 0)
                                {
                                    strcpy(temp, kar);
                                    strcat(temp, "/");
                                    strcat(temp, dirent->d_name);
                                    strcat(pathgetter, temp);
                                    strcat(pathgetter, " ");
                                    printf("%s [%lu]\n", dirent->d_name, (*getFileSize_ptr)(dirent->d_name, kar));
                                }
                            }
                            else
                            {
                                printf("[%d] %s (%s)\t[%lu]\n", count, dirent->d_name, filetype(dirent->d_type), (*getFileSize_ptr)(dirent->d_name, kar));
                            }
                        }
                    }
                    else
                    {
                        if (strstr(dirent->d_name, fvalue))
                        {
                            if (eflag == 1)
                            {
                                if (strcmp(filetype(dirent->d_type), "directory") != 0)
                                {
                                    strcpy(temp, kar);
                                    strcat(temp, "/");
                                    strcat(temp, dirent->d_name);
                                    strcat(pathgetter, temp);
                                    strcat(pathgetter, " ");
                                }
                            }
                            else
                            {
                                printf("[%d] %s (%s)\n", count, dirent->d_name, filetype(dirent->d_type));
                            }
                        }
                    }
                }

                count++;
                if (dirent->d_type == DT_DIR)
                {
                    char *childDir = (char *)malloc(10000 * sizeof(char));
                    strcpy(childDir, kar);
                    strcat(childDir, "/");
                    strcat(childDir, dirent->d_name);
                    readingDir(childDir, Sflag, srvalue, fvalue, tflag, trvalue, eflag);
                    free(childDir);
                }
            }
        }
    }
    closedir(parentDir);
}

void inputForEeflag(char *argument, char *pathcopy[])
{
    parsing = strtok(argument, " ");
    while (parsing != NULL)
    {
        pathcopy[ui] = parsing;
        ui++;
        parsing = strtok(NULL, " ");
    }
}