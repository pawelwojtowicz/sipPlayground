#pragma once
#include <pjsua2.hpp>

namespace SIPPlayer
{
class CPlaybackCall : public pj::Call
{
public:
  CPlaybackCall(const std::string& waveFilename, pj::Account &acc, int call_id = PJSUA_INVALID_ID);
  virtual ~CPlaybackCall();

private:
  virtual void onCallState(pj::OnCallStateParam &prm);

  virtual void onCallMediaState(pj::OnCallMediaStateParam &prm);

private:
  pj::AudioMediaPlayer m_audioPlayer;
};

}
