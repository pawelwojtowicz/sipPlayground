#include "CSIPPlayer.h"
#include "CPlayerAccount.h"
#include "CPlaybackCall.h"

namespace SIPPlayer
{

CSIPPlayer::CSIPPlayer()
: m_pPlayerAccount(new CPlayerAccount())
, m_remoteSpeakerURI("sip:6001@192.168.1.103")
{
  m_sipEndpoint.libCreate();
}

CSIPPlayer::~CSIPPlayer()
{
  delete m_pPlayerAccount;
}

bool CSIPPlayer::Initialize(const std::string sipServer, const std::string& user, const std::string& password )
{
  m_sipEndpoint.libCreate();

  pj::EpConfig ep_cfg;
  m_sipEndpoint.libInit( ep_cfg );

  // Create SIP transport. Error handling sample is shown
  pj::TransportConfig tcfg;
  tcfg.port = 5061;
  try {
    m_sipEndpoint.transportCreate(PJSIP_TRANSPORT_UDP, tcfg);
  } catch (pj::Error &err) {
    //std::cout << err.info() << std::endl;
    return false;
  }

  std::string sipPlayerURI = std::string("sip:") + user + std::string("@localhost");
  std::string sipServerURI = std::string("sip:") + sipServer;

  // Configure an AccountConfig
  pj::AccountConfig acfg;
  acfg.idUri = sipPlayerURI;
  acfg.regConfig.registrarUri = sipServerURI;
  pj::AuthCredInfo cred("asterisk", "*", user, 0, password);
  acfg.sipConfig.authCreds.push_back( cred );

  m_pPlayerAccount->create(acfg);




  m_sipEndpoint.libStart();
  return true;
}

void CSIPPlayer::Shutdown()
{
}

void CSIPPlayer::PlayWAV( const std::string& waveFilename )
{
  pj::Call *pCall = new CPlaybackCall(waveFilename, *m_pPlayerAccount);

  pj::CallOpParam prm(true); // Use default call settings

  try {
    pCall->makeCall(m_remoteSpeakerURI, prm);
  } 
  catch(pj::Error& err) {
    //cout << err.info() << endl;
  }
}


}
