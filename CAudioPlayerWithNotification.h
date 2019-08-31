#pragma once
#include <pjsua2.hpp>

namespace SIPPlayer
{
class IAudioPlayerCallback;

class CAudioPlayerWithNotification : public pj::AudioMediaPlayer
{
public:
  CAudioPlayerWithNotification(IAudioPlayerCallback* pNotifier);

  virtual bool onEof() override;

private:
  IAudioPlayerCallback* m_eofListener;
};
}
