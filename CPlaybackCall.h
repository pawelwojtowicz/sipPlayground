#pragma once
#include <pjsua2.hpp>
#include "IAudioPlayerCallback.h"
#include "CAudioPlayerWithNotification.h"

namespace SIPPlayer
{
class CPlaybackCall : public pj::Call, public IAudioPlayerCallback
{
public:
  CPlaybackCall(const std::string& waveFilename, pj::Account &acc, int call_id = PJSUA_INVALID_ID);
  virtual ~CPlaybackCall();

private:
	//IPlayerCallback 
	virtual void NotifyPlaybackEnd() override;

private:
  virtual void onCallState(pj::OnCallStateParam &prm);

  virtual void onCallMediaState(pj::OnCallMediaStateParam &prm);

private:
  CAudioPlayerWithNotification m_audioPlayer;
};

}
