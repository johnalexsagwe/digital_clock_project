#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to clear the screen using ANSI escape codes
void clear_screen(void)
{
	printf("\033[H\033[J");
}

// Function to display the clock
void display_clock(void)
{
	time_t raw_time;            // Holds the raw time (seconds since the epoch)
	struct tm *time_info;       // Pointer to a struct containing broken-down time
	char buffer[80];            // Buffer to store the formatted time as a string

	while (1)
	{
		time(&raw_time);                        // Get the current time
		time_info = localtime(&raw_time);       // Convert raw time to broken-down time

		// Format the broken-down time into a string
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);

		clear_screen();                        // Clear the screen
		printf("%s", buffer);                  // Print the formatted time to the console

		fflush(stdout);                        // Flush the output buffer

		sleep(1);                              // Wait for 1 second before updating the display
	}
}

int main(void)
{
	display_clock();                          // Call the function to display the clock
	return 0;
}
