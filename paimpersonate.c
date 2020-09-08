#include <pulse/simple.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Time that application should sleep before gracefully exiting.
int sleeptime = 60;

int main(int argc, char *argv[])
{

  if(argc != 2){
    printf("This command takes exactly one argument:");
    printf("The application to impersonate.");
    return 1;
  }

  char *appname = argv[1];

  printf("Impersonating %s\n", appname);
  pa_simple *s;
  pa_sample_spec ss;

  ss.format = PA_SAMPLE_S16NE;
  ss.channels = 2;
  ss.rate = 44100;

  s = pa_simple_new(
                    NULL,               // Use the default server.
                    appname,            // Our application's name.
                    PA_STREAM_PLAYBACK,
                    NULL,               // Use the default device.
                    "Music",            // Description of our stream.
                    &ss,                // Our sample format.
                    NULL,               // Use default channel map
                    NULL,               // Use default buffering attributes.
                    NULL                // Ignore error code.
                    );

  sleep(sleeptime);
  printf("Stopping impersonation\n");

  pa_simple_free(s);
  return 0;
}
