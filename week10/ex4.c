#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int get_inode (int fd)
{
    struct stat buf;
    int ret;

    ret = fstat(fd, &buf);
    if ( ret <0 ) {
         perror ("fstat");
         return -1;
    }

    return buf.st_ino;
}

char a[100][100];
long long b[100];
int c[100];

int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    int cnt=0;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            long long fd = open ( dir->d_name,O_RDONLY);
            int inode = get_inode (fd);
            b[cnt]=inode;
            strcpy(a[cnt],dir->d_name);
            //printf("%lld %s \n",b[cnt],a[cnt]);
            cnt++;
        }
        closedir(d);
    }
    for(int i=0;i<cnt;i++){
        if(!c[i]){
            int inds = 0;
            for(int j=i+1;j<cnt;j++){
                if(b[j]==b[i])inds++;
            }
            if(inds>0){
                printf("%lld :\n",b[i]);
                printf("%s \n",a[i]);
                for(int j=i+1;j<cnt;j++){
                    if(b[j]==b[i]){
                        c[j]=1;
                        printf("%s \n",a[j]);
                    }
                }
            }
        }
    }


    return(0);
}
