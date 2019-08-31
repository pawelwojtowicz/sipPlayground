#pragma once

namespace SIPPlayer
{
class IAudioPlayerCallback
{
public:
  IAudioPlayerCallback() = default;
  virtual ~IAudioPlayerCallback() = default;

  virtual void NotifyPlaybackEnd() = 0;

private:
  IAudioPlayerCallback(const IAudioPlayerCallback&) = delete;
  IAudioPlayerCallback& operator=(const IAudioPlayerCallback&) = delete;


};
}
