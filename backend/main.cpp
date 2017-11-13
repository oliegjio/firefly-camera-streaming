#include <vlc/libvlc.h>
#include <vlc/libvlc_vlm.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>
#include <iostream>

int main(int argc, char** argv) 
{
  libvlc_instance_t* vlc;
  const char* url;
  
  const char* sout = "#transcode{vcodec=mjpg, vb=1600}:http{dst=127.0.0.1:8090/cam.mp4}";
  const char* media_name = "Foo";

  url = "v4l2:///dev/video1";

  vlc = libvlc_new(0, NULL);
  libvlc_vlm_add_broadcast(vlc, media_name, url, sout, 0, NULL, true, false);
  libvlc_vlm_play_media(vlc, media_name);

  sleep(60);

  libvlc_vlm_stop_media(vlc, media_name);
  libvlc_vlm_release(vlc);

  return 0;



  return 0;
}
