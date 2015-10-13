#include <iostream>
extern "C"
{
 #include <stdio.h>
 #include <time.h>
 #include <iwlib.h>
}

int main(int argc, char **argv)
{
 wireless_scan_head head;
 wireless_scan *result;
 iwrange range;
 int sock;

 sock = iw_sockets_open(); // Socket to kernel

 if (iw_get_range_info(sock, "wlan0", &range) < 0) // Get data
 {
  printf("Error during iw_get_range_info. Aborting.\n");
  exit(2);
 }

 if (iw_scan(sock, "wlan0", range.we_version_compiled, &head) < 0) // Scan
 {
  printf("Error during iw_scan. Aborting.\n");
  exit(2);
 }

 result = head.result; 
 while (NULL != result) 
 {
  printf("%s\n", result->b.essid);
  result = result->next;
 }

 exit(0);
}

