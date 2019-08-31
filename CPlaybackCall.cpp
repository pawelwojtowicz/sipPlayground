#include "CPlaybackCall.h"

namespace SIPPlayer
{
CPlaybackCall::CPlaybackCall(const std::string& waveFilename, pj::Account &acc, int call_id)
: Call(acc, call_id)
{
  m_audioPlayer.createPlayer(waveFilename, PJMEDIA_FILE_NO_LOOP);
}

CPlaybackCall::~CPlaybackCall()
{
}

void CPlaybackCall::onCallState(pj::OnCallStateParam &prm)
{
}

void CPlaybackCall::onCallMediaState(pj::OnCallMediaStateParam &prm)
{
  pj::CallInfo ci = getInfo();

  for (unsigned i = 0; i < ci.media.size(); i++)
  {
    if (ci.media[i].type==PJMEDIA_TYPE_AUDIO && getMedia(i))
    {
      pj::AudioMedia *aud_med = (pj::AudioMedia *)getMedia(i);

      pj::AudDevManager& mgr = pj::Endpoint::instance().audDevManager();
      m_audioPlayer.startTransmit(*aud_med);
    }
  }

}

}
