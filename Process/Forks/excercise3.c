/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : excercise3.c
* Creation Date : 03-02-2016
* Last Modified : Thu 04 Feb 2016 07:27:26 PM CST
* Created By : shiro-saber

KNOW LEARN        .==.
C LANGUAGE       ()''()-.
      .---.       ;--; /
    .'_:___". _..'.  __'.
    |__ --==|'-''' \'...;
   [  ]  :[|       |---\
    |__| I=[|     .'    '.
    / / ____|     :       '._
   |-/.____.'      | :       :
  /___\ /___\      '-'._----'
_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>

// Make a C program that create N number of child process, each child
// wait for a random time, the father will print the PID of each child
// when this finish

int main(int argc, char *argv[])
{
  int n, i, r, state;
  int *pid = (int*)malloc(sizeof(int)*n);

  srand((int)time(NULL));
  
  printf("How many childs?\n");
  scanf("%d", &n);

  printf("Father Process\t\tPid Hijo\n");
  printf("    %d  \t\t\n", getpid());

  for(i = 0; i < n; i++)
  {
    *(pid+i) = fork();
    //r = rand() % 10;

    if(*(pid+i) < 0) 
    {
      printf("Error creating child");
      exit(1);
    } 
    else if (*(pid+i) == 0) 
    {
       //printf("Estamos en el proceso hijo con PID = %d y su padre es PPID = %d \n", getpid(), getppid());
      printf("    %d      \t\t%d\n", getppid(), getpid());
      sleep(rand()%10);
      exit(0);
    } 
  }

  for(i = 0; i < n; i++)
    if (waitpid(*(pid), &state, 0) != -1)
        {
            if (WIFEXITED(state))
                printf("Ya terminó el hijo con PID %d con valor de retorno %d \n", pid, WEXITSTATUS(state));
        }

  return 0;
}
