#include <pjsua2.hpp>
#include "CSIPPlayer.h"

using namespace pj;

int main(int argc, char** argv)
{
  SIPPlayer::CSIPPlayer remotePlayer;

  remotePlayer.Initialize( "localhost" , "5001", "pawel");

  pj_thread_sleep(3000);

  remotePlayer.PlayWAV( "file.wav");

  pj_thread_sleep(60000);

  remotePlayer.Shutdown();

  return 0;
}


