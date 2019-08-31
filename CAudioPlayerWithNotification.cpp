#include "CAudioPlayerWithNotification.h"
#include "IAudioPlayerCallback.h"

namespace SIPPlayer
{
CAudioPlayerWithNotification::CAudioPlayerWithNotification(IAudioPlayerCallback* listener)
: m_eofListener(listener)
{
}

bool CAudioPlayerWithNotification::onEof()
{
  m_eofListener->NotifyPlaybackEnd();
  return false;
}

}
