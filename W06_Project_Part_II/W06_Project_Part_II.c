/*
 ============================================================================
 Name        : W06_Final_Project_Part_II
 Author      : Collin Squires
 Description : This program keeps a task list and sets a one hour timer for
    the user.  When the timer goes off, it reminds the user to take a break
    from their work.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
//#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    char taskList[20][40];
    bool finished = false;
    int taskNumber = 0;

    printf("Welcome to the task timer.\n");
    printf("You put in a list of tasks you need to accomplish and\nthis program will remind you to take a break every once in a while.\n");
    printf("\n");
    printf("First off, let's get a list of tasks you need to do.  You may input up to 20.\n");

    do
    {
        char response[3];
        printf("Please type in a task: ");
        fgets(taskList[taskNumber], 40, stdin);

        if (taskNumber < 20)
        {
            do
            {
                printf("Would you like to add another task (y/n)? ");
                fgets(response, 3, stdin);

                if (response[0] == 'y')
                {
                    taskNumber++;
                }
                else if (response[0] == 'n')
                {
                    finished = true;
                }
                else
                {
                    printf("That isn't a valid response.\n");
                }
            } while (response[0] != 'y' && response[0] != 'n');
        }

        else
        {
            finished = true;
        }

    } while (!finished);



    bool cont = true;
    char continuingResponse[3];

    do
    {
        printf("\nTasks\n");
        for (int i = 0; i < taskNumber + 1; i++)
        {
            printf("-%s", taskList[i]);
        }

        printf("\n");

        printf("A 1 hour timer has been set.  It will alert you when it is over.\n");
        printf("When the timer runs out, make sure to take a break.  You can do this!\n");
        //Sleep(15000); // I set this to only 15 seconds rather than a full hour so that you
                        // don't have to sit around for an hour just to see that this works.
        time_t now = time(0);
        while (time(0) < now + 15)
        {
            // This just sits for a bit.
        }
        printf("\n");
        printf("Alright, go ahead and take a break.\n");
        printf("Press 'y' if you're ready to get back to work.\n");
        printf("Press 'n' if you're done using this program.\n");
        printf(">> ");
        fgets(continuingResponse, 3, stdin);

        if (continuingResponse[0] == 'n')
        {
            cont = false;
            printf("Thanks for participating.  Good job today!\n");
        }
    } while (cont);

    return EXIT_SUCCESS;
}